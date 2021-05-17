#include<Servo.h>

Servo c_d_f;
Servo r_d_f;
Servo c_i_f;
Servo r_i_f;
Servo c_d_t;
Servo r_d_t;
Servo c_i_t;
Servo r_i_t;

const float pi = 3.14159;
// tiempo para cambiar 1º de un servo sg90 en ms: floor((0.3 s/ 60º)*1000)
// Es una aproximaxión a un valor bonito :)
// Se puede usar el valor exacto si se usa la librería microseconds
const int esp = 5;
// Resolución maxima para el servo sg90: 1000 / floor((0.3 s/ 60º)*1000)
const int res = 200.0;

float max_c = 135.0;
float min_c = 45.0;
float max_r = 90.0;
float min_r = 0.0;

// Referencia de fase (0º): servo motor cadera izquierda delantera
// Desfase en grados, configuración física del robot
const int desf_i = 0;
const int desf_d = 180;
const int desf_r_i = 270;
const int desf_r_d = 90;

//Desfase en grados para mover al tiempo las piernas diagonalmente puestas
//izquierda frontal - derecha trasera
//derecha frontal - izquierda trasera
int desf_c_i_f = desf_i + 0;
int desf_c_d_f = desf_d + 180;
int desf_c_i_t = desf_i + 180;
int desf_c_d_t = desf_d + 0;

// Desfase para momento de constacto con el suelo, 0: levantado en los extremos
int desf_r_i_f = desf_c_i_f + desf_r_i + 0;
int desf_r_d_f = desf_c_d_f + desf_r_d + 0;
int desf_r_i_t = desf_c_i_t + desf_r_i + 0;
int desf_r_d_t = desf_c_d_t + desf_r_d + 0;


float times = 1; //tiempo en segundos para cambiar del valor maximo al mínimo

//int def,det,izf,izt = 0; // Variables para ver la señal de salida

int swich = 0;

float smoth_servo(bool tipo, float per_2, int desf, int moment) {
  float amp = 0.0;
  float offset = 0.0;
  float val = 0.0;
  float phi = float(desf) * pi / 180;
  if (tipo == 0){
    amp = (max_c - min_c) / 2;
    offset = (max_c + min_c) / 2;
  }else{
    amp = (max_r - min_r) / 2;
    offset = (max_r + min_r) / 2;
  }
  val = amp * sin((2 * pi * float(moment) / (2 * per_2 * float(res))) + phi) + offset;
  
  return val;
}

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
  c_i_f.write(smoth_servo(0, times, desf_c_i_f, 0));
  c_d_f.write(smoth_servo(0, times, desf_c_d_f, 0));
  c_d_t.write(smoth_servo(0, times, desf_c_d_t, 0));
  c_i_t.write(smoth_servo(0, times, desf_c_i_t, 0));
  r_i_f.write(smoth_servo(1, times, desf_r_i_f, 0));
  r_d_f.write(smoth_servo(1, times, desf_r_d_f, 0));
  r_d_t.write(smoth_servo(1, times, desf_r_d_t, 0));
  r_i_t.write(smoth_servo(1, times, desf_r_i_t, 0));
}

void loop() {
  swich = digitalRead(10);
  //swich = HIGH;
  if (swich == HIGH) {
    for (int i = 0; i <= int(float(res)*2*times); i++){
      
      c_i_f.write(smoth_servo(0, times, desf_c_i_f, i));
      c_d_f.write(smoth_servo(0, times, desf_c_d_f, i));
      c_d_t.write(smoth_servo(0, times, desf_c_d_t, i));
      c_i_t.write(smoth_servo(0, times, desf_c_i_t, i));
      
      r_i_f.write(smoth_servo(1, times, desf_r_i_f, i));
      r_d_f.write(smoth_servo(1, times, desf_r_d_f, i));
      r_d_t.write(smoth_servo(1, times, desf_r_d_t, i));
      r_i_t.write(smoth_servo(1, times, desf_r_i_t, i));

//      Serial.print(smoth_servo(0, times, desf_c_d_t, i));
//      Serial.print('\t');
//      Serial.print(smoth_servo(1, times, desf_r_d_t, i)+180);
//      Serial.print('\t');
//      Serial.print(smoth_servo(0, times, desf_c_i_t, i));
//      Serial.print('\t');
//      Serial.println(smoth_servo(1, times, desf_r_i_t, i));
    }
  }
}
