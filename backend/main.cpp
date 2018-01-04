#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "json.hh"


int main() {
    srand (time(NULL));

    using json = nlohmann::json;

    unsigned int microseconds = 500000;
    while(true){

        json data = {
                {"x", rand() % 200},
                {"y", rand() % 200},
                {"height", rand() % 200},
                {"width", rand() % 200},
        };

        std::cout << data.dump() << std::flush;

        usleep(microseconds);
    }
}