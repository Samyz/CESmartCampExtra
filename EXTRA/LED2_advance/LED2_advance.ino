#define LED D7

int divider = 8;
boolean directions = true;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop() {
  flash();
  if (directions) {
    divider = (divider >> 1);
    if (divider == 1) {
      directions = !directions;
    }
  }
  else {
    divider = (divider << 1);
    if (divider == 8) {
      directions = !directions;
    }
  }
}

void flash() {
  digitalWrite(LED, LOW);
  delay(2000 / divider);
  digitalWrite(LED, HIGH);
  delay(2000 / divider);
}
