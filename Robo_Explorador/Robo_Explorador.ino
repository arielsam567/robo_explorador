#include <Servo.h>
#include <SPI.h>
#include "Motor.h"


#define DEFINE_frente "8"
#define DEFINE_tras "2"
#define DEFINE_esquerda "4"
#define DEFINE_direita "6"
#define DEFINE_parado "0"



Motor motor1;
Motor motor2;



void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  motor1.defineRight(8, 5, 7); //9 4 6 //motor 2
  motor1.defineLeft(9, 6, 4); //8 7 5 // motor 1
  motor2.defineRight(47, 48, 50); //9 4 6 //motor 2
  motor2.defineLeft(46, 51, 49); //8 7 5 // motor 1
  //
  delay(5000);
  Serial.println("INIT");

}



void loop() {
  if (Serial1.available()) {

    String dadoB = Serial1.readString();
    Serial.println(dadoB);

    if (dadoB.substring(5, 6) == "0") {
      dadoB = "0:255";
      Serial.println("fuck");
    }

    String comando = dadoB.substring(0, 1);
    //Serial.println(comando);

    String velocidade = dadoB.substring(2, 5);
    //Serial.println(velocidade);
    int v = velocidade.toInt();
    v = 254;




    if (comando == DEFINE_frente) {
      Serial.println(DEFINE_frente);
      frente(v, 1000);
    } else if (comando == DEFINE_tras) {
      Serial.println(DEFINE_tras);
      tras(v, 1000);
    } else if (comando == DEFINE_direita) {
      Serial.println(DEFINE_direita);
      right(v, 1000);
    } else if (comando == DEFINE_esquerda) {
      Serial.println(DEFINE_esquerda);
      left(v, 1000);
    } else if (comando == DEFINE_parado) {
      Serial.println(DEFINE_parado);
      stop(1000);
    }


  }


  //    Serial.println("DEFINE_frente");
  //    frente(254, 1000);
  //    stop(1000);
  //    right(180, 700);
  //    stop(1000);
  //    left(180, 800);
  //    stop(1000);
  //
  //    tras(254, 1000);
  //    stop(800);


}


void frente(int velocidade, int time_run) {
  motor1.back(velocidade);
  motor2.back(velocidade);
  //  delay(time_run);
}

void tras(int velocidade, int time_run) {
  motor1.front(velocidade);
  motor2.front(velocidade);
  // delay(time_run);

}


void right(int velocidade, int time_run) {
  motor1.right(velocidade);
  motor2.right(velocidade);
  // delay(time_run);

}

void left(int velocidade, int time_run) {
  motor1.left(velocidade);
  motor2.left(velocidade);
  //  delay(time_run);

}

void stop( int time_run) {
  motor1.stop();
  motor2.stop();
  //delay(time_run);

}
