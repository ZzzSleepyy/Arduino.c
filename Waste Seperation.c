void loop() {
  int inductiveVal = digitalRead(inductivePin);
  
  int ultrasonicVal = digitalRead(echoPin);

  int capacitiveVal = digitalRead(capacitivePin);

  if (inductiveVal == HIGH && capacitiveVal == HIGH || InductiveVal == HIGH) {
    Serial.println("Non-Plastic or Glass");
  } 
  else if (ultrasonicVal == HIGH && capacitiveVal == LOW &&) {
    Serial.println("Plastic or Glass");
  }
}
