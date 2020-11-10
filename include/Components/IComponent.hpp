/*
** EPITECH PROJECT, 2020
** IComponant
** File description:
** hpp
*/

#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

namespace nts {
    enum  Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent{
    public:
        virtual ~IComponent(){};
        virtual nts::Tristate compute(size_t  pin = 1) = 0;
        virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
        virtual void dump() const = 0;
    };
}

 #endif // __ICOMPONENT_HPP__
