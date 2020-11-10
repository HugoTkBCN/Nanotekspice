/*
** EPITECH PROJECT, 2020
** C4069
** File description:
** hpp
*/

#ifndef _C4069_H_
#define _C4069_H_

#include <memory>
#include <vector>
#include <functional>
#include "AComponent.hpp"

namespace nts {
    typedef std::function<Tristate (size_t pin)> computeFunctionPtr;
    class C4069 : public AComponent {
    private:
        std::map<size_t, size_t> gates;
        std::map<size_t, computeFunctionPtr> inPins;

        void initGates() override;
        void initInPins() override;
        void initOutPins() override;
        void initOtherPins() override;
    public:
        C4069();
        ~C4069();

        Tristate compute(size_t pin) override;
        Tristate computeOutput(size_t pin);
        Tristate computeInput(size_t pin);
        Tristate computeVss(size_t pin);
        Tristate computeVdd(size_t pin);
    };
}

#endif /* !_C4069_H_ */
