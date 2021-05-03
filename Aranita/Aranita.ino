#include<Servo.h>

// Declaración de los servo motores
Servo izq_pata1;
Servo izq_hombro1;
Servo der_pata1;
Servo der_hombro1;

Servo izq_pata2;
Servo izq_hombro2;
Servo der_pata2;
Servo der_hombro2;
int swich = 1 ;


// posiciones de las articulaciones
int ang_i_p1[] = {150, 150, 150, 150, 150, 150, 180, 180, 180, 180, 180, 180};
int ang_i_h1[] = {135, 120, 105, 90, 75, 60, 45, 60, 75, 90, 105, 120};
int ang_d_p1[] = { 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0};
int ang_d_h1[] = {45, 60, 75, 90, 105, 120, 135, 120, 105, 90, 75, 60};

int ang_i_p2[] = {30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0};
int ang_i_h2[] = {90, 83, 76, 62, 55, 48, 41, 48, 55, 62, 76, 83};
int ang_d_p2[] = {150, 150, 150, 150, 150, 150, 180, 180, 180, 180, 180, 180 };
int ang_d_h2[] = {60, 75, 90, 105, 120, 135, 120, 105, 90, 75, 60, 45};

int x = 1 ;
int y = 1 ;
void setup()
{
  Serial.begin(9600);
  pinMode(10, INPUT);

  izq_pata1.attach(2);
  izq_hombro1.attach(3);
  der_hombro1.attach(4);
  der_pata1.attach(5);

  izq_pata2.attach(6);
  izq_hombro2.attach(7);
  der_hombro2.attach(8);
  der_pata2.attach(9);

  izq_pata1.write(180);
  izq_hombro1.write(90);
  der_hombro1.write(90);
  der_pata1.write(0);

  izq_pata2.write(0);
  izq_hombro2.write(90);
  der_hombro2.write(90);
  der_pata2.write(180);

  izq_pata2.write(0);
  izq_hombro2.write(90);
  der_hombro2.write(90);
  der_pata2.write(180);

}

void loop() {
  swich = digitalRead(10);
  if (swich == HIGH) {
    if (x == 1) {
      for (byte i = 0; i < 12; i = i + 1) {
        izq_pata1.write(ang_i_p1[i]);  // enviar posición al servo de la rodilla izquierda
        izq_hombro1.write(ang_i_h1[i]);  // enviar posición al servo de la cadera izquierda
        der_pata2.write(ang_d_p2[i]);  // enviar posición al servo de la rodilla derecha
        der_hombro2.write(ang_d_h2[i]);  // enviar posición al servo de la cadera derecha

        delay(200); // Refrescar posición cada 50 ms
      }
      x = 0;
      y = 1;
    }

    if (y == 1) {
      for (byte i = 0; i < 12; i = i + 1) {
        der_pata1.write(ang_d_p1[i]);  // enviar posición al servo de la rodilla derecha
        der_hombro1.write(ang_d_h1[i]);  // enviar posición al servo de la cadera derecha
        izq_pata2.write(ang_i_p2[i]);  // enviar posición al servo de la rodilla izquierda
        izq_hombro2.write(ang_i_h2[i]);  // enviar posición al servo de la cadera izquierda
        delay(200); // Refrescar posición cada 50 ms
      }
      y = 0;
      x = 1;
    }
  }
}
