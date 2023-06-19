#include "caninterface.hh"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <string>

CanInterface::CanInterface(std::string ifname, int baudrate,
                           bool start_interface, bool is_virtual) {

  if (start_interface) {
    // bring up interface
    // if its virtual, its a different set of instructions
  }

  _socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);

  struct ifreq ifr;

  strcpy(ifr.ifr_name, ifname.c_str());
  ioctl(_socket, SIOCGIFINDEX, &ifr);

  struct sockaddr_can addr;
  memset(&addr, 0, sizeof(addr));
  addr.can_family = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;
  _bind = bind(_socket, (struct sockaddr *)&addr, sizeof(addr));
}

uint8_t CanInterface::send(CanMessage msg) {
  uint8_t rc = 1; // good for now...

  struct can_frame frame;
  frame.can_id = msg.id();
  frame.can_dlc = msg.length();

  for (int i = 0; i < msg.length(); i++) {
    frame.data[i] = msg.data()[i];
  }

  if (write(_socket, &frame, sizeof(struct can_frame)) !=
      sizeof(struct can_frame)) {
    rc = -1;
  } else {
    _msg_count_send[msg.id()] += 1;
  }

  return rc;
}

CanMessage CanInterface::read() {
  CanMessage msg(0, 0, 0, nullptr, TOYOTA);

  ioctl(_socket, SIOCGSTAMP, &_msg_timestamp[msg.id()]);

  return msg;
}