/*
** EPITECH PROJECT, 2020
** Exception
** File description:
** hpp
*/

#ifndef _EXCEPTIONNTS_H_
#define _EXCEPTIONNTS_H_

#include <string>
#include <exception>

namespace nts
{
    class ExceptionNts : public std::exception {
    private:
        std::string _msg;
    public:
        ExceptionNts(const std::string& msg) : _msg(msg) {};
        ~ExceptionNts() throw() {};
        virtual const char* what() const throw() { return _msg.c_str(); };
    };
}

#endif /* !_EXCEPTIONNTS_H_ */