/*
** EPITECH PROJECT, 2020
** C4030
** File description:
** cpp
*/

#include "ExceptionComponent.hpp"
#include <iostream>
#include "C4030.hpp"

namespace nts
{
    C4030::C4030() : AComponent("4030", 14)
    {
        initGates();
        initInPins();
        initOutPins();
        initOtherPins();
    }

    C4030::~C4030()
    {
    }

    void C4030::initGates()
    {
        gates[3] = std::make_pair(1, 2);
        gates[4] = std::make_pair(5, 6);
        gates[10] = std::make_pair(8, 9);
        gates[11] = std::make_pair(12, 13);
    }

    void C4030::initInPins()
    {
        inPins[1] = std::bind(&C4030::computeInput, this, std::placeholders::_1);
        inPins[2] = std::bind(&C4030::computeInput, this, std::placeholders::_1);
        inPins[5] = std::bind(&C4030::computeInput, this, std::placeholders::_1);
        inPins[6] = std::bind(&C4030::computeInput, this, std::placeholders::_1);
        inPins[8] = std::bind(&C4030::computeInput, this, std::placeholders::_1);
        inPins[9] = std::bind(&C4030::computeInput, this, std::placeholders::_1);
        inPins[12] = std::bind(&C4030::computeInput, this, std::placeholders::_1);
        inPins[13] = std::bind(&C4030::computeInput, this, std::placeholders::_1);
    }

    void C4030::initOutPins()
    {
        inPins[3] = std::bind(&C4030::computeOutput, this, std::placeholders::_1);
        inPins[4] = std::bind(&C4030::computeOutput, this, std::placeholders::_1);
        inPins[10] = std::bind(&C4030::computeOutput, this, std::placeholders::_1);
        inPins[11] = std::bind(&C4030::computeOutput, this, std::placeholders::_1);
    }

    void C4030::initOtherPins()
    {
        inPins[7] = std::bind(&C4030::computeVss, this, std::placeholders::_1);
        inPins[14] = std::bind(&C4030::computeVdd, this, std::placeholders::_1);
    }

    Tristate C4030::compute(size_t pin)
    {
        checkPinNum(pin + 1);
        return (inPins[pin](pin));
    }

    Tristate C4030::computeOutput(size_t pin)
    {
        if (gates.count(pin) == 0)
            throw nts::ExceptionComponent(std::to_string(pin) + " is not an output");
        size_t	Pin1;
        size_t	Pin2;

        Pin1 = gates[pin].first - 1;
        Pin2 = gates[pin].second - 1;
        return (AComponent::computeOpXor(pins[Pin1]->compute(link[Pin1]),
                                        pins[Pin2]->compute(link[Pin2])));
    }

    Tristate C4030::computeInput(size_t pin)
    {
        if (pins[pin - 1] == nullptr)
            return (Tristate::UNDEFINED);
        return (pins[pin]->compute(link[pin]));
    }

    Tristate C4030::computeVdd(size_t)
    {
        return (Tristate::UNDEFINED);
    }

    Tristate C4030::computeVss(size_t)
    {
        return (Tristate::UNDEFINED);
    }

}
