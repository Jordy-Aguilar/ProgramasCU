const int ledRojo = 9;  // LED rojo conectado al pin 10
const int ledVerde = 10;  // LED verde conectado al pin 9

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600); // Configuración del puerto serial
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Leer el carácter enviado desde Python

    if (comando == 'R') {
      // Rostro no reconocido
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRojo, HIGH);
      delay(3000);
      digitalWrite(ledRojo, LOW);
      
      Serial.println("Acceso denegado"); // Enviar mensaje al monitor serial
    } else if (comando == 'G') {
      // Rostro reconocido
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledVerde, HIGH);
      delay(3000);
      digitalWrite(ledVerde, LOW);

      Serial.println("Acceso correcto"); // Enviar mensaje al monitor serial
    } else {
      // Apagar ambos LEDs si el comando no es válido
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledVerde, LOW);
    }
  }
}
