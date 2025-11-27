#include<dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
#include<LiquidCrystal.h>

int pirPin = 3; // Input for HC-S501
int pirValue; // Place to store read PIR Value
int lastPirValue = LOW; //Place to store last PIR Vakue

const int DHT_SENSOR_PIN = 2; //Input for DHT11
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
float temperature;
float humidity;
bool measuring = false;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

unsigned long displayEndTime = 0;
const unsigned long displayDuration = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);

  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  pirValue = digitalRead(pirPin);
  
  if(pirValue == HIGH && lastPirValue == LOW && !measuring){
    measuring = true;
  }
  
  if(measuring){
    if(dht_sensor.measure(&temperature, &humidity)){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("T = ");
      lcd.print(temperature, 1);
      lcd.print(" C");
      lcd.setCursor(0, 1);
      lcd.print("H = ");
      lcd.print(humidity, 1);
      lcd.print(" %");
      displayEndTime = millis() + displayDuration;
      measuring = false;
    }
  }

  if(millis() > displayEndTime && displayEndTime != 0){
    lcd.clear();
    displayEndTime = 0;
  }
  lastPirValue = pirValue;
}
