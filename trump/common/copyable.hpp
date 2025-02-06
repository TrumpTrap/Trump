/*
 * @Author: Mass
 * @Date: 2022-02-14 22:23:04
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-11 23:13:23
 * @FilePath: /trump/common/copyable.hpp
 *
 *   copyable and noncopyable provide a tag class to emphasises objects are value type or object type.
 *      * value type  : copy is always avariable, once the copy is disconnected from the source object.    
 *      * object type : copy is not always avariable, Underlying resources may be shared after copying.
 *      Most objects are not copiable, so class copyable just a empty identify class.
 */

#ifndef TRUMP_BASE_COMMON_COPYABLE_HPP
#define TRUMP_BASE_COMMON_COPYABLE_HPP

#include "trumpdef.hpp"

BEGIN_NAMESAPCE_TRUMP

// empty class, any derived class should be a value type.
class copyable
{
protected:
    copyable() = default;
    ~copyable() = default;
};

END_NAMESPACE_TRUMP

#endif  // TRUMP_COMMON_COPYABLE_HPP