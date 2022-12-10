//
// Created by Jan Heil on 10.12.2022.
//

#ifndef BYTEUSBIC_CONFIG_H
#define BYTEUSBIC_CONFIG_H


// Define Hardware.
#define CHIP_NAME "pico"
#define CHIP_MANUFACTURER "raspberry"

// Define SPI (MISO used as interrupt).
#define CHIP_MISO 10

// Define Baud.
#define BAUD_RATE 115200

// Define Software.
#define BYTEUSB_VERSION  "1.10.0"
#define BYTEUSB_BUFFER 1024

#endif //BYTEUSBIC_CONFIG_H
