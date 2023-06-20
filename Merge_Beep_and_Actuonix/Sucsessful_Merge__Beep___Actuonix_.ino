#include "pitches.h"  //add note library

#include <Servo.h>

int melody[] = {NOTE_G7, NOTE_AS6};

int buttonPin = 12;

int noteDurations[] = {4, 5};

Servo myservo;

int pos = 0;

void setup() {

  pinMode(buttonPin, INPUT);

  Serial.begin(115200);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  myservo.attach(9);
  pos = 90;
  myservo.write(90);
  Serial.println(pos);
  delay(100);

}

void loop() {
  {
    if (digitalRead(2) == LOW) {
      if (pos > 0)  {
        pos--;
        Serial.println(pos);
      }
      myservo.write(pos);
    }

    if (digitalRead(3) == LOW) {
      if (pos < 180) {
        pos++;
        Serial.println(pos);
      }
      myservo.write(pos);
    }

    delay(2);
  }
  //read the input pin
  int buttonState = digitalRead(buttonPin);

  //if the button is pressed
{ if (buttonState == 1) {

      //iterate over the notes of the melody
      for (int thisNote = 0; thisNote < 2; thisNote++) {

        //to calculate the note duration, take one second. Divided by the note type
        int noteDuration = 700 / noteDurations [thisNote];
        tone(8, melody [thisNote], noteDuration);

        //to distinguish the notes, set a minimum time between them
        //the note's duration +30% seems to work well
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        //stop the tone playing
        noTone(8);
      }
    }
  }
}
