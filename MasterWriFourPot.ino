//Master Writer Four Potentiometer 
//Transmits mapped values of all four potentiometers via I2C to the slave that is connected to four servos
//Edits made by Dipti Kulkarni <<https://github.com/cyberdrk>>
//Acknowledgements and grateful to the official Arduino Wire Master Writer tutorial by Nicholas Zambetti <http://www.zambetti.com>


#include <Wire.h>

int val1 = 0, val2 = 0, val3 = 0, val4 = 0;// val5 = 0;
//int valH = 0, valT = 0, valU = 0; 
int potpin1 = 0, potpin2 = 0, potpin3 = 0, potpin4 = 0;// potpin5 = 0;

void setup() 
{
  // Start the I2C bus as Master
  Wire.begin();
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(9);
  
  val1 = analogRead(potpin1);
  val1 = map(val1, 3, 1023, 0, 176);
  
  val2 = analogRead(potpin2);
  val2 = map(val2, 3, 1023, 0, 176);
  
  val3 = analogRead(potpin3);
  val3 = map(val3, 3, 1023, 0, 176);
  
  val4 = analogRead(potpin4);
  val4 = map(val4, 3, 1023, 0, 176);
  
  /*val5 = analogRead(potpin5);
  val5 = map(val5, 3, 1023, 0, 176);*/
  Wire.write('1');
  Wire.write(val1);

  Wire.write('2');
  Wire.write(val2);
  
  Wire.write('3');
  Wire.write(val3);
  
  Wire.write('4');
  Wire.write(val4);

  Wire.endTransmission();

  delay(15); 

}
  /*Wire.write(1);
  writeHTU(val1);

  Wire.write(2);
  writeHTU(val2);

  Wire.write(3);
  writeHTU(val3);

  Wire.write(4);
  writeHTU(val4);

  Wire.write(5);
  writeHTU(val5);

  delay(250);
}

// To send a 3 digit value character by character
void writeHTU(int val) // HTU stands for Hundredth Tenth Unit
{
  valU = val % 10; 
  val = val / 10; 
  Wire.write(valU); 
  
  valT = val % 10; 
  val = val / 10; 
  Wire.write(valT); 

  valH = val % 10; 
  val = val / 10; 
  Wire.write(valH); 
}*/

