#define ldrpin 33
#define ledpin 32

int threshold=2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
   pinMode(ledpin,OUTPUT);
   pinMode(ldrpin,INPUT);

}

void loop() {
  int ldrvalue=analogRead(ldrpin);
  Serial.print("LDR Value:");

  Serial.println(ldrvalue);

  if(ldrvalue>threshold){
    digitalWrite(ledpin,HIGH);
  }else{
    digitalWrite(ledpin,LOW);
  }
  // put your main code here, to run repeatedly:
  delay(300); // this speeds up the simulation
}
