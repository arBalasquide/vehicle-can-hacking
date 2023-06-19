#include "can.hh"

#include <cstdint>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

CanMessage::CanMessage(uint8_t idh, uint8_t idl, uint16_t length, uint8_t *data,
                       VehicleMake make) {
  _idl = idl;
  _idh = idh;
  _length = length;
  _data = data;

  _make = make;

  _id = idl | (idh << 8);
}

// TODO: probs want to close the socket (｡>﹏<｡)
CanMessage::~CanMessage(){};

// sometimes we need msg to have a cs, but sometimes not so make this an
// optional call
uint8_t CanMessage::generateChecksum() {
  // lambda for summing data field of message, probably repeated in a lot of
  // msgs across different makes
  auto sum = [](uint8_t *data, uint8_t length) {
    int res = 0;
    for (int i = 0; i < length; i++) {
      res += data[i];
    }

    return res;
  };

  // different vehicles have different ways to generate a checksum
  switch (_make) {
  case TOYOTA:
    _checksum = (_idh + _idl + _length + (sum(_data, _length - 1))) & 0xff;
	_data[_length-1] = _checksum;
    break;
	case FORD:
	//_checksum =
  default:
    break;
  }

  return _checksum;
}

// maybe this should go under a utils file
std::string CanMessage::intToHex(int value) {
  std::stringstream stream;
  stream << std::hex << value;

  return std::string(stream.str());
}

std::ostream &operator<<(std::ostream &os, CanMessage msg) {

  std::string idh = CanMessage::intToHex(msg.idh());
  std::string idl = CanMessage::intToHex(msg.idl());

  // byte array into pretty string
  std::string data = "[ ";
  for (int i = 0; i < msg.length(); i++) {
    data += (i < msg.length() - 1) ? CanMessage::intToHex(msg.data()[i]) + ", "
                                   : CanMessage::intToHex(msg.data()[i]);
  }
  data += "]";

  os << "IDH: " << idh << " IDL: " << idl << " LEN: " << msg.length()
     << " DAT: " << data << " MAKE: ";

  switch (msg.make()) {
  case TOYOTA:
    os << "TOYOTA";
    break;
  case FORD:
	os << "FORD";
	break;
  case BMW:
	os << "BMW";
	break;
  case HONDA:
	os << "HONDA";
	break;
  default:
    os << "UNKNOWN";
    break;
  }

  os << std::endl;

  return os;
}
