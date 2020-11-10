/*
** EPITECH PROJECT, 2020
** ExceptionParser
** File description:
** hpp
*/

#ifndef _EXCEPTIONPARSER_H_
#define _EXCEPTIONPARSER_H_

#include "ExceptionNts.hpp"

namespace nts
{
    class ExceptionParser : public ExceptionNts
    {
    public:
        ExceptionParser(const std::string& arg) : ExceptionNts(arg) {};
        ~ExceptionParser() throw() {};
    };
}

#endif /* !_EXCEPTIONPARSER_H_ */
