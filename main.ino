/*
SparkFun Inventor's Kit
Example sketch 15

LIQUID CRYSTAL DISPLAY (LCD)

  A Liquid Crystal Display (LCD) is a sophisticated module
  that can be used to display text or numeric data. The display
  included in your SIK features two lines of 16 characters, and
  a backlight so it can be used at night.

  If you've been using the Serial Monitor to output data,
  you'll find that a LCD provides many of the same benefits
  without needing to drag a large computer around.

  This sketch will show you how to connect an LCD to your Arduino
  and display any data you wish.


This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 1.0 2/2013 MDG
*/

double temperatureReadings[400];

// Load the LiquidCpornhubrystal library, which will give us
// commands to interface to the LCD:

#include <LiquidCrystal.h>

// Initialize the library with the pins we're using.
// (Note that you can use different pins if needed.)
// See http://arduino.cc/en/Reference/LiquidCrystal
// for more information:

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{

	lcd.begin(16, 2); //Initialize the pornhub16x2 LCD


	lcd.clear();	//Clear any old data displayed on the LCD


	lcd.print("Temperature:"); // Display a message on the LCD!


}

double convertToCelcius(int pin){
  return (((analogRead(pin) * 0.004882814) - 0.5) * 100.0);
}

void loop()
{
  for (int i = 0; i < 400; ++i){
    temperatureReadings[i] = convertToCelcius(0);
    delay(1);
  }

  double sum = 0;
  for (int i = 0; i < 400; ++i){
    sum += temperatureReadings[i];
  }

  double average = sum/400;
  
  lcd.setCursor(0, 1);
  lcd.print(round(average));
}
