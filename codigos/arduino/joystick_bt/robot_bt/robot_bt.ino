#include <SoftwareSerial.h>
SoftwareSerial SerialBT(5, 6); // RX | TX

struct Message {
  int16_t motorSpeedA;
  int16_t motorSpeedB;
  int16_t weaponSpeed;
} message;

struct Motor {
  uint8_t pin;
  int currentSpeed;
  int newSpeed;
  int jumpSpeed;
};

int motorSpeedB = 0;
int motorSpeedA = 0;

int periodo = 100;  //cada cuanto manda datos
unsigned long TiempoAhora = 0;

char char_in1, char_in2;
char *ptr;
struct Message state;
long count;
long sizex;

Motor motorA;
Motor motorB;
Motor weapon;

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
#define PIN_MOT_BEN 11  //ENB

//motor arma
#define PIN_ARMA_PWMR 10
#define PIN_ARMA_PWML 9
#define PIN_ARMA_ENR 7
#define PIN_ARMA_ENL 8

void setup() {

  configurarMotoresMovimiento();
  configurarArma();
  Serial.begin(9600);
  SerialBT.begin(9600);

  Motor weapon = {PIN_ARMA_PWML, 0, 0,2};
  Motor motorA = {PIN_MOT_AEN, 0, 0,4};
  Motor motorB = {PIN_MOT_BEN, 0, 0,4};
}

void loop() {
  //Recibir mensajes
  leerSerialBT();

  //Para detener todo
  detenertodo();

  // Mover el robot
  setVelMov();

  // Mover el arma
  setVelArma();

  if (millis() >= TiempoAhora + periodo) {
    analogWrite(PIN_ARMA_PWML, weapon.currentSpeed); // Send PWM signal to weapon motor
    analogWrite(PIN_MOT_AEN, motorA.currentSpeed);   // Send PWM signal to motor A
    analogWrite(PIN_MOT_BEN, motorB.currentSpeed);   // Send PWM signal to motor B
  }


}

void setVelArma() {
  weapon.newSpeed = state.weaponSpeed;
  check_vel(&weapon);
}

void check_vel(Motor* motor) {
  if (motor->currentSpeed > motor->newSpeed) {
    motor->currentSpeed -= motor ->jumpSpeed;
  }

  else if (motor->currentSpeed < motor->newSpeed) {
    motor->currentSpeed += motor ->jumpSpeed;
  }
}

void leerSerialBT() {
  SerialBT.listen();
  int rcv_bytes = SerialBT.available();
  //Serial.println("" + String(rcv_bytes));
  if (rcv_bytes == 6) {
    //while (!SerialBT.available());
    sizex = sizeof(struct Message);
    ptr = (char *)&state;
    for (count = 0; count < sizex; count++) {
      *(ptr + count) = SerialBT.read();
    }
  }
}

void setVelMov() {
  motorSpeedA = state.motorSpeedA;
  motorSpeedB = state.motorSpeedB;
  if (state.motorSpeedA < 0) {
    moverRobot_atras();
    motorSpeedA=-1*motorSpeedA;
    motorSpeedB=-1*motorSpeedB;
  }
  else if (state.motorSpeedA > 0) {
    moverRobot_adelante();
  }
  else {
    pararRobot();
  }
  check_vel(&motorA);
  check_vel(&motorB);

}

void detenertodo() {
  if (state.weaponSpeed == -1) {
    pararRobot();
    digitalWrite(PIN_MOT_AEN, LOW);
    digitalWrite(PIN_MOT_BEN, LOW);
    analogWrite(PIN_ARMA_PWML, 0);
    analogWrite(PIN_ARMA_PWMR, 0);
  }
}

void moverRobot_atras() {
  digitalWrite(PIN_MOT_A1, HIGH);
  digitalWrite(PIN_MOT_A2, LOW);
  digitalWrite(PIN_MOT_B1, LOW);
  digitalWrite(PIN_MOT_B2, HIGH);
}

void moverRobot_adelante() {
  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, HIGH);
  digitalWrite(PIN_MOT_B1, HIGH);
  digitalWrite(PIN_MOT_B2, LOW);
}

void pararRobot() {
  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, LOW);
  digitalWrite(PIN_MOT_B1, LOW);
  digitalWrite(PIN_MOT_B2, LOW);
}

void configurarBluetooth() {
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

  digitalWrite(PIN_ARMA_PWMR, LOW);
  digitalWrite(PIN_ARMA_PWML, LOW);
  digitalWrite(PIN_ARMA_ENR, HIGH);
  digitalWrite(PIN_ARMA_ENL, HIGH);
}
