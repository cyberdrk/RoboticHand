//Master Writer Potentiometer 
//Transmits the mapped value of a potentiometer via I2C to a slave that is connected to a servo
//Edits made by Dipti Kulkarni <<https://github.com/cyberdrk>>
//Acknowledgements and grateful to the official Arduino Wire Master Writer tutorial  by Nicholas Zambetti <http://www.zambetti.com>




#include <Wire.h>

int potpinblue = 0;  // analog pin used to connect the potentiometer
int valblue;    // variable to read the value from the analog pin

void setup() 
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
}

byte x = 0;

void loop() 
{
  Wire.beginTransmission(8); // transmit to device #8
  valblue = analogRead(potpinblue);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.println(valblue);
  valblue = map(valblue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

  Wire.write("valblue is ");        // sends five bytes
  Wire.write(valblue);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  delay(500);
}
