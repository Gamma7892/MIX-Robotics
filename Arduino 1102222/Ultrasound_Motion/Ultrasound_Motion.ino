/* This program is an adaptation of the photosensor one except that it uses IR senosrs that are powered and can detect 
 *  an object at a distance you can set manually.  The sensor provides a digital output to the Arduino of 1 or 0 if an
 *  object is detected in the field of vision.  
 */

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

int E1 = 10;  //pin 10 PWM speed for DC motor
int M1 = 12;  //pin 12 will be high/low for direction
int E2 =11;   //pin 11 PWM speed for DC motor
int M2 = 13;  //pin 13 will be high/low for direction
int Red = 7;  //pin 7 for red led
int Yellow = 6;   //pin 6 for yellow led

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup()
{
  pinMode(M1, OUTPUT);  //Set up pin 12 as digital output (high or low)
  pinMode(M2, OUTPUT);  //Set up pin 13 as digital output (high or low)
  pinMode(Red, OUTPUT); //Set up pin 7 as output
  pinMode(Yellow, OUTPUT);  //set up pin 6 as output
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

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

       digitalWrite(M1,HIGH);  //Set M1 to forward 
       digitalWrite(M2, HIGH);  //Set M2 to forward 
       analogWrite(E1, 55);   //set power to half power
       analogWrite(E2, 55);
     }
    else 
    {
      digitalWrite(M1,LOW);     //make a turn right or left
      digitalWrite(M2, HIGH);  
      analogWrite(E1, 55);     //set power to full
      analogWrite(E2, 55);
     }


}
