const int RPWM_OUTPUT = 3; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
const int LPWM_OUTPUT = 2; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)
const int DELAY = 100;

void setup()
{
   pinMode(RPWM_OUTPUT, OUTPUT);
   pinMode(LPWM_OUTPUT, OUTPUT);
   digitalWrite(RPWM_OUTPUT, LOW);
   digitalWrite(LPWM_OUTPUT, LOW);
   Serial.begin(9600);
}
void loop()
{
 while(Serial.available() == 0);
 int input = Serial.parseInt(SKIP_WHITESPACE);
 Serial.print(input);
 Serial.println();
 if(input == 1) {
  digitalWrite(LPWM_OUTPUT, LOW);
  digitalWrite(RPWM_OUTPUT, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(RPWM_OUTPUT, LOW);

 } else if(input == 2) {
  digitalWrite(RPWM_OUTPUT, LOW);
  digitalWrite(LPWM_OUTPUT, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(LPWM_OUTPUT, LOW);
 } else if(input == 3) {
  digitalWrite(RPWM_OUTPUT, HIGH);
  digitalWrite(LPWM_OUTPUT, LOW);
 } else if (input == 4) {
    digitalWrite(RPWM_OUTPUT, LOW);
    digitalWrite(LPWM_OUTPUT, HIGH);
 } else {
    digitalWrite(RPWM_OUTPUT, LOW);
    digitalWrite(LPWM_OUTPUT, LOW);
 }
 Serial.print(digitalRead(RPWM_OUTPUT));
 Serial.print(digitalRead(LPWM_OUTPUT));
 Serial.println("<- Digital outputs");
}
