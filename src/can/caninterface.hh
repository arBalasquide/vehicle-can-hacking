#include "can.hh"
#include <cstdint>
#include <linux/can.h>
#include <linux/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unordered_map>

#include <linux/sockios.h>

#include <stdio.h>
#include <string.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include <unistd.h>

#pragma once

class CanInterface {
public:
  CanInterface(std::string ifname, int baudrate, bool start_interface = false,
               bool is_virtual = false);
  ~CanInterface() {}

  uint8_t close(); // close socket

  uint8_t send(CanMessage msg);
  uint8_t getMsgCount(int id) { return _msg_count_send[id]; }
  CanMessage read();

  int getSocket() { return _socket; }

private:
  int _socket;
  int _bind;
  struct ifreq _ifr;
  struct sockaddr_can _addr;

  // track how many errors we've had receiving
  int _error_count;

  // keep track of times sent a specific can msg
  std::unordered_map<uint8_t, uint64_t> _msg_count_send;

  // keep track of the last we received a specific message
  std::unordered_map<uint8_t, timeval> _msg_timestamp;
};