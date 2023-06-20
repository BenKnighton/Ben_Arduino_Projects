#include "pitches.h"  //add note library

int melody[] = {NOTE_G7, NOTE_AS6};

int buttonPin = 12;

int noteDurations[] = {6, 6};
int buttonState = digitalRead(buttonPin);
void setup() {

  pinMode(buttonPin, INPUT);

}

void loop() {

  int buttonState = digitalRead(buttonPin);



  if (buttonState == LOW) {

    digitalWrite( 10, HIGH);

    for (int thisNote = 0; thisNote < 2; thisNote++) {

      int noteDuration = 1000 / noteDurations [thisNote];
      tone(8, melody [thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      noTone(8);
    }
    else if (buttonState == LOW) {
      digitalWrite( 10, LOW);
    }
  }




  if (buttonState == HIGH) {

    digitalWrite( 10, HIGH);

    for (int thisNote = 0; thisNote < 2; thisNote++) {

      int noteDuration = 1000 / noteDurations [thisNote];
      tone(8, melody [thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      noTone(8);
    }
    digitalWrite( 10, LOW);
  }
}
