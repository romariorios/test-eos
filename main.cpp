#include <iostream>
#include <fstream>
#include <string>

#include <boost/serialization/string.hpp>
#include <eos/portable_iarchive.hpp>
#include <eos/portable_oarchive.hpp>

[[noreturn]]
void usage(const char* exec) {
    std::cerr << "Usage:\n"
              << "  " << exec << " write <file> <text>\n"
              << "  " << exec << " read <file>\n";
    exit(-1);
}

int main(int argc, char* argv[]) {
    if (argc != 3 && argc != 4)
        usage(argv[0]);

    std::string op = argv[1];
    auto filename = argv[2];

    if (op != "write" && op != "read")
        usage(argv[0]);

    if (op == "write") {
        std::string text = argv[3];

        std::ofstream file{filename, std::ios::binary};
        eos::portable_oarchive oa{file};

        oa << text;
    } else {
        std::ifstream file{filename, std::ios::binary};
        eos::portable_iarchive ia{file};

        std::string text;
        ia >> text;

        std::cout << text << "\n";
    }

    return 0;
}
