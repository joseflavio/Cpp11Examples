#include <Rot13Comparison.hpp>

using std::cout;
using std::string;

char rot13(const char c) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 13) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + 13) % 26 + 'A';
    }
    return c;
}

string& convertLine(string &s) {
    for (auto &c : s) {
        c = rot13(c);
    }
    return s;
}

void readLines(std::istream &in, std::ostream &out) {
    string s;
    while (getline(in, s)) {
        out << convertLine(s) << '\n';
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        readLines(std::cin, std::cout);
    } else {
        for (int arg = 1; arg < argc; ++arg) {
            std::ifstream fs { argv[arg] };
            if (!fs) {
                return EXIT_FAILURE;
            }
            readLines(fs, std::cout);
        }
    }
    return EXIT_SUCCESS;
}



