#include <RH_ASK.h>
#include <SPI.h>

int motorSpeedA = 0;
int motorSpeedB = 0;
int sentido = 0; // 1 <- adelante -1 <- atras

RH_ASK driver;

struct Message {
  int16_t motorSpeedA;
  int16_t motorSpeedB;
} message;

void setup() {
  Serial.begin(9600);    // Debugging only
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

void loop() {

  int xAxis = analogRead(A1); // Read Joysticks X-axis
  int yAxis = analogRead(A0); // Read Joysticks Y-axis

  if (yAxis < 470) {

    //ruedas girando hacia atras
    sentido = -1;

    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {

    //ruedas girando hacia adelante
    sentido = 1;

    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
  else {
    sentido = 0;
    motorSpeedA = 0;
    motorSpeedB = 0;
  }

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

  if (motorSpeedA < 30) {
    motorSpeedA = 0;
  }

  if (motorSpeedB < 30) {
    motorSpeedB = 0;
  }

  motorSpeedA = motorSpeedA * sentido;
  motorSpeedB = motorSpeedB * sentido;

  message.motorSpeedA = motorSpeedA;
  message.motorSpeedB = motorSpeedB;

  Serial.print(message.motorSpeedA);
  Serial.print(' ');
  Serial.print(message.motorSpeedB);
  Serial.println();


  driver.send(((const uint8_t *)&message), sizeof(message));
  driver.waitPacketSent();
  delay(100);

}
