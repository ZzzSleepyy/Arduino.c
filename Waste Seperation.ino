#include <Servo.h>

#define GREEN_LED 13
#define RED_LED 12

#define S0 3
#define S1 4
#define S2 6
#define S3 7
#define SOUT 8

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

const int trigger = 5;
const int echo = 2;

Servo theservo;

float distance;
float dist_inches;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(SOUT, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);


  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
  pinMode(echo, INPUT);


  theservo.attach(11);
}

void loop() {
  digitalWrite(trigger,LOW);
  delay(500);
  digitalWrite(trigger, LOW);
  delay(500);
  digitalWrite(trigger, HIGH);
  delay(500);
  digitalWrite(trigger, LOW);
  int distance=pulseIn(echo, HIGH);
  distance=distance * 0.035 / 2;
  //RED SETTINGS
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  //RED OUTPUT
  redFrequency = pulseIn(SOUT, LOW);
  Serial.print("red = ");
  Serial.println(redFrequency);
  delay(150);
  //GREEN SETTINGS
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  //GREEN OUTPUT
  greenFrequency = pulseIn(SOUT, LOW);
  Serial.print("green = ");
  Serial.println(greenFrequency);
  delay(150);
  //BLUE SETTINGS
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  //BLUE OUTPUT
  blueFrequency = pulseIn(SOUT, LOW);
  Serial.print("blue = ");
  Serial.println(blueFrequency);
  delay(150);
  if (distance < 20) {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
      // OBJeCT DEtECTED
      delay(500);
      if (redFrequency > 30 && redFrequency < 80 && greenFrequency > 30 && greenFrequency < 80) {
          Serial.println("====Plastic====");
          theservo.write(180);  
      } else {
          Serial.println("=====Non Plastic====");
          theservo.write(1); 
      } 
  } else {
      // OBJECT NOT DeTEcTED
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      theservo.write(90); 
  }
}
