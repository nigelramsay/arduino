/*
  Mega analogWrite() test
 	
  This sketch fades LEDs up and down one at a time on digital pins 2 through 13.  
  This sketch was written for the Arduino Mega, and will not work on previous boards.
 	
  The circuit:
  * LEDs attached from pins 2 through 13 to ground.

  created 8 Feb 2009
  by Tom Igoe
  
  This example code is in the public domain.
  
 */
// These constants won't change.  They're used to give names
// to the pins used:

const int greenPin = 9;
const int bluePin = 10;
const int redPin = 11;


void setup() {
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
  pinMode(redPin, OUTPUT); 

  Serial.begin(9600); 
}

void loop() {
  for(int i=0; i=i+1; i< 16777216){
    int red = i / 65535;
    int green = i % 65535 / 255;
    int blue = i % 655535 % 255; 

    Serial.print("R");                       
    Serial.print(red);      
    Serial.print(" G");                       
    Serial.print(green);      
    Serial.print(" B");                       
    Serial.print(blue);      
    Serial.print("\n");                       

    analogWrite(redPin, 255 - red);
    analogWrite(greenPin, 255 - green);
    analogWrite(bluePin, 255 - blue);

    delay(10);
  }
}
