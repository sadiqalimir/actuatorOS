// Code by SUHANA ARSH, SADIQ ALI< VEERABHADRAYYA C ROOGI. 
//THIS IS GENERAL CODE, YOU CAN MODIFY IT ACCORDING TO YOUR ACTUATOR SPECIFICATIONS.
// Pin definitions for the LN298 module
const int enA = 9;  // Enable pin for actuator A
const int in1 = 8;  // Input 1 for actuator A
const int in2 = 7;  // Input 2 for actuator A
const int enB = 10; // Enable pin for actuator B
const int in3 = 6;  // Input 1 for actuator B
const int in4 = 5;  // Input 2 for actuator B

// Variables to store the actuator positions
const int totalExtension = 15;  // Total extension of the actuators (15 cm)
const int retraction = 10;     // Retraction distance (10 cm)

int currentPositionA = 0;  // Current position of actuator A (in cm)
int currentPositionB = 0;  // Current position of actuator B (in cm)

// Function to extend Actuator A by the specified distance
void extendActuatorA(int distance) {
  // Calculate the new position after extension
  int newPositionA = currentPositionA + distance;

  // Limit the extension within the total available range
  newPositionA = constrain(newPositionA, 0, totalExtension);

  // Move the actuator to the new position
  if (newPositionA > currentPositionA) {
    analogWrite(enA, 255);  // Enable the actuator
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(500);  // Adjust the delay as needed for smooth operation
    analogWrite(enA, 0);  // Disable the actuator
    currentPositionA = newPositionA;
  }
}

// Function to retract Actuator A by the specified distance
void retractActuatorA(int distance) {
  // Calculate the new position after retraction
  int newPositionA = currentPositionA - distance;

  // Limit the retraction within the available range
  newPositionA = constrain(newPositionA, 0, totalExtension - retraction);

  // Move the actuator to the new position
  if (newPositionA < currentPositionA) {
    analogWrite(enA, 255);  // Enable the actuator
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(500);  // Adjust the delay as needed for smooth operation
    analogWrite(enA, 0);  // Disable the actuator
    currentPositionA = newPositionA;
  }
}

// Function to extend Actuator B by the specified distance
void extendActuatorB(int distance) {
  // Calculate the new position after extension
  int newPositionB = currentPositionB + distance;

  // Limit the extension within the total available range
  newPositionB = constrain(newPositionB, 0, totalExtension);

  // Move the actuator to the new position
  if (newPositionB > currentPositionB) {
    analogWrite(enB, 255);  // Enable the actuator
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(500);  // Adjust the delay as needed for smooth operation
    analogWrite(enB, 0);  // Disable the actuator
    currentPositionB = newPositionB;
  }
}

// Function to retract Actuator B by the specified distance
void retractActuatorB(int distance) {
  // Calculate the new position after retraction
  int newPositionB = currentPositionB - distance;

  // Limit the retraction within the available range
  newPositionB = constrain(newPositionB, 0, totalExtension - retraction);

  // Move the actuator to the new position
  if (newPositionB < currentPositionB) {
    analogWrite(enB, 255);  // Enable the actuator
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(500);  // Adjust the delay as needed for smooth operation
    analogWrite(enB, 0);  // Disable the actuator
    currentPositionB = newPositionB;
  }
}

void setup() {
  // Set the pin modes
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initially disable both actuators
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void loop() {
  // Test the actuator extension and retraction
  extendActuatorA(5);    // Extend Actuator A by 5 cm
  delay(1000);           // Delay to observe the extension
  retractActuatorA(5);   // Retract Actuator A by 5 cm
  delay(1000);           // Delay to observe the retraction
  extendActuatorB(10);   // Extend Actuator B by 10 cm
  delay(1000);           // Delay to observe the extension
  retractActuatorB(10);  // Retract Actuator B by 10 cm
  delay(1000);           // Delay to observe the retraction
}
