/*
 * @Author: Mass
 * @Date: 2022-02-14 22:23:04
 * @LastEditors: Mass
 * @LastEditTime: 2022-02-14 22:37:28
 * @FilePath: /Trump/base/common/copyable.h
 *
 *      copyable and noncopyable private a tag class to emphasises objects are value type or obj type.
 */

#ifndef TRUMP_BASE_COMMON_COPYABLE_H
#define TRUMP_BASE_COMMON_COPYABLE_H

#include "trumpdef.h"

BEGIN_NAMESAPCE_TRUMP

// empty class, any derived class should be a value type.
class copyable
{
protected:
    copyable() = default;
    ~copyable() = default;
};

END_NAMESPACE_TRUMP

#endif  // TRUMP_COMMON_COPYABLE_H