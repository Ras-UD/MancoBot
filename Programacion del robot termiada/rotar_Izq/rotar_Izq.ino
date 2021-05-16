#include <Servo.h>

//# de patas en sentido horario
//1 grado horizontal, 1_2 grado vertical

Servo delaIzq;
Servo delaIzqCodo;
Servo delaDer;
Servo delaDerCodo;

Servo traDer;
Servo traDerCodo;
Servo traIzq;
Servo traIzqCodo;
int swich = 1 ;
int i = 0;

struct servo  {
  int AngIn;
  int AngFin;
  int Velocidad;
  int n_pata;
} servo1, servo2;

void setup() {
  //declaración
  Serial.begin(9600);
  pinMode(10, INPUT);
  delaIzqCodo.attach(2);
  delaIzq.attach(3);
  delaDer.attach(4);
  delaDerCodo.attach(5);
  traIzqCodo.attach(6);
  traIzq.attach(7);
  traDer.attach(8);
  traDerCodo.attach(9);
  //inicializacion
  delaIzqCodo.write(180);   // 0 abajo
  delaIzq.write(90);        //90 AL MEDIO
  delaDer.write(90);        //90 AL MEDIO
  delaDerCodo.write(0);     //0 abajo
  traIzqCodo.write(0);      //0 abajo
  traIzq.write(90);         //0 AL MEDIO
  traDer.write(90);         //180 AL MEDIO
  traDerCodo.write(180);    //180 abajo

}

//x=angulo inicial y= angulo final z=numero de la pata  w=delay
void pataPos(int x, int y, int z, int w) {
  for (i = x; i <= y; i++)  //patas 4 y 5 arriba
  {
    switch (z) {
      case 1 :
        delaIzqCodo.write(i);
        break;
      case 2 :
        delaIzq.write(i);
        break;
      case 3 :
        delaDer.write(i);
        break;
      case 4 :
        delaDerCodo.write(i);
        break;
      case 5 :
        traIzqCodo.write(i);
        break;
      case 6 :
        traIzq.write(i);
        break;
      case 7 :
        traDer.write(i);
        break;
      case 8 :
        traDerCodo.write(i);
        break;
    }
    delay(w);
  }
}
void pataNeg(int x, int y, int z, int w) {

  for (i = x; i >= y; i--)  //patas 4 y 5 arriba
  {
    switch (z) {
      case 1 :
        delaIzqCodo.write(i);
        break;
      case 2 :
        delaIzq.write(i);
        break;
      case 3 :
        delaDer.write(i);
        break;
      case 4 :
        delaDerCodo.write(i);
        break;
      case 5 :
        traIzqCodo.write(i);
        break;
      case 6 :
        traIzq.write(i);
        break;
      case 7 :
        traDer.write(i);
        break;
      case 8 :
        traDerCodo.write(i);
        break;
    }
    delay(w);
  }
}

void rotDer() {
  //levanta las patas 1 y 8
  pataNeg(30, 0, 1, 50);
  pataNeg(30, 0, 8, 50);
  delay(150);
  
  //adelanta los hombros 2 y 7
  pataNeg(90, 20, 2, 50);
  pataNeg(90, 20, 7, 50);
  delay(3500);
  
  //Baja las patas 1 y 8
  pataPos(0, 30, 1, 50);
  pataPos(0, 30, 8, 50);
  delay(150);

  //levanta las patas 4 y 5
  pataNeg(30, 0, 4, 50);
  pataNeg(30, 0, 5, 50);
  delay(150);

  //atrasa los hombros 2 y 7
  pataPos(20, 90, 2, 50);
  pataPos(20, 90, 7, 50);
  delay(3500);

  //adelanta los hombros 3 y 6
  pataNeg(160, 90, 3, 50);
  pataNeg(160, 90, 6, 50);
  delay(3500);
  
  //baja las patas 4 y 5
  pataPos(0, 30, 4, 50);
  pataPos(0, 30, 5, 50);
  delay(150);
  
  //atrasa los hombros 3 y 6
  pataPos(90, 160, 3, 50);
  pataPos(90, 160, 6, 50);
  delay(3500);
}


void loop() {
  swich = digitalRead(10);
  if (swich == HIGH) {

    rotDer();

  }
}
