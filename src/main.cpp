//
// Created by Jan Heil on 09.12.2022.
//

// Include Arduino Framework SDK.
#include <Arduino.h>

// Include Paket Utils for parsing and compiling Pakets.
#include <paket/PaketUtils.h>

// Store UART Baud Rate.
int baudIO = 115200;

// Store Manufacturer of Chip.
String manufacturerIO = "raspberry";

// Store Chip Name.
String chipIO = "pico";

// Store Version of ByteUSBIC.
String versionIO = "1.0.10";

// Store last read Byte.
int byteIO = 0;

/**
 * Call when IC is starting.
 */
void setup() {
    // Setup Baud Stream.
    Serial.begin(baudIO);
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
    Serial.write(paket::PaketUtils::hello().c_str());

    // Wait for 200 milliseconds (!! save Thread usage !!).
    delay(200);
}
