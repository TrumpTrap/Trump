/*
 * @Author: Mass
 * @Date: 2022-07-11 23:10:44
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-13 00:07:11
 * @FilePath: /trump/tests/atomic_unittest.cc
 */

#include <common/Atomic.hpp>

#include <cassert>

int main()
{
  {
    Trump::AtomicInt64 a0 {};
    assert( a0.get() == 0 );
    assert( a0.getAndAdd( 1 ) == 0 );
    assert( a0.get() == 1 );
    assert( a0.addAndGet( 2 ) == 3 );
    assert( a0.get() == 3 );
    // assert(a0.incrementAndGet() == 4);
    assert( ++a0 == 4 );
    assert( a0.get() == 4 );
    a0.increment();
    assert( a0.get() == 5 );
    assert( a0.addAndGet( -3 ) == 2 );
    assert( a0.getAndSet( 100 ) == 2 );
    assert( a0.get() == 100 );
    assert( --a0 == 99 );
    assert( a0 + 2 == 101 );
    a0 += 2;
    assert( a0 == 101 );
  }

  {
    Trump::AtomicInt32 a1 {};
    assert( a1.get() == 0 );
    assert( a1.getAndAdd( 1 ) == 0 );
    assert( a1.get() == 1 );
    assert( a1.addAndGet( 2 ) == 3 );
    assert( a1.get() == 3 );
    assert( a1.incrementAndGet() == 4 );
    assert( a1.get() == 4 );
    a1.increment();
    assert( a1.get() == 5 );
    assert( a1.addAndGet( -3 ) == 2 );
    assert( a1.getAndSet( 100 ) == 2 );
    assert( a1.get() == 100 );
    assert( --a1 == 99 );
    assert( a1 + 2 == 101 );
    a1 += 2;
    assert( a1 == 101 );
  }
}