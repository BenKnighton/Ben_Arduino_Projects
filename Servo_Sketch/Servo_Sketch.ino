#include <Servo.h>

Servo myservo;

int position = 0;

void setup() {

  Serial.begin(115200);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  myservo.attach(9);
  position = 90;
  myservo.write(90);
  Serial.println(position);
  delay(100);
}

void loop() {
  if (digitalRead(2) == LOW) {
    if (position > 0)  {
      position--;
      Serial.println(position);
    }
    myservo.write(position);
  }

  if (digitalRead(3) == LOW) {
    if (position < 180) {
      position++;
      Serial.println(position);
    }
    myservo.write(position);
  }

  delay(2);
}
