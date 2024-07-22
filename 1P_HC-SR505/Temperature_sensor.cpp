// Define the pins
#define TEMP_SENSOR_PIN A0 // Assuming we're using analog pin A0 for the TMP36 sensor
#define LED_PIN 13

void setup() {
  // Initialize
  pinMode(LED_PIN, OUTPUT);

  pinMode(TEMP_SENSOR_PIN, INPUT);
  // Begin the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the value from temperature sensor
  int sensorValue = analogRead(TEMP_SENSOR_PIN);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature in Celsius
  float temperatureC = (voltage - .5) *100;

  // Check the temperature
  if (temperatureC > 30.0) { 
    // Turn the LED on
    digitalWrite(LED_PIN, HIGH);
    // Print the temperature
    Serial.print("High temperature detected: ");
    Serial.print(temperatureC);
    Serial.println(" C");
  } else {
    // Turn the LED off
    digitalWrite(LED_PIN, LOW);
    // Print the temperature
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" C");
  }
  // Wait for a second
  delay(1000);
}
