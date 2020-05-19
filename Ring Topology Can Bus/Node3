#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
struct can_frame canMsg1;
struct can_frame canMsg2;
struct can_frame canMsg3;
MCP2515 mcp2515(10);

//int potPin1=A0;
//int potValue1=0;
//int cantxValue1=0;

//int potPin2=A0;
//int potValue2=0;
//int cantxValue2=0;

int potPin3=A0;
int potValue3=0;
int cantxValue3=0;

void setup() {  
  while (!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("Example: Write to CAN");
}

void loop() {

//   //input potensio & button 1
//  potValue1 = analogRead(potPin1);
//  btnValue1 = digitalRead(btnPin1);
//  cantxValue1 = map(potValue1,0,1025,0,255);

 //input potensio & button 2
//  potValue2 = analogRead(potPin2);
//  btnValue2 = digitalRead(btnPin);
//  cantxValue2 = map(potValue2,0,1025,0,255);
 
 //input potensio & button 3
  potValue3 = analogRead(potPin3);
//  btnValue3 = digitalRead(btnPin);
  cantxValue3 = map(potValue3,0,1025,0,255);
 

//  canMsg1.can_id  = 0x0F6;
//  canMsg1.can_dlc = 8;
//  canMsg1.data[0] = 0x8E;
//  canMsg1.data[1] = 0x87;
//  canMsg1.data[2] = 0x32;
//  canMsg1.data[3] = 0xFA;
//  canMsg1.data[4] = 0x26;
//  canMsg1.data[5] = 0x8E;
//  canMsg1.data[6] = 0xBE;
//  canMsg1.data[7] = 0x86;

//  canMsg2.can_id  = 0x036;
//  canMsg2.can_dlc = 8;
//  canMsg2.data[0] = 0x0E;
//  canMsg2.data[1] = 0x00;
//  canMsg2.data[2] = 0x00;
//  canMsg2.data[3] = 0x08;
//  canMsg2.data[4] = 0x01;  
//  canMsg2.data[5] = 0x00;
//  canMsg2.data[6] = 0x00;
//  canMsg2.data[7] = 0xA0;

  canMsg3.can_id  = 0x07B;
  canMsg3.can_dlc = 1;
  canMsg3.data[0] = cantxValue3;
  canMsg3.data[1] = 0;
  canMsg3.data[2] = 0;
  canMsg3.data[3] = 0;
  canMsg3.data[4] = 0;
  canMsg3.data[5] = 0;
  canMsg3.data[6] = 0;
  canMsg3.data[7] = 0;
  
//  mcp2515.sendMessage(&canMsg1);
//  mcp2515.sendMessage(&canMsg2);
  mcp2515.sendMessage(&canMsg3);

  Serial.println("Messages sent");
  
  delay(100);

    if (mcp2515.readMessage(&canMsg1) == MCP2515::ERROR_OK) {
    Serial.print(canMsg1.can_id, HEX); // print ID
    Serial.print(" "); 
    Serial.print(canMsg1.can_dlc, HEX); // print DLC
    Serial.print(" ");
    
   // for (int i = 0; i<canMsg1.can_dlc; i++)  {  // print the data
      Serial.print(canMsg1.data[0]);
      Serial.print(" ");
    

    Serial.println();      
  }
  
    if (mcp2515.readMessage(&canMsg2) == MCP2515::ERROR_OK) {
    Serial.print(canMsg2.can_id, HEX); // print ID
    Serial.print(" "); 
    Serial.print(canMsg2.can_dlc, HEX); // print DLC
    Serial.print(" ");
    
    //for (int i = 0; i<canMsg2.can_dlc; i++)  {  // print the data
      Serial.print(canMsg2.data[0]);
      Serial.print(" ");
    

    Serial.println();      
  }
    if (canMsg1.data[0] >= 50){
    Serial.println("F6 To High");
  }
     else{
    Serial.println("OK");
  }
   if (canMsg2.data[0] >= 100){
    Serial.println("36 To High");
  }
  else{
    Serial.println("OK");
  }
  delay(1000);
}
