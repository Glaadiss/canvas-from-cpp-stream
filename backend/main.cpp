#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "json.hh"

int main()
{
    srand(time(NULL));

    using json = nlohmann::json;

    unsigned int second = 1000000;

    json newAnimal = {
        {"eventName", "newAnimal"},
        {
            "eventData",
            {
                {"name", "Burek"},
                {"type", "dog"},
                {"x", rand() % 200},
                {"y", rand() % 200},
            },
        },
    };

    std::cout << newAnimal.dump() << std::flush;

    usleep(2 * second); // program must sleep a moment, before you can do anotother cout (there are some weird problems with parsing json... try yourself!)

    newAnimal = {
        {"eventName", "newAnimal"},
        {
            "eventData",
            {
                {"name", "Mruczek"},
                {"type", "kot"},
                {"x", rand() % 200},
                {"y", rand() % 200},
            },
        },
    };

    std::cout << newAnimal.dump() << std::flush;

    usleep(2 * second); // program must sleep a moment, before you can do anotother cout (there are some weird problems with parsing json... try yourself!)

    // WORKING!!!
    json move;

    while (true)
    {
        move = {
            {"eventName", "move"},
            {
                "eventData",
                {
                    {"name", "Mruczek"},
                    {"x", rand() % 200},
                    {"y", rand() % 200},
                },
            },
        };

        std::cout << move.dump() << std::flush;

        usleep(2 * second); // program must sleep a moment, before you can do anotother cout (there are some weird problems with parsing json... try yourself!)
    }

    /*  unsigned int microseconds = 500000;
    while (true)
    {

        json data = {
            {"x", rand() % 200},
            {"y", rand() % 200},
            {"height", rand() % 200},
            {"width", rand() % 200},
        };

        std::cout << data.dump() << std::flush;

        usleep(microseconds);
    } */
}