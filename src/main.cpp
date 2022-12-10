//
// Created by Jan Heil on 09.12.2022.
//

// Include Arduino Framework SDK.
#include <Arduino.h>

// Include Config Class.
#include <objects/Config.h>

// Include Paket Utils for parsing and compiling Pakets.
#include <paket/PaketUtils.h>

// Include USB Utils for connecting to CH376S.
#include <data/USBUtils.h>

// Store last read Byte.
int byteIO = 0;

void setupOutput();

// Store current USB Util Class.
data::USBUtils currentIO = *new data::USBUtils();

/**
 * Call when IC is starting.
 */
void setup() {
    // Setup Baud Stream.
    Serial.begin(BAUD_RATE);

    // Setup GPIO.
    setupOutput();

    // Connect to USB Driver.
    currentIO.connect();
}


/**
 * Call every Loop of IC.
 */
void loop() {
    // Loop for USB Driver Functions.
    currentIO.loop();

    // Check if Data is available.
    if (Serial.available()) {
        // Read incoming Byte.
        byteIO = Serial.read();
    }

    // Send Hello Command.
    paket::PaketUtils::write(paket::PaketUtils::hello());

    std::vector<objects::File> filesIO = {
            *new objects::File("test.txt", 1, "10.12.2022", objects::FileType::FILE),
            *new objects::File("discord.txt", 100, "09.12.2022", objects::FileType::FILE),
            *new objects::File("alibert", 0, "01.11.2023", objects::FileType::DIR)};

    paket::PaketUtils::write(paket::PaketUtils::list(filesIO));

    // Wait for 1000 milliseconds (!! save Thread usage !!).
    delay(1000);
}

/**
 * Setup GPIO Output Pins.
 */
void setupOutput() {
    // Setup Builtin LED as Output for IC.
    pinMode(LED_BUILTIN, OUTPUT);
}
