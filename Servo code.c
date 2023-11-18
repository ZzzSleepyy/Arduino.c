#include <Servo.h>
const int SWITCHPIN = 3;
const int trigger = 5;
const int echo = 2;

Servo theservo;

float distance;
float dist_inches;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SWITCHPIN, INPUT);
  theservo.attach(11);
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  int pos = 0;
  int ValSwitch;
  ValSwitch = digitalRead(SWITCHPIN);
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);
    
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  int distance=pulseIn(echo, HIGH);
  distance=distance * 0.035 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (ValSwitch == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(50);  
    if(distance < 60) {
      theservo.write(180);   
      delay(5);
      Serial.println("Object Observed");
    }           
    else{
      theservo.write(90);       
      delay(5);  
      Serial.println("No Object Observed");
    }                  
  if (ValSwitch == LOW) {
    digitalWrite(LED_BUILTIN, LOW); 
    delay(50);
    }
  }
}
