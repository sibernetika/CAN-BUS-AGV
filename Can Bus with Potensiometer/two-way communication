//Canbus Send Data (MASTER)

#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>
#include "mcp_can.h"
#include <stdio.h>

#define INT8U unsigned char
const int SPI_CS_PIN = 10;
MCP_CAN CAN(SPI_CS_PIN);


int potPin = A0;
int btnPin = 8;
int potValue = 0;
int cantxValue = 0;
int btnValue = 0;

INT8U len = 0;
INT8U buf[8];
unsigned char canId;
char str[20];

int btnvalue;
int potvalue;


void setup()
{
  Serial.begin(115200);
  
  while (CAN_OK != CAN.begin(CAN_500KBPS))  // baudrate 500kbps
  {
      Serial.println("CAN BUS Shield init fail");
      Serial.println("Init CAN BUS Shield again");
      delay(100);
  }
      Serial.println("CAN BUS Initialisation Succesful!");
}

    void loop()
{
  potValue = analogRead(potPin);
  btnValue = digitalRead(btnPin);
  cantxValue = map(potValue,0,1025,0,255);
  Serial.print("cantxValue: ");
  Serial.println(cantxValue);
  Serial.print("btnValue: ");
  Serial.println(btnValue);

  //Create CanBus data pack 
  unsigned char canMsg[8] = {cantxValue, btnValue, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  //Send Data Construction:  id = 0x07B ---  standart Flame ---  data lenght = 8 ----  stmp:data buf
  CAN.sendMsgBuf(0x07B, 0, 8, canMsg);
  delay(100);
      while (CAN_MSGAVAIL == CAN.checkReceive())
        {
      CAN.readMsgBuf(&len, buf);
      canId = CAN.getCanId();
      potvalue = buf[0];
      btnvalue = buf[1];
      }
      
       Serial.print(" Potensiometer Value : ");
       Serial.print(potvalue);
       Serial.print(" Button Value : ");
       Serial.println(btnvalue);
}

    
