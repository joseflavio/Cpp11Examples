#include <stdafx.h>

#include <Timer.hpp>
#include <PrintUtils.hpp>

void PerformanceTest() {

    static const size_t MAX_I = 50000;
    static const size_t MAX_J = 2000;
    static const size_t ELEMENT_SIZE = sizeof(uint64_t) + 40; // 20 bytes of container overhead
    std::cout << "Expected memory needed: " << ( ELEMENT_SIZE * MAX_I * MAX_J ) / (1024 * 1024) << " MB" << std::endl;

    std::random_device rd;
    std::default_random_engine generator { rd() };
    std::uniform_int_distribution<uint64_t> distribution;

    Timer t1;
    {
        std::vector<std::set<uint64_t> > v;
        for(size_t i = 0; i < MAX_I; ++i) {
            std::set<uint64_t> set;
            for(size_t j = 0; j < MAX_J; ++j) {
                uint64_t random_number = distribution(generator);
                set.insert(random_number);
            }
            v.push_back(set);
        }
        std::cout << "(construction) t1 elapsed = " << Timer::Elapsed(t1) << std::endl;

        // std::cout << "sleeping..." << std::endl; sleep(10);

        Timer t2;
        std::sort(v.begin(), v.end());
        std::cout << "(sort) t2 elapsed = " << Timer::Elapsed(t2) << std::endl;


        Timer t3;
        std::rotate(v.begin(), (v.begin() + (v.size()/2)), v.end());
        std::cout << "(rotate) t3 elapsed = " << Timer::Elapsed(t3) << std::endl;

        std::cout << "total elapsed = " << Timer::Elapsed(t1) << std::endl;
    }
    std::cout << "total elapsed = " << Timer::Elapsed(t1) << std::endl;

}


int main() {

    INVOKE_METHOD(PerformanceTest());

    return 0;

}

