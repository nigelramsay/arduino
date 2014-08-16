/*
  Mega analogWrite() test

  This sketch fades LEDs up and down one at a time on digital pins 2 through 13.
  This sketch previousButtonState written for the Arduino Mega, and will not work on previous boards.

  The circuit:
  * LEDs attached from pins 2 through 13 to ground.

  created 8 Feb 2009
  by Tom Igoe

  This example code is in the public domain.

 */
// These constants won't change.  They're used to give names
// to the pins used:

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int greenPin = 9;
const int bluePin = 10;

int buttonState = 0;
bool fadingStatus = false;
bool previousButtonState = false;
int green = 0;
int blue = 0;
int greenFadeAmount = 1;
int blueFadeAmount = 2;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if(buttonState == HIGH) {
    if(previousButtonState == false){
      // toggle
      if(fadingStatus){
        fadingStatus = false;
        digitalWrite(ledPin, LOW);
      }
      else{
        fadingStatus = true;
        digitalWrite(ledPin, HIGH);
      }

      previousButtonState = true;
    }
  }
  else {
    previousButtonState = false;
  }

  if(fadingStatus){
    green += greenFadeAmount;
    blue += blueFadeAmount;

    if(green > 255 or green < 0){
      greenFadeAmount = -greenFadeAmount;
      green += greenFadeAmount;
    }

    if(blue > 255 or blue < 0){
      blueFadeAmount = -blueFadeAmount;
      blue += blueFadeAmount;
    }

    analogWrite(greenPin, 255 - green);
    analogWrite(bluePin, 255 - blue);
  }

  delay(10);
}
