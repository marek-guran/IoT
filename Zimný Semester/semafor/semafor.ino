#define BUTTON_PIN 26

int LED_PIN0 = 22; //červená
int LED_PIN1 = 21; //žltá
int LED_PIN2 = 17; //zelená
int pocitadlo = 0;
int button_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN0, OUTPUT); //nastavenie červenej na výstupný bod
  pinMode(LED_PIN1, OUTPUT); // žltej
  pinMode(LED_PIN2, OUTPUT); // zelenej
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  button_state = digitalRead(BUTTON_PIN);
  if (button_state == LOW)  {
    pocitadlo++;

  if (pocitadlo == 1) {
    digitalWrite(LED_PIN0, HIGH);
    delay(1000);
  }
  else if (pocitadlo == 2)  {
    digitalWrite(LED_PIN1, HIGH);
    delay(2000);
    digitalWrite(LED_PIN0, LOW);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, HIGH);
  }
  if (pocitadlo == 3) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED_PIN2, LOW);
      delay(500);
    }
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN1, HIGH);
    delay(2000);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN0, HIGH);
    pocitadlo = 1;
  }
  }
}
