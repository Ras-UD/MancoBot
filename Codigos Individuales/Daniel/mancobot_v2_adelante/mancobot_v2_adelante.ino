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

int longitud = 12;

int paso = 500; // Tiempo de espera entre pasos

int desf = 6; // Desfase entre la piernas diagonalmente opuestas 
              // (derecha frontal - izquierda traseara VS izquierda frontal - derecha trasera)

//int def,det,izf,izt = 0; // Variables para ver la señal de salida

int swich = 0;

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
  //swich = HIGH;
  swich = digitalRead(10);
  if (swich == HIGH) {
    // primer movimiento diagonal
    for (byte i = 0; i < 12 ; i = i + 1) {
      c_d_f.write(ang_c_d[i]);  // enviar posición al servo de la cadera derecha
      r_d_f.write(ang_r_d[i]);  // enviar posición al servo de la rodilla derecha
      c_i_t.write(ang_c_i[i]); // enviar posición al servo de la cadera izquierda
      r_i_t.write(ang_r_d[i]); // enviar posición al servo de la rodilla izquierda
//      def = ang_c_d[i];
//      izt = ang_c_i[i];
      
      if ((i + desf) < 12) {
        c_i_f.write(ang_c_i[i + desf]); // enviar posición al servo de la cadera izquierda
        r_i_f.write(ang_r_d[i + desf]); // enviar posición al servo de la rodilla izquierda
        c_d_t.write(ang_c_d[i + desf]); // enviar posición al servo de la cadera derecha
        r_d_t.write(ang_r_d[i + desf]); // enviar posición al servo de la rodilla derecha
//        izf = ang_c_i[i + desf];
//        det = ang_c_d[i + desf];
      } else {
        c_i_f.write(ang_c_i[i - 12 + desf]); // enviar posición al servo de la cadera izquierda
        r_i_f.write(ang_r_d[i - 12 + desf]); // enviar posición al servo de la rodilla izquierda
        c_d_t.write(ang_c_d[i - 12 + desf]); // enviar posición al servo de la cadera derecha
        r_d_t.write(ang_r_d[i - 12 + desf]); // enviar posición al servo de la rodilla derecha
//        izf = ang_c_i[i - 12 + desf];
//        det = ang_c_d[i - 12 + desf];
      }
      Serial.println(sizeof(ang_c_i));
//      Serial.print(def + 200);
//      Serial.print("\t");
//      Serial.print(izf + 200);
//      
//      Serial.print("\t");
//      Serial.print(det);
//      Serial.print("\t");
//      Serial.println(izt);
      delay(paso); // Pausa para cada paso
    }
  }
}
