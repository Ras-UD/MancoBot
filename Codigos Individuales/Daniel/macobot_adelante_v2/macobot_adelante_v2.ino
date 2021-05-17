#include<Servo.h>
// Parte: cadera(h) o rodilla(r)
// Lado: izquierda(i) or derech(d)
// Posición: frontal(f) or trasera(t)
// Fomula par nombre de servos: Parte_Lado_Posición
Servo c_d_f;
Servo r_d_f;
Servo c_i_f;
Servo r_i_f;
Servo c_d_t;
Servo r_d_t;
Servo c_i_t;
Servo r_i_t;

int ang_c_d[] = {135, 120, 105, 90, 75, 60, 45, 60, 75, 90, 105, 120};
int ang_r_d[] = {  0, 15, 30, 45, 60, 75, 90, 75, 60, 45, 30, 15};
int ang_c_i[] = { 45, 60, 75, 90, 105, 120, 135, 120, 105, 90, 75, 60};
int ang_r_i[] = {0, 15, 30, 45, 60, 75, 90, 75, 60, 45, 30, 15};

int paso = 100;

int desf = 6;

int swich = 1 ;

void setup() {
  Serial.begin(9600);
  pinMode(10, INPUT);

  c_d_f.attach(4);
  r_d_f.attach(5);
  c_i_f.attach(3);
  r_i_f.attach(2);
  c_d_t.attach(7);
  r_d_t.attach(11);
  c_i_t.attach(8);
  r_i_t.attach(9);
  // posiciònes iniciales
  c_d_f.write(ang_c_d[0]);
  r_d_f.write(ang_r_d[0]);
  c_i_f.write(ang_c_i[desf]);
  r_i_f.write(ang_r_i[desf]);
  c_d_t.write(ang_c_d[desf]);
  r_d_t.write(ang_r_d[desf]);
  c_i_t.write(ang_c_i[0]);
  r_i_t.write(ang_r_i[0]);
}

void loop() {
  swich = digitalRead(10);
  if (swich == HIGH) {
    // primer movimiento diagonal
    for (byte i = 0; i < 12 ; i = i + 1) {
      c_d_f.write(ang_c_d[i]);  // enviar posición al servo de la cadera derecha
      r_d_f.write(ang_r_d[i]);  // enviar posición al servo de la rodilla derecha
      c_i_t.write(ang_c_i[i]); // enviar posición al servo de la cadera izquierda
      r_i_t.write(ang_r_i[i]); // enviar posición al servo de la rodilla izquierda
      if ((i + desf) < 12) {
        c_i_f.write(ang_c_i[i + desf]); // enviar posición al servo de la cadera izquierda
        r_i_f.write(ang_r_i[i + desf]); // enviar posición al servo de la rodilla izquierda
        c_d_t.write(ang_c_d[i + desf]); // enviar posición al servo de la cadera derecha
        r_d_t.write(ang_r_d[i + desf]); // enviar posición al servo de la rodilla derecha
      } else {
        c_i_f.write(ang_c_i[i - 12 + desf]); // enviar posición al servo de la cadera izquierda
        r_i_f.write(ang_r_i[i - 12 + desf]); // enviar posición al servo de la rodilla izquierda
        c_d_t.write(ang_c_d[i - 12 + desf]); // enviar posición al servo de la cadera derecha
        r_d_t.write(ang_r_d[i - 12 + desf]); // enviar posición al servo de la rodilla derecha
      }
      delay(paso); // Pausa para cada paso
    }
  }
  //  for (byte i = 0; i < 12; i = i + 1) {
  //    c_i_t.write(ang_c_i[i]);  // enviar posición al servo de la cadera izquierda
  //    r_i_t.write(ang_r_i[i]);  // enviar posición al servo de la rodilla izquierda
  //    //delay(1000); // Pausa para cada paso
  //  }
  //  // segundo movimiento diagonal
  //  for (byte i = 0; i < 12; i = i + 1) {
  //    c_i_f.write(ang_c_i[i]);  // enviar posición al servo de la cadera izquierda
  //    r_i_f.write(ang_r_i[i]);  // enviar posición al servo de la rodilla izquierda
  //    //delay(1000); // Pausa para cada paso
  //  }
  //  for (byte i = 0; i < 12; i = i + 1) {
  //    c_d_t.write(ang_c_d[i]);  // enviar posición al servo de la cadera derecha
  //    r_d_t.write(ang_r_d[i]);  // enviar posición al servo de la rodilla derecha
  //    //delay(1000); // Pausa para cada paso
  //  }
}
