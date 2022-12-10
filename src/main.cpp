//
// Created by Jan Heil on 09.12.2022.
//

// Include Arduino Framework SDK.
#include <Arduino.h>

// Include Config Class.
#include "objects/Config.h";

// Include Paket Utils for parsing and compiling Pakets.
#include <paket/PaketUtils.h>

// Store last read Byte.
int byteIO = 0;

/**
 * Call when IC is starting.
 */
void setup() {
    // Setup Baud Stream.
    Serial.begin(objects::Config::getBaud());
}

/**
 * Call every Loop of IC.
 */
void loop() {
    // Check if Data is available.
    if (Serial.available()) {
        // Read incoming Byte.
        byteIO = Serial.read();
    }

    // Send Hello Command.
    paket::PaketUtils::write(paket::PaketUtils::hello());

    // Wait for 200 milliseconds (!! save Thread usage !!).
    delay(200);
}
