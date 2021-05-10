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
int i=0;


void setup() {

    Serial.begin(9600);
     pinMode(10, INPUT);


     delaIzqCodo.attach(2);
    delaIzq.attach(3);      //igual 1
    
    
    delaDer.attach(4);
    delaDerCodo.attach(5);
  
    traIzqCodo.attach(6);
    traIzq.attach(7);
    
    traDer.attach(8);
    traDerCodo.attach(9);

    
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
  
swich = digitalRead(10);
  if (swich == HIGH) {
    delaIzqCodo.write(180);
    traDerCodo.write(180);
    delay(100);
    
    for(i=70; i>=20; i-=2)
    {
      delaIzq.write(i);
      traDer.write(i);
  
      delaDer.write(90+i);
      traIzq.write(90+i);
      
      delay(50);
    }
    
    delaIzqCodo.write(120);
    delaDerCodo.write(0);
    traDerCodo.write(120);
    traIzqCodo.write(60);
    
    delay(100);
    
    for(i=70; i>=20; i-=2)
    {
      delaDer.write(180-i);
      traIzq.write(180-i);
  
      delaIzq.write(90-i);
      traDer.write(90-i);
      
      delay(50);
    }
    
    delaDerCodo.write(60);
    traIzqCodo.write(60);

  }
}
