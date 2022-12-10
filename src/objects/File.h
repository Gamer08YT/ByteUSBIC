//
// Created by Jan Heil on 09.12.2022.
//

#ifndef BYTEUSBIC_FILE_H
#define BYTEUSBIC_FILE_H

#include "api/String.h"

namespace objects {

    class File {
    private:
        // Store Name of File.
        String nameIO;

        // Store Size of File.
        int sizeIO;

        // Store last Edit Date of File.
        String editedIO;

    public:
        File(String nameIO, int sizeIO, String editedIO) {
            this->nameIO = nameIO;
            this->sizeIO = sizeIO;
            this->editedIO = editedIO;
        }

        String getName();

        int getSize();

        String getEdited();
    };

} // objects

#endif //BYTEUSBIC_FILE_H
