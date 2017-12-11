int temPin = A2;

float temp;
void setup(){
    Serial.begin(9600);
    pinMode(temPin, INPUT);

}

void loop(){
  temp = getTemp();
  
    Serial.println("");
    Serial.println("###################");
    Serial.print("Tempreture for room is = ");
    Serial.println(temp);
    Serial.println("##################");
    Serial.println(" ");
    delay(5000);

}

float getTemp(){
    int volt = analogRead(temPin);
    float miliVolt = volt*(5.0/1023.0)*1000;
    return (float)miliVolt/10;
}
