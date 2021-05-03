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

int i=0;


void setup() {
    Serial.begin(9600);
    
    delaIzq.attach(1);
    delaIzqCodo.attach(2);     //igual 1

    delaDer.attach(3);
    delaDerCodo.attach(4);

    traDer.attach(5);
    traDerCodo.attach(6);     //igual 1

    traIzq.attach(7);
    traIzqCodo.attach(8);

//inicializacion              
    delaIzq.write(70);             // 0 delante
    delaIzqCodo.write(180);        //180 abajo

    delaDer.write(160);           //180 delante     //20
    delaDerCodo.write(20);        //0 abajo

    traDer.write(70);             //180 delante      //110
    traDerCodo.write(0);          //180 abajo

    traIzq.write(160);            //0 delante
    traIzqCodo.write(20);         //0 abajo
}

void loop() {

  delaIzqCodo.write(180);
  traDerCodo.write(180);
  delay(250);
  
  for(i=70; i>=20; i-=2)
  {
    delaIzq.write(i);
    traDer.write(i);

    delaDer.write(90+i);
    traIzq.write(90+i);
    
    delay(250);
  }
  
  delaIzqCodo.write(160);
  delaDerCodo.write(0);
  traDerCodo.write(160);
  traIzqCodo.write(0);
  
  delay(500);
  
  for(i=70; i>=20; i-=2)
  {
    delaDer.write(180-i);
    traIzq.write(180-i);

    delaIzq.write(90-i);
    traDer.write(90-i);
    
    delay(250);
  }
  
  delaDerCodo.write(20);
  traIzqCodo.write(20);

}
