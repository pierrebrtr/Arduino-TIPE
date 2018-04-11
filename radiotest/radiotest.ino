
#include <RF24.h>


RF24 transmit (9,10);                    //create RF24 object called transmit

byte address [5] = "00001";             //set address to 00001

void setup() {
  transmit.begin();
  transmit.openWritingPipe(address);    //open writing pipe to address 00001
  transmit.setPALevel(RF24_PA_MIN);     //set RF power output to minimum
  transmit.setDataRate(RF24_250KBPS);   //set datarate to 250kbps
  transmit.setChannel(1);             //set frequency to channel 100
  transmit.stopListening(); 
   }

void loop() {

  char data[32] = "It Works !";         //send character string upto 32 bytes long
  transmit.write(&data,sizeof(data));   //transmit the data
  delay(1000);      
}
