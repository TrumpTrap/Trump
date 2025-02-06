/*
 * @Author: Mass
 * @Date: 2022-02-14 22:30:15
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-11 23:02:32
 * @FilePath: /trump/common/trumpdef.hpp
 *
 *      all common defined tag here.
 */

#include <string>
#include <cstring>

#ifndef TRUMP_BASE_COMMON_TRUMPDEF_HPP
#define TRUMP_BASE_COMMON_TRUMPDEF_HPP

#define BEGIN_NAMESPACE(name)   namespace name {
#define END_NAMESPACE(name)     } //#/#/name

#define BEGIN_NAMESAPCE_TRUMP   BEGIN_NAMESPACE(Trump)
#define END_NAMESPACE_TRUMP     END_NAMESPACE(Trump) 


 //* namespace Trump
using std::string;

BEGIN_NAMESAPCE_TRUMP

using stringBuilder = std::ostringstream;

inline void bzero( void *p, std::size_t n )
{
    memset( p, 0, n );
}

END_NAMESPACE_TRUMP

#include <cstdint>

#endif // TRUMP_BASE_COMMON_TRUMPDEF_HPP

