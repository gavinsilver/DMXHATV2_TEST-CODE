/*
 * Test code to read in values from the dip switch and print values via serial interface
 * V1 - 11/5/18 - Tested on Breadboard
 */
int dmx_add = 0;  // 0 - 511
int dmx_mode = 0; // 0-7
int jp3 = 0;      // JP3 0=Open 1=Closed
int val = 0;      // Temp variable used to read input


// the setup routine runs once when you press reset:
void setup() {    
  
  // Setup pins to read DMX address and DMX_Mode.  Becuse of the internal pullup resistor 
  // when the swith id off the input will be HIGH and when the switch is on the input will
  // be LOW
        
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT); // Note A6 & A7 Analog only and need external pullup resistor
  pinMode(A7, INPUT);
  // start serial port for debug
  Serial.begin(9600);
  Serial.println("Starting ....");
}

// the loop routine runs over and over again forever:
void loop() 
{

  // read in DMX address (9bits)
  dmx_add = 0;
  val = digitalRead(2); 
  if (val==LOW) {
      dmx_add |= 1;
    };
  val = digitalRead(4); 
  if (val==LOW) {
      dmx_add |= 1<<1;
    };
  val = digitalRead(7); 
  if (val==LOW) {
      dmx_add |= 1<<2;
    };
  val = digitalRead(8); 
  if (val==LOW) {
      dmx_add |= 1<<3;
    };
  val = digitalRead(9); 
  if (val==LOW) {
      dmx_add |= 1<<4;
    };
  val = digitalRead(A0); 
  if (val==LOW) {
      dmx_add |= 1<<5;
    };
  val = digitalRead(A1); 
  if (val==LOW) {
      dmx_add |= 1<<6;
    };
  val = digitalRead(A2); 
  if (val==LOW) {
      dmx_add |= 1<<7;
    };
  val = digitalRead(A3); 
  if (val==LOW) {
      dmx_add |= 1<<8;
    };
  Serial.print("DMX Address =");
  Serial.println(dmx_add);

  // read in DMX Mode (3 bits)
  dmx_mode = 0;
  val = digitalRead(A4); 
  Serial.print("A4 =");
  Serial.println(val);
  if (val==LOW) {
      dmx_mode |= 1;
    };
  val = digitalRead(A5);
  Serial.print("A5 =");
  Serial.println(val); 
  if (val==LOW) {
      dmx_mode |= 1<<1;
    };
  val = analogRead(A6); // Note that A6 and A7 only work as analog inputs and need an external pullup resistor
  Serial.print("A6 =");
  Serial.println(val);
  if (val<500) {
      dmx_mode |= 1<<2;
    };
  Serial.print("DMX Mode =");
  Serial.println(dmx_mode);

  // Read in JP3
  val = analogRead(A7); // Note that A6 and A7 only work as analog inputs and need an external pullup resistor
  Serial.print("A7 =");
  Serial.println(val);
  if (val<500) {
      jp3 = 1;
    }
    else {
      jp3 = 0;
    }
  Serial.print("JP3 =");
  Serial.println(jp3);

  // wait for 2 seconds
  delay(1000);
}
