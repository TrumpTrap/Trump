/*
 * @Author: Mass
 * @Date: 2022-07-13 00:40:24
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-13 00:52:43
 * @FilePath: /trump/common/Exception.ipp
 */


using namespace Trump;

Exception::Exception( std::string msg )
    : message_ { std::move( msg ) }, stack_ {stack(true)}
{
       
}

#include <execinfo.h>
#include <cxxabi.h>

std::string Exception::stack( bool demangle )
{
    std::string stack {};
    const int max_frames { 200 };
    void *frame[ max_frames ] {};
    
    int nptrs { ::backtrace( frame, max_frames ) };
    char **strings = { ::backtrace_symbols( frame, nptrs ) };

    if ( not strings )
        return stack;

    size_t len { 256 };
    char *demangled { demangle ? static_cast<char *>( ::malloc( len ) ) : nullptr };
    for ( int i { 1 }; i < nptrs; ++i ) {// skipping the 0-th, which is this funciton {
        if ( demangle ) {
            // https://panthema.net/2008/0901-stacktrace-demangled/
            // bin/exception_test(_ZN3Bar4testEv+0x79) [0x401909]

            char *left_par { nullptr };
            char *plus { nullptr };
            for ( char *p = strings[ i ]; *p; ++p ) {
                if ( *p == '(' ) left_par = p;
                else if ( *p == '+' ) plus = p;
            }

            if ( left_par and plus ) {
                *plus = '\0';
                int status { 0 };
                char *ret { abi::__cxa_demangle( left_par + 1, demangled, &len, &status ) };
                *plus = '+';
                if ( status == 0 ) {
                    demangle = ret; // ret could be realloc()
                    stack.append( strings[ i ], left_par + 1 );
                    stack.append( demangled );
                    stack.append( plus );
                    stack.push_back( '\n' );
                    continue;
                }
            }
        }
        // Fallback to mangled names
        stack.append( strings[ i ] );
        stack.push_back( '\n' );
    }

    free( demangled );
    free( strings );

    return stack;
}