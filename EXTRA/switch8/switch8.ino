#define LED_R D5
#define LED_M D6
#define LED_L D7
#define SWITCH D1
long setMillis, pauseMillis;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_M, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
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
  if (!digitalRead(SWITCH)) {
    pauseMillis = millis() - setMillis;
    delay(100);
    while (1) {
      if (!digitalRead(SWITCH)) {
        delay(100);
        setMillis = millis() - pauseMillis;
        break;
      }
      delay(1);
    }
  }
}
