#define LED_R D5
#define LED_M D6
#define LED_L D7
#define SWITCH_A D1
#define SWITCH_B D2
#define SWITCH_C D3
long setMillisL, setMillisM, setMillisR;
boolean stateL = false, stateM = false, stateR = false;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_M, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SWITCH_A, INPUT_PULLUP);
  pinMode(SWITCH_B, INPUT_PULLUP);
  pinMode(SWITCH_C, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(SWITCH_A) && !stateL) {
    delay(100);
    stateL = !stateL;
    setMillisL = millis();
  }
  if (!digitalRead(SWITCH_B) && !stateM && !stateL && !stateR) {
    delay(100);
    stateM = !stateM;
    setMillisM = millis();
  }
  if (!digitalRead(SWITCH_C) && !stateL && !stateR) {
    delay(100);
    stateR = !stateR;
    setMillisR = millis();
  }
  if (stateL) {
    if (millis() - setMillisL < 5000) {
      digitalWrite(LED_L, HIGH);
    }
    else {
      stateL = !stateL;
      digitalWrite(LED_L, LOW);
    }
  }
  if (stateR) {
    if (millis() - setMillisR < 3000) {
      digitalWrite(LED_R, HIGH);
    }
    else {
      stateR = !stateR;
      digitalWrite(LED_R, LOW);
    }
  }
  if (stateM) {
    if (millis() - setMillisM < 2000) {
      if (millis() - setMillisM < 500)
        digitalWrite(LED_M, HIGH);
      else if (millis() - setMillisM < 1000)
        digitalWrite(LED_M, LOW);
      else if (millis() - setMillisM < 1500)
        digitalWrite(LED_M, HIGH);
      else
        digitalWrite(LED_M, LOW);
    }
    else {
      stateM = !stateM;
      digitalWrite(LED_M, LOW);
    }
  }
}
