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
                        "'version':'" + String(BYTEUSB_VERSION) + "','buffer':'" + BYTEUSB_BUFFER +
                        "','device':'byteusb','manufacturer':'" +
                        String(CHIP_MANUFACTURER) +
                        "','hardware':'" + CHIP_NAME + "', 'version':'" + BYTEUSB_VERSION + "'");
    }

    /**
     * Return List Paket.
     * @return
     */
    String PaketUtils::list(std::vector<objects::File> filesIO) {
        // Initialize new Document.
        DynamicJsonDocument documentIO(BYTEUSB_BUFFER);

        // Create new JSON Array.
        JsonArray arrayIO = documentIO.to<JsonArray>();

        // Check if Size is not null.
        // Loop trough File Array.
        for (auto fileIO: filesIO) {
            // Create new Nested Object.
            JsonObject objectIO = arrayIO.createNestedObject();

            // Add File Information.
            objectIO["name"] = fileIO.getName();

            // Add Size only for Files.
            if (fileIO.getType() != "1") {
                objectIO["size"] = fileIO.getSize();
            }

            // Set last Edit Date.
            objectIO["edited"] = fileIO.getEdited();

            // Set Type of Directory / File.
            objectIO["type"] = fileIO.getType();
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
        int sizeIO = (int) dataIO.length() + 1;

        // Check if Size is not null.
        if (sizeIO > 0) {
            // Enable Builtin LED.
            digitalWrite(LED_BUILTIN, HIGH);

            // Create new Char Buffer for Data.
            char bufferIO[sizeIO];

            // Write String into Char Array.
            dataIO.toCharArray(bufferIO, sizeIO);

            // Write to Baud.
            Serial.println(bufferIO);

            // Disable Builtin LED.
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}