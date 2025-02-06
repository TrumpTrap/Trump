/*
 * @Author: Mass
 * @Date: 2022-07-13 00:25:27
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-13 00:37:34
 * @FilePath: /trump/tests/exception_unittest.cc
 */

#include <common/Exception.hpp>
#include <iostream>

class Bar
{
public:
    void test()
    {
        throw Trump::Exception( "oops" );
    }
};

void foo()
{
    Bar b;
    b.test();
}

int main()
{
    try
    {
        foo();
    }
    catch(const Trump::Exception& e)
    {
        std::cerr << "reason: " << e.what() << '\n';
        std::cerr << "stack trace:\n" << e.stack() << '\n';
    }
    
}