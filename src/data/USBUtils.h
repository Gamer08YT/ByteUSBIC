//
// Created by Jan Heil on 10.12.2022.
//

#ifndef BYTEUSBIC_USBUTILS_H
#define BYTEUSBIC_USBUTILS_H

#include "Ch376msc.h"
#include "vector"
#include "objects/File.h"

namespace data {

    class USBUtils {
    private:
        // Store Driver Lib.
        Ch376msc driverIO;

        /**
        * Get FileType by current Driver File.
        * @return
        */
        objects::FileType getType();

    public:
        // Connect to CH376S via SPI.
        void connect();

        // Loop Function for USB.
        void loop();

        /**
        * Set Path of USB URI.
        * @param pathIO
        */
        void setPath(arduino::String pathIO);

        /**
         * List Files inside URI Path.
         * @param pathIO
         * @return
         */
        std::vector<objects::File> listFiles(arduino::String pathIO);

        USBUtils();
    };

} // data

#endif //BYTEUSBIC_USBUTILS_H
