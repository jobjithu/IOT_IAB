#include<Wire.h>

int buzzer = 13;
int motion_sensor = 5;
int state = LOW;
int value = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(motion_sensor,INPUT);
}

void loop()
{
    int val = digitalRead(motion_sensor);
    Serial.println(val);
    if(val == 1){
        delay(1000);
        if(state==LOW){
            Serial.println("Motion Detected");
            tone(buzzer,1000);
            delay(1000);
            noTone(buzzer);
            delay(500);
            state = HIGH;
        }
    } else {
        delay(1000);
        if(state=HIGH){
            Serial.println("Motion Stopped");
            state = LOW;
        }
    }
}