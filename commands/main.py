#!/usr/bin/env python3

import can
import time
import os
import itertools

if __name__ == "__main__":
    # keep a list of messages found
    messages = {}

    # for throttling our prints
    messages_gotten = 0

    try:
        bus = can.interface.Bus(channel='can0', bustype='socketcan')
    except OSError:
        print("Cannot find can0 device")
        exit()

    while True:
        message = bus.recv()

        c = '{0:f} {1:x} {2:x} '.format(message.timestamp, message.arbitration_id, message.dlc)

        messages[message.arbitration_id] = message 

        # at 500kbit/s we're getting around 1000 msgs from can
        if messages_gotten > 100:
            # pretty print the messages
            os.system('cls' if os.name == 'nt' else 'clear')

            sliced_msgs = dict(itertools.islice(messages.items(),80))
            for k in sliced_msgs:
                msg = messages[k]
                data = [hex(data) for data in msg.data]
                print(hex(msg.arbitration_id), data)

            messages_gotten = 0

        messages_gotten += 1
