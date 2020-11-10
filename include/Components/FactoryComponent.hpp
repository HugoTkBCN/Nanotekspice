/*
** EPITECH PROJECT, 2020
** FactoryComponent
** File description:
** hpp
*/

#ifndef _FactoryComponent_H_
#define _FactoryComponent_H_

#include <map>
#include <functional>
#include <string>
#include "IComponent.hpp"

namespace nts {
    typedef std::function<IComponent*(const std::string &)> cmpFunctionPtr;
    class FactoryComponent {
    private:
        std::map<std::string, cmpFunctionPtr> comp;
        IComponent *create4001(const std::string &value) const;
        IComponent *create4011(const std::string &value) const;
        //IComponent *create4013(const std::string &value) const;
        IComponent *create4040(const std::string &value) const;
        IComponent *create4030(const std::string &value) const;
        IComponent *create4069(const std::string &value) const;
        IComponent *create4071(const std::string &value) const;
        IComponent *create4081(const std::string &value) const;
        IComponent *createInput(const std::string &value) const;
        IComponent *createOutput(const std::string &value) const;
        IComponent *createFalse(const std::string &value) const;
        IComponent *createTrue(const std::string &value) const;
        IComponent *createClock(const std::string &value) const;
    public:
        FactoryComponent();
        ~FactoryComponent();
        IComponent *createComponent(const std::string &type, const std::string &value);
    };
}

#endif /* !_FactoryComponent_H_ */
