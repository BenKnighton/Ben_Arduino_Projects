#include "pitches.h"

const int button = 2;
int var_store = 0;
boolean set = true;

int note_pin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(note_pin, OUTPUT);
}


int closing()
{
  int melody[] = {NOTE_AS7, NOTE_G7};  //NOTE_AS7, NOTE_G7
  int noteDurations[] = {4, 5};
  for (int thisNote = 0; thisNote < 2; thisNote++)
  {
    //to calculate the note duration, take one second. Divided by the note type
    int noteDuration = 700 / noteDurations [thisNote];
    tone(note_pin, melody [thisNote], noteDuration);
    
    //to distinguish the notes, set a minimum time between them
    //the note's duration +30% seems to work well
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing
    noTone(note_pin);
  }
  return 0;
}

/*
to get better at programming, 
make this function be able to 
take inputs instead of having 
2 seperate functions
 */


int opening()
{
  int melody[] = {NOTE_G7, NOTE_AS7};  //NOTE_AS7, NOTE_G7
  int noteDurations[] = {4, 5};
  for (int thisNote = 0; thisNote < 2; thisNote++)
  {
    int noteDuration = 700 / noteDurations [thisNote];
    tone(note_pin, melody [thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(note_pin);
  }
  return 0;
}



void loop() {
  int x = digitalRead(button);
  if( x == var_store && set == true )
  {
    delay(5); //this is for button debouncing
    if(var_store == 1)
    {
      var_store = 0;
    }
    else
    {
      var_store = 1;
    }
    set = false;

    Serial.println("hello");
    Serial.println(var_store);
    if( var_store == 1 )
    {
      opening();
    }
    else
    {
      closing();
    }

 
  }
  else
  {
    set = true;
  }
}
