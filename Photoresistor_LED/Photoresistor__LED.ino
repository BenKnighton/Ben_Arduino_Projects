int yellowlight = 3;

int redlight = 4;

int greenlight = 2;

int lightsensorpin = A0;

int analogValue = 0;

void setup() {
  pinMode(greenlight, OUTPUT);
  pinMode(yellowlight,OUTPUT);
  pinMode(redlight,OUTPUT);
}

void loop(){
  analogValue = analogRead(lightsensorpin);
  if(analogValue < 50){            
    digitalWrite(redlight, HIGH);
  }
  else if(analogValue >= 50 && analogValue <= 100){
    digitalWrite(yellowlight, HIGH);
  }
  else{
    digitalWrite(greenlight, HIGH);
  }
  delay(200);
  digitalWrite(greenlight, LOW);
  digitalWrite(yellowlight, LOW);
  digitalWrite(redlight, LOW);
}
