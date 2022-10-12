/* This program is an adaptation of the photosensor one except that it uses IR senosrs that are powered and can detect 
 *  an object at a distance you can set manually.  The sensor provides a digital output to the Arduino of 1 or 0 if an
 *  object is detected in the field of vision.  
 */

int E1 = 10;  //pin 10 PWM speed for DC motor
int M1 = 12;  //pin 12 will be high/low for direction
int E2 =11;   //pin 11 PWM speed for DC motor
int M2 = 13;  //pin 13 will be high/low for direction
int Red = 7;  //pin 7 for red led
int Yellow = 6;   //pin 6 for yellow led

int ir1 = 2;  //set up what pin we will use for IR sensor 1
int ir2 = 3;  //set up what pin we will us for IR sensor 2

void setup()
{
pinMode(M1, OUTPUT);  //Set up pin 12 as digital output (high or low)
pinMode(M2, OUTPUT);  //Set up pin 13 as digital output (high or low)
pinMode(Red, OUTPUT); //Set up pin 7 as output
pinMode(Yellow, OUTPUT);  //set up pin 6 as output

pinMode(ir1, INPUT);   //These are digital read pins, so we have to define them in Void Setup
pinMode(ir2, INPUT);   

Serial.begin(9600);     //setup terminal screen for debugging

}

void loop()
{
    Serial.print("IR 1; ");   //Print the value of IR Sensor so that you can calibrate to set distance it will detect.
    Serial.println(digitalRead(ir1));
    Serial.print("IR 2; ");   //Print the value of IR Sensor so that you can calibrate to set distance it will detect.
    Serial.println(digitalRead(ir2));
    delay(100);

    if (digitalRead(ir1) == 0)
      {
        digitalWrite(Red, HIGH);
      }
      else
      {
        digitalWrite(Red,LOW);
      }

    if (digitalRead(ir2) == 0)
      {
        digitalWrite(Yellow, HIGH);
      }
      else
      {
        digitalWrite(Yellow,LOW);
      }

/*

    digitalWrite(M1,HIGH);  //Set M1 to forward or backward?
    digitalWrite(M2, HIGH);  //Set M2 to forward or backward?
    analogWrite(E1, 55);   //set power to half power
    analogWrite(E2, 55);
    digitalWrite(Red, HIGH);    //Turn on RED LED
    digitalWrite(Yellow, HIGH);  //Turn on Yellow LED
    //delay(500);

    if (photoSensor1 < photoSensor2)
    {
      digitalWrite(M1,HIGH);    //make a turn right or left
      digitalWrite(M2, LOW);    
      analogWrite(E1, 55);     //set power to full
      analogWrite(E2, 55);
      digitalWrite(Red, LOW);    //Turn off RED LED
      digitalWrite(Yellow, HIGH);  //Turn on Yellow LED
      //delay(500);
    }
    else if(photoSensor1 > photoSensor2)
    {
      digitalWrite(M1,LOW);     //make a turn right or left
      digitalWrite(M2, HIGH);  
      analogWrite(E1, 55);     //set power to full
      analogWrite(E2, 55);
      digitalWrite(Red, HIGH);    //Turn on RED LED
      digitalWrite(Yellow, LOW);  //Turn off Yellow LED
      //delay(500);
    }
    */
}
