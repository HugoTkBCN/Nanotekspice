/*
** EPITECH PROJECT, 2020
** Componant clock
** File description:
** hpp
*/

#ifndef _Clock_H_
#define _Clock_H_

#include <map>
#include <vector>
#include <memory>
#include "AComponent.hpp"

namespace nts {
    class Clock : public AComponent {
    public:
        Clock();
        ~Clock();
        void setValue();
    };
}

#endif /* !_Clock_H_ */