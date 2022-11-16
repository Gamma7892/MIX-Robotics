/* This program using the ultrasonic range finder and IR sensors to search for another object within a certain amount of distance 
 *  and then tries to follow it. It will also use IR sensors as interrupt enabled inputs to avoid the edge of the platform
 *  and reverse direction to avoid falling off.  If Ultrasonic sees an object that is within 40 cm, it will head towards it.  If
 *  nothing is seen inside the 40 cm, it will move forward for a fixed distance and then scan again
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

int maxRange = 40; //max distance to scan.  Anything beyond 40 cm will be 'ignored'
int measure;

void setup()
{
  pinMode(M1, OUTPUT);  //Set up pin 12 as digital output (high or low)
  pinMode(M2, OUTPUT);  //Set up pin 13 as digital output (high or low)
   
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  attachInterrupt(0,rightIR,LOW);  //D2 pin is now Intr0 set to logic 0, run function rightIR
  attachInterrupt(1,leftIR,LOW);  //D3 pin is noe Intr1 set to logic 0, run function leftIR

}

//Motion functions - motor controls with time arguments included

void forward(int millisec)
{
  digitalWrite(M1,HIGH);     //go forward for ever, no delay :)
  digitalWrite(M2, HIGH);  
  analogWrite(E1, 55);     //set power to 55/255
  analogWrite(E2, 55);
  delay(millisec);
  Serial.println("FORWARD!");
}

void backward(int millisec)     // Reverse direction for #millisec
{
  digitalWrite(M1,LOW);     //make a turn right or left
  digitalWrite(M2, LOW);  
  analogWrite(E1, 255);     //set power to full
  analogWrite(E2, 255);
  Serial.println("BACKWARDS!");
  delay(millisec);
}

void rightTurn(int millisec)    //Function to turn right for #millisec
{
  digitalWrite(M1,LOW);     //make a turn right
  digitalWrite(M2, HIGH);  
  analogWrite(E1, 255);     //set power to full
  analogWrite(E2, 255);
  Serial.println("RIGHT!");
  delay(millisec);              //use value sent to function for delay
}

void leftTurn(int millisec)  //function to turn left for #millisec
{
  digitalWrite(M1,HIGH);     //make a turn left
  digitalWrite(M2, LOW);  
  analogWrite(E1, 255);     //set power to full
  analogWrite(E2, 255);
  Serial.println("LEFT!");
  delay(millisec);            //use value sent to function for delay
}

void halt()                   
{
  digitalWrite(M1,HIGH);     //motor direction irrelevant since we are stopping
  digitalWrite(M2, HIGH);  
  analogWrite(E1, 0);        //set power to 0
  analogWrite(E2, 0);
  Serial.println("STOP!");
}


// Function to make mesauring from range finder easier to call.  Call function and set it equal to a variable

void range()
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
    return distance;
}

/* Interrupt Functions that will be called on if we we don't see the edge of platform anymore
 *  currently set to Int0 = pin D2 and Int1 = pin D3.  They are set to detect a logic 0 at pin
 */

void rightIR()
{
  backward(500);
  rightTurn(500);
  Serial.println("Right REVERSE!");
}

void leftIR()
{
  backward(500);
  leftTurn(500);
  Serial.println("LEFT REVERSE!");
}

void scanRight()
{
  measure = range;              //scan and measure distance
  
  if (measure < maxRange)       //If object sighted withing maxRange
    {
     forward(10);               //move forward to target for 10 milliSec.
     
     }                          //and end the IF conditional and leave to Funtcion
    else 
    {
      rightTurn(100);           //If not turn a little bit and exit and wait to be called again
    }
 
}

void scanLeft()
{
  measure = range;              //scan and measure distance
  
  if (measure < maxRange)       //If object sighted withing maxRange
    {
     forward(10);               //move forward to target for 10 milliSec.
    }                          //and end the IF conditional and leave to Funtcion
    else 
    {
      leftTurn(100);           //If not turn a little bit and exit and wait to be called again
    }
  
}

void loop()
{

    forward(100);
    halt();
    scanRight();
    
}
