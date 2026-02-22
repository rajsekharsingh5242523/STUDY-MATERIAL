#include <ESP32Servo.h>

#define trigpin 5
#define echopin 18
#define servopin 19

Servo sensor;

long duration;
float distance;
void setup() {
  
  Serial.begin(115200);
  
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

  sensor.attach(servopin);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin,LOW);

  duration=pulseIn(echopin,HIGH);

  distance=duration*0.034/2;

  Serial.print("Distance:");
  Serial.println(distance);

  if(distance<20){
    sensor.write(90);
  }else{
    sensor.write(0);
  }
  
  delay(500);
}
