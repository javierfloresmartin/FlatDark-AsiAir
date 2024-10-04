/*
  Control de Servo con Detección de Entrada Digital y Retardo (Debounce)
  
  Este programa utiliza un botón o interruptor conectado a un pin digital del Arduino
  para mover un servo motor de una posición a otra. Implementa una técnica de debounce 
  para evitar lecturas erróneas debido al ruido del interruptor, y mueve el servo lentamente
  a la nueva posición cuando el estado del botón cambia.

  - Librerías: Servo.h para controlar el servo motor.
  - El pin de entrada está configurado para leer el estado de un botón o interruptor.
  - El servo motor se mueve entre dos posiciones (0 y 142 grados) basándose en el estado 
    de la entrada digital.
  
  Autor: Javier Flores Martín
  Fecha: 04/10/2024

  Componentes:
  - Servo motor conectado al pin 9.
  - Botón o interruptor conectado al pin 2.
*/

#include <Servo.h>  // Importamos la librería para controlar servos

Servo miServo;      // Creamos un objeto de la clase Servo para controlar el servo
int servoPin = 9;   // Pin al que está conectado el servo

int entrada = 2;             // Pin donde se lee la entrada del botón/interruptor
int estadoActual = LOW;       // Variable para almacenar el estado actual de la entrada
int estadoAnterior = LOW;     // Variable para almacenar el estado anterior de la entrada
int posicionServo = 142;      // Posición inicial del servo motor. AJUSTAR SEGÚN NECESIDADES

unsigned long tiempoUltimoCambio = 0;   // Tiempo registrado del último cambio de estado
unsigned long debounceDelay = 2000;     // Retardo para evitar rebotes (debounce), en ms

void setup() {
  Serial.begin(9600);          // Inicializamos la comunicación serie a 9600 bps
  pinMode(entrada, INPUT);     // Configuramos el pin de entrada como INPUT
  miServo.attach(servoPin);    // Asociamos el servo al pin designado

  // Mensaje para confirmar que el programa ha iniciado correctamente
  Serial.println("Iniciando programa...");
}

void loop() {
  // Leemos el estado actual del pin de entrada
  int lecturaActual = digitalRead(entrada);

  // Comprobamos si el estado actual del botón ha cambiado comparado con el anterior
  if (lecturaActual != estadoAnterior) {
    // Reiniciamos el temporizador de debounce para contar desde el cambio de estado
    tiempoUltimoCambio = millis();
  }

  // Verificamos si ha pasado suficiente tiempo para evitar el rebote (debounce)
  if ((millis() - tiempoUltimoCambio) > debounceDelay) {
    // Si el estado ha cambiado después del debounce, actualizamos el estado
    if (lecturaActual != estadoActual) {
      estadoActual = lecturaActual;

      // Si el botón/interruptor está en estado HIGH
      if (estadoActual == HIGH) {
        Serial.println("Estado cambiado a HIGH");
        // Movemos el servo lentamente de 142 a 0 grados
        for (posicionServo = 142; posicionServo >= 0; posicionServo--) {
          miServo.write(posicionServo);  // Escribimos la nueva posición al servo
          delay(15);                     // Esperamos 15 ms para un movimiento suave
        }
      } 
      // Si el botón/interruptor está en estado LOW
      else {
        Serial.println("Estado cambiado a LOW");
        // Movemos el servo lentamente de 0 a 142 grados
        for (posicionServo = 0; posicionServo <= 144; posicionServo++) {
          miServo.write(posicionServo);  // Escribimos la nueva posición al servo
          delay(15);                     // Esperamos 15 ms entre cada paso
        }
      }
    }
  }

  // Actualizamos el estado anterior para la próxima iteración del loop
  estadoAnterior = lecturaActual;

  // Retardo para evitar saturar la comunicación serie y dar tiempo al procesamiento
  delay(1000);
}
