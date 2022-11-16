/* This program is an adaptation of the photosensor one except that it uses IR senosrs that are powered and can detect 
 *  an object at a distance you can set manually.  The sensor provides a digital output to the Arduino of 1 or 0 if an
 *  object is detected in the field of vision.  
 */

#define echoPin 6 // attach pin 6 Arduino to pin Echo of HC-SR04
#define trigPin 7 //attach pin 7 Arduino to pin Trig of HC-SR04

int E1 = 10;  //pin 10 PWM speed for DC motor
int M1 = 12;  //pin 12 will be high/low for direction
int E2 =11;   //pin 11 PWM speed for DC motor
int M2 = 13;  //pin 13 will be high/low for direction


// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup()
{
  pinMode(M1, OUTPUT);  //Set up pin 12 as digital output (high or low)
  pinMode(M2, OUTPUT);  //Set up pin 13 as digital output (high or low)
   
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  attachInterrupt(0,rightIR,LOW);  //D2 pin is now Intr0 set to FALLING, run function rightIR
  attachInterrupt(1,leftIR,LOW);  //D3 pin is noe Intr1 set to Falling, run function leftIR

}

//Motion functions

void rightIR()
{
  digitalWrite(M1,LOW);     //Seen Cliff on right IR, reverse
  digitalWrite(M2, LOW);  
  analogWrite(E1, 255);     //set power to 255/255
  analogWrite(E2, 255);
  delay(500);
  digitalWrite(M1,LOW);     //turn away from right edge
  digitalWrite(M2, HIGH);  
  analogWrite(E1, 255);     //set power to 255/255
  analogWrite(E2, 255);
  delay (500);
  Serial.println("Right REVERSE!");
}

void leftIR()
{
  digitalWrite(M1,LOW);     //Seen Cliff on right IR, reverse
  digitalWrite(M2, LOW);  
  analogWrite(E1, 255);     //set power to 255/255
  analogWrite(E2, 255);
  delay(500);
  digitalWrite(M1,HIGH);     //turn away from right edge
  digitalWrite(M2, LOW);  
  analogWrite(E1, 255);     //set power to 255/255
  analogWrite(E2, 255);
  delay (500);
  Serial.println("LEFT REVERSE!");
}

void forward()
{
  digitalWrite(M1,HIGH);     //go forward for ever, no delay :)
  digitalWrite(M2, HIGH);  
  analogWrite(E1, 55);     //set power to 55/255
  analogWrite(E2, 55);
  Serial.println("FORWARD!");
}

void backward(int seconds)     // Reverse direction for #seconds
{
  digitalWrite(M1,LOW);     //make a turn right or left
  digitalWrite(M2, LOW);  
  analogWrite(E1, 255);     //set power to full
  analogWrite(E2, 255);
  Serial.println("BACKWARDS!");
  delay(seconds);
}

void rightTurn(int seconds)    //Function to turn right for #seconds
{
  digitalWrite(M1,LOW);     //make a turn right
  digitalWrite(M2, HIGH);  
  analogWrite(E1, 255);     //set power to full
  analogWrite(E2, 255);
  Serial.println("RIGHT!");
  delay(seconds);              //use value sent to function for delay
}

void leftTurn(int seconds)  //function to turn left for #seconds
{
  digitalWrite(M1,HIGH);     //make a turn left
  digitalWrite(M2, LOW);  
  analogWrite(E1, 255);     //set power to full
  analogWrite(E2, 255);
  Serial.println("LEFT!");
  delay(seconds);            //use value sent to function for delay
}

void halt()
{
  digitalWrite(M1,HIGH);     //go forward for ever, no delay :)
  digitalWrite(M2, HIGH);  
  analogWrite(E1, 0);     //set power to 0
  analogWrite(E2, 0);
  Serial.println("STOP!");
}


void loop()
{
    
    digitalWrite(trigPin, LOW);     // Clears the trigPin condition
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);     // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);  // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    Serial.print("Distance: ");       // Displays the distance on the Serial Monitor
    Serial.print(distance);
    Serial.println(" cm");

    
    if (distance > 5)       //If distance is greater than 5 cm (2inches) go forward
    {

      forward();      //If you see nothing in front of you, go Forward
      
     }
    else 
    {
      halt();               //if you do see something, stop
      backward(200);       //go backwards for 200 milliseconds
      leftTurn(500);        //then make a left turn for 500 milliseconds
                             
     }


}
