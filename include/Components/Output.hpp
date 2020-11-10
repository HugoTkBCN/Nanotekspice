/*
** EPITECH PROJECT, 2020
** componant output
** File description:
** hpp
*/

#ifndef _COUPUT_H_
#define _COUPUT_H_

#include <map>
#include <vector>
#include <memory>
#include "AComponent.hpp"

namespace nts {
    class Output : public AComponent {
    public:
        Output();
        ~Output();
        nts::Tristate compute(size_t pin = 1) override;
        void setValue(Tristate value) override;
    };
}

#endif /* !_COUPUT_H_ */