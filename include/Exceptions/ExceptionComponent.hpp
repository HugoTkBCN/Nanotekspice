/*
** EPITECH PROJECT, 2020
** Exception
** File description:
** component
*/

#ifndef _ExceptionComponent_H_
#define _ExceptionComponent_H_

#include "ExceptionNts.hpp"

namespace nts
{
    class ExceptionComponent : public ExceptionNts {
    public:
        ExceptionComponent(const std::string &arg) : ExceptionNts(arg){};
        ~ExceptionComponent() throw(){};
    };
}

#endif /* !_ExceptionComponent_H_ */