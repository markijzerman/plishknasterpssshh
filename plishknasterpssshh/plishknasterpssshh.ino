 #include <SimpleTimer.h>
 #include <Morse.h>
 #include <Adafruit_NeoPixel.h>

 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, 9, NEO_GRB + NEO_KHZ800);

 // Class declaration
 Morse morse(13, 10);
 SimpleTimer timer;

 // Set values
 int readCounter = 0;
 int numOfStrings = 4;

 // Set lines!
String Lines[] = {
  "STARTUP",
  "hi izabela.", 
  "hi from the couch where I'm programming",
  "one simple light"
};

 // a function to be executed periodically
 void repeatMe()
 {
   morse.update();
   if(digitalRead(13) == HIGH) { 
    pixels.setPixelColor(0, pixels.Color(255,255,255));
    pixels.show();
   }

   if(digitalRead(13) == LOW) { 
    pixels.setPixelColor(0, pixels.Color(0,0,0));
    pixels.show();
   }
 }

 void setup()
 { 
    Serial.begin(115200);
    pixels.begin(); // This initializes the NeoPixel library.
    timer.setInterval(1, repeatMe);

    delay(1000);

 }

 void loop() {
   timer.run();
   // if the board is not busy, send next message
   if (morse.busy == 0) {
      if (readCounter < numOfStrings){
        char curLine[Lines[readCounter].length()+1]; // make a char with dynamic length based on string length
        Lines[readCounter].toCharArray(curLine, Lines[readCounter].length()+1);
        
        Serial.println(curLine);
    
        morse.send(curLine);
        readCounter ++;
        Serial.println(readCounter);
       }
   }
 }
