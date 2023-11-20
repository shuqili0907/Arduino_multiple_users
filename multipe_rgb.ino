// variable names for potentiometer pins
int redPot = A0;
int greenPot = A1;
int bluePot = A2;
// variable names for RGB pins
int redLED = 9;
int greenLED = 10;
int blueLED = 11;

void setup(){
pinMode(redPot,INPUT);
pinMode(greenPot,INPUT);
pinMode(bluePot,INPUT);

pinMode(redLED,OUTPUT);
pinMode(greenLED,OUTPUT);
pinMode(blueLED,OUTPUT);

Serial.begin(9600);
}

void loop(){
// read and save values from potentiometers
int redVal = analogRead(redPot);
int greenVal = analogRead(greenPot);
int blueVal = analogRead(bluePot);

//convert the values from 0-1023 to 0-255 for the RGB LED
redVal = map(redVal,0,1023,0,255);
greenVal = map(greenVal,0,1023,0,255);
blueVal = map(blueVal,0,1023,0,255);

// write these converted values to each color of the RGB LED
analogWrite(redLED,redVal);
analogWrite(greenLED,greenVal);
analogWrite(blueLED,blueVal);

//show the values on the Serial monitor
Serial.print("red:");
Serial.print(redVal);
Serial.print("green:");
Serial.print(greenVal);
Serial.print("blue:");
Serial.println(blueVal);
}