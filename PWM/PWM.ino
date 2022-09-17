#define PWM 4
void setup() {
  // put your setup code here, to run once:
  pinMode(PWM,4);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(PWM, 76);
}
