#define LED D7
#define SWITCH D8

boolean switchState = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(SWITCH) == LOW) {
    delay(100);
    switchState = !switchState;
    digitalWrite(LED, switchState);
  }
}
