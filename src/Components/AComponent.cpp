/*
** EPITECH PROJECT, 2020
** AComponent
** File description:
** hpp
*/

#include <iostream>
#include <cstddef>
#include "AComponent.hpp"
#include "ExceptionComponent.hpp"

namespace nts
{
    AComponent::AComponent(std::string const &componentName, size_t _nbrPins) : NbrPins(_nbrPins), name(componentName), tristateValue(Tristate::UNDEFINED), pins(NbrPins)
    {
        for (size_t i = 0; i < NbrPins; ++i)
            pins[i] = nullptr;
        initGates();
        initInPins();
        initOutPins();
        initOtherPins();
    }

    AComponent::~AComponent()
    {
    }

    void AComponent::initGates()
    {
    }

    void AComponent::initInPins()
    {
    }

    void AComponent::initOutPins()
    {
    }

    void AComponent::initOtherPins()
    {
    }

    std::string const &AComponent::getComponentName() const
    {
        return (name);
    }

    void AComponent::setLink(size_t pin, nts::IComponent &component, size_t pinTarget)
    {
        checkPinNum(pin);
        if (pins[pin - 1] == nullptr) {
            link[pin - 1] = pinTarget;
            pins[pin - 1] = &component;
            pins[pin - 1]->setLink(pinTarget, *this, pin);
        }
    }

    Tristate AComponent::compute(size_t pin)
    {
        checkPinNum(pin);
        return (tristateValue);
    }

    void AComponent::checkPinNum(size_t pin) const
    {
        if (pin - 1 > NbrPins)
            throw ExceptionComponent({"Bad pin number :" + std::to_string(pin)});
    }

    void AComponent::setValue(Tristate value)
    {
        tristateValue = value;
    }

    Tristate AComponent::getValue() const
    {
        return (tristateValue);
    }

    std::string AComponent::tristateToString(Tristate tristate) const
    {
        return ((tristate == Tristate::FALSE) ? 
        "false" : (tristate == Tristate::TRUE) ? 
        "true" : "undefined");
    }

    void AComponent::dump() const
    {
        std::cout << name << " :" << std::endl;
        for (size_t i = 0; i < NbrPins; ++i) {
            std::cout << "pin: " << i + 1 << " = ";
            pins[i] ? std::cout << tristateToString(pins[i]->compute(link.at(i))) : std::cout << "(null)";
            std::cout << std::endl;
        }
    }

    Tristate AComponent::computeOpAnd(Tristate first, Tristate second)
    {
        return ((nts::Tristate)(first && second));
    }

    Tristate AComponent::computeOpNand(Tristate first, Tristate second)
    {
        return ((nts::Tristate)(!(first && second)));
    }

    Tristate AComponent::computeOpNor(Tristate first, Tristate second)
    {
        return ((nts::Tristate)(!(first || second)));
    }

    Tristate AComponent::computeOpOr(Tristate first, Tristate second)
    {
        return ((nts::Tristate)((first || second)));
    }

    Tristate AComponent::computeOpXor(Tristate first, Tristate second)
    {
        return ((nts::Tristate)((first ^ second)));
    }
}
