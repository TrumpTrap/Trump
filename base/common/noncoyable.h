/*
 * @Author: Mass
 * @Date: 2022-02-14 22:29:08
 * @LastEditors: Mass
 * @LastEditTime: 2022-02-14 22:51:26
 * @FilePath: /Trump/base/common/noncoyable.h
 */

#ifndef TRUMP_BASE_COMMON_NONCOPYABLE_H
#define TRUMP_BASE_COMMON_NONCOPYABLE_H

#include "trumpdef.h"

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

#endif // TRUMP_BASE_NONCOPYABLE_H