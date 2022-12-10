//
// Created by Jan Heil on 09.12.2022.
//

#include "PaketUtils.h"
#include "Arduino.h"
#include "ArduinoJson.h"
#include "objects/Config.h"

namespace paket {
    /**
     * Return Hello Paket (Device Name, IC Manufacturer, IC Hardware, Version).
     * @return
     */
    String PaketUtils::hello() {
        return generate("hello",
                        "'version':'1.0.10','device':'byteusb','manufacturer':'" + String(CHIP_MANUFACTURER) +
                        "','hardware':'" + CHIP_NAME + "', 'version':'" + BYTEUSB_VERSION + "'");
    }

    /**
     * Return List Paket.
     * @return
     */
    String PaketUtils::list(objects::File filesIO[]) {
        // Initialize new Document.
        DynamicJsonDocument documentIO(1024);

        // Create new JSON Array.
        JsonArray arrayIO = documentIO.to<JsonArray>();

        // Calculate Size of Data.
        int sizeIO = sizeof(filesIO);

        // Check if Size is not null.
        if (sizeIO > 0) {
            // Loop trough File Array.
            for (int countIO = 0; countIO < sizeIO; countIO++) {

                // Get File Object from Array.
                objects::File fileIO = filesIO[countIO];

                // Create new Nested Object.
                JsonObject objectIO = arrayIO.createNestedObject();

                // Add File Information.
                objectIO["name"] = fileIO.getName();
                objectIO["size"] = fileIO.getSize();
                objectIO["edited"] = fileIO.getEdited();
            }

        }

        // Create new String Buffer.
        String bufferIO;

        // Serialize JSON Array.
        serializeJson(arrayIO, bufferIO);

        // Generate List Paket.
        return generate("list", "'files':" + bufferIO);
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
        // Calculate Size of Data.
        int sizeIO = (int) dataIO.length();

        // Check if Size is not null.
        if (sizeIO > 0) {
            // Create new Char Buffer for Data.
            char bufferIO[sizeIO];

            // Write String into Char Array.
            dataIO.toCharArray(bufferIO, dataIO.length());

            // Write to Baud.
            Serial.println(bufferIO);
        }
    }
}