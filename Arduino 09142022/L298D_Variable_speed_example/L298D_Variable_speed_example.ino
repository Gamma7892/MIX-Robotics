int E1 = 10;  //pin 10 PWM speed for DC motor
int M1 = 12;  //pin 12 will be high/low for direction
int E2 =11;   //pin 11 PWM speed for DC motor
int M2 = 13;  //pin 13 will be high/low for direction

void setup()
{
pinMode(M1, OUTPUT);
pinMode(M2, OUTPUT);
}

void loop()
{
  { 
  int value;
  for(value = 0 ; value <= 255; value+=5)
    {
     digitalWrite(M1,HIGH);
     digitalWrite(M2, HIGH);
     analogWrite(E1, value);
     analogWrite(E2, value);
     delay(30);
    }
    delay(1000);
 }
 {
  int value;
  for(value = 0 ; value <= 255; value+=5)
   {
    digitalWrite(M1,LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, value);
    analogWrite(E2, value);
    delay(30);
   }
   delay(1000);
  }
}
