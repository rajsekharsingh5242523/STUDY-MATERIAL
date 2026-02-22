int pot = 0;
void setup() {
  Serial.begin(115200);
  pinMode(34, INPUT);
}

void loop() {
  pot=analogRead(34);
  Serial.println(pot);
  delay(200);
}
