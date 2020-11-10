/*
** EPITECH PROJECT, 2020
** C4001
** File description:
** cpp
*/

#include "ExceptionComponent.hpp"
#include <iostream>
#include "C4001.hpp"

namespace nts
{
    C4001::C4001() : AComponent("4001", 14)
    {
        initGates();
        initInPins();
        initOutPins();
        initOtherPins();
    }

    C4001::~C4001()
    {
    }

    void C4001::initGates()
    {
        gates[3] = std::make_pair(1, 2);
        gates[4] = std::make_pair(5, 6);
        gates[11] = std::make_pair(12, 13);
        gates[10] = std::make_pair(8, 9);
    }

    void C4001::initInPins()
    {
        inPins[1] = std::bind(&C4001::computeInput, this, std::placeholders::_1);
        inPins[2] = std::bind(&C4001::computeInput, this, std::placeholders::_1);
        inPins[5] = std::bind(&C4001::computeInput, this, std::placeholders::_1);
        inPins[6] = std::bind(&C4001::computeInput, this, std::placeholders::_1);
        inPins[8] = std::bind(&C4001::computeInput, this, std::placeholders::_1);
        inPins[9] = std::bind(&C4001::computeInput, this, std::placeholders::_1);
        inPins[12] = std::bind(&C4001::computeInput, this, std::placeholders::_1);
        inPins[13] = std::bind(&C4001::computeInput, this, std::placeholders::_1);
    }

    void C4001::initOutPins()
    {
        inPins[3] = std::bind(&C4001::computeOutput, this, std::placeholders::_1);
        inPins[4] = std::bind(&C4001::computeOutput, this, std::placeholders::_1);
        inPins[10] = std::bind(&C4001::computeOutput, this, std::placeholders::_1);
        inPins[11] = std::bind(&C4001::computeOutput, this, std::placeholders::_1);
    }

    void C4001::initOtherPins()
    {
        inPins[7] = std::bind(&C4001::computeVss, this, std::placeholders::_1);
        inPins[14] = std::bind(&C4001::computeVdd, this, std::placeholders::_1);
    }

    Tristate C4001::compute(size_t pin)
    {
        checkPinNum(pin + 1);
        return (inPins[pin](pin));
    }

    Tristate C4001::computeOutput(size_t pin)
    {
        if (gates.count(pin) == 0)
            throw nts::ExceptionComponent(std::to_string(pin) + " not an output");
        size_t Pin1 = gates[pin].first - 1;
        size_t Pin2 = gates[pin].second - 1;
        return (AComponent::computeOpNor(pins[Pin1]->compute(link[Pin1]),
                                        pins[Pin2]->compute(link[Pin2])));
    }

    Tristate C4001::computeInput(size_t pin)
    {
        if (pins[pin - 1] == nullptr)
            return (Tristate::UNDEFINED);
        return (pins[pin - 1]->compute(link[pin - 1]));
    }

    Tristate C4001::computeVdd(size_t)
    {
        return (Tristate::UNDEFINED);
    }

    Tristate C4001::computeVss(size_t)
    {
        return (Tristate::UNDEFINED);
    }
}
