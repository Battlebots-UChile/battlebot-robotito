#include <VirtualWire.h>
#include <VirtualWire_Config.h>


int estado_arma = Estado::VEL_FIJA;

int state;
int motorA_vel = 0;
int motorB_vel = 0;
int vel_actual = 0;
int vel_nueva = 0;
int vel_salto = 2;

struct Message{
  uint8_t axisX;
  uint8_t axisY;
  uint8_t motorSpeedA;
  uint8_t motorSpeedB;
} message;

// motor A, izquierdo
#define PIN_MOT_A1 2    //IN1
#define PIN_MOT_A2 4    //IN2
#define PIN_MOT_AEN 9   //ENA

//motor B, derecho
#define PIN_MOT_B1 7    //IN3
#define PIN_MOT_B2 8    //IN4
#define PIN_MOT_BEN 10  //ENB

//motor arma
#define PIN_ARMA_PWMR 11
#define PIN_ARMA_PWML 3
#define PIN_ARMA_ENR 12
#define PIN_ARMA_ENL 13

void setup(){
  
  configurarBluetooth();
  configurarMotoresMovimiento();
  configurarArma();
  
  Serial.begin(9600);
  SerialBT.begin(9600);
}

void loop() {
  // Chequear Serial
  leerSerial();
  
  //Para detener todo
  detenertodo();
  
  // Mover el robot
  moverRobot();
  
  // Mover el arma
  setVelArma();
  Serial.println(vel_actual);
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

  int xAxis = analogRead(A0); // Read Joysticks X-axis
  int yAxis = analogRead(A1); // Read Joysticks Y-axis
  
  if (yAxis < 470) {
    //Set Motor A backward
    digitalWrite(PIN_MOT_A1, HIGH);
    digitalWrite(PIN_MOT_A2, LOW);
    // Set Motor B backward
    digitalWrite(PIN_MOT_B1, HIGH);
    digitalWrite(PIN_MOT_B2, LOW);
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {
    digitalWrite(PIN_MOT_A1, LOW);
    digitalWrite(PIN_MOT_A2, HIGH);
    digitalWrite(PIN_MOT_B1, LOW);
    digitalWrite(PIN_MOT_B2, HIGH);
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
   }
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
    }
   // X-axis used for left and right control


   
  if (xAxis < 470) {
    int xMapped = map(xAxis, 470, 0, 0, 255);
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
      }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
      }
    
    }
  if (xAxis > 550) {
    // Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
    int xMapped = map(xAxis, 550, 1023, 0, 255);
    // Move right - decrease right motor speed, increase left motor speed
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA > 255) {
      motorSpeedA = 255;
      }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
      }
    }
  if (motorSpeedA < 50) {
    motorSpeedA = 0;
    }
  if (motorSpeedB < 50) {
    motorSpeedB = 0;
    }
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B




  
  if (state == 'E'){
    rotarRobot_derecha();
  }
  else if (state == 'Q') {
    rotarRobot_izquierda();
  }
  else if (state == 'S') {
    moverRobot_atras();
  }  
  else if (state == 'W') {
    moverRobot_adelante();
  }
  else if (state == 'A') {
    moverRobot_izquierda();
  }
  else if (state == 'D') {
    moverRobot_derecha();
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
    analogWrite(PIN_MOT_AEN,motorA_vel);
    analogWrite(PIN_MOT_BEN,motorB_vel);
    
    digitalWrite(PIN_MOT_A1, LOW);
    digitalWrite(PIN_MOT_A2, HIGH);
    digitalWrite(PIN_MOT_B1, HIGH);
    digitalWrite(PIN_MOT_B2, LOW);
}
void moverRobot_izquierda() {
    // mover a la izquierda

    //modificar velocidad
    motorA_vel = 150;
    motorB_vel = 255;
    analogWrite(PIN_MOT_AEN,motorA_vel);
    analogWrite(PIN_MOT_BEN,motorB_vel);
    
    //direccion
    digitalWrite(PIN_MOT_A1, LOW);
    digitalWrite(PIN_MOT_A2, HIGH);
    digitalWrite(PIN_MOT_B1, HIGH);
    digitalWrite(PIN_MOT_B2, LOW);
}
void moverRobot_atras() {
    // mover hacia atras
    motorA_vel = 255;
    motorB_vel = 255;
    analogWrite(PIN_MOT_AEN,motorA_vel);
    analogWrite(PIN_MOT_BEN,motorB_vel);
    
    digitalWrite(PIN_MOT_A1, HIGH);
    digitalWrite(PIN_MOT_A2, LOW);
    
    digitalWrite(PIN_MOT_B1, LOW);
    digitalWrite(PIN_MOT_B2, HIGH);
}
void moverRobot_adelante() {
    // mover hacia adelante
    motorA_vel = 255;
    motorB_vel = 255;
    analogWrite(PIN_MOT_AEN,motorA_vel);
    analogWrite(PIN_MOT_BEN,motorB_vel);
    
    digitalWrite(PIN_MOT_A1, LOW);
    digitalWrite(PIN_MOT_A2, HIGH);
    digitalWrite(PIN_MOT_B1, HIGH);
    digitalWrite(PIN_MOT_B2, LOW);
}

void rotarRobot_derecha() {
    // rotar a la derecha
    motorA_vel = 200;
    motorB_vel = 200;
    analogWrite(PIN_MOT_AEN,motorA_vel);
    analogWrite(PIN_MOT_BEN,motorB_vel);
    
    digitalWrite(PIN_MOT_A1, LOW);
    digitalWrite(PIN_MOT_A2, HIGH);
    digitalWrite(PIN_MOT_B1, LOW);
    digitalWrite(PIN_MOT_B2, HIGH);
}

void rotarRobot_izquierda() {
    // rotar a la izquierda
    motorA_vel = 200;
    motorB_vel = 200;
    analogWrite(PIN_MOT_AEN,motorA_vel);
    analogWrite(PIN_MOT_BEN,motorB_vel);
    
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
  //Pines Motor Central
  pinMode(PIN_ARMA_PWMR, OUTPUT);
  pinMode(PIN_ARMA_PWML, OUTPUT);
  pinMode(PIN_ARMA_ENR, OUTPUT);
  pinMode(PIN_ARMA_ENL, OUTPUT);

  digitalWrite(PIN_ARMA_PWMR,LOW);
  digitalWrite(PIN_ARMA_PWML,LOW);
  digitalWrite(PIN_ARMA_ENR,HIGH);
  digitalWrite(PIN_ARMA_ENL,HIGH);
}
