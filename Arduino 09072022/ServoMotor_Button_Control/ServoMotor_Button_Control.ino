#include <Servo.h>  //Import servo libraries

Servo testMotor;   //create an "Object" in our code to represent our motor and what it can do

#define LED 12     //permanantly set 12 to LED and 7 to Button
#define Button 7   // cannot be altered in code from now on

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);    //setup pin 12, LED pin, as an output
  pinMode(Button, INPUT);  //setup pin 7, button, as in input   BOTH are digital inputs

  testMotor.attach(6);    //set up pin 6, a PWM pin, as the pin that will send command to servo motor
}
void loop()
{
  // put your main code here, to run repeatedly:

    testMotor.write(0);       //when program starts, move servo to position 0

    if (digitalRead(Button) == 0)   //wait to see if button is press, when pressed, it will = 0
    {
      digitalWrite(LED, HIGH);        //turn on LED
      testMotor.write(255);           //move servo to position at 255, 180 degrees away
      delay(1000);                    //wait for 1 second (1000 milliseconds)
    }
    else
      {
      digitalWrite(LED,LOW);        //else, if not pressed, hold at position 0
      testMotor.write(0);           //and keep led off
      
    }
  

}
