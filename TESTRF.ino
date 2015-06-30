#include "EEPROM.h"
#include "cc1101.h"
                         // SQ5RIQ | www.marcinnoga75.blogspot.com | 
CC1101 cc1101;           // The connection to the hardware chip CC1101 the RF Chip

char paTableM30dBm[] = {0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};   // -30dBm = 0.000001W
char paTableM20dBm[] = {0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};   // -20dBm = 0.00001W
char paTableM10dBm[] = {0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};   // -10dBm = 0.0001W
char paTable0dBm[] =   {0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};   //   0dBm = 0.001W
char paTable10dBm[] =  {0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};   //  10dBm = 0.01W
     
void setup()
{
   cc1101.init();                                 // initialize the RF Chip
     cc1101.writeReg(CC1101_FREQ2,0x10);
     cc1101.writeReg(CC1101_FREQ1,0xB1);          //  434MHz przy kwarcu 26MHz
     cc1101.writeReg(CC1101_FREQ0,0x3B);          //  0x10 | 0xB1 | 0x3B
     cc1101.writeReg(CC1101_DEVIATN,0x24);        //  0x24 - Deviation 1.587 Khz
   
     cc1101.setTxState();
}
void loop()
{
   cc1101.writeReg(0x3E, paTableM30dBm[0]);
   delay(10);
   cc1101.writeReg(0x3E, paTableM20dBm[0]);
   delay(20);
}
