/*
 * @Author: Mass
 * @Date: 2022-07-11 01:50:45
 * @LastEditors: Mass
 * @LastEditTime: 2023-09-19 16:08:30
 * @FilePath: /Trump/trump/time/Timestamp.hpp
 */

#ifndef TRUMP_BASE_TIME_TIMESTAMP_H
#define TRUMP_BASE_TIME_TIMESTAMP_H

#include "common/copyable.hpp"

#include <concepts>
#include <sstream>
#include <string>


BEGIN_NAMESAPCE_TRUMP

class Timestamp : public copyable
{
public:
    
    constexpr static int kMicroSecondsPerSecond = 1000 * 1000; // 1s = 1000000μs

public:
    /**
     * @brief Construct a new invalid Timestamp object
     */
    Timestamp():Timestamp{0} {}

    /**
     * @brief Construct a new Timestamp object at specific time
     * 
     * @param microSecondsSinceEpoch 
     */
    explicit Timestamp( int64_t microSecondsSinceEpoch ) : microSecondsSinceEpoch_ { microSecondsSinceEpoch } { }

    ~Timestamp() = default;
    
    //* use default copy ctor and copy assignment operator.
    // it's ok.

    void swap( Timestamp &that ) { std::swap( microSecondsSinceEpoch_, that.microSecondsSinceEpoch_ ); }

    std::string toString() const;

    std::string formatString( bool microseconds = true, bool local = true ) const;

    //* for internal usage
    int64_t microSecondsSinceEpoch() const { return microSecondsSinceEpoch_; }
    
    time_t secondsSinceEpoch() const { return static_cast<time_t>( microSecondsSinceEpoch_ / kMicroSecondsPerSecond ); }

    //* get time of now.

    static Timestamp now();

    static Timestamp invalid() { return Timestamp(); }

    bool valid() const { return microSecondsSinceEpoch_ > 0; }

    static Timestamp fromUnixTime( time_t t, int microseconds = 0 )
    {
        return Timestamp( static_cast<int64_t>( t ) * kMicroSecondsPerSecond + microseconds );
    }


private:
    int64_t     microSecondsSinceEpoch_; // microseconds since 1970.1.1 00:00:00
};

END_NAMESPACE_TRUMP

#include "Timestamp.ipp"

#endif // TRUMP_BASE_TIME_TIMESTAMP_H