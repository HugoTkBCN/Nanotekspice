/*
** EPITECH PROJECT, 2020
** FactoryComponent
** File description:
** cpp
*/

#include "C4001.hpp"
#include "ExceptionComponent.hpp"
#include "FactoryComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4040.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "False.hpp"
#include "True.hpp"
#include "Clock.hpp"

namespace nts
{
    FactoryComponent::FactoryComponent()
    {
        comp["output"] = std::bind(&FactoryComponent::createOutput, this, std::placeholders::_1);
        comp["input"] = std::bind(&FactoryComponent::createInput, this, std::placeholders::_1);
        comp["true"] = std::bind(&FactoryComponent::createTrue, this, std::placeholders::_1);
        comp["false"] = std::bind(&FactoryComponent::createFalse, this, std::placeholders::_1);
        comp["clock"] = std::bind(&FactoryComponent::createClock, this, std::placeholders::_1);
        comp["4001"] = std::bind(&FactoryComponent::create4001, this, std::placeholders::_1);
        comp["4011"] = std::bind(&FactoryComponent::create4011, this, std::placeholders::_1);
        comp["4030"] = std::bind(&FactoryComponent::create4030, this, std::placeholders::_1);
        comp["4040"] = std::bind(&FactoryComponent::create4040, this, std::placeholders::_1);
        comp["4069"] = std::bind(&FactoryComponent::create4069, this, std::placeholders::_1);
        comp["4081"] = std::bind(&FactoryComponent::create4081, this, std::placeholders::_1);
        comp["4071"] = std::bind(&FactoryComponent::create4071, this, std::placeholders::_1);
    }

    FactoryComponent::~FactoryComponent()
    {
    }

    IComponent* FactoryComponent::createComponent(const std::string &type, const std::string &value)
    {
        if (comp.find(type) == std::end(comp))
            throw ExceptionComponent("Component not found: " + type);
        return (comp[type](value));
    }

    IComponent* FactoryComponent::createInput(const std::string &) const
    {
        return (new Input());
    }

    IComponent* FactoryComponent::createOutput(const std::string &) const
    {
        return (new Output());
    }

    IComponent* FactoryComponent::create4081(const std::string &) const
    {
        return (new C4081());
    }

    IComponent* FactoryComponent::create4001(const std::string &) const
    {
        return (new C4001());
    }

    IComponent* FactoryComponent::create4011(const std::string &) const
    {
        return (new C4011());
    }

    IComponent* FactoryComponent::create4030(const std::string &) const
    {
        return (new C4030());
    }

    IComponent* FactoryComponent::create4040(const std::string &) const
    {
        return (new C4040());
    }

    IComponent* FactoryComponent::create4069(const std::string &) const
    {
        return (new C4069());
    }

    IComponent* FactoryComponent::create4071(const std::string &) const
    {
        return (new C4071());
    }

    IComponent* FactoryComponent::createFalse(const std::string &) const
    {
        return (new False());
    }

    IComponent* FactoryComponent::createTrue(const std::string &) const
    {
        return (new True());
    }

    IComponent* FactoryComponent::createClock(const std::string &) const
    {
        return (new Clock());
    }
}
