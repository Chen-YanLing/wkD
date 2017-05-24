/*
  LED bar graph

  Turns on a series of LEDs based on the value of an analog sensor.
  This is a simple way to make a bar graph display. Though this graph
  uses 10 LEDs, you can use any number by changing the LED count
  and the pins in the array.

  This method can be used to control any series of digital outputs that
  depends on an analog input.

  The circuit:
   * LEDs from pins 2 through 11 to ground

 created 4 Sep 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/BarGraph
 */


// these constants won't change:
const int analogPin = A0;   // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph

int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};   // an array of pin numbers to which LEDs are attached


void setup() {
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  int dTime;
  // read the potentiometer:
  for(int i=0;i<=ledCount;i++){
     digitalWrite(ledPins[i], HIGH);
     int sensorReading = analogRead(analogPin);
     dTime = map(sensorReading, 0, 900, 10, 1000);
     delay(dTime);
    };
   for(int i=10;i>=0;i--){
     digitalWrite(ledPins[i], LOW);
     int sensorReading = analogRead(analogPin);
     dTime = map(sensorReading, 0, 900, 10, 1000);
     delay(dTime);
   };
}



