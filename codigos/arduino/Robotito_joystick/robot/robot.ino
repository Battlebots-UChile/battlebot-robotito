#include <RH_ASK.h>
#include <SPI.h>

int state;
int motorSpeedB = 0;
int motorSpeedA = 0;
int vel_actual = 0;
int vel_nueva = 0;
int vel_salto = 2;

struct Message {
  int16_t motorSpeedA;
  int16_t motorSpeedB;
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
#define PIN_ARMA_PWMR 12
#define PIN_ARMA_PWML 3
#define PIN_ARMA_ENR 6
#define PIN_ARMA_ENL 13

RH_ASK driver;


// Primero creamos un buffer de un tamaño suficiente para que caiga el mensaje (16 bits)
uint8_t rcvBuffer[32];
// Creamos una estructura mensaje para guardar el mensaje recibido
Message rcvMessage;
// Guardamos el tamaño esperado del mensaje
uint8_t rcvBufferSize = sizeof(rcvMessage);


void setup() {

  configurarMotoresMovimiento();
  configurarArma();

  Serial.begin(9600);  // Debugging only
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

void loop() {
  // Recibir mensajes
  leerRF();

  //Para detener todo
  detenertodo();

  // Mover el robot
  moverRobot();

  // Mover el arma
  setVelArma();
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

void leerRF() {
  if (driver.recv((rcvBuffer), &rcvBufferSize)) // tratamos de leer desde el RF cualquier mensaje. Leemos (rcvBufferSize) bytes y los guardamos en rcvBuffer
  {
    Serial.println("Recibimos un mensaje");
    // Por último copiamos el buffer rcvBuffer en la estructura rcvMessage (indicando la cantidad de bytes que tenemos que copiar -rcvBufferSize-),
    // para poder acceder a los elementos axisX y axisY
    memcpy( &rcvMessage, rcvBuffer, rcvBufferSize );
  }
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

  analogWrite(PIN_MOT_AEN, motorSpeedA); // Send PWM signal to motor A
  analogWrite(PIN_MOT_BEN, motorSpeedB); // Send PWM signal to motor B

  Serial.print("Message: ");
  Serial.print("MotorSpeedA: ");
  Serial.print(rcvMessage.motorSpeedA);
  Serial.print(", MotorSpeedB: ");
  Serial.print(rcvMessage.motorSpeedB);
  Serial.println(" ");
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
