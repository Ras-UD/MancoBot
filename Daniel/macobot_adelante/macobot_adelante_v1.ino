#include<Servo.h>
// Declaración de los servo motores
Servo der_cadera;
Servo der_rodilla;
Servo izq_cadera;
Servo izq_rodilla;
// posiciones de las articulaciones
int ang_d_c[] = {45, 60, 75, 90, 105, 120, 135, 120, 105, 90, 75, 60};
int ang_d_r[] = {180, 180, 180, 180, 180, 180, 90, 90, 90, 90, 90, 90};
int ang_i_c[] = {135, 120, 105, 90, 75, 60, 45, 60, 75, 90, 105, 120};
int ang_i_r[] = {180, 180, 180, 180, 180, 180, 90, 90, 90, 90, 90, 90};

void setup()
{
  Serial.begin(9600);
  der_cadera.attach(4);
  der_rodilla.attach(5);
  izq_cadera.attach(6);
  izq_rodilla.attach(7);
}

void loop()
{
  for (byte i = 0; i < 12; i = i + 1) {
    der_cadera.write(ang_d_c[i]);  // enviar posición al servo de la cadera derecha
    der_rodilla.write(ang_d_r[i]);  // enviar posición al servo de la rodilla derecha
    izq_cadera.write(ang_i_c[i]);  // enviar posición al servo de la cadera izquierda
    izq_rodilla.write(ang_i_r[i]);  // enviar posición al servo de la rodilla izquierda
    delay(1000); // Refrescar posición cada 50 ms
  }
