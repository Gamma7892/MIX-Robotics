//  Motor A
int const ENA = 10;  
int const INA = 12;
//  Motor B
int const ENB = 11;  
int const INB = 13;

int const MIN_SPEED = 27;   // Set to minimum PWM value that will make motors turn
int  const ACCEL_DELAY = 50; // delay between steps when ramping motor speed up or down.

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


//Ultrasonics pins
#define echoPin 8 // attach pin D8 Arduino to pin Echo of HC-SR04
#define trigPin 7 //attach pin D7  Arduino to pin Trig of HC-SR04

//#define DEBUG
#ifdef DEBUG
  #define DEBUG_PRINTLN(x) Serial.println(x)
  #define DEBUG_PRINT(x) Serial.print(x)
#elseifdef DEBUG
  #define DEBUG_PRINTLN(x)
  #define DEBUG_PRINT(x)
#endif

void setup() {
  pinMode(ENA, OUTPUT);   // set all the motor control pins to outputs
  pinMode(ENB, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  
  
  #ifdef DEBUG
    Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  #endif
  DEBUG_PRINTLN("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  DEBUG_PRINTLN("with Arduino UNO R3");
}

void loop() {
  // put your main code here, to run repeatedly:
  Forward(75);   
  //TurnLeft(75);
  delay(10);
  Distance();
}

void Distance(){
// Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  DEBUG_PRINT("Distance: ");
  DEBUG_PRINT(distance);
  DEBUG_PRINTLN(" cm");
}

// Forward(int s) drives the robot forward
// Assumes motor A is left motor and B right motor (ultrasonic sensor is the front of the robot)
// int s: sets the speed of the robot between 0-100 percent
void Forward (int s)
{
  Motor('B', 'F', s);
}

// Backward(int s) drives the robot forward
// Assumes motor A is left motor and B right motor (ultrasonic sensor is the front of the robot)
// int s: sets the speed of the robot between 0-100 percent
void Backward (int s)
{
  Motor('B', 'R', s);
}

// Stop(int s) drives the robot forward
// Assumes motor A is left motor and B right motor (ultrasonic sensor is the front of the robot)
// int s: sets the speed of the robot between 0-100 percent
void Stop ()
{
  Motor('B', 'F', 0);
}

// TurnLeft(int s) drives the robot forward
// Assumes motor A is left motor and B right motor (ultrasonic sensor is the front of the robot)
// int s: sets the speed of the robot between 0-100 percent
void TurnLeft (int s)
{
  Motor('R', 'R', s);
  Motor('L', 'F', s);
}

// TurnRight(int s) drives the robot forward
// Assumes motor A is left motor and B right motor (ultrasonic sensor is the front of the robot)
// int s: sets the speed of the robot between 0-100 percent
void TurnRight (int s)
{
  Motor('R', 'F', s);
  Motor('L', 'R', s);
}

/*
 * Motor function does all the heavy lifting of controlling the motors
 * mot = motor to control either 'R' or 'L'.  'B' controls both motors.
 * dir = Direction either 'F'orward or 'R'everse
 * speed = Speed.  Takes in 1-100 percent and maps to 0-255 for PWM control.  
 * Mapping ignores speed values that are too low to make the motor turn.
 * In this case, anything below 27, but 0 still means 0 to stop the motors.
 */
void Motor(char mot, char dir, int speed)
{
  // remap the speed from range 0-100 to 0-255
  int newspeed;
  if (speed == 0)
    newspeed = 0;   // Don't remap zero, but remap everything else.
  else
    newspeed = map(speed, 1, 100, MIN_SPEED, 255);

  switch (mot) {
    case 'R':   // Controlling Right
      if (dir == 'F') {
        digitalWrite(INA, HIGH);
      }
      else if (dir == 'R') {
        digitalWrite(INB, LOW);
      }
      analogWrite(ENA, newspeed);
      break;

    case 'L':   // Controlling Left Motor
      if (dir == 'F') {
        digitalWrite(INB, HIGH);
      }
      else if (dir == 'R') {
        digitalWrite(INB, LOW);
      }
      analogWrite(ENB, newspeed);
      break;

    case 'B':  // Controlling 'B'oth Motors
      if (dir == 'F') {
        digitalWrite(INA, HIGH);
        digitalWrite(INB, HIGH);
      }
      else if (dir == 'R') {
        digitalWrite(INA, LOW);
         digitalWrite(INB, LOW);
      }
      analogWrite(ENA, newspeed);
      analogWrite(ENB, newspeed);
      break;
  }
}
