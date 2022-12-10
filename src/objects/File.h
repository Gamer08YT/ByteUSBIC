//
// Created by Jan Heil on 09.12.2022.
//

#ifndef BYTEUSBIC_FILE_H
#define BYTEUSBIC_FILE_H

#include "api/String.h"
#include "File.h"


namespace objects {

    enum FileType {
        FILE, DIR
    };

    class File {
    private:
        // Store Name of File.
        String nameIO;

        // Store Size of File.
        int sizeIO;

        // Store last Edit Date of File.
        String editedIO;

        // Store Type of File.
        FileType typeIO;

    public:
        File(String nameIO, int sizeIO, String editedIO, FileType typeIO) {
            this->nameIO = nameIO;
            this->sizeIO = sizeIO;
            this->editedIO = editedIO;
            this->typeIO = typeIO;
        }

        String getName();

        int getSize();

        String getEdited();

        String getType();
    };

} // objects

#endif //BYTEUSBIC_FILE_H
