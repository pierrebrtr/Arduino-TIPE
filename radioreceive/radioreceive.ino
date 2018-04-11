
#include <RF24.h>


RF24 receive (9,10);                         //create object called receive
byte address [5] = "00001";                 //creat an array with 5 elements, where each element is 1 byte;

void setup() {
  Serial.begin(9600);
  Serial.print("Starting Receiver \n");
  receive.begin();
  receive.openReadingPipe(0,address);      //open reading pipe 0 at address 00001 
  receive.setPALevel(RF24_PA_MIN);         //Set RF output to minimum
  receive.setDataRate(RF24_250KBPS);       //set datarate to 250kbps
  receive.setChannel(1);                 //set frequency to channel 100 
  receive.startListening();                

  }

void loop() {

  if (receive.available())                //check when received data available
  {
    char data[32];
    receive.read(&data, sizeof(data));
    Serial.print(data);                   //print data to serial monitor
  }
}
