//
// Created by Jan Heil on 09.12.2022.
//

#ifndef BYTEUSBIC_FILE_H
#define BYTEUSBIC_FILE_H

namespace objects {

    class File {
    private:
        // Store Name of File.
        char *nameIO;

        // Store Size of File.
        int sizeIO;

        // Store last Edit Date of File.
        char *editedIO;

    public:
        File(char *nameIO, int sizeIO, char *editedIO) {
            this->nameIO = nameIO;
            this->sizeIO = sizeIO;
            this->editedIO = editedIO;
        }

        char *getName() const;

        int getSize() const;

        char *getEdited() const;
    };

} // objects

#endif //BYTEUSBIC_FILE_H
