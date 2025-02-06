/*
 * @Author: Mass
 * @Date: 2022-07-11 01:51:58
 * @LastEditors: Mass
 * @LastEditTime: 2023-09-21 09:56:09
 * @FilePath: /Trump/trump/time/Timestamp.ipp
 */

using namespace Trump;

inline bool operator< ( Timestamp lhs, Timestamp rhs )
{
    return lhs.microSecondsSinceEpoch() < rhs.microSecondsSinceEpoch();
}

inline bool operator==(Timestamp lhs, Timestamp rhs)
{
  return lhs.microSecondsSinceEpoch() == rhs.microSecondsSinceEpoch();
}

///
/// Gets time difference of two timestamps, result in seconds.
///
/// @param high, low
/// @return (high-low) in seconds
/// @c double has 52-bit precision, enough for one-microsecond
/// resolution for next 100 years.
inline double timeDifference(Timestamp high, Timestamp low)
{
  int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
  return static_cast<double>(diff) / Timestamp::kMicroSecondsPerSecond;
}

///
/// Add @c seconds to given timestamp.
///
/// @return timestamp + seconds as Timestamp
///
inline Timestamp addTime(Timestamp timestamp, double seconds)
{
  int64_t delta = static_cast<int64_t>(seconds * Timestamp::kMicroSecondsPerSecond);
  return Timestamp(timestamp.microSecondsSinceEpoch() + delta);
}

inline Timestamp operator+(Timestamp lhs, uint64_t ms) {
    return Timestamp(lhs.microSecondsSinceEpoch() + ms);
}

inline Timestamp operator+(Timestamp lhs, double seconds) {
    uint64_t delta = static_cast<uint64_t>(seconds * Timestamp::kMicroSecondsPerSecond);
    return Timestamp(lhs.microSecondsSinceEpoch() + delta);
}


/**********************************
 *!  member function.
 ************************************/
std::string Timestamp::toString() const 
{
    stringBuilder os;
    os << microSecondsSinceEpoch_ / kMicroSecondsPerSecond
        << "."
        << microSecondsSinceEpoch_ % kMicroSecondsPerSecond;

    return os.str();
}

#include <iomanip>
std::string Timestamp::formatString( bool microseconds, bool local ) const
{
    time_t  seconds = static_cast<time_t>( microSecondsSinceEpoch_ / kMicroSecondsPerSecond );

    //* traditional implement.
    // struct tm tm_time;
    // gmtime_r( &seconds, &tm_time );
    // std::ostringstream sb;
    // sb << tm_time.tm_year + 1900 << "-" << tm_time.tm_mon + 1 << "-" << tm_time.tm_mday
    //     << " " << tm_time.tm_hour << ":" << tm_time.tm_min << ":" << tm_time.tm_sec;
    // if ( showMicroseconds ) {
    //     int microseconds = static_cast<int>( microSecondsSinceEpoch_ % kMicroSecondsPerSecond );
    //     sb << "." << microseconds;
    // }

    stringBuilder sb;
    sb << std::put_time( local ? std::localtime( &seconds ) : std::gmtime( &seconds ), "%F %X" )
        << (microseconds ? "." + std::to_string( static_cast<int>( microSecondsSinceEpoch_ % kMicroSecondsPerSecond ) ) : "");

    return sb.str();
}

#include <chrono>
Timestamp Timestamp::now()
{
    /*****************************************
     ** paragraph describing what is to be done traditional implement.
     *
     *  struct timeval tv;
     *  gettimeofday( &tv, nullptr );
     *  int64_t seconds = tv.tv_sec;
     *  return Timestamp( seconds * kMicroSecondsPerSecond + tv.tv_usec );
     *************************************************/

    return Timestamp( std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch() ).count() );
}
