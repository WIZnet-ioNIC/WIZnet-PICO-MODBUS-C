# How to Test MODBUS Example



## Step 1: Prepare software

The following serial terminal program and Modbus poll are required for MODBUS example test, download and install from below link.

- [**Tera Term**][link-tera_term]
- [**Modbus Poll**][link-modbus_poll]



## Step 2: Prepare hardware

If you are using W5100S-EVB-Pico, W5500-EVB-Pico, W55RP20-EVB-Pico, W5100S-EVB-Pico2 or W5500-EVB-Pico2, you can skip '1. Combine...'

1. Combine WIZnet Ethernet HAT with Raspberry Pi Pico.

2. Connect ethernet cable to WIZnet Ethernet HAT, W5100S-EVB-Pico, W5500-EVB-Pico, W55RP20-EVB-Pico, W5100S-EVB-Pico2 or W5500-EVB-Pico2 ethernet port.

3. Connect Raspberry Pi Pico, W5100S-EVB-Pico or W5500-EVB-Pico to desktop or laptop using 5 pin micro USB cable. W55RP20-EVB-Pico, W5100S-EVB-Pico2 or W5500-EVB-Pico2 require a USB Type-C cable.



## Step 3: Setup MODBUS Example

To test the MODBUS example, minor settings shall be done in code.

1. Setup SPI port and pin in 'w5x00_spi.h' in 'WIZnet-PICO-C/port/ioLibrary_Driver/' directory.

Setup the SPI interface you use.
- If you use the W5100S-EVB-Pico, W5500-EVB-Pico, W5100S-EVB-Pico2 or W5500-EVB-Pico2,

```cpp
/* SPI */
#define SPI_PORT spi0

#define PIN_SCK 18
#define PIN_MOSI 19
#define PIN_MISO 16
#define PIN_CS 17
#define PIN_RST 20
```

If you want to test with the MODBUS example using SPI DMA, uncomment USE_SPI_DMA.

```cpp
/* Use SPI DMA */
//#define USE_SPI_DMA // if you want to use SPI DMA, uncomment.
```
- If you use the W55RP20-EVB-Pico,
```cpp
/* SPI */
#define USE_SPI_PIO

#define PIN_SCK 21
#define PIN_MOSI 23
#define PIN_MISO 22
#define PIN_CS 20
#define PIN_RST 25
```

2. Setup network configuration such as IP in 'w5x00_modbus.c' which is the MODBUS example in 'WIZnet-PICO-C/examples/modbus/' directory.

Setup IP and other network settings to suit your network environment.

```cpp
/* Network */
static wiz_NetInfo g_net_info =
    {
        .mac = {0x00, 0x08, 0xDC, 0x12, 0x34, 0x56}, // MAC address
        .ip = {192, 168, 11, 2},                     // IP address
        .sn = {255, 255, 255, 0},                    // Subnet Mask
        .gw = {192, 168, 11, 1},                     // Gateway
        .dns = {8, 8, 8, 8},                         // DNS server
        .dhcp = NETINFO_STATIC                       // DHCP enable/disable
};
```

3. Setup MODBUS configuration in 'w5x00_modbus.c' in 'WIZnet-PICO-C/examples/modbus/' directory.

Setup local port.

```cpp
uint16_t local_port = 8000;   // Local port
```

## Step 4: Setup MODBUS Poll

1. In the Modbus poll connection setup, set the connection to Modbus TCP/IP. Configure the IP and port of the remote Modbus server.

![][link-connection_setup]

2. In the Read/Write Definition setup, set the function to 05 Write Single Coil. Configure the address to 1.

![][link-read_write_definition_setup]

## Step 5: Build

1. After completing the MODBUS example configuration, click 'build' in the status bar at the bottom of Visual Studio Code or press the 'F7' button on the keyboard to build.

2. When the build is completed, 'w5x00_modbus.uf2' is generated in 'WIZnet-PICO-C/build/examples/modbus/' directory.



## Step 6: Upload and Run

1. While pressing the BOOTSEL button of Raspberry Pi Pico, W5100S-EVB-Pico, W5500-EVB-Pico, W55RP20-EVB-Pico, W5100S-EVB-Pico2 or W5500-EVB-Pico2 power on the board, the USB mass storage 'RPI-RP2' is automatically mounted.

![][link-raspberry_pi_pico_usb_mass_storage]

2. Drag and drop 'w5x00_modbus.uf2' onto the USB mass storage device 'RPI-RP2'.

3. Connect to the serial COM port of Raspberry Pi Pico, W5100S-EVB-Pico, W5500-EVB-Pico, W55RP20-EVB-Pico, W5100S-EVB-Pico2 or W5500-EVB-Pico2 with Tera Term.

![][link-connect_to_serial_com_port]

4. Reset your board.

5. If the MODBUS example works normally on Raspberry Pi Pico, W5100S-EVB-Pico, W5500-EVB-Pico, W55RP20-EVB-Pico, W5100S-EVB-Pico2 or W5500-EVB-Pico2, you can see the network information and user led status. In Modbus Poll, you can press '0', '1', or space to toggle the value and change the status of the user LED.

![][link-modbus_poll_and_tera_term]


<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-modbus_poll]: https://www.modbustools.com/download.html
[link-connection_setup]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-MODBUS-C/blob/main/static/images/modbus/connection_setup.png
[link-read_write_definition_setup]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-MODBUS-C/blob/main/static/images/modbus/read_write_definition_setup.png
[link-raspberry_pi_pico_usb_mass_storage]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/blob/main/static/images/sntp/raspberry_pi_pico_usb_mass_storage.png
[link-connect_to_serial_com_port]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/blob/main/static/images/sntp/connect_to_serial_com_port.png
[link-modbus_poll_and_tera_term]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-MODBUS-C/blob/main/static/images/modbus/modbus_poll_and_tera_term.png
