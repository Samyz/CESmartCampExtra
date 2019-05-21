#define LED_R D4
#define LED_M D5
#define LED_L D6
#define SWITCH_A D7
#define SWITCH_B D8
long setMillis;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_M, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SWITCH_A, INPUT_PULLUP);
  pinMode(SWITCH_B, INPUT_PULLUP);
  while(digitalRead(SWITCH_A));
  setMillis=millis();
}

void loop() {
  if(millis()-setMillis<500)
    digitalWrite(LED_L,HIGH);
  if(millis()-setMillis>=500&&millis()-setMillis<1000)
    digitalWrite(LED_L,LOW);
  if(millis()-setMillis>=1000&&millis()-setMillis<1500)
    digitalWrite(LED_M,HIGH);
  if(millis()-setMillis>=1500&&millis()-setMillis<2000)
    digitalWrite(LED_M,LOW);
  if(millis()-setMillis>=2000&&millis()-setMillis<2500)
    digitalWrite(LED_R,HIGH);
  if(millis()-setMillis>=2500&&millis()-setMillis<3000)
    digitalWrite(LED_R,LOW);
  if(millis()-setMillis>=3000)
    setMillis=millis();
  if(!digitalRead(SWITCH_B)){
    digitalWrite(LED_L,LOW);
    digitalWrite(LED_M,LOW);
    digitalWrite(LED_R,LOW);
    while(digitalRead(SWITCH_A));
      setMillis=millis();
  }
}
