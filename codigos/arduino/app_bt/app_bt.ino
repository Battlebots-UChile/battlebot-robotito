//version del codigo para controlar a Robotito mediante la aplicación

//no se está usando, puede llegar a ser útil
enum Estado {
  VEL_FIJA,
  VEL_VAR,
};

int estado_arma = Estado::VEL_FIJA;

int state;

int motorA_vel = 0;
int motorB_vel = 0;

int vel_actual = 0;
int vel_nueva = 0;
int vel_salto = 2;

//nuevos pines RX y TX
#include <SoftwareSerial.h>
SoftwareSerial SerialBT(5, 6);

//bluetooth
#define PIN_BT_TX 5
#define PIN_BT_RX 6

// motor A, izquierdo
#define PIN_MOT_A1 2    //IN1
#define PIN_MOT_A2 4    //IN2
#define PIN_MOT_AEN 3   //ENA

//motor B, derecho
#define PIN_MOT_B1 13    //IN3
#define PIN_MOT_B2 12    //IN4
#define PIN_MOT_BEN 11   //ENB

//motor arma
#define PIN_ARMA_PWMR 10
#define PIN_ARMA_PWML 9
#define PIN_ARMA_ENR 7
#define PIN_ARMA_ENL 8

void setup() {

  configurarBluetooth();
  configurarMotoresMovimiento();
  configurarArma();

  Serial.begin(9600);
  //SerialBT.begin(9600);
}

void loop() {
  
  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, HIGH);
  digitalWrite(PIN_MOT_B1, HIGH);
  digitalWrite(PIN_MOT_B2, LOW);
  motorA_vel = 255;
  motorB_vel = 255;
  analogWrite(PIN_MOT_AEN, motorA_vel);
  analogWrite(PIN_MOT_BEN, motorB_vel);
  delay(1000);
  motorA_vel = 100;
  motorB_vel = 100;
  analogWrite(PIN_MOT_AEN, motorA_vel);
  analogWrite(PIN_MOT_BEN, motorB_vel);
  delay(1000);

  // Chequear Serial
  //leerSerial();

  //Detener todo
  //detenertodo();

  // Mover el robot
  //moverRobot();

  // Mover el arma
  //setVelArma();

}

void setVelArma() {
  if (state == 'G') {
    vel_nueva = 0;
  }
  else if (state == 'H') {
    vel_nueva = 75;
  }
  else if (state == 'J') {
    vel_nueva = 100;
  }
  else if (state == 'K') {
    vel_nueva = 150;
  }
  else if (state == 'L') {
    vel_nueva = 200;
  }
  check_vel();

}

void check_vel() {
  if (vel_actual > vel_nueva) {
    disminuir_vel();
  }
  else if (vel_actual < vel_nueva) {
    aumentar_vel();
  }
}

void disminuir_vel() {
  vel_actual -= vel_salto;
  analogWrite(PIN_ARMA_PWML, vel_actual);
  delay(25);
}

void aumentar_vel() {
  vel_actual += vel_salto;
  analogWrite(PIN_ARMA_PWML, vel_actual);
  delay(25);
}

void moverRobot() {
  //direcciones
  if (state == 'E') {
    rotarRobot_izquierda();
  }
  else if (state == 'Q') {
    rotarRobot_derecha();
  }
  else if (state == 'S') {
    moverRobot_atras();
  }
  else if (state == 'W') {
    moverRobot_adelante();
  }
  else if (state == 'A') {
    moverRobot_derecha();
  }
  else if (state == 'D') {
    moverRobot_izquierda();
  }
  else if (state == 'P') {
    pararRobot();
  }
}

void detenertodo() {
  if (state == 'M') {
    pararRobot();
    digitalWrite(PIN_MOT_AEN, LOW);
    digitalWrite(PIN_MOT_BEN, LOW);
    analogWrite(PIN_ARMA_PWML, 0);
    analogWrite(PIN_ARMA_PWMR, 0);
  }
}

void leerSerial() {
  SerialBT.listen();
  if (SerialBT.available() > 0) {
    state = SerialBT.read();
  }
}

void moverRobot_derecha() {
  // mover a la derecha

  motorA_vel = 255;
  motorB_vel = 150;
  analogWrite(PIN_MOT_AEN, motorA_vel);
  analogWrite(PIN_MOT_BEN, motorB_vel);

  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, HIGH);
  digitalWrite(PIN_MOT_B1, HIGH);
  digitalWrite(PIN_MOT_B2, LOW);
}
void moverRobot_izquierda() {
  // mover a la izquierda

  motorA_vel = 150;
  motorB_vel = 255;
  analogWrite(PIN_MOT_AEN, motorA_vel);
  analogWrite(PIN_MOT_BEN, motorB_vel);

  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, HIGH);
  digitalWrite(PIN_MOT_B1, HIGH);
  digitalWrite(PIN_MOT_B2, LOW);
}
void moverRobot_atras() {
  // mover hacia atras

  motorA_vel = 255;
  motorB_vel = 255;
  analogWrite(PIN_MOT_AEN, motorA_vel);
  analogWrite(PIN_MOT_BEN, motorB_vel);

  digitalWrite(PIN_MOT_A1, HIGH);
  digitalWrite(PIN_MOT_A2, LOW);

  digitalWrite(PIN_MOT_B1, LOW);
  digitalWrite(PIN_MOT_B2, HIGH);
}
void moverRobot_adelante() {
  // mover hacia adelante

  motorA_vel = 255;
  motorB_vel = 255;
  analogWrite(PIN_MOT_AEN, motorA_vel);
  analogWrite(PIN_MOT_BEN, motorB_vel);

  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, HIGH);
  digitalWrite(PIN_MOT_B1, HIGH);
  digitalWrite(PIN_MOT_B2, LOW);
}

void rotarRobot_derecha() {
  // rotar a la derecha

  motorA_vel = 200;
  motorB_vel = 200;
  analogWrite(PIN_MOT_AEN, motorA_vel);
  analogWrite(PIN_MOT_BEN, motorB_vel);

  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, HIGH);
  digitalWrite(PIN_MOT_B1, LOW);
  digitalWrite(PIN_MOT_B2, HIGH);
}

void rotarRobot_izquierda() {
  // rotar a la izquierda

  motorA_vel = 200;
  motorB_vel = 200;
  analogWrite(PIN_MOT_AEN, motorA_vel);
  analogWrite(PIN_MOT_BEN, motorB_vel);

  digitalWrite(PIN_MOT_A1, HIGH);
  digitalWrite(PIN_MOT_A2, LOW);
  digitalWrite(PIN_MOT_B1, HIGH);
  digitalWrite(PIN_MOT_B2, LOW);
}

void pararRobot() {

  //detener motores
  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, LOW);
  digitalWrite(PIN_MOT_B1, LOW);
  digitalWrite(PIN_MOT_B2, LOW);
}

void configurarBluetooth() {

  //Pines Bluetooth
  pinMode(PIN_BT_TX, INPUT);
  pinMode(PIN_BT_RX, INPUT);
}

void configurarMotoresMovimiento() {

  //Pines Motor A
  pinMode(PIN_MOT_A1, OUTPUT);
  pinMode(PIN_MOT_A2, OUTPUT);
  pinMode(PIN_MOT_AEN, OUTPUT);
  digitalWrite(PIN_MOT_AEN, HIGH);

  //Pines Motor B
  pinMode(PIN_MOT_B1, OUTPUT);
  pinMode(PIN_MOT_B2, OUTPUT);
  pinMode(PIN_MOT_BEN, OUTPUT);
  digitalWrite(PIN_MOT_BEN, HIGH);
}

void configurarArma() {

  //Pines Motor Arma
  pinMode(PIN_ARMA_PWMR, OUTPUT);
  pinMode(PIN_ARMA_PWML, OUTPUT);
  pinMode(PIN_ARMA_ENR, OUTPUT);
  pinMode(PIN_ARMA_ENL, OUTPUT);

  digitalWrite(PIN_ARMA_PWMR, LOW);
  digitalWrite(PIN_ARMA_PWML, LOW);
  digitalWrite(PIN_ARMA_ENR, HIGH);
  digitalWrite(PIN_ARMA_ENL, HIGH);
}
