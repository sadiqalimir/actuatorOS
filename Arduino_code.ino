// Code by SUHANA ARSH, SADIQ ALI< VEERABHADRAYYA C ROOGI
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Pin assignments for relay control
int relay_1 = 22; // Relay 1 pin to activate extension
int relay_2 = 24; // Relay 2 pin to activate retraction

// LCD button press readings on Pin A0
const int btnup = 100; // Value of sensor when the UP button is pressed
const int btndown = 255; // Value of sensor when the DOWN button is pressed
const int threshold = 5;

// Electrical actuator specifications
const float extension_distance_cm = 15.0; // Linear extension distance in cm
const float retraction_distance_cm = 10.0; // Linear retraction distance in cm

// Power supply (battery) specifications
const float battery_voltage = 12.0; // Battery voltage in volts (adjust based on your battery)

void setup() {
  Serial.begin(9600);

  // Set relay pins as outputs
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);

  // Initialize relays in LOW state (deactivated)
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Press UP to ext");
  lcd.setCursor(0, 1);
  lcd.print("Press DN to ret");
}

void loop() {
  // Read if there is any input from button presses
  int lcd_key = analogRead(A0);

  if (lcd_key > btnup - threshold && lcd_key < btnup + threshold) {
    // Perform extension
    digitalWrite(relay_1, HIGH);
    digitalWrite(relay_2, LOW);

    // Calculate and display the maximum power consumption during extension
    float extension_power = calculatePowerConsumption(true);
    lcd.clear();
    lcd.print("Extension Power:");
    lcd.setCursor(0, 1);
    lcd.print(extension_power, 2); // Display power with 2 decimal places (assuming units are correct)
  } else if (lcd_key > btndown - threshold && lcd_key < btndown + threshold) {

    digitalWrite(relay_1, LOW);
    digitalWrite(relay_2, HIGH);


    float retraction_power = calculatePowerConsumption(false);
    lcd.clear();
    lcd.print("Retraction Power:");
    lcd.setCursor(0, 1);
    lcd.print(retraction_power, 2); // Display power with 2 decimal places (assuming units are correct)
  } else {

    digitalWrite(relay_1, LOW);
    digitalWrite(relay_2, LOW);
  }
}

float calculatePowerConsumption(bool isExtension) {
  float actuator_power = 10.0; // Power rating of the actuator in watts
  float actuation_time = 5.0; // Time taken for full extension/retraction in seconds


  float energy_consumption = actuator_power * actuation_time;


  float power_consumption = energy_consumption / actuation_time;

  return power_consumption;
}
