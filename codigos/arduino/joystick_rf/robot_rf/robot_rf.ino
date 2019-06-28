#include <RH_ASK.h>
#include <SPI.h>

int motorSpeedB = 0;
int motorSpeedA = 0;

struct Message {
  int16_t motorSpeedA;
  int16_t motorSpeedB;
  uint8_t weaponSpeed;
};

struct Motor {
  uint8_t pin;
  int currentSpeed;
  int newSpeed;
  int jumpSpeed;
};

// motor A, izquierdo
#define PIN_MOT_A1 2    //IN1
#define PIN_MOT_A2 4    //IN2
#define PIN_MOT_AEN 3   //ENA

//motor B, derecho
#define PIN_MOT_B1 13   //IN3
#define PIN_MOT_B2 12   //IN4
#define PIN_MOT_BEN 11  //ENB

//motor arma
#define PIN_ARMA_PWMR 10
#define PIN_ARMA_PWML 9
#define PIN_ARMA_ENR 7
#define PIN_ARMA_ENL 8

RH_ASK driver;


// Primero creamos un buffer de un tamaño suficiente para que caiga el mensaje (16 bits)
uint8_t rcvBuffer[40];
// Creamos una estructura mensaje para guardar el mensaje recibido
Message rcvMessage;
// Guardamos el tamaño esperado del mensaje
uint8_t rcvBufferSize = sizeof(rcvMessage);

Motor motorA;
Motor motorB;
Motor weapon;

void setup() {
  configurarMotoresMovimiento();
  configurarArma();
  Serial.begin(9600);  // Debugging only
  if (!driver.init()) {
    Serial.println("init failed");
  }
  
  Motor weapon = {PIN_ARMA_PWML, 0, 0, 2};
  Motor motorA = {PIN_MOT_AEN, 0, 0, 2};
  Motor motorB = {PIN_MOT_BEN, 0, 0, 2};
}

void loop() {
  // Recibir mensajes
  leerRF();

  //Para detener todo
  detenertodo();

  // Mover el robot
  moverRobot();

  // Activar arma
  setVelArma();
}

void setVelArma() {
  weapon.newSpeed = rcvMessage.weaponSpeed;
  check_vel(weapon);

}

void check_vel(Motor motor) {
  if (motor.currentSpeed > motor.newSpeed) {
    disminuir_vel(motor);
  }
  else if (motor.currentSpeed < motor.newSpeed) {
    aumentar_vel(motor);
  }
}

void disminuir_vel(Motor motor) {
  motor.currentSpeed -= motor.jumpSpeed;
  analogWrite(motor.pin, motor.currentSpeed);
  delay(25);
}

void aumentar_vel(Motor motor) {
  motor.currentSpeed += motor.jumpSpeed;
  analogWrite(motor.pin, motor.currentSpeed);
  delay(25);
}

void moverRobot() {
  
  if (rcvMessage.motorSpeedA < 0) {
    moverRobot_atras();
    motorSpeedA = -1 * rcvMessage.motorSpeedA;
    motorSpeedB = -1 * rcvMessage.motorSpeedB;
  }
  else if (rcvMessage.motorSpeedA > 0) {
    moverRobot_adelante();
  }
  else {
    pararRobot();
  }

  analogWrite(PIN_MOT_AEN, motorA.currentSpeed); // Send PWM signal to motor A
  analogWrite(PIN_MOT_BEN, motorB.currentSpeed); // Send PWM signal to motor B

  Serial.print("Message: ");
  Serial.print("MotorSpeedA: ");
  Serial.print(rcvMessage.motorSpeedA);
  Serial.print(", MotorSpeedB: ");
  Serial.print(rcvMessage.motorSpeedB);
  Serial.println(" ");
}

void leerRF() {
  if (driver.recv((rcvBuffer), &rcvBufferSize)) // tratamos de leer desde el RF cualquier mensaje. Leemos (rcvBufferSize) bytes y los guardamos en rcvBuffer
  {
    Serial.println("Recibimos un mensaje");
    // Por último copiamos el buffer rcvBuffer en la estructura rcvMessage (indicando la cantidad de bytes que tenemos que copiar -rcvBufferSize-),
    // para poder acceder a los elementos axisX y axisY
    memcpy( &rcvMessage, rcvBuffer, rcvBufferSize );
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

void moverRobot_atras() {
  // mover hacia atras
  digitalWrite(PIN_MOT_A1, HIGH);
  digitalWrite(PIN_MOT_A2, LOW);
  digitalWrite(PIN_MOT_B1, LOW);
  digitalWrite(PIN_MOT_B2, HIGH);
}

void moverRobot_adelante() {
  // mover hacia adelante
  digitalWrite(PIN_MOT_A1, LOW);
  digitalWrite(PIN_MOT_A2, HIGH);
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
