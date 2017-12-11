#include <dht11.h>



int temPin = A2;
int lightPin = A3;
int humPin = A4;


dht11 DHT11;

float temp;
float light;
float hud;


void setup(){
    Serial.begin(9600);
    pinMode(temPin, INPUT);
    pinMode(lightPin, INPUT);
    pinMode(humPin, INPUT);

}

void loop(){
    temp = getTemp();
    light = getLight();
    hud = getHud();
    Serial.println(" ");
    Serial.println("######################");
    Serial.print("temprature = ");
    Serial.println(temp);
    Serial.print("light = ");
    Serial.println(light);
    Serial.print("Humadity = ");
    Serial.println(hud);
    Serial.println("####################");
    Serial.println(" ");
    delay(5000);
}


float getTemp(){
    int volt = analogRead(temPin);
    float miliVolt = volt*(5.0/1023.0)*1000;
    return (float)miliVolt/10.0; 
}
float getLight(){
    int volt = analogRead(lightPin);
    float miliVolt = volt*(5.0/1023.0)*1000;
    return (float)miliVolt/10.0; 
}

float getHud(){
    DHT11.read(humPin);
    return (float)DHT11.humidity;
    
}




