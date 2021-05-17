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
  traIzqCodo.attach(11);
  traIzq.attach(7);
  traDer.attach(8);
  traDerCodo.attach(9);
  //inicializacion
  delaIzqCodo.write(0);   // 0 abajo
  delaIzq.write(90);        //90 AL MEDIO
  delaDer.write(90);        //90 AL MEDIO
  delaDerCodo.write(0);     //0 abajo
  traIzqCodo.write(0);      //0 abajo
  traIzq.write(90);         //0 AL MEDIO
  traDer.write(90);         //180 AL MEDIO
  traDerCodo.write(0);    //180 abajo

}

//x=angulo inicial y= angulo final z=numero de la pata
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
void irAtras() {
   //levanta las patas 1 y 8
  pataPos(0, 30, 1, 20);
  pataPos(0, 30, 8, 20);
  delay(150);
  
  //adelanta los hombros 2 y 7
  pataPos(90, 150, 2, 20);
  pataNeg(90, 150, 7, 20);
  delay(3000);
  
  //Baja las patas 1 y 8
  pataNeg(30, 0, 1, 20);
  pataNeg(30, 0, 8, 20);
  delay(150);

  //levanta las patas 4 y 5
  pataPos(0, 30, 4, 20);
  pataPos(0, 30, 5, 20);
  delay(150);

  //atrasa los hombros 2 y 7
  pataPos(150, 90, 2, 20);
  pataPos(150, 90, 7, 20);
  delay(3000);

  //adelanta los hombros 3 y 6
  pataPos(90, 20, 3, 20);
  pataPos(90, 20, 6, 20);
  delay(3000);
  
  //baja las patas 4 y 5
  pataNeg(30, 0, 4, 20);
  pataNeg(30, 0, 5, 20);
  delay(150);
  
  //atrasa los hombros 3 y 6
  pataNeg(20, 90, 3, 20);
  pataNeg(20, 90, 6, 20);
  delay(3000);
  
  
  
  
  }

void rotDer() {
  //levanta las patas 1 y 8
  pataPos(0, 30, 1, 0);
  pataPos(0, 30, 8, 0);
  delay(150);
  
  //adelanta los hombros 2 y 7
  pataNeg(90, 20, 2, 0);
  pataNeg(90, 20, 7, 0);
  delay(100);
  
  //Baja las patas 1 y 8
  pataNeg(30, 0, 1, 0);
  pataNeg(30, 0, 8, 0);
  delay(150);

  //levanta las patas 4 y 5
  pataPos(0, 30, 4, 0);
  pataPos(0, 30, 5, 0);
  delay(150);

  //atrasa los hombros 2 y 7
  pataPos(20, 90, 2, 0);
  pataPos(20, 90, 7, 0);
  delay(100);

  //adelanta los hombros 3 y 6
  pataPos(90, 150, 3, 0);
  pataPos(90, 150, 6, 0);
  delay(100);
  
  //baja las patas 4 y 5
  pataNeg(30, 0, 4, 00);
  pataNeg(30, 0, 5, 00);
  delay(150);
  
  //atrasa los hombros 3 y 6
  pataNeg(150, 90, 3, 00);
  pataNeg(150, 90, 6, 00);
  delay(100);
}


void loop() {
  swich = digitalRead(10);
  if (swich == HIGH) {
    rotDer();
  }
}
