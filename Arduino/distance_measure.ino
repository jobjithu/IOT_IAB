#include<Wire.h>

int echo_pin = 9;
int trigger_pin = 10;
int buzzer = 13;

void setup()
{
  pinMode(echo_pin,INPUT);
  pinMode(trigger_pin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigger_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW);
  delayMicroseconds(2);
  
  int duration = pulseIn(echo_pin,HIGH);
  int distance = duration  * 0.034 / 2;
  
  Serial.print("Distance:");
  Serial.println(distance);
  
  if(distance <= 20){
    Serial.println("Close Object");
    tone(buzzer,1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
  } else {
    Serial.println("Far Object");
  }
  delay(1000);
}