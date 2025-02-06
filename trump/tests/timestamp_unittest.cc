/*
 * @Author: Mass
 * @Date: 2022-07-11 01:16:40
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-13 00:39:20
 * @FilePath: /trump/tests/timestamp_unittest.cc
 */

#include <time/Timestamp.hpp>

#include <iostream>
#include <vector>

#include <sys/time.h>

using Trump::Timestamp;

void passbyValue(Timestamp x) {
    std::cout << "Pass by value : " 
        << x.toString() << " " << x.formatString() << std::endl;
}

void passByconstReference(const Timestamp& time) {
    std::cout << "Pass by const ref : " 
        << time.toString() << " " << time.formatString() << std::endl;
}

void benchmark() {
    const int kNumber {1000 * 1000};
    std::vector<Timestamp> stamps {};

    stamps.reserve(kNumber);
    for(int i = 0; i < kNumber; i++) {
        stamps.emplace_back(Timestamp::now());
    }
    std::cout << stamps.front().toString() << std::endl;
    std::cout << stamps.back().toString() << std::endl;
    std::cout << timeDifference(stamps.back(), stamps.front());

    std::vector<int> increments(100, 0);
    auto start { stamps.front().microSecondsSinceEpoch() };
    for (size_t i = 1; i < kNumber; ++i) {
        auto next { stamps[ i ].microSecondsSinceEpoch() };
        int64_t inc { next - start };
        start = next;
        if (inc < 0) {
            std::cout << "reverse!" << std::endl;
        }
        else if (inc < 100) {
            ++increments[inc];
        } else {
            std::cout << "big gap" << static_cast<int>(inc) << std::endl;
        }
    }
    for (int i = 0; i < 100; ++i) {
        std::cout << i <<  " : " << increments[i] <<std::endl;
    }
}

int main( void )
{
    auto now { Timestamp::now() };
    std::cout << now.toString() << '\n';
    std::cout << now.formatString( false ) << '\n';
    std::cout << ( now + 3.0 ).formatString() << '\n';
    std::cout << addTime( now, 3 ).formatString() << '\n';

    passbyValue( now );
    passByconstReference( now );

    benchmark();

    return 0;
}