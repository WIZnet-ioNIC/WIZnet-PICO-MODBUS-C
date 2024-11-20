# Getting Started with Ethernet Examples

These sections will guide you through a series of steps from configuring development environment to running ethernet examples using the **WIZnet's ethernet products**.

- [**Development environment configuration**](#development_environment_configuration)
- [**Hardware requirements**](#hardware_requirements)
- [**Ethernet example structure**](#ethernet_example_structure)
- [**Ethernet example testing**](#ethernet_example_testing)
- [**How to use port directory**](#how_to_use_port_directory)



<a name="development_environment_configuration"></a>
## Development environment configuration

To test the ethernet examples, the development environment must be configured to use Raspberry Pi Pico, W5100S-EVB-Pico, W5500-EVB-Pico, W55RP20-EVB-Pico, W5100S-EVB-Pico2 or W5500-EVB-Pico2.

These examples were tested after configuring the development environment on **Windows**. Please refer to '**Chapter 3: Installing the Raspberry Pi Pico VS Code Extension**' in the document below and configure accordingly.

- [**Getting started with Raspberry Pi Pico**][link-getting_started_with_raspberry_pi_pico]

**Visual Studio Code** was used during development and testing of ethernet examples, the guide document in each directory was prepared also base on development with Visual Studio Code. Please refer to corresponding document.



<a name="hardware_requirements"></a>
## Hardware requirements

The ethernet examples use **Raspberry Pi Pico** and **WIZnet Ethernet HAT** - ethernet I/O module built on WIZnet's [**W5100S**][link-w5100s] ethernet chip, **W5100S-EVB-Pico** - ethernet I/O module built on [**RP2040**][link-rp2040] and WIZnet's [**W5100S**][link-w5100s] ethernet chip,  **W5500-EVB-Pico** and **W55RP20-EVB-Pico** - ethernet I/O module built on [**RP2040**][link-rp2040] and WIZnet's [**W5500**][link-w5500] ethernet chip, **W5100S-EVB-Pico2** - ethernet I/O module built on [**RP2350**][link-rp2350] and WIZnet's [**W5100S**][link-w5100s] ethernet chip or **W5100S-EVB-Pico2** - ethernet I/O module built on [**RP2350**][link-rp2350] and WIZnet's [**W5100S**][link-w5100s] ethernet chip.

- [**Raspberry Pi Pico**][link-raspberry_pi_pico] & [**WIZnet Ethernet HAT**][link-wiznet_ethernet_hat]
- [**W5100S-EVB-Pico**][link-w5100s-evb-pico]
- [**W5500-EVB-Pico**][link-w5500-evb-pico]
- [**W55RP20-EVB-Pico**][link-w55rp20-evb-pico]
- [**W5100S-EVB-Pico2**][link-w5100s-evb-pico2]
- [**W5500-EVB-Pico2**][link-w5500-evb-pico2]

<a name="ethernet_example_structure"></a>
## Ethernet example structure

Examples are available at '**WIZnet-PICO-C/examples/**' directory. As of now, following examples are provided.

- [**DHCP & DNS**][link-dhcp_dns]
- [**FTP**][link-ftp]
	- [**Client**][link-ftp_client]
	- [**Server**][link-ftp_server]
- [**HTTP**][link-http]
	- [**Server**][link-http_server]
- [**Loopback**][link-loopback]
- [**MQTT**][link-mqtt]
	- [**Publish**][link-mqtt_publish]
	- [**Publish & Subscribe**][link-mqtt_publish_subscribe]
	- [**Subscribe**][link-mqtt_subscribe]
- [**SNTP**][link-sntp]
- [**TCP Client over SSL**][link-tcp_client_over_ssl]

Note that **ioLibrary_Driver**, **mbedtls**, **pico-sdk** are needed to run ethernet examples.

- **ioLibrary_Driver** library is applicable to WIZnet's W5x00 ethernet chip.
- **mbedtls** library supports additional algorithms and support related to SSL and TLS connections.
- **pico-sdk** is made available by Pico to enable developers to build software applications for the Pico platform.

Libraries are located in the '**WIZnet-PICO-C/libraries/**' directory.

- [**ioLibrary_Driver**][link-iolibrary_driver]
- [**mbedtls**][link-mbedtls]
- [**pico-sdk**][link-pico_sdk]

If you want to modify the code that MCU-dependent and use a MCU other than **RP2040**, you can modify it in the '**WIZnet-PICO-C/port/**' directory.

port is located in the '**WIZnet-PICO-C/port/**' directory.

- [**ioLibrary_Driver**][link-port_iolibrary_driver]
- [**mbedtls**][link-port_mbedtls]
- [**timer**][link-port_timer]

The structure of this WIZnet-PICO-C 2.0.0 version or higher has changed a lot compared to the previous version. If you want to refer to the previous version, please refer to the link below.

- [**WIZnet-PICO-C 1.0.0 version**][link-wiznet_pico_c_1_0_0_version]



<a name="ethernet_example_testing"></a>
## Ethernet example testing

1. Download

If the ethernet examples are cloned, the library set as a submodule is an empty directory. Therefore, if you want to download the library set as a submodule together, clone the ethernet examples with the following Git command.

```cpp
/* Change directory */
// change to the directory to clone
cd [user path]

// e.g.
cd D:/WIZnet-PICO

/* Clone */
git clone --recurse-submodules https://github.com/Wiznet/WIZnet-PICO-C.git
```

With Visual Studio Code, the library set as a submodule is automatically downloaded, so it doesn't matter whether the library set as a submodule is an empty directory or not, so refer to it.

2. Setup board

Setup the board in '**CMakeLists.txt**' in '**WIZnet-PICO-C/**' directory according to the evaluation board to be used referring to the following.

- WIZnet Ethernet HAT
- W5100S-EVB-Pico
- W5500-EVB-Pico
- W55RP20-EVB-Pico
- W5100S-EVB-Pico2
- W5500-EVB-Pico2

For example, when using WIZnet Ethernet HAT :

```cpp
# Set board
set(BOARD_NAME WIZnet_Ethernet_HAT)
```

When using W5500-EVB-Pico :

```cpp
# Set board
set(BOARD_NAME W5500_EVB_PICO)
```

3. Test

Please refer to 'README.md' in each example directory to find detail guide for testing ethernet examples.


> ※ If the board pauses when rebooting using W55RP20-EVB-Pico, patch it as follows.
>
> ```cpp
> // Patch
> git apply ./patches/0001_pico_sdk_clocks.patch
> ```

<a name="how_to_use_port_directory"></a>
## How to use port directory

We moved the MCU dependent code to the port directory. The tree of port is shown below.

```
WIZnet-PICO-C
┣ port
    ┣ ioLibrary_Driver
    ┃   ┣ inc
    ┃   ┃   ┣ w5x00_gpio_irq.h
    ┃   ┃   ┣ w5x00_spi.h
    ┃   ┃   ┣ wiznet_spi.h
    ┃   ┃   ┗ wiznet_spi_pio.h
    ┃   ┗ src
    ┃   ┃   ┣ w5x00_gpio_irq.c
    ┃   ┃   ┣ w5x00_spi.c
    ┃   ┃   ┣ w5x00_spi_pio.c
    ┃   ┃   ┗ w5x00_spi_pio.pio
    ┣ mbedtls
    ┃   ┗ inc
    ┃   ┃   ┗ ssl_config.h
    ┣ timer
    ┃   ┣ timer.c
    ┃   ┗ timer.h
    ┣ CMakeLists.txt
    ┗ port_common.h
```

- **ioLibrary_Driver**

If you want to change things related to **SPI**, such as the SPI port number and SPI read/write function, or GPIO port number and function related to **interrupt** or use a different MCU without using the RP2040, you need to change the code in the '**WIZnet-PICO-C/port/ioLibrary_Driver/**' directory. Here is information about functions.

```cpp
/* W5x00 */
/*! \brief Set CS pin
 *  \ingroup w5x00_spi
 *
 *  Set chip select pin of spi0 to low(Active low).
 *
 *  \param none
 */
static inline void wizchip_select(void);

/*! \brief Set CS pin
 *  \ingroup w5x00_spi
 *
 *  Set chip select pin of spi0 to high(Inactive high).
 *
 *  \param none
 */
static inline void wizchip_deselect(void);

/*! \brief Read from an SPI device, blocking
 *  \ingroup w5x00_spi
 *
 *  Set spi_read_blocking function.
 *  Read byte from SPI to rx_data buffer.
 *  Blocks until all data is transferred. No timeout, as SPI hardware always transfers at a known data rate.
 *
 *  \param none
 */
static uint8_t wizchip_read(void);

/*! \brief Write to an SPI device, blocking
 *  \ingroup w5x00_spi
 *
 *  Set spi_write_blocking function.
 *  Write byte from tx_data buffer to SPI device.
 *  Blocks until all data is transferred. No timeout, as SPI hardware always transfers at a known data rate.
 *
 *  \param tx_data Buffer of data to write
 */
static void wizchip_write(uint8_t tx_data);

#ifdef USE_SPI_DMA
/*! \brief Configure all DMA parameters and optionally start transfer
 *  \ingroup w5x00_spi
 *
 *  Configure all DMA parameters and read from DMA
 *
 *  \param pBuf Buffer of data to read
 *  \param len element count (each element is of size transfer_data_size)
 */
static void wizchip_read_burst(uint8_t *pBuf, uint16_t len);

/*! \brief Configure all DMA parameters and optionally start transfer
 *  \ingroup w5x00_spi
 *
 *  Configure all DMA parameters and write to DMA
 *
 *  \param pBuf Buffer of data to write
 *  \param len element count (each element is of size transfer_data_size)
 */
static void wizchip_write_burst(uint8_t *pBuf, uint16_t len);
#endif

/*! \brief Enter a critical section
 *  \ingroup w5x00_spi
 *
 *  Set ciritical section enter blocking function.
 *  If the spin lock associated with this critical section is in use, then this
 *  method will block until it is released.
 *
 *  \param none
 */
static void wizchip_critical_section_lock(void);

/*! \brief Release a critical section
 *  \ingroup w5x00_spi
 *
 *  Set ciritical section exit function.
 *  Release a critical section.
 *
 *  \param none
 */
static void wizchip_critical_section_unlock(void);

/*! \brief Initialize SPI instances and Set DMA channel
 *  \ingroup w5x00_spi
 *
 *  Set GPIO to spi0.
 *  Puts the SPI into a known state, and enable it.
 *  Set DMA channel completion channel.
 *
 *  \param none
 */
void wizchip_spi_initialize(void);

/*! \brief Initialize a critical section structure
 *  \ingroup w5x00_spi
 *
 *  The critical section is initialized ready for use.
 *  Registers callback function for critical section for WIZchip.
 *
 *  \param none
 */
void wizchip_cris_initialize(void);

/*! \brief W5x00 chip reset
 *  \ingroup w5x00_spi
 *
 *  Set a reset pin and reset.
 *
 *  \param none
 */
void wizchip_reset(void);

/*! \brief Initialize WIZchip
 *  \ingroup w5x00_spi
 *
 *  Set callback function to read/write byte using SPI.
 *  Set callback function for WIZchip select/deselect.
 *  Set memory size of W5x00 chip and monitor PHY link status.
 *
 *  \param none
 */
void wizchip_initialize(void);

/*! \brief Check chip version
 *  \ingroup w5x00_spi
 *
 *  Get version information.
 *
 *  \param none
 */
void wizchip_check(void);

/* Network */
/*! \brief Initialize network
 *  \ingroup w5x00_spi
 *
 *  Set network information.
 *
 *  \param net_info network information.
 */
void network_initialize(wiz_NetInfo net_info);

/*! \brief Print network information
 *  \ingroup w5x00_spi
 *
 *  Print network information about MAC address, IP address, Subnet mask, Gateway, DHCP and DNS address.
 *
 *  \param net_info network information.
 */
void print_network_information(wiz_NetInfo net_info);
```

```cpp
/* GPIO */
/*! \brief Initialize w5x00 gpio interrupt callback function
 *  \ingroup w5x00_gpio_irq
 *
 *  Add a w5x00 interrupt callback.
 *
 *  \param socket socket number
 *  \param callback the gpio interrupt callback function
 */
void wizchip_gpio_interrupt_initialize(uint8_t socket, void (*callback)(void));

/*! \brief Assign gpio interrupt callback function
 *  \ingroup w5x00_gpio_irq
 *
 *  GPIO interrupt callback function.
 *
 *  \param gpio Which GPIO caused this interrupt
 *  \param events Which events caused this interrupt. See \ref gpio_set_irq_enabled for details.
 */
static void wizchip_gpio_interrupt_callback(uint gpio, uint32_t events);
```

- **timer**

If you want to change things related to the **timer**. Also, if you use a different MCU without using the RP2040, you need to change the code in the '**WIZnet-PICO-C/port/timer/**' directory. Here is information about functions.

```cpp
/* Timer */
/*! \brief Initialize timer callback function
 *  \ingroup timer
 *
 *  Add a repeating timer that is called repeatedly at the specified interval in microseconds.
 *
 *  \param callback the repeating timer callback function
 */
void wizchip_1ms_timer_initialize(void (*callback)(void));

/*! \brief Assign timer callback function
 *  \ingroup timer
 *
 *  1ms timer callback function.
 *
 *  \param t Information about a repeating timer
 */
bool wizchip_1ms_timer_callback(struct repeating_timer *t);

/* Delay */
/*! \brief Wait for the given number of milliseconds before returning
 *  \ingroup timer
 *
 *  This method attempts to perform a lower power sleep (using WFE) as much as possible.
 *
 *  \param ms the number of milliseconds to sleep
 */
void wizchip_delay_ms(uint32_t ms);
```



<!--
Link
-->

[link-getting_started_with_raspberry_pi_pico]: https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf
[link-rp2040]: https://www.raspberrypi.org/products/rp2040/
[link-rp2350]: https://www.raspberrypi.com/products/rp2350/
[link-w5100s]: https://docs.wiznet.io/Product/iEthernet/W5100S/overview
[link-w5500]: https://docs.wiznet.io/Product/iEthernet/W5500/overview
[link-w55rp20-evb-pico]: https://docs.wiznet.io/Product/ioNIC/W55RP20/w55rp20-evb-pico#overview
[link-raspberry_pi_pico]: https://www.raspberrypi.org/products/raspberry-pi-pico/getting_started/raspberry_pi_pico_main.png
[link-wiznet_ethernet_hat]: https://docs.wiznet.io/Product/Open-Source-Hardware/wiznet_ethernet_hat
[link-w5100s-evb-pico]: https://docs.wiznet.io/Product/iEthernet/W5100S/w5100s-evb-pico
[link-w5500-evb-pico]: https://docs.wiznet.io/Product/iEthernet/W5500/w5500-evb-pico
[link-dhcp_dns]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/dhcp_dns
[link-ftp]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/ftp
[link-ftp_client]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/ftp/client
[link-ftp_server]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/ftp/server
[link-http]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/http
[link-http_server]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/http/server
[link-loopback]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/loopback
[link-mqtt]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/mqtt
[link-mqtt_publish]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/mqtt/publish
[link-mqtt_publish_subscribe]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/mqtt/publish_subscribe
[link-mqtt_subscribe]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/mqtt/subscribe
[link-sntp]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/sntp
[link-tcp_client_over_ssl]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/examples/tcp_client_over_ssl
[link-iolibrary_driver]: https://github.com/Wiznet/ioLibrary_Driver
[link-mbedtls]: https://github.com/ARMmbed/mbedtls
[link-pico_sdk]: https://github.com/raspberrypi/pico-sdk
[link-port_iolibrary_driver]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/port/ioLibrary_Driver
[link-port_mbedtls]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/port/mbedtls
[link-port_timer]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/main/port/timer
[link-wiznet_pico_c_1_0_0_version]: https://github.com/WIZnet-ioNIC/WIZnet-PICO-C/tree/1.0.0
[link-w5100s-evb-pico2]: https://docs.wiznet.io/Product/iEthernet/W5100S/w5100s-evb-pico2
[link-w5500-evb-pico2]: https://docs.wiznet.io/Product/iEthernet/W5500/w5500-evb-pico2
