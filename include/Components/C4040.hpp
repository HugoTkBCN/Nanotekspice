/*
** EPITECH PROJECT, 2020
** C4040
** File description:
** hpp
*/

#ifndef _C4040_H_
#define _C4040_H_

#include <functional>
#include "AComponent.hpp"

namespace nts {
    typedef std::function<Tristate (size_t pin)> computeFunctionPtr;
    class C4040 : public AComponent {
    private:
        std::map<size_t, std::pair<size_t, size_t>> gates;
        std::map<size_t, computeFunctionPtr> inPins;

        void initGates() override;
        void initInPins() override;
        void initOutPins() override;
        void initOtherPins() override;
    public:
        C4040();
        ~C4040();

        Tristate compute(size_t pin) override;
        Tristate computeOutput(size_t pin);
        Tristate computeInput(size_t pin);
        Tristate computeVss(size_t pin);
        Tristate computeVdd(size_t pin);
    };
}

#endif /* !_C4040_H_ */
