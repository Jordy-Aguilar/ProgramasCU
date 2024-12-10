#include "DHT.h"

// Definiciones para el sensor DHT
#define DHTPIN 15     // Pin digital conectado al sensor DHT
#define DHTTYPE DHT22 // Tipo de sensor DHT

// Pines de los LEDs
#define GREEN_LED 10
#define YELLOW_LED 9
#define RED_LED 6

// Pines de los botones
#define TEMP_BUTTON 8
#define HUMID_BUTTON 20

// Inicializa el sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando el sensor DHT...");

  // Configuración de los pines
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(TEMP_BUTTON, INPUT);
  pinMode(HUMID_BUTTON, INPUT);

  // Inicializa el sensor DHT
  dht.begin();
}

void loop() {
  // Verifica si se presiona el botón para la temperatura
  if (digitalRead(TEMP_BUTTON) == LOW) {
    // Lee la temperatura
    float t = dht.readTemperature();

    // Verifica errores en la lectura
    if (isnan(t)) {
      Serial.println("Error al leer la temperatura!");
      return;
    }

    // Lee la humedad también para enviarla junto con la temperatura
    float h = dht.readHumidity();

    if (isnan(h)) {
      Serial.println("Error al leer la humedad!");
      return;
    }

    // Enviar la temperatura y humedad por Serial en formato "humedad,temperatura"
    Serial.print(h);
    Serial.print(",");
    Serial.println(t);

    // Control de LEDs según la temperatura
    if (t >= 10 && t <= 24) {
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(RED_LED, LOW);
    } else if (t >= 25 && t <= 28) {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(RED_LED, LOW);
    } else if (t > 28) {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(RED_LED, HIGH);
    }

    // Pausa para evitar múltiples lecturas al presionar el botón
    delay(1000);
  }

  // Verifica si se presiona el botón para la humedad
  if (digitalRead(HUMID_BUTTON) == LOW) {
    // Lee la humedad
    float h = dht.readHumidity();

    // Verifica errores en la lectura
    if (isnan(h)) {
      Serial.println("Error al leer la humedad!");
      return;
    }

    // Lee la temperatura también para enviarla junto con la humedad
    float t = dht.readTemperature();

    if (isnan(t)) {
      Serial.println("Error al leer la temperatura!");
      return;
    }

    // Enviar la temperatura y humedad por Serial en formato "humedad,temperatura"
    Serial.print(h);
    Serial.print(",");
    Serial.println(t);

    // Control de LEDs según la humedad
    if (h >= 10 && h <= 59) {
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(RED_LED, LOW);
    } else if (h >= 60 && h <= 90) {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(RED_LED, LOW);
    } else if (h > 91) {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(RED_LED, HIGH);
    }

    // Pausa para evitar múltiples lecturas al presionar el botón
    delay(1000);
  }

  // Apagar los LEDs cuando no se presiona ningún botón
  if (digitalRead(TEMP_BUTTON) == HIGH && digitalRead(HUMID_BUTTON) == HIGH) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }

  delay(100); // Pequeña pausa para estabilidad
}

