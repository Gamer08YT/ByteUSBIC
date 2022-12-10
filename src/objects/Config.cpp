//
// Created by Jan Heil on 10.12.2022.
//

#include "Config.h"

namespace objects {
    Config::~Config() {
        this->baudIO = 115200;
        this->chipIO = "pico";
        this->manufacturerIO = "raspberry";
        this->versionIO = "1.10.0";
    }

    int Config::getBaud() {
        return baudIO;
    }

    const String &Config::getManufacturer() {
        return manufacturerIO;
    }

    const String &Config::getChip() {
        return chipIO;
    }

    const String &Config::getVersion() {
        return versionIO;
    }
}
