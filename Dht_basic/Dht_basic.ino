#include <DHT.h>

// Define DHT sensor type and pin
#define DHTPIN 2       // Pin connected to the data pin of DHT sensor
#define DHTTYPE DHT11  // Change to DHT22 if using DHT22 sensor

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start serial communication
  Serial.begin(9600);
  Serial.println("DHT Sensor Reading - Temperature and Humidity");

  // Start DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Reading temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Default: Celsius
  // float temperatureF = dht.readTemperature(true); // Uncomment for Fahrenheit

  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}
