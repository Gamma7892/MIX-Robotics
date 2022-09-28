int E1 = 10;  //pin 10 PWM speed for DC motor
int M1 = 12;  //pin 12 will be high/low for direction
int E2 =11;   //pin 11 PWM speed for DC motor
int M2 = 13;  //pin 13 will be high/low for direction
int Red = 7;  //pin 7 for red led
int Yellow = 6;   //pin 6 for yellow led

int photoSensor1 = 0;  //set up variable to store value of photsensor
int photoSensor2 = 0;  //set up variable to store value of photsensor

void setup()
{
pinMode(M1, OUTPUT);  //Set up pin 12 as digital output (high or low)
pinMode(M2, OUTPUT);  //Set up pin 13 as digital output (high or low)
pinMode(Red, OUTPUT); //Set up pin 7 as output
pinMode(Yellow, OUTPUT);  //set up pin 6 as output

Serial.begin(9600);     //setup terminal screen for debugging

}

void loop()
{
    photoSensor1 = analogRead(A3);  //Read pin A3 and store it in photSensor1 variable
    photoSensor2 = analogRead(A4);  //Read pin A4 and store it in photSensor2 variable
    Serial.print("Photo 1; ");   //Print the value of photsensor to serial monitor to be able to measure light in room
    Serial.println(photoSensor1);
    Serial.print("Photo 2; ");   //Print the value of photsensor to serial monitor to be able to measure light in room
    Serial.println(photoSensor2);

    digitalWrite(M1,HIGH);  //Set M1 to forward or backward?
    digitalWrite(M2, HIGH);  //Set M2 to forward or backward?
    analogWrite(E1, 127);   //set power to half power
    analogWrite(E2, 127);
    digitalWrite(Red, HIGH);    //Turn on RED LED
    digitalWrite(Yellow, HIGH);  //Turn on Yellow LED
    delay(500);

    if (photoSensor1 < photoSensor2)
    {
      digitalWrite(M1,HIGH);    //make a turn right or left
      digitalWrite(M2, LOW);    
      analogWrite(E1, 255);     //set power to full
      analogWrite(E2, 255);
      digitalWrite(Red, LOW);    //Turn off RED LED
      digitalWrite(Yellow, HIGH);  //Turn on Yellow LED
      delay(500);
    }
    else if(photoSensor1 > photoSensor2)
    {
      digitalWrite(M1,LOW);     //make a turn right or left
      digitalWrite(M2, HIGH);  
      analogWrite(E1, 255);     //set power to full
      analogWrite(E2, 255);
      digitalWrite(Red, HIGH);    //Turn on RED LED
      digitalWrite(Yellow, LOW);  //Turn off Yellow LED
      delay(500);
    }
    
}
