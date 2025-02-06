/*
 * @Author: Mass
 * @Date: 2022-07-12 23:44:41
 * @LastEditors: Mass
 * @LastEditTime: 2022-07-13 00:41:15
 * @FilePath: /trump/common/Exception.hpp
 */

#ifndef TRUMP_COMMON_EXCEPION_HPP
#define TRUMP_COMMON_EXCEPION_HPP 

#include "trumpdef.hpp"

#include <exception>

BEGIN_NAMESAPCE_TRUMP

class Exception : public std::exception
{
public:
    explicit Exception(std::string msg);
    ~Exception() noexcept override = default;

    // default copy-ctor and operator=, ok.

    const char *what() const noexcept override { return message_.data(); }

    const char *stack() const noexcept { return stack_.data(); }

private:
    std::string stack( bool demangle );

private:
    std::string message_;
    std::string stack_;
};

END_NAMESPACE_TRUMP

#include "Exception.ipp"

#endif //  TRUMP_COMMON_EXCEPION_HPP