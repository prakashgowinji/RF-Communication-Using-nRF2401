#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

const byte rxAddress[6] = "00001";

void setup()
{
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddress);
  
  radio.stopListening();
}

void loop()
{
  const char text[] = "It is from  MCU ! :) ";
  radio.write(&text, sizeof(text));
  
  delay(1000);
}
