//
// Created by Jan Heil on 09.12.2022.
//

#include "File.h"

namespace objects {
    char *File::getName() const {
        return nameIO;
    }

    int File::getSize() const {
        return sizeIO;
    }

    char *File::getEdited() const {
        return editedIO;
    }
} // objects