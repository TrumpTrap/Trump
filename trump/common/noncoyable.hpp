/*
 * @Author: Mass
 * @Date: 2022-02-14 22:29:08
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-11 01:21:03
 * @FilePath: /trump/common/noncoyable.hpp
 *
 *   *   copyable and noncopyable provide a tag class to emphasises objects are value type or object type.
 *      * value type  : copy is always avariable, once the copy is disconnected from the source object.    
 *      * object type : copy is not always avariable, Underlying resources may be shared after copying.
 *
 *    class nocopyable diable copy by disabling copy semantics member functions(copy ctor and copy assignment operator)
 */

#ifndef TRUMP_BASE_COMMON_NONCOPYABLE_HPP
#define TRUMP_BASE_COMMON_NONCOPYABLE_HPP

#include "trumpdef.hpp"

BEGIN_NAMESAPCE_TRUMP

class noncopyable
{
private:
    noncopyable( const noncopyable & ) = delete;
    void operator=( const noncopyable & ) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

END_NAMESPACE_TRUMP

#endif // TRUMP_BASE_NONCOPYABLE_HPP