#include <ezButton.h>
#define BUTTON_PIN 26
#define LED_PIN 22

ezButton button(BUTTON_PIN);
int led_state = LOW;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  button.setDebounceTime(50);

}

void loop() {
  button.loop();
  if(button.isPressed())  {
    led_state = !led_state;
    digitalWrite(LED_PIN,led_state);
    }

}
