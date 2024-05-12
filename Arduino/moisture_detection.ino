#include<Wire.h>

int buzzer = 13;
int led = 7;
int moisture_sensor = A0;

void setup(){
    pinMode(buzzer,OUTPUT);
    pinMode(led,OUTPUT);
    pinMode(moisture_sensor,INPUT);
    Serial.begin(9600);
}

void loop(){
    int value = analogRead(motion_sensor);
    int moisture = (100 - ((value/1023)*100))
    Serial.print("Moisture :");
    Serial.println(value);

    if(value >= 1000){
        Serial.println("Not in Soil");
    }
    if(value < 1000 & value >= 600){
        Serial.println("Dry Soil");
        tone(buzzer,1000);
        delay(1000);
        noTone(buzzer);
        delay(500);
        digitalWrite(led,HIGH);
    }
    if(value < 600 && value >= 370){
        Serial.println("Humid Soil");
        noTone(buzzer);
        digitalWrite(led,HIGH);
    }
    if(value < 370){
        Serial.println("Water Soil");
        noTone(buzzer);
        digitalWrite(led,LOW);
    }
    delay(1000);
}