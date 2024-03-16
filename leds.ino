const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
bool secuencia_activa = true;

// Variables para mantener el estado de cada LED
bool ledEstado1 = false;
bool ledEstado2 = false;
bool ledEstado3 = false;
bool ledEstado4 = false;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (secuencia_activa && Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      ledEstado1 = !ledEstado1; // Cambia el estado del LED 1
      digitalWrite(ledPin1, ledEstado1 ? HIGH : LOW); // Enciende o apaga el LED 1 según su estado
    } else if (command == '2') {
      ledEstado2 = !ledEstado2; // Cambia el estado del LED 2
      digitalWrite(ledPin2, ledEstado2 ? HIGH : LOW); // Enciende o apaga el LED 2 según su estado
    } else if (command == '3') {
      ledEstado3 = !ledEstado3; // Cambia el estado del LED 3
      digitalWrite(ledPin3, ledEstado3 ? HIGH : LOW); // Enciende o apaga el LED 3 según su estado
    } else if (command == '4') {
      ledEstado4 = !ledEstado4; // Cambia el estado del LED 4
      digitalWrite(ledPin4, ledEstado4 ? HIGH : LOW); // Enciende o apaga el LED 4 según su estado
    } else if (command == '0') {
      // Apaga todos los LEDs y reinicia los estados
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      ledEstado1 = false;
      ledEstado2 = false;
      ledEstado3 = false;
      ledEstado4 = false;
    }
  }
}




