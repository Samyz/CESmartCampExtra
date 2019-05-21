#define LED_R D5
#define LED_L D6
#define SWITCH_A D7
#define SWITCH_B D8
boolean ledL = false;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SWITCH_A, INPUT_PULLUP);
  pinMode(SWITCH_B, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(SWITCH_A)) {
    delay(100);
    if (!ledL) {
      ledL = !ledL;
      digitalWrite(LED_L, HIGH);
    }
    else
      digitalWrite(LED_R, HIGH);
  }
  if (!digitalRead(SWITCH_B)) {
    delay(100);
    digitalWrite(LED_L, LOW);
    digitalWrite(LED_R, LOW);
    ledL = false;
  }
}
