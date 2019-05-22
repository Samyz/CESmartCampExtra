#define LED_R D5
#define LED_L D6
#define SWITCH_A D1
#define SWITCH_B D2
long setMillisL, setMillisR;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SWITCH_A, INPUT_PULLUP);
  pinMode(SWITCH_B, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(SWITCH_A)) {
    setMillisL = millis();
  }
  if (!digitalRead(SWITCH_B)) {
    setMillisR = millis();
  }
  if (millis() - setMillisL < 3000)
    digitalWrite(LED_L, HIGH);
  else
    digitalWrite(LED_L, LOW);
  if (millis() - setMillisR < 2000)
    digitalWrite(LED_R, HIGH);
  else
    digitalWrite(LED_R, LOW);
}
