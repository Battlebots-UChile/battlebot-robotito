
#include <SoftwareSerial.h>

SoftwareSerial SerialBT(2, 3); // RX | TX

#define PIN_BUTTON1 4
#define PIN_BUTTON2 5
#define PIN_BUTTON3 6
#define PIN_BUTTON4 7
#define PIN_BUTTONSTOP 8

int motorSpeedA = 0;
int motorSpeedB = 0;
int sentido = 0; // 1 <- adelante -1 <- atras

int xAxis;
int yAxis;
int periodo = 100;  //cada cuanto manda datos
unsigned long TiempoAhora = 0;

struct Message {
  int16_t motorSpeedA;
  int16_t motorSpeedB;
  int16_t weaponSpeed;
} message;

void setup() {
  Serial.begin(9600);
  SerialBT.begin(9600);
  configurarBotones();
}

void loop() {

  xAxis = analogRead(A1); // Read Joysticks X-axis
  yAxis = analogRead(A0); // Read Joysticks Y-axis

  setWeaponSpeed();

  if (digitalRead(PIN_BUTTONSTOP) == LOW) {
    message.weaponSpeed = -1;
    sendMessage();
  }

  if (millis() >= TiempoAhora + periodo) {
    TiempoAhora = millis();
    mapAxis();
    sendMessage();
  }
}


void setWeaponSpeed() {
  if (digitalRead(PIN_BUTTON1) == LOW) {
    message.weaponSpeed = 0;
  }
  if (digitalRead(PIN_BUTTON2) == LOW) {
    message.weaponSpeed = 70;
  }
  if (digitalRead(PIN_BUTTON3) == LOW) {
    message.weaponSpeed = 100;
  }
  if (digitalRead(PIN_BUTTON4) == LOW) {
    message.weaponSpeed = 130;
  }
}

void mapAxis() {
  if (yAxis < 500) {

    //ruedas girando hacia atras
    sentido = -1;
    motorSpeedA = map(yAxis, 500, 0, 0, 255);
    motorSpeedB = map(yAxis, 500, 0, 0, 255);
  }
  else if (yAxis > 520) {

    //ruedas girando hacia adelante
    sentido = 1;
    motorSpeedA = map(yAxis, 520, 1023, 0, 255);
    motorSpeedB = map(yAxis, 520, 1023, 0, 255);
  }
  else {
    sentido = 0;
    motorSpeedA = 0;
    motorSpeedB = 0;
  }

  if (xAxis < 500) {
    int xMapped = map(xAxis, 500, 0, 0, 255);
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;

    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }

  if (xAxis > 520) {
    int xMapped = map(xAxis, 520, 1023, 0, 255);

    // Move right - decrease right motor speed, increase left motor speed
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;

    if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  }
  if (motorSpeedA < 30) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 30) {
    motorSpeedB = 0;
  }
}

void sendMessage() {
  message.motorSpeedA = motorSpeedA * sentido;
  message.motorSpeedB = motorSpeedB * sentido;
  SerialBT.write((const uint8_t *)&message, sizeof(struct Message));
  Serial.println(message.motorSpeedA);
  Serial.println(message.motorSpeedB);
  Serial.println(message.weaponSpeed);
}

void configurarBotones() {
  pinMode(PIN_BUTTON1, INPUT);
  pinMode(PIN_BUTTON2, INPUT);
  pinMode(PIN_BUTTON3, INPUT);
  pinMode(PIN_BUTTON4, INPUT);
}
