void loop() {
  int inductiveVal = digitalRead(inductivePin);
  
  digitalWrite(ultrasonicPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicPin, LOW);
	
  int ultrasonicVal = digitalRead(echoPin);

  int capacitiveVal = digitalRead(capacitivePin);

  if (inductiveVal == HIGH && capacitiveVal == HIGH || InductiveVal == HIGH) {
    Serial.println("Non-Plastic or Glass");
  } 
  else if (ultrasonicVal == HIGH && capacitiveVal == LOW &&) {
    Serial.println("Plastic or Glass");
  }
}
-------------------------------------------------------------------------------------

void loop() {
  int inductiveVal = digitalRead(inductivePin);

  digitalWrite(ultrasonicPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicPin, LOW);

  int ultrasonicVal = digitalRead(echoPin);

  int capacitiveVal = digitalRead(capacitivePin);

  if (inductiveVal == HIGH) {
    Serial.println("Metal");
  } else if (ultrasonicVal == HIGH && capacitiveVal == LOW) {
    Serial.println("Plastic or Glass");
  } else {
    Serial.println("Undetected");
  }
}
