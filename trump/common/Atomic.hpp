/*
 * @Author: Mass
 * @Date: 2022-07-11 23:12:22
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-12 00:10:27
 * @FilePath: /trump/common/Atomic.hpp
 */

#ifndef TRUMP_COMMON_ATOMIC_HPP
#define TRUMP_COMMON_ATOMIC_HPP

#include "trumpdef.hpp"

BEGIN_NAMESAPCE_TRUMP

BEGIN_NAMESPACE( detail )

template<typename Integer>
class AtomicI
{
public:
    AtomicI() : value_ { 0 } { }

    //* uncomment if you need copying and assignment

    // AtomicI(const AtomicI& that) : value_(that.get()) {}

    // AtomicI& operator=(const AtomicI& that)
    // {
    //     getAndSet(that.get());
    //     return *this;
    // }

    //* get and set

    Integer get()
    {
        // in gcc >= 4.7: __atomic_load_n(&value_, __ATOMIC_SEQ_CST)
        return __sync_val_compare_and_swap( &value_, 0, 0 );
    }

    // i++
    Integer getAndAdd( Integer i )
    {
        // in gcc >= 4.7: __atomic_fetch_add(&value_, x, __ATOMIC_SEQ_CST)
        return __sync_fetch_and_add( &value_, i );
    }


    // ++i
    Integer addAndGet( Integer i )
    {
        return getAndAdd( i ) + i;
    }
    Integer operator++()
    {
        return addAndGet( 1 );
    }
    Integer incrementAndGet()
    {
        return addAndGet( 1 );
    }

    void increment() { incrementAndGet(); }

    // --i
    Integer operator--()
    {
        return addAndGet( -1 );
    }
    Integer decrementAndGet()
    {
        return addAndGet( -1 );
    }

    void decrement() { decrementAndGet(); }

    // +
    Integer operator+( Integer i ) { return get() + i; }

    // +=
    void operator+=( Integer i ) { getAndAdd( i ); }
    void add( Integer i ) { getAndAdd( i ); }

    Integer getAndSet( Integer i )
    {
        // in gcc >= 4.7: __atomic_exchange_n(&value, i, __ATOMIC_SEQ_CST)
        return __sync_lock_test_and_set( &value_, i );
    }

    bool operator==( Integer i )
    {
        return get() == i;
    }

private:
    volatile Integer value_;
};

END_NAMESPACE( detail )

using AtomicInt32 = detail::AtomicI<int32_t>;
using AtomicInt64 = detail::AtomicI<int64_t>;

END_NAMESPACE_TRUMP


#endif //  TRUMP_COMMON_ATOMIC_HPP