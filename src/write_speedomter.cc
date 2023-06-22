#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <string>

#include <chrono>
#include <thread>

#include "can/can.hh"
#include "can/caninterface.hh"

int main() {
  CanInterface can_interface("vcan0", 500000);

  uint8_t bytes[2];
  bytes[0] = 0x66;
  bytes[1] = 0x06;

  uint16_t speed = bytes[0] | bytes[1] << 8;

  std::cout << "Speed: " << int(speed * 0.0062) << std::endl;
  
  uint8_t s1 = (speed >> 8) & 0xFF;
  uint8_t s2 = speed & 0xFF;

  uint8_t data[8] = {0, 0, 0, 0, 0, s1, s2, 0};

  CanMessage speedometer(0x00, 0xB4, 8, data, TOYOTA);
  speedometer.generateChecksum(); // this msg has a checksum, so lets let it
                                  // generate it for us

  while (true) {
    can_interface.send(speedometer);

    // kinda ugly... rethink how this is done? TODO
    speedometer.data()[4] = can_interface.getMsgCount(speedometer.id());
    speedometer.generateChecksum();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}
