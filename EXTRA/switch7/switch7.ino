#define LED_R D5
#define LED_L D6
#define SWITCH D1
long timer;
int count = 0;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
  timer = millis();
}

void loop() {
  if (millis() - timer < 5000) {
    if (!digitalRead(SWITCH)) {
      delay(100);
      count++;
    }
    digitalWrite(LED_R, HIGH);
  }
  else if (millis() - timer < 7000) {
    digitalWrite(LED_R, LOW);
    if (count != 0) {
      count %= 3;
      if (count == 0)
        count = 3;
      for (int i = 0; i < count; i++) {
        digitalWrite(LED_L, HIGH);
        delay(500);
        digitalWrite(LED_L, LOW);
        delay(500);
      }
      count = 0;
    }
    timer += 7000;
  }
  else
    timer = millis();
}
