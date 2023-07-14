# Ball Tracking Robot
  The ball tracking robot is a robot designed to track a ball through a camera, and follow it using ultrasonic sensors. One of the biggest challenge was getting the ball to be detected through the raspberry pi camera, as it took me a while to figure out how opencv really works. I also had some problems with videoCapture() and videoStream(), so I decided to use PiCamera instead of opencv to do the frame part of the robot. 
<!--Replace this text with a brief description (2-3 sentences) of your project. This description should draw the reader in and make them interested in what you've built. You can include what the biggest challenges, takeaways, and triumphs from completing the project were. As you complete your portfolio, remember your audience is less familiar than you are with all that your project entails!-->

<!--You should comment out all portions of your portfolio that you have not completed yet, as well as any instructions:
```HTML 
This is an HTML comment in Markdown 
Anything between these symbols will not render on the published site 
'''
-->
| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| FirstName LastInitialOnly | School Name | Electrical Engineering | Incoming Senior


**Replace the BlueStamp logo below with an image of yourself and your completed project. Follow the guide [here](https://tomcam.github.io/least-github-pages/adding-images-github-pages-site.html) if you need help.**

![Headstone Image](logo.svg)
  
# Final Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/F7M7imOVGug" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For your final milestone, explain the outcome of your project. Key details to include are:
- What you've accomplished since your previous milestone
- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at BSE



# Second Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/y3VAmNlER5Y" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  For my second milestone, I worked on connecting the ultrasonic sensors, while trying to figure out ways to attach it to the breadboard. I wasn't able to see how I could attach the 2 other ultrasonic sensors shown on the schematic for the project, so I just attached one of them for now. One major challenge that I faced was that my connection from the battery to the VCC and Ground ports in the Raspberry Pi were pretty weak, as it would disconnect and reconnect easily, making it hard to control wirelessly. Hopefully I can fix this problem by Milestone 3, so the bot can be able to run wirelessly with the battery pack. For my final milestone, I need to be able to attach the camera and ultrasonic sensors to a stable position, and be able to code 
For your second milestone, explain what you've worked on since your previous milestone. You can highlight:
- Technical details of what you've accomplished and how they contribute to the final goal
- What has been surprising about the project so far
- Previous challenges you faced that you overcame
- What needs to be completed before your final milestone 

# First Milestone

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/CaCazFBhYKs" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  My project, the bal tracking robot, is designed to track a ball using ultrasonic sensors (distance sensors), and a built in Raspberry Pi Camera. So far, I've connected the chassis with the motors and wheels, and the battery pack installed. The Raspberry Pi's software is correctly installed, and it connects well with my moniter. I also have the breadboard attached, with all the wires connecting everything together. One major challenege I faced was the limitted amount of space, as I had to switch around the components so everything could fit. So far, the layout seems to fit everything that I need, with the exception of the PiCamera. To complete the project, my plan is to figure out how the ultrasonic sensors work, and also learn how to track the ball using openCV.  


# Schematics 
Here's where you'll put images of your schematics. [Tinkercad](https://www.tinkercad.com/blog/official-guide-to-tinkercad-circuits) and [Fritzing](https://fritzing.org/learning/) are both great resoruces to create professional schematic diagrams, though BSE recommends Tinkercad becuase it can be done easily and for free in the browser. 

# Code
Here's where you'll put your code. The syntax below places it into a block of code. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize it to your project needs. 

```c++
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

# Bill of Materials
Here's where you'll list the parts in your project. To add more rows, just copy and paste the example rows below.
Don't forget to place the link of where to buy each component inside the quotation marks in the corresponding row after href =. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize this to your project needs. 

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Drive Train | Chassis, wheels, battery, motors | $13.59| <a href="https://www.amazon.com/Smart-Chassis-Motors-Encoder-Battery/dp/B01LXY7CM3/ref=sr_1_5?crid=373Y5YK6JWMD&keywords=robot+chassis&qid=1687740144&sprefix=robot+chassi%2Caps%2C93&sr=8-5"> Link </a> |
| Raspberry Pi | Nate's Supply | $139.99 | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/](https://www.amazon.com/CanaKit-Raspberry-4GB-Starter-Kit/dp/B07V5JTMV9/ref=sr_1_2_sspa?crid=S71E3O7XIUUH&keywords=raspberry%2Bpi%2B4&qid=1689364765&sprefix=raspberry%2Bpi%2B4%2Caps%2C184&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1)"> Link </a> |
| Screwdriver Kit | Screwing Stuff | $7.98 | <a href="https://www.amazon.com/Small-Screwdriver-Set-Mini-Magnetic/dp/B08RYXKJW9/"> Link </a> |
| Ultrasonic Sensor | A.K.A. Distance Sensor | $8.99 | <a href="https://www.amazon.com/ELEGOO-HC-SR04-Ultrasonic-Distance-MEGA2560/dp/B01COSN7O6/"> Link </a> |
| H Bridges | only using one of them | $8.99 | <a href="https://www.amazon.com/ACEIRMC-Stepper-Controller-2-5-12V-H-Bridge/dp/B0923VMKSZ/"> Link </a> |
| Raspberr Pi Camera | taking pictures and videos | $9.99 | <a href="https://www.amazon.com/Arducam-Megapixels-Sensor-OV5647-Raspberry/dp/B012V1HEP4/"> Link </a> |
| Jumper Wires | Connecting everything together | $6.98| <a href="https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/"> Link </a> |
| Keyboard and Mouse | To connect to Raspberry Pi | $23.99 | <a href="https://www.amazon.com/gp/product/B07XDWCLYF/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1"> Link </a> |
| Wire Strippers | Cuts wires | $6.98 | <a href="https://www.amazon.com/Eclipse-CP-301G-ProsKit-Precision-Stripper/dp/B005JVJDIA/ref=sr_1_5?crid=3EA8H92LI1T8Z&keywords=30+awg+stripper&qid=1687440357&sprefix=30awg+stripper%2Caps%2C160&sr=8-5"> Link </a> |
| Soldering Kit | Solders stuff | $17.99 | <a href="https://www.amazon.com/Soldering-Iron-Kit-Temperature-Desoldering/dp/B07S61WT16/ref=sxts_b2b_sx_reorder_acb_business?content-id=amzn1.sym.44ecadb3-1930-4ae5-8e7f-c0670e7d86ce%3Aamzn1.sym.44ecadb3-1930-4ae5-8e7f-c0670e7d86ce&crid=3M9M2FJSFSN8U&cv_ct_cx=soldering+kit&keywords=soldering+kit&pd_rd_i=B07S61WT16&pd_rd_r=81dfb3be-2f9f-471b-9612-c467f88a93a0&pd_rd_w=6Cvia&pd_rd_wg=6kA87&pf_rd_p=44ecadb3-1930-4ae5-8e7f-c0670e7d86ce&pf_rd_r=7FY6MS4DKN5ENRJ6J8WD&qid=1685477027&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=soldering+ki%2Caps%2C163&sr=1-1-62d64017-76a9-4f2a-8002-d7ec97456eea"> Link </a> |
| Digital Multimeter | Measures voltage | $9.98 | <a href="https://www.amazon.com/Etekcity-Multimeter-MSR-R500-Electronic-Multimeters/dp/B01N9QW620/ref=sxts_b2b_sx_reorder_acb_business?content-id=amzn1.sym.44ecadb3-1930-4ae5-8e7f-c0670e7d86ce%3Aamzn1.sym.44ecadb3-1930-4ae5-8e7f-c0670e7d86ce&crid=1741POGJIFZMN&cv_ct_cx=multimeter&keywords=multimeter&pd_rd_i=B01N9QW620&pd_rd_r=831d94e3-2e6d-428c-aeed-e326df3b43f6&pd_rd_w=WPcva&pd_rd_wg=EsDRz&pf_rd_p=44ecadb3-1930-4ae5-8e7f-c0670e7d86ce&pf_rd_r=XZMYRCR5X4ZWN2YPYV9E&qid=1687376939&sprefix=multimeter%2Caps%2C88&sr=1-1-62d64017-76a9-4f2a-8002-d7ec97456eea"> Link </a> |
| Safety Glasses | Wear them while soldering | $6.12 | <a href="https://www.amazon.com/MCR-Safety-CL010-Checklite-Glasses/dp/B009SRXSUA/ref=sr_1_12?keywords=safety+glasses&qid=1687376864&sprefix=safety+gla%2Caps%2C91&sr=8-12"> Link </a> |
| Backup Battery | Extra battery if other one is broken | $16.99 | <a href="https://www.amazon.com/EnergyQC-Portable-Ultra-Compact-Compatible-More-Black/dp/B09Z6T7FQ8/ref=sr_1_31?crid=KNHGHKNN3CWT&keywords=backup+battery+usb&qid=1687378917&sprefix=backup+battery+usb%2Caps%2C86&sr=8-31"> Link </a> |
# Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here.
