#define LED_R D5
#define LED_M D6
#define LED_L D7
#define SWITCH_A D1
#define SWITCH_B D2
long setMillis;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_M, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SWITCH_A, INPUT_PULLUP);
  pinMode(SWITCH_B, INPUT_PULLUP);
  while (digitalRead(SWITCH_A));
  setMillis = millis();
}

void loop() {
  if (millis() - setMillis < 500)
    digitalWrite(LED_L, HIGH);
  else if (millis() - setMillis < 1000)
    digitalWrite(LED_L, LOW);
  else if (millis() - setMillis < 1500)
    digitalWrite(LED_M, HIGH);
  else if (millis() - setMillis < 2000)
    digitalWrite(LED_M, LOW);
  else if (millis() - setMillis < 2500)
    digitalWrite(LED_R, HIGH);
  else if (millis() - setMillis < 3000)
    digitalWrite(LED_R, LOW);
  else
    setMillis = millis();
  if (!digitalRead(SWITCH_B)) {
    digitalWrite(LED_L, LOW);
    digitalWrite(LED_M, LOW);
    digitalWrite(LED_R, LOW);
    while (digitalRead(SWITCH_A));
    setMillis = millis();
  }
}
