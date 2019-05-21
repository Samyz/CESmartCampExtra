#define RED_LED D7
#define GREEN_LED D8

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(1000);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    RedFlash();
  }
  for (int i = 0; i < 2; i++) {
    GreenFlash();
  }
  RedFlash();
  GreenFlash();
}

void RedFlash(){
  digitalWrite(RED_LED, HIGH);
  delay(500);
  digitalWrite(RED_LED, LOW);
  delay(500);
}

void GreenFlash(){
  digitalWrite(GREEN_LED, LOW);
  delay(500);
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
}
