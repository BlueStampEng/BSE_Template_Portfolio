#include <Keypad.h>
#include <Servo.h>
#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal.h>

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// Set up the serial port to use softwareserial..
SoftwareSerial mySerial(4, 5);

#else
// On Leonardo/M0/etc, others with hardware serial, use hardware serial!
// #0 is green wire, #1 is white
#define mySerial Serial1

#endif


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

uint8_t id;



const int ROW_NUM = 4;     //four rows
const int COLUMN_NUM = 3;  //three columns

char keys[ROW_NUM][COLUMN_NUM] = {  //Mapping the keypad
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte pin_rows[ROW_NUM] = { 13, 12, 11, 10 };  //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = { 9, 8, 7 };    //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

Servo myservo;  //Defining servo - Works

void setup() {  //Runs once (Basically start of program)
  Serial.begin(9600);
  myservo.attach(3);  //Linking the servo to digital pin #3 on the arduino
  Serial.println("Enter Password: ");

  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);

  // set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {
    //Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getParameters();
  Serial.println(finger.getTemplateCount());
  if (finger.templateCount == 0) {

    Serial.print("Sensor doesn't contain any fingerprint data. Please enroll a fingerprint.");
  }

  else {
    //Serial.println("Waiting for valid finger...");
    Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }
}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}


//Random variable indentifiables here
int password = "432016";
int i;
String attempted_passcode;
char key = 'j';
int delay_timer = "1000";
int pos;
int finger_count;
char new_keys;
char unlock_key;
char lock_key;

void loop() {
  finger.LEDcontrol(FINGERPRINT_LED_ON, 0, FINGERPRINT_LED_RED);
  char key = keypad.getKey();  //Saves inputed key into key variable

  delay(50);

  if (key) {

    if (key == '*') {  //Checks for * (clear key)
      Serial.println("Terminal cleared.");
      attempted_passcode = "";
     } 
      else if (key == '#') {  //Checks for # (answer key)
        Serial.println("Password entered");
        if (attempted_passcode == password) {  //Check for correct password
          Serial.println("Password correct.");
          attempted_passcode = "";
          char new_keys = keypad.getKey();
          finger.LEDcontrol(FINGERPRINT_LED_ON, 0, FINGERPRINT_LED_PURPLE);
          Serial.println("Press # to enroll a new fingerprint. Press any key to continue.");
        //SERVO CODE HERE/Fingerprint code
          while (true) {
            new_keys = keypad.getKey();
            if (new_keys) {
              Serial.println(new_keys);
              break;

            }
            
          }
          if (new_keys) {
            if (finger.templateCount == 0 || new_keys == '#') {
              finger.LEDcontrol(FINGERPRINT_LED_FLASHING, 25, FINGERPRINT_LED_PURPLE, 2000);
              Serial.println("Ready to enroll a fingerprint!");
              Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as...");
              id = readnumber();
              //ADD A FUNCTION THAT CAN MAKE THE KEYPAD ENROLL A NEW FINGERPRINT.
              if (id == 0) {// ID #0 not allowed, try again!
                return;
              }
              Serial.print("Enrolling ID #");
              Serial.println(id);

              getFingerprintEnroll();
              finger_count = finger_count + 1;
              

          }
            else {
              Serial.println("Put ur finger on the sensor ");
              //finger.LEDcontrol(FINGERPRINT_LED_FLASHING, 25, FINGERPRINT_LED_RED, 7000);  (Blinking red, the breathing one is a fade blink)
              finger.LEDcontrol(FINGERPRINT_LED_BREATHING, 100, FINGERPRINT_LED_RED);
              delay(5000);
              getFingerprintID();
              Serial.println("Press * to unlock/lock the box.");
              if (finger.confidence > 150){
                char unlock_key = keypad.getKey();
                while (true) {
                  unlock_key = keypad.getKey();
                  if (unlock_key) {
                    Serial.println(unlock_key);
                    break;
                  }
                }
                if (unlock_key == '*') {
                for (pos = 90; pos >= 0; pos -= 3){
                  myservo.write(pos);
                  }
                char lock_key = keypad.getKey();
                while (true) {
                  lock_key = keypad.getKey();
                  if (lock_key) {
                    Serial.println(lock_key);
                    break;
                  }
                }
                for (; pos <= 90; pos +=3){
                  myservo.write(pos);
                  }
              
                }
              }
                
              else {
                Serial.println("Fingerprint confidence not high enough. L");
              }
              
            }
          }

       } else {
          Serial.println("Password incorrect.");
          finger.LEDcontrol(FINGERPRINT_LED_FLASHING, 25, FINGERPRINT_LED_RED, 2000);
          attempted_passcode = "";
          //COULD ADD DEALY TIME FOR FUNNYS
          delay_timer = delay_timer + "1000";
          delay(delay_timer);
       }


     }else {

      attempted_passcode = attempted_passcode + key;
      Serial.println(attempted_passcode);
     }
   }
 }

//Fingerprint enroll function

uint8_t getFingerprintEnroll() {

  int p = -1;
  Serial.print("Waiting for valid finger to enroll as #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println(".");

      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  Serial.println("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("Place same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  Serial.print("Creating model for #");  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Prints matched!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Fingerprints did not match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("Stored!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  return true;
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    finger.LEDcontrol(FINGERPRINT_LED_ON, 0, FINGERPRINT_LED_BLUE);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
