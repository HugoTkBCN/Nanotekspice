/*
** EPITECH PROJECT, 2020
** ExceptionPrompt
** File description:
** hpp
*/

#ifndef _EXCEPTIONPROMPT_HPP_
#define _EXCEPTIONPROMPT_HPP_

#include "ExceptionNts.hpp"

namespace nts
{
    class ExceptionPrompt : public ExceptionNts
    {
    public:
        ExceptionPrompt(const std::string& arg) : ExceptionNts(arg) {};
        ~ExceptionPrompt() throw() {};
    };
}

#endif /* !_EXCEPTIONPROMPT_HPP_ */