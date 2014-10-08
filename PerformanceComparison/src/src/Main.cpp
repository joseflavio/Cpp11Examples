#include <stdafx.h>

#include <Timer.hpp>
#include <PrintUtils.hpp>


class MyRandom {

    //    std::random_device rd;
    //    std::default_random_engine generator { rd() };
    //    std::uniform_int_distribution<uint64_t> distribution;

    // uint64_t generate() {
    //    return distribution(generator);
    // }

public:

    MyRandom() {
        srand(time(NULL));
    }

    uint64_t generate() {
        uint64_t hh = ((uint64_t) random() << 48) & 0xFFFF000000000000ull;
        uint64_t hl = ((uint64_t) random() << 32) & 0x0000FFFF00000000ull;
        uint64_t lh = ((uint64_t) random() << 16) & 0x00000000FFFF0000ull;
        uint64_t ll = ((uint64_t) random()) & 0x000000000000FFFFull;
        return hh | hl | lh | ll;
    }

};

void PerformanceTest() {

    static const size_t MAX_I = 50000;
    static const size_t MAX_J = 1500;
    static const size_t ELEMENT_SIZE = sizeof(uint64_t) + 40; // 20 bytes of container overhead
    std::cout << "Expected memory needed: "
            << (ELEMENT_SIZE * MAX_I * MAX_J) / (1024 * 1024) << " MB\n";

    MyRandom rnd;

    Timer t1;
    {
        std::vector<std::set<uint64_t> > v;
        for (size_t i = 0; i < MAX_I; ++i) {
            std::set<uint64_t> set;
            for (size_t j = 0; j < MAX_J; ++j) {
                const uint64_t random_number = rnd.generate();
                // std::bitset<64> bs(random_number); std::cout << random_number << " : " << bs << std::endl;
                set.insert(random_number);
            }
            v.push_back(set);
        }
        std::cout << "(construction) elapsed = " << Timer::Elapsed(t1) << "\n";

        // std::cout << "sleeping..." << std::endl; sleep(10);

        Timer t2;
        std::sort(v.begin(), v.end());
        std::cout << "(sort) t2 elapsed = " << Timer::Elapsed(t2) << "\n";

        Timer t3;
        std::rotate(v.begin(), (v.begin() + (v.size() / 2)), v.end());
        std::cout << "(rotate) t3 elapsed = " << Timer::Elapsed(t3) << "\n";

        std::cout << "total elapsed = " << Timer::Elapsed(t1) << "\n";
    }
    std::cout << "total elapsed = " << Timer::Elapsed(t1) << "\n";

}

int main() {

    INVOKE_METHOD(PerformanceTest());

    return 0;

}

