int E1 = 10;  //pin 10 PWM speed for DC motor
int M1 = 12;  //pin 12 will be high/low for direction
int E2 =11;   //pin 11 PWM speed for DC motor
int M2 = 13;  //pin 13 will be high/low for direction


void setup()
{
pinMode(M1, OUTPUT);  //Set up pin 12 as digital output (high or low)
pinMode(M2, OUTPUT);  //Set up pin 13 as digital output (high or low)
}

void loop()
{
   
  
    digitalWrite(M1,LOW);  //Set M1 to forward or backward?
    digitalWrite(M2, LOW);  //Set M2 to forward or backward?
    analogWrite(E1, 127);   //set power to 127 'half'
    analogWrite(E2, 127);
     
    delay(1000);              //wait 1 second
 
    digitalWrite(M1,LOW);     //set both motors to stop
    digitalWrite(M2, LOW);
    analogWrite(E1, 0);
    analogWrite(E2, 0);
   
    delay(1000);

    digitalWrite(M1,HIGH);     //set both motors to opposite direction
    digitalWrite(M2, HIGH);
    analogWrite(E1, 127);
    analogWrite(E2, 127);
   
    delay(1000);

    digitalWrite(M1,LOW);     //set both motors to stop
    digitalWrite(M2, LOW);
    analogWrite(E1, 0);
    analogWrite(E2, 0);
   
    delay(1000);
 
}
