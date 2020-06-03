// CAN-BUS Receive Data

#include "mcp_can.h"
#include <SPI.h>
#include <stdio.h>

#define INT8U unsigned char
const int SPI_CS_PIN = 10;
MCP_CAN CAN(SPI_CS_PIN);

INT8U len = 0;
INT8U buf[8];
unsigned char canId;
char str[20];

int btnvalue;
int potvalue;

void setup()
{
  
  Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_500KBPS))   // canbus baudrate 500kbps
    {
        Serial.println("CAN BUS Shield init fail!!!");
        Serial.println("Init CAN BUS Shield again...");
        delay(100);
    }

    Serial.println("CAN BUS Initialisation Succesful");
}
void loop()
{

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
