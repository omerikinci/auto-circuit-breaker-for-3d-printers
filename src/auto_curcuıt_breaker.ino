#define SENSOR 2
#define LED_GREEN 3
#define LED_RED 4
#define RELAY_1 5
#define RELAY_2 6
#define BUTTON 7

int status = 0;
int timer = 0;

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(BUTTON, INPUT);

  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);

  digitalWrite(LED_RED, LOW);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    timer = 0;
    status = 0;
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
    digitalWrite(RELAY_1, HIGH);
    digitalWrite(RELAY_2, HIGH);
  }

  if (status == 0) {
    digitalWrite(LED_GREEN, HIGH);

    if (timer == 30) {
      status = 1;
      return;
    } else {
      if (digitalRead(SENSOR) == LOW) {
        timer = 0;
        return;
      }
      
      delay(1000);
      timer++;
    }
  } else if (status == 1) {
    timer = 0;
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(RELAY_1, LOW);
    digitalWrite(RELAY_2, LOW);
  }
}
