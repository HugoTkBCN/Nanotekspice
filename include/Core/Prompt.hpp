/*
** EPITECH PROJECT, 2020
** Prompt
** File description:
** hpp
*/

#ifndef Prompt_HPP_
#define Prompt_HPP_

#include <map>
#include <signal.h>
#include <functional>
#include "Core.hpp"

namespace nts
{
    class Prompt {
    private:
        std::map<std::string, std::function<void()>> commands;
        Core core;
        std::string	input;
        bool exist;
        
        void exit();
        void display() const;
        void setInput();
        void simulate();
        void loop();
        void dump() const;

    public:
        Prompt() = delete;
        Prompt(int, char **);
        Prompt(const Prompt &) = delete;
        ~Prompt();
        Prompt &operator=(const Prompt &) = delete;
        void run();
    };
}

void sigSimulate(sig_t);

#endif /* !Prompt_HPP_ */
