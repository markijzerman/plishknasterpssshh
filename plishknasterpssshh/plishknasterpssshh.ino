 #include <SimpleTimer.h>
 #include <Morse.h>
 #include <Adafruit_NeoPixel.h>

 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, 9, NEO_GRB + NEO_KHZ800);

  // Set values
 int readCounter = 0;
 int numOfStrings = 5;
 int WPM = 15;
 int flashPin = 13;

 // Class declaration
 Morse morse(flashPin, WPM); // first nr is pin, second is speed. higher is faster. WPM.
 SimpleTimer timer;

 // Set the strings first
#include <avr/pgmspace.h>
// max length: /////////////////////////////////////////////////////////////////
const char string_0[] PROGMEM = "Dit is zin een";
const char string_1[] PROGMEM = "Dit is zin twee";
const char string_2[] PROGMEM = "Dit is zin drie";
const char string_3[] PROGMEM = "Dit is zin vier";
const char string_4[] PROGMEM = "Dit is zin vijf";

// Now set up a table to refer to the strings

const char * const string_table[] PROGMEM =
{
  string_0,
  string_1,
  string_2,
  string_3,
  string_4
};

// set max characters. 65 characters per sentence. otherwise it will NOT start!
char buffer[65];

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
    Serial.begin(9600);
    pixels.begin(); // This initializes the NeoPixel library.
    timer.setInterval(1, repeatMe);

    delay(1000);

 }

 void loop() {
   timer.run();
   // if the board is not busy, send next message

   if (morse.busy == 0) {
       if (readCounter < numOfStrings) {
        strcpy_P(buffer, (char*)pgm_read_word(&(string_table[readCounter]))); // Necessary casts and dereferencing, just copy.
        morse.send(buffer); 
        Serial.println( buffer );
        readCounter ++;
        
        if (readCounter >= numOfStrings) {
          readCounter = 0;
        }
      }
   }
 }
