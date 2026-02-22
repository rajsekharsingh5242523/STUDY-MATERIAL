#include <ESP32Servo.h>

Servo myServo;

void setup() {
  myServo.attach(18);   
}

void loop() {
  myServo.write(0);
  Serial.println("0")
  delay(1000);
  myServo.write(90);
  Serial.println("90")
  delay(1000);
  myServo.write(180);
  Serial.println("180");
  delay(1000);
}
