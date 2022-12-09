//
// Created by Jan Heil on 09.12.2022.
//

#ifndef BYTEUSBIC_PAKETUTILS_H
#define BYTEUSBIC_PAKETUTILS_H

#include <api/String.h>
#include <objects/File.h>

namespace paket {
    class PaketUtils {
    public:
        // Generate Hello Command.
        static arduino::String hello();

        // Generate List Command.
        static arduino::String list(objects::File filesIO[]);

        // Generate JSON Command.
        static arduino::String generate(arduino::String channelIO, arduino::String dataIO);

        // Write to Baud.
        static void write(arduino::String hello);
    };
} // paket

#endif //BYTEUSBIC_PAKETUTILS_H
