const int ledrojo = 9;
const int ledverde = 10;
const int ledazul = 6;
const int touch = 20;

int buttonState = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledrojo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledazul, OUTPUT);
  pinMode(touch, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(touch);

  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledverde, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);                      // wait for a second

  } else {
    // turn LED off:
    digitalWrite(ledverde, LOW);   // turn the LED off by making the voltage LOW
    delay(1000);  
  }
}
