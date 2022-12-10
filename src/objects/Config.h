//
// Created by Jan Heil on 10.12.2022.
//

#ifndef BYTEUSBIC_CONFIG_H
#define BYTEUSBIC_CONFIG_H

#include "api/String.h"

namespace objects {

    class Config {
    public:
        static int getBaud();

        static const String &getManufacturer();

        static const String &getChip();

        static const String &getVersion();

        virtual ~Config();

    public:
        // Store UART Baud Rate.
        static int baudIO;

        // Store Manufacturer of Chip.
        static String manufacturerIO;

        // Store Chip Name.
        static String chipIO;

        // Store Version of ByteUSBIC.
        static String versionIO;
    };
};

#endif //BYTEUSBIC_CONFIG_H
