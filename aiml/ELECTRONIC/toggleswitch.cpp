// analog pin connected to potentiometer
#define POT 34
// digital pin for push button input
#define Push1 14
// pin driving the LED
#define LED 12
// variable to store potentiometer reading
int pot= 0;
// counter for number of button presses
int push= 0;
void setup() {
  // start serial communications at 115200 baud for debugging
  Serial.begin(115200);
  // configure pins: potentiometer as input, LED as output, button as input
  pinMode(POT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Push1, INPUT);
}
void loop() {
  // read the button; it is wired active-low so 0 means pressed
  if (digitalRead(Push1)==0){
    // increment push count on each press
    push = push + 1;
    // simple debounce / rate limit
    delay(500);
    
  }
  // when push count is even, LED stays off and potentiometer value is shown
  if (push%2 == 0) {
      digitalWrite(LED,LOW);
      pot=analogRead(POT); // read analog value from pot
      Serial.println(pot); // send it over serial
      delay(500);
    }
  // when push count is odd, blink the LED rapidly
  if (push%2 == 1) {
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
    }
    
  }
