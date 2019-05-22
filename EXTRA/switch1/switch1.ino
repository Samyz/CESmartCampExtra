#define LED D7
#define SWITCH D1

boolean switchState = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(SWITCH));
  if (digitalRead(SWITCH) == LOW) {
    delay(100);
    switchState = !switchState;
    digitalWrite(LED, switchState);
  }
}
