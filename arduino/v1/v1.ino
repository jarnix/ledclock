#include <Time.h>
#include <TimeLib.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
/*
#include <TimeLib.h>
*/

#define PIN 6

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_RGBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  // setSyncProvider(requestSync);  //set function to call when sync required
  Serial.println("Waiting for time sync message");
  // Messages consist of the letter T followed by ten digit time (as seconds since Jan 1 1970)
  // On Linux, you can use "date +T%s\n > /dev/ttyACM0" (UTC time zone)
  // ex: T1357041600

  setTime(1496605541);
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.println(second());

  strip.begin();
  strip.show();

//  int8_t i;
//  for(i=0; i<90; i++) {
//    Serial.print(i);
//    Serial.print(" => ");
//    getIndexSixtyInCircle(i);
//  }
}


void loop() {
  // Some example procedures showing how to display to the pixels:
  //colorWipe(strip.Color(255, 0, 0), 50); // Red
  //colorWipe(strip.Color(0, 255, 0), 50); // Green
  //colorWipe(strip.Color(0, 0, 255), 50); // Blue
  //colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  //theaterChase(strip.Color(127, 127, 127), 50); // White
  //theaterChase(strip.Color(127, 0, 0), 50); // Red
  //theaterChase(strip.Color(0, 0, 127), 50); // Blue

  uint16_t totalMs = 0;

  // Serial.println("Hello Pi");

  if (Serial.available()) {
    processSyncMessage();
  }
  if (timeStatus() != timeNotSet) {

    for(uint8_t i = 0; i<60; i++) {
      clearStrip();

      showHour();
      showMinute();
      showSecond();
      showInSecond(i);
      
      strip.show();
      delay(8); // increment = 60 * 8
      totalMs += 8;
    }
    delay(1000 - totalMs); // missing milliseconds
  }

  /*
  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
  */
}

void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if (Serial.find(TIME_HEADER)) {
    pctime = Serial.parseInt();
    if (pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
      setTime(pctime); // Sync Arduino clock to the time received on the serial port
    }
  }
}

time_t requestSync()
{
  Serial.write(TIME_REQUEST);
  return 0; // the time will be sent later in response to serial mesg
}

void clearStrip() {
  for(uint8_t i = 0; i<60; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0, 0));
  }
}

void showInSecond(uint8_t ledIndex) {
  int8_t indexOut = getIndexSixtyInCircle(second() + ledIndex);
//  Serial.print("inSecond : ");
//  Serial.print(second() + ledIndex);
//  Serial.print(" => ");
//  Serial.println(indexOut);
  strip.setPixelColor(indexOut, strip.Color(0, 0, 0, 10));
}

void showSecond() {
  int8_t nbSeconds = second();
  for(int8_t secondLed = nbSeconds; secondLed <= nbSeconds + 1; secondLed++) {
    strip.setPixelColor(getIndexSixtyInCircle(secondLed), strip.Color(253, 231, 76, 0));
  }
}

void showMinute() {
  int8_t nbMinutes = minute();
  for(int8_t index = nbMinutes - 2; index <= nbMinutes + 1; index++) {
    strip.setPixelColor(getIndexSixtyInCircle(index), strip.Color(91, 192, 235, 0));
  }
}

void showHour() {
  int8_t nbHours = hour();
  int8_t indexHours = getIndexTwelveInCircle(nbHours);
  for(int8_t index = indexHours - 2; index <= indexHours + 1; index++) {
    strip.setPixelColor(getIndexSixtyInCircle(index), strip.Color(220, 52, 235, 0));
  }
}

// for minutes and seconds
uint8_t getIndexSixtyInCircle(int8_t index) {
//  Serial.print("sixty : ");
  int8_t indexOut;
  indexOut = index;
  if(index < 0) {
    indexOut = 60 + index;
  }
  if(index > 60) {
//    Serial.print(" (> 60) ");
    indexOut = index - 60;
  }
  if(indexOut < 30) {
    indexOut = 30 + indexOut;
  }
  else {
    indexOut = indexOut - 30;
  }
//  Serial.print(index);
//  Serial.print(" => ");
//  Serial.println(indexOut);
  return indexOut;
}

// for the hours
uint8_t getIndexTwelveInCircle(int8_t index) {
  int8_t indexOut;
  if(index > 12) {
    index = index - 12;
  }
  if (index  < 6) {
    indexOut = 30 + 5 * index;
  }
  else {
    indexOut =  5 * index - 30;
  }
  return indexOut;
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
