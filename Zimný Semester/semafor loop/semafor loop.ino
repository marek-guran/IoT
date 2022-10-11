#define BUTTON_PIN 26

int LED_PIN0 = 22;  //červená
int LED_PIN1 = 21;  //žltá
int LED_PIN2 = 17;  //zelená
int pocitadlo = 1;
int button_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN0, OUTPUT);  //nastavenie červenej na výstupný bod
  pinMode(LED_PIN1, OUTPUT);  // žltej
  pinMode(LED_PIN2, OUTPUT);  // zelenej
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  button_state = digitalRead(BUTTON_PIN);
  if (button_state == LOW) {
    pocitadlo++;
  }

  if (pocitadlo == 3) {
    pocitadlo = 1;
  }

  while (pocitadlo == 1) {
    digitalWrite(LED_PIN0, HIGH);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    delay(5000);
    digitalWrite(LED_PIN1, HIGH);
    delay(2000);
    digitalWrite(LED_PIN0, LOW);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, HIGH);
    delay(5000);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN1, HIGH);
    delay(2000);
    return;
  }

  while (pocitadlo == 2) {
    digitalWrite(LED_PIN0, LOW);
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, LOW);
    delay(2000);
    digitalWrite(LED_PIN1, LOW);
    delay(2000);
    return;
  }
}