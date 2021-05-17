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

int paso = 50;

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

void rotIzq() {
  //levanta las patas 1 y 8
  pataPos(0, 45, 1, paso);
  pataPos(0, 45, 8, paso);
  delay(150);
  
  //movimiento hacia izquierda de hombros 3 y 6
  pataNeg(135, 45, 4, paso);
  pataNeg(135, 45, 5, paso);
  delay(3500);

  //retorno de los hombros 2 y 7
  pataPos(45, 135, 2, paso);
  pataPos(45, 135, 7, paso);
  delay(3500);
  
  //Baja las patas 1 y 8
  pataNeg(45, 0, 1, paso);
  pataNeg(45, 0, 8, paso);
  delay(150);

  //levanta las patas 4 y 5
  pataPos(0, 45, 4, paso);
  pataPos(0, 45, 5, paso);
  delay(150);

  //movimiento hacia izquerda de hombros 2 y 7
  pataNeg(135, 45, 2, paso);
  pataNeg(135, 45, 7, paso);
  delay(3500);

  //retorno de los hombros 3 y 6
  pataPos(45, 135, 3, paso);
  pataPos(45, 135, 6, paso);
  delay(3500);
  
  //baja las patas 4 y 5
  pataNeg(45, 0, 4, paso);
  pataNeg(45, 0, 5, paso);
  delay(150);  
}


void loop() {
  swich = digitalRead(10);
  if (swich == HIGH) {

    rotIzq();

  }
}
