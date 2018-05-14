/*
This is an interface for the Arduino, a tempareture sensor and an LCD display.
*/

// An array of temperature readings so I can take the average of 400 readings.
double temperatureReadings[400];

// Load the LiquidCrystal library, which will give us
// commands to interface to the LCD:

#include <LiquidCrystal.h>

// Initialize the library with the pins we're using.
// (Note that you can use different pins if needed.)
// See http://arduino.cc/en/Reference/LiquidCrystal
// for more information:

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2); //Initialize the 16x2 LCD
  lcd.clear();	//Clear any old data displayed on the LCD

  lcd.print("Temperature:"); // Display Temperature:
}

// Converts the raw analog input of a pin to Celcius
double convertToCelcius(int pin){
  return (((analogRead(pin) * 0.004882814) - 0.5) * 100.0);
}

void loop()
{
  // Fill an array with temperature readings
  for (int i = 0; i < 400; ++i){
    temperatureReadings[i] = convertToCelcius(0);
    delay(1);
  }

  // Sum the temperature readings together
  double sum = 0;
  for (int i = 0; i < 400; ++i){
    sum += temperatureReadings[i];
  }

  // Take the average of the sum
  double average = sum/400.0;
  
  // Print the number out.
  lcd.setCursor(0, 1);
  lcd.print(round(average));
}
