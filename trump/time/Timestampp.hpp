/*
 * @Author: Mass
 * @Date: 2023-09-21 09:56:47
 * @LastEditors: Mass
 * @LastEditTime: 2023-09-21 10:21:48
 * @FilePath: /Trump/trump/time/Timestampp.hpp
 */

#ifndef TRUMP_BASE_TIMESTAMPP_HPP
#define TRUMP_BASE_TIMESTAMPP_HPP

#include <iostream>
#include <chrono>
#include <ctime>
#include <sys/time.h>
#include <inttypes.h>
#include <cstring>
#include <thread>

class Timestampp
{
public:
    static constexpr int DATE_SIZE = 12;
    static constexpr int BASE_TIME_SIZE = 10;
    static constexpr int MICROSECOND_SIZE = 8;
    static constexpr int SIZE = 26;

    using time_type = std::chrono::hh_mm_ss<std::chrono::microseconds>;
};


#endif // TRUMP_BASE_TIMESTAMPP_HPP