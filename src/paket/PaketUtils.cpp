//
// Created by Jan Heil on 09.12.2022.
//

#include "PaketUtils.h"
#include "Arduino.h"

namespace paket {
    /**
     * Return Hello Paket.
     * @return
     */
    String PaketUtils::hello() {
        return generate("hello", "'version':'1.0.10','device':'byteusb','hardware':'pico'");
    }

    /**
     * Return List Paket.
     * @return
     */
    String PaketUtils::list(objects::File filesIO[]) {
        return generate("list", "");
    }

    /**
     * Generate JSON Paket.
     * @param channelIO
     * @param dataIO
     * @return
     */
    String PaketUtils::generate(String channelIO, String dataIO) {
        return (String) "{'cmd':'" + channelIO + "','data':{" + dataIO + "}}";
    }

    /**
     * Write to Serial Baud.
     * @param dataIO
     */
    void PaketUtils::write(arduino::String dataIO) {
        // Create new Char Buffer for Data.
        char bufferIO[dataIO.length()];

        // Write String into Char Array.
        dataIO.toCharArray(bufferIO, dataIO.length());

        // Write to Baud.
        Serial.write(bufferIO);
    }
}