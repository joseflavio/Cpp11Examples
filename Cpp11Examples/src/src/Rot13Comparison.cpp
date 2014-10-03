#include <Rot13Comparison.hpp>

using namespace std;

char rot13(const char c) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 13) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + 13) % 26 + 'A';
    }
    return c;
}

string &convertLine(string &s) {
    for (auto &c : s) {
        c = rot13(c);
    }
    return s;
}

void readLines(istream &in, ostream &out) {
    string s;
    while (getline(in, s)) {
        out << convertLine(s) << '\n';
    }
}

int Rot13ExampleMain(int argc, char *argv[]) {
    if (argc == 1) {
        readLines(cin, cout);
    } else {
        for (int arg = 1; arg < argc; ++arg) {
            ifstream fs { argv[arg] };
            if (!fs) {
                return EXIT_FAILURE;
            }
            readLines(fs, cout);
        }
    }
    return EXIT_SUCCESS;
}



