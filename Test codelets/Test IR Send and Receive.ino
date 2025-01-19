#include <IRremote.h>

#define IR_RECEIVE_PIN 6
#define IR_SEND_PIN 7

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  IrSender.begin(IR_SEND_PIN);
}

void loop() {
  //Example code to print out received codes information
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.printIRSendUsage(&Serial);
    IrReceiver.resume();
  }
  // Example Call to send data
  IrSender.sendRC5(0xE,0x3E,2);
  delay(2000);
}
