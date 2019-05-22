#define LED_R D5
#define LED_M D6
#define LED_L D7
#define SWITCH D1

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_M, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
  while(digitalRead(SWITCH));
}

void loop() {
  digitalWrite(LED_L,HIGH);
  delay(500);
  digitalWrite(LED_L,LOW);
  delay(500);
  digitalWrite(LED_M,HIGH);
  delay(500);
  digitalWrite(LED_M,LOW);
  delay(500);
  digitalWrite(LED_R,HIGH);
  delay(500);
  digitalWrite(LED_R,LOW);
  delay(500);
}
