#include<DHT.h>
#define dhtpin 15
#define dhttype DHT22

DHT dht(dhtpin,dhttype);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float humidity= dht.readHumidity();
  float temperature=dht.readTemperature();
  
  Serial.print("Humidity:");
  Serial.println(humidity);
  Serial.print("Temperature:");
  Serial.println(temperature);
  
  delay(1000);// this speeds up the simulation
}
