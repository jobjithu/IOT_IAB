#include<Wire.h>
#include "DHT.h"

#define dht_pin 2
#define dht_type DHT11

DHT dht(dht_pin,dht_type);

int buzzer = 13;

void setup(){
    pinMode(buzzer,OUTPUT);
    Serial.begin(9600);

    dht.begin();
}

void loop(){
    float h = dht.readHumidity();
    float temp_in_cel = dht.readTemperature();
    float temp_in_farhen = dht.readTemperature(true);

    if(isnan(h) || isnan(temp_in_cel) || isnan(temp_in_farhen)){
        Serial.println("Failed to Read");
        return;
    }

    // Print The data

    if(temp_in_cel > 29){
        Serial.println("Alert: High Temperature");
        tone(buzzer,1000);
        delay(1000);
        noTone(buzzer);
        define(1000);
    } else {
        Serial.println("Low Temperature");
    }
    delay(1000);
}