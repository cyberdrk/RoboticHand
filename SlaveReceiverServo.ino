//Slave Receiver Servo 
//Receives the mapped value of a potentiometer via I2C and writes it onto the servo
//Acknowledgements and grateful to the official Arduino Wire Slave Receiver tutorial by Nicholas Zambetti <http://www.zambetti.com>


#include <Wire.h>
#include <Servo.h>

Servo servo1;  // create servo object to control a servo connected by a blue wire

void setup() 
{
  servo1.attach(11);  // attaches the servo on pin 11 to the servo object
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() 
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) 
{
  /*while (1 < Wire.available()) 
  { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }*/
 
  
  int x = Wire.read();    // receive byte as an integer

  servo1.write(x);               // sets the servo position according to the scaled value
  Serial.println(x);         // print the integer
  
  delay(15);                           // waits for the servo to get there

}
