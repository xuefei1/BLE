
#include <ble_mini.h>

#define DIGITAL_OUT_PIN_1   2
#define DIGITAL_OUT_PIN_2   3
#define DIGITAL_OUT_PIN_3   4
#define DIGITAL_OUT_PIN_4   5
#define DIGITAL_OUT_PIN_5   6

byte CMD_TYPE_GET = 0x02;
byte CMD_TYPE_SET = 0x01;

byte CMD_SET_LEVEL = 0x01;

void setup() {
  // put your setup code here, to run once:
  BLEMini_begin(57600);
  Serial.begin(57600);
  pinMode(DIGITAL_OUT_PIN_1, OUTPUT);
  pinMode(DIGITAL_OUT_PIN_2, OUTPUT);
  pinMode(DIGITAL_OUT_PIN_3, OUTPUT);
  pinMode(DIGITAL_OUT_PIN_4, OUTPUT);
  pinMode(DIGITAL_OUT_PIN_5, OUTPUT);
  Serial.println("Init success");
  digitalWrite(DIGITAL_OUT_PIN_1, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  while ( BLEMini_available() == 5)
  {
    Serial.println("Received something");
    // read out command and data
    byte cmd_type = BLEMini_read();
    byte cmd = BLEMini_read();
    byte data0 = BLEMini_read();
    byte data1 = BLEMini_read();
    byte data2 = BLEMini_read();
    if(cmd == CMD_SET_LEVEL){
      updatePos((int)data0);
    }
  }

  delay(100);
}

void updatePos(int level){
  if(level == 1){
    digitalWrite(DIGITAL_OUT_PIN_2, LOW);
    digitalWrite(DIGITAL_OUT_PIN_3, LOW);
    digitalWrite(DIGITAL_OUT_PIN_4, LOW);
    digitalWrite(DIGITAL_OUT_PIN_5, LOW);
  }else if(level == 2){
    digitalWrite(DIGITAL_OUT_PIN_2, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_3, LOW);
    digitalWrite(DIGITAL_OUT_PIN_4, LOW);
    digitalWrite(DIGITAL_OUT_PIN_5, LOW);
  }else if(level == 3){
    digitalWrite(DIGITAL_OUT_PIN_2, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_3, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_4, LOW);
    digitalWrite(DIGITAL_OUT_PIN_5, LOW);
  }else if(level == 4){
    digitalWrite(DIGITAL_OUT_PIN_2, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_3, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_4, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_5, LOW);
  }else {
    digitalWrite(DIGITAL_OUT_PIN_2, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_3, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_4, HIGH);
    digitalWrite(DIGITAL_OUT_PIN_5, HIGH);
  }
}
