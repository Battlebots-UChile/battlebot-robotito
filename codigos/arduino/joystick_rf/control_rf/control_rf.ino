#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

int periodo = 100;  //cada cuanto manda datos
unsigned long TiempoAhora = 0;

int motorSpeedA = 0;
int motorSpeedB = 0;
int sentido = 0;    // 1 <- adelante -1 <- atras

struct Message {
  int16_t motorSpeedA;
  int16_t motorSpeedB;
  uint8_t weaponSpeed;
}message;

void setup() {
  Serial.begin(115200);    // Debugging only
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

void loop() {

  int xAxis = analogRead(A1); // Read Joysticks X-axis
  int yAxis = analogRead(A0); // Read Joysticks Y-axis

  sendMessage();
  
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

    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }

  if (xAxis > 520) {
    // Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
    int xMapped = map(xAxis, 520, 1023, 0, 255);

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
}
void sendMessage() {
  if (millis() > TiempoAhora + periodo) {
    TiempoAhora = millis();
    message.motorSpeedA = motorSpeedA * sentido;
    message.motorSpeedB = motorSpeedB * sentido;

    Serial.print(analogRead(A0));
    Serial.print(' ');
    Serial.print(analogRead(A1));
    Serial.println();

    driver.send(((const uint8_t *)&message), sizeof(message));
    driver.waitPacketSent();
  }
  
}
