#define MQ3_PIN A0  // Analog pin connected to MQ3 sensor
#define LED_PIN 7   // Digital pin connected to LED
#define BUZZER_PIN 8 // Digital pin connected to Buzzer

int threshold = 400; // Set a threshold value for alcohol detection (adjust as needed)

void setup() {
  pinMode(LED_PIN, OUTPUT);     // Set LED pin as output
  pinMode(BUZZER_PIN, OUTPUT);  // Set Buzzer pin as output
  Serial.begin(9600);           // Initialize serial communication for debugging
}

void loop() {
  int sensorValue = analogRead(MQ3_PIN);  // Read alcohol concentration from MQ3 sensor
  Serial.println(sensorValue);           // Print sensor value to Serial Monitor

  if (sensorValue > threshold) {
    digitalWrite(LED_PIN, HIGH);         // Turn ON LED
    digitalWrite(BUZZER_PIN, HIGH);      // Turn ON Buzzer
  } else {
    digitalWrite(LED_PIN, LOW);          // Turn OFF LED
    digitalWrite(BUZZER_PIN, LOW);       // Turn OFF Buzzer
  }

  delay(500); // Wait for 500ms before next reading
}
