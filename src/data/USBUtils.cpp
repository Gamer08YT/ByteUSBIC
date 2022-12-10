//
// Created by Jan Heil on 10.12.2022.
//

#include "USBUtils.h"
#include "Ch376msc.h"
#include "objects/Config.h"
#include "paket/PaketUtils.h"

namespace data {

    /**
     * Connect to Ch376S via SPI.
     */
    void USBUtils::connect() {
        // Initialize Ch376msc Library.
        USBUtils::driverIO = Ch376msc(CHIP_MISO);

        // Init Driver.
        USBUtils::driverIO.init();
    }

    void USBUtils::loop() {
        // Write USB Paket.
        paket::PaketUtils::write(paket::PaketUtils::usb(driverIO.getFreeSectors()), driverIO.get);
    }

    /**
     * Set Path of USB URI.
     * @param pathIO
     */
    void USBUtils::setPath(arduino::String pathIO) {

        // Create new Char Buffer for Data.
        char bufferIO[pathIO.length() + 1];

        // Write String into Char Array.
        pathIO.toCharArray(bufferIO, pathIO.length() + 1);

        // Set File Name via Char Buffer.
        driverIO.setFileName(bufferIO);
    }

    /**
     * List Files inside URI Path.
     * @param pathIO
     * @return
     */
    std::vector<objects::File> USBUtils::listFiles(arduino::String pathIO) {
        // Init new Vector Based Object Buffer.
        std::vector<objects::File> bufferIO;

        // Set new Path.
        this->setPath(pathIO);

        // Loop trough Files / Directories in Path.
        while (driverIO.listDir()) {
            // Create new File Object.
            objects::File fileIO = *new objects::File(driverIO.getFileName(), driverIO.getFileSize(),
                                                      String(driverIO.getDay()),
                                                      this->getType());

            // Append File Object into Vector.
            bufferIO.insert(bufferIO.begin(), fileIO);
        }

        return bufferIO;
    }

    /**
     * Get FileType by current Driver File.
     * @return
     */
    objects::FileType USBUtils::getType() {
        if (driverIO.getFileAttrb() == CH376_ATTR_DIRECTORY) {
            return objects::DIR;
        }

        return objects::FILE;
    }
} // data