int E1 = 10;  //pin 10 PWM speed for DC motor
int M1 = 12;  //pin 12 will be high/low for direction
int E2 =11;   //pin 11 PWM speed for DC motor
int M2 = 13;  //pin 13 will be high/low for direction

int photoSensor1 = 0;  //set up variable to store value of photsensor
int photoSensor2 = 0;  //set up variable to store value of photsensor

void setup()
{
pinMode(M1, OUTPUT);  //Set up pin 12 as digital output (high or low)
pinMode(M2, OUTPUT);  //Set up pin 13 as digital output (high or low)

Serial.begin(9600);     //setup terminal screen for debugging

}

void loop()
{
    photoSensor1 = analogRead(A3);  //Read pin A3 and store it in photSensor1 variable
    photoSensor1 = analogRead(A4);  //Read pin A4 and store it in photSensor2 variable
    Serial.print("Photo 1; ");   //Print the value of photsensor to serial monitor to be able to measure light in room
    Serial.println(photoSensor1);
    Serial.print("Photo 2; ");   //Print the value of photsensor to serial monitor to be able to measure light in room
    Serial.println(photoSensor2);

    if (photoSensor1 < 600 && photoSensor2 <600)  //if both sensors are less than 600, assume not dark enough to move
    {
      digitalWrite(M1,LOW);  //Set M1 to forward or backward?
      digitalWrite(M2, LOW);  //Set M2 to forward or backward?
      analogWrite(E1, 0);   //set power to 0 'stop'
      analogWrite(E2, 0);
      delay(500);
    }
    else if (photoSensor1 < photoSensor2)
    {
      digitalWrite(M1,HIGH);  //Set M1 to forward or backward?
      digitalWrite(M2, HIGH);  //Set M2 to forward or backward?
      analogWrite(E1, 127);   //set power to 127 'half'
      analogWrite(E2, 127);
      delay(500);
    }
    else if(photoSensor1 > photoSensor2)
    {
      digitalWrite(M1,LOW);  //Set M1 to forward or backward?
      digitalWrite(M2, LOW);  //Set M2 to forward or backward?
      analogWrite(E1, 127);   //set power to 127 'half'
      analogWrite(E2, 127);
      delay(500);
    }

}
