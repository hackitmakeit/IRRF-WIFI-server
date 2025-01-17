#include <IRremote.h>

#define IR_RECEIVE_PIN 16
#define IR_SEND_PIN 36
//IRsend irsend(IR_SEND_PIN);

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
  }
  //irsend.sendRC5(0x3E, 13);
  //delay(2000);
}
