/*
Hat V2 Test code

currently just flashes the red, green and blue LED's in sequence
*/
int LEDred = 2;
int LEDgreen = 3;
int LEDblue = 4;
int pause = 200; // pause time in Ms

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDblue, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // First the red LED
  digitalWrite(LEDred, HIGH);   // turn the RED LED on (HIGH is the voltage level)
  delay(pause);                       // wait for a second
  digitalWrite(LEDred, LOW);    // turn the RED LED off by making the voltage LOW
  delay(pause);                       // wait for a second
  // Now the green LED
  digitalWrite(LEDgreen, HIGH);   // turn the RED LED on (HIGH is the voltage level)
  delay(pause);                       // wait for a second
  digitalWrite(LEDgreen, LOW);    // turn the RED LED off by making the voltage LOW
  delay(pause);                       // wait for a second
  // finally the blue LED
  digitalWrite(LEDblue, HIGH);   // turn the RED LED on (HIGH is the voltage level)
  delay(pause);                       // wait for a second
  digitalWrite(LEDblue, LOW);    // turn the RED LED off by making the voltage LOW
  delay(pause);                       // wait for a second
}
