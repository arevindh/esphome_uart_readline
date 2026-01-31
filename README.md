# UART ReadLine Text Sensor

ESPHome external component for reading line-delimited data from UART.

## Description

This component reads data from a UART interface and publishes complete lines as text sensor updates. Lines are delimited by semicolon (`;`) characters.

## Installation

Add this repository as an external component in your ESPHome configuration:

```yaml
external_components:
  - source:
      type: local
      path: components  # or use git source for remote
```

## Configuration

```yaml
uart:
  id: uart_bus
  tx_pin: GPIO1
  rx_pin: GPIO3
  baud_rate: 9600

text_sensor:
  - platform: uart_readline
    name: "UART Line Data"
    uart_id: uart_bus
```

## Features

- Reads data from UART character by character
- Buffers up to 20 characters per line
- Publishes complete lines when semicolon (`;`) delimiter is received
- Automatically resets buffer after each line

## Configuration Variables

- **name** (*Required*, string): The name of the text sensor
- **uart_id** (*Required*, ID): The ID of the UART component to use
- All other options from [Text Sensor](https://esphome.io/components/text_sensor/index.html#config-text-sensor)

## Example

See [example.yaml](example.yaml) for a complete configuration example.
