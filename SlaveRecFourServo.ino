//4 Slave Receiver Servo
//Recieves the mapped values of all four potentiometer via I2C as data and writes it on the respective servos
//Edits made by Dipti Kulkarni <<https://github.com/cyberdrk>>
//Acknowledgements and grateful to the official Arduino Wire Master Writer tutorial by Nicholas Zambetti <http://www.zambetti.com>
  

#include <Wire.h>
#include <Servo.h>

Servo servo1;  // create servo object to control a servo connected by a blue wire
Servo servo2;  // create servo object to control a servo connected by a blue wire
Servo servo3;  // create servo object to control a servo connected by a blue wire
Servo servo4;  // create servo object to control a servo connected by a blue wire

void setup() 
{
  servo1.attach(11);  // attaches the servo on pin 11 to the servo object
  servo2.attach(10);  // attaches the servo on pin 10 to the servo object
  servo3.attach(6);  // attaches the servo on pin 6 to the servo object
  servo4.attach(5);  // attaches the servo on pin 5 to the servo object
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
  char c;
  
  while(1)
  {
    c = Wire.read(); // receive byte as a character 
    Serial.print(c);
    break;
  }
  
  int x = Wire.read();    // receive byte as an integer

  switch(c)
  {
    case '1':
     servo1.write(x);               // sets the servo position according to the scaled value
     Serial.println(x);         // print the integer

    case '2':
     servo2.write(x);               // sets the servo position according to the scaled value
     Serial.println(x);         // print the integer

    case '3':
     servo3.write(x);               // sets the servo position according to the scaled value
     Serial.println(x);         // print the integer

   case '4':
     servo4.write(x);               // sets the servo position according to the scaled value
     Serial.println(x);         // print the integer

  }
  
 delay(15);                           // waits for the servo to get there

}
