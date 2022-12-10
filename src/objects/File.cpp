//
// Created by Jan Heil on 09.12.2022.
//

#include "File.h"

namespace objects {
    String File::getName() {
        return nameIO;
    }

    int File::getSize() {
        return sizeIO;
    }

    String File::getEdited() {
        return editedIO;
    }
} // objects