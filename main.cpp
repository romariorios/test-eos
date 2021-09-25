#include <iostream>
#include <fstream>
#include <string>

#include <boost/serialization/string.hpp>
#include <eos/portable_oarchive.hpp>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <file> <text>\n";
        return -1;
    }

    std::ofstream file{argv[1], std::ios::binary};
    eos::portable_oarchive oa{file};

    oa << std::string{argv[2]};

    return 0;
}
