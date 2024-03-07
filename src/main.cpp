#include <ModbusRTUSlave.h>

uint16_t inputRegisters[9];

ModbusRTUSlave modbus(Serial, 255);

void setup() {
  //
  modbus.configureInputRegisters(inputRegisters, 9);
  modbus.begin(1, 9600);

  for (uint8_t i = 0; i < sizeof(inputRegisters); i++) {
    inputRegisters[i] = i;
  }

}  // eof setup

void loop() { modbus.poll(); }

// EOF
