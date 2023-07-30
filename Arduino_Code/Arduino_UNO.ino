// Code by SUHANA ARSH, SADIQ ALI, VEERABHADRAYYA C ROOGI.
void setup() {
pinMode(7, OUTPUT); // Configure pin 7 as an Output
pinMode(8, OUTPUT); // Configure pin 8 as an Output

digitalWrite(7, HIGH); // Initialize pin 7 as Low
digitalWrite(8, HIGH); // Initialize pin 7 as Low

}

void loop() {
  // Extend Linear Actuator
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);

  delay(2000); // 2 seconds
  
  // Stops Actuator
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);

  delay(2000); // 2 seconds
  
  // Retracts Linear Actuator
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

  delay(2000); // 2 seconds

  // Stop Actuator
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);

  delay(2000); // 2 seconds
}
