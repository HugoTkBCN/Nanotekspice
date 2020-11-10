/*
** EPITECH PROJECT, 2020
** C4071
** File description:
** cpp
*/

#include <ExceptionComponent.hpp>
#include <iostream>
#include "C4071.hpp"

namespace nts
{
    C4071::C4071() : AComponent("4071", 14)
    {
        initGates();
        initInPins();
        initOutPins();
        initOtherPins();
    }

    C4071::~C4071()
    {
    }

    void C4071::initGates()
    {
        gates[3] = std::make_pair(1, 2);
        gates[4] = std::make_pair(5, 6);
        gates[11] = std::make_pair(12, 13);
        gates[10] = std::make_pair(8, 9);
    }

    void C4071::initInPins()
    {
        inPins[1] = std::bind(&C4071::computeInput, this, std::placeholders::_1);
        inPins[2] = std::bind(&C4071::computeInput, this, std::placeholders::_1);
        inPins[5] = std::bind(&C4071::computeInput, this, std::placeholders::_1);
        inPins[6] = std::bind(&C4071::computeInput, this, std::placeholders::_1);
        inPins[8] = std::bind(&C4071::computeInput, this, std::placeholders::_1);
        inPins[9] = std::bind(&C4071::computeInput, this, std::placeholders::_1);
        inPins[12] = std::bind(&C4071::computeInput, this, std::placeholders::_1);
        inPins[13] = std::bind(&C4071::computeInput, this, std::placeholders::_1);
    }

    void C4071::initOutPins()
    {
        inPins[3] = std::bind(&C4071::computeOutput, this, std::placeholders::_1);
        inPins[4] = std::bind(&C4071::computeOutput, this, std::placeholders::_1);
        inPins[10] = std::bind(&C4071::computeOutput, this, std::placeholders::_1);
        inPins[11] = std::bind(&C4071::computeOutput, this, std::placeholders::_1);
    }

    void C4071::initOtherPins()
    {
        inPins[7] = std::bind(&C4071::computeVss, this, std::placeholders::_1);
        inPins[14] = std::bind(&C4071::computeVdd, this, std::placeholders::_1);
    }

    Tristate C4071::compute(size_t pin)
    {
        static unsigned int cp = 0;

        checkPinNum(pin + 1);
        if (cp > this->NbrPins)
            throw ExceptionComponent("infinity loop.");
        cp++;
        auto ret = inPins[pin](pin);
        return ret;
    }

    Tristate C4071::computeOutput(size_t pin)
    {
        if (gates.count(pin) == 0)
            throw nts::ExceptionComponent(std::to_string(pin) + " is not an output");
        size_t Pin1 = gates[pin].first - 1;
        size_t Pin2 = gates[pin].second - 1;
        return (AComponent::computeOpOr(pins[Pin1]->compute(link[Pin1]),
                                    pins[Pin2]->compute(link[Pin2])));
    }

    Tristate C4071::computeInput(size_t pin)
    {
        pin = pin - 1;
        if (pins[pin] == nullptr)
            return Tristate::UNDEFINED;
        return (pins[pin]->compute(link[pin]));
    }

    Tristate C4071::computeVdd(size_t)
    {
        return (Tristate::UNDEFINED);
    }

    Tristate C4071::computeVss(size_t)
    {
        return (Tristate::UNDEFINED);
    }

}
