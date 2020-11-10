/*
** EPITECH PROJECT, 2020
** C4069
** File description:
** cpp
*/

#include "ExceptionComponent.hpp"
#include <iostream>
#include "C4069.hpp"

namespace nts
{
    C4069::C4069() : AComponent("4069", 14)
    {
        initGates();
        initInPins();
        initOutPins();
        initOtherPins();
    }

    C4069::~C4069()
    {
    }

    void C4069::initGates()
    {
        gates[2] = 1;
        gates[4] = 3;
        gates[6] = 5;
        gates[8] = 9;
        gates[10] = 11;
        gates[12] = 13;
    }

    void C4069::initInPins()
    {
        inPins[1] = std::bind(&C4069::computeInput, this, std::placeholders::_1);
        inPins[3] = std::bind(&C4069::computeInput, this, std::placeholders::_1);
        inPins[5] = std::bind(&C4069::computeInput, this, std::placeholders::_1);
        inPins[9] = std::bind(&C4069::computeInput, this, std::placeholders::_1);
        inPins[11] = std::bind(&C4069::computeInput, this, std::placeholders::_1);
        inPins[13] = std::bind(&C4069::computeInput, this, std::placeholders::_1);
    }

    void C4069::initOutPins()
    {
        inPins[2] = std::bind(&C4069::computeOutput, this, std::placeholders::_1);
        inPins[4] = std::bind(&C4069::computeOutput, this, std::placeholders::_1);
        inPins[6] = std::bind(&C4069::computeOutput, this, std::placeholders::_1);
        inPins[8] = std::bind(&C4069::computeOutput, this, std::placeholders::_1);
        inPins[10] = std::bind(&C4069::computeOutput, this, std::placeholders::_1);
        inPins[12] = std::bind(&C4069::computeOutput, this, std::placeholders::_1);
    }

    void C4069::initOtherPins()
    {
        inPins[7] = std::bind(&C4069::computeVss, this, std::placeholders::_1);
        inPins[14] = std::bind(&C4069::computeVdd, this, std::placeholders::_1);
    }

    Tristate C4069::compute(size_t pin)
    {
        checkPinNum(pin + 1);
        return (inPins[pin](pin));
    }

    Tristate C4069::computeOutput(size_t pin)
    {
        if (gates.count(pin) == 0)
            throw nts::ExceptionComponent(std::to_string(pin) + " is not an output");
        return ((Tristate) (!(pins[gates[pin] - 1]->compute(link[gates[pin] - 1]))));
    }

    Tristate C4069::computeInput(size_t pin)
    {
        if (pins[pin - 1] == nullptr)
            return Tristate::UNDEFINED;
        return (pins[pin - 1]->compute(link[pin - 1]));
    }

    Tristate C4069::computeVdd(size_t)
    {
        return (Tristate::UNDEFINED);
    }

    Tristate C4069::computeVss(size_t)
    {
        return (Tristate::UNDEFINED);
    }
}
