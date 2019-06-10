
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

struct Message{
  uint8_t axisX;
  uint8_t axisY;
} message;

void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{   
    message.axisX = 90;
    message.axisY = 60;
    driver.send(((uint8_t *)&message), sizeof(message));
    
    driver.waitPacketSent();
    delay(100);
}
