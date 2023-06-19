#include <iostream>
#include <stdint.h>

#pragma once

// custom enum, since some ECUs could be aftermarket?
enum VehicleMake { CUSTOM = 0, TOYOTA, FORD, HONDA, BMW };

class CanMessage {
public:
  CanMessage(uint8_t idh, uint8_t idl, uint16_t length, uint8_t data[8],
             VehicleMake make);
  ~CanMessage();

  uint8_t getChecksum();
  uint8_t generateChecksum();

  uint8_t idl() { return _idl; }
  uint8_t idh() { return _idh; }
  uint8_t checksum() { return _checksum; }
  uint8_t* data() { return _data; }

  uint16_t id() { return _id; };
  uint16_t length() { return _length; }

  VehicleMake make() { return _make; }

  friend std::ostream &operator<<(std::ostream &os, CanMessage msg);

  static std::string intToHex(int value);

private:
  uint8_t _idh;
  uint8_t _idl;
  uint8_t _checksum{0};

  // can2.0A supports 11bit identifier but 2.0B supports 29bit... todo
  uint16_t _id;

  VehicleMake _make{CUSTOM};

  uint16_t _length;
  uint8_t * _data;
};
