#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace uart_readline {

class UartReadLineSensor : public text_sensor::TextSensor, public Component, public uart::UARTDevice {
 public:
  void setup() override {
    // nothing to do here
  }
  int readline(int readch, char *buffer, int len)
  {
    static int pos = 0;
    int rpos;
    if (readch > 0) {
      switch (readch) {
        case ';': // Return on CR
          rpos = pos;
          pos = 0;  // Reset position index ready for next time
          return rpos;
        default:
          if (pos < len-1) {
            buffer[pos++] = readch;
            buffer[pos] = 0;
          }
      }
    }
    // No end of line has been found, so return -1.
    return -1;
  }
  void loop() override {
    const int max_line_length = 20;
    static char buffer[max_line_length];
    while (available()) {
      if(readline(read(), buffer, max_line_length) > 0) {
        publish_state(buffer);
      }
    }
  }
};

}  // namespace uart_readline
}  // namespace esphome
