/*
** EPITECH PROJECT, 2020
** AComponant
** File description:
** hpp
*/

#ifndef _AComponent_H_
#define _AComponent_H_

#include <memory>
#include <vector>
#include <map>
#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
    protected:
        const size_t NbrPins;
        std::string name;
        Tristate tristateValue;
        std::vector<IComponent *> pins;
        std::map<size_t, size_t> link;

        virtual void initGates();
        virtual void initInPins();
        virtual void initOutPins();
        virtual void initOtherPins();
        Tristate computeOpAnd(Tristate first, Tristate second);
        Tristate computeOpNand(Tristate first, Tristate second);
        Tristate computeOpNor(Tristate first, Tristate second);
        Tristate computeOpOr(Tristate first, Tristate second);
        Tristate computeOpNot(Tristate first, Tristate second);
        Tristate computeOpXor(Tristate first, Tristate second);
    public:
        AComponent(std::string const &name, size_t _nbrPins);
        virtual ~AComponent();
        AComponent(AComponent const &) = delete;
        AComponent &operator=(AComponent const &) = delete;

        virtual Tristate compute(size_t pin);
        virtual void setLink(size_t pin, nts::IComponent &component, size_t pinTaget);
        virtual void dump() const;

        virtual Tristate getValue() const;
        virtual void setValue(Tristate value);

        std::string tristateToString(Tristate tristate) const;
        void checkPinNum(size_t pin) const;
        std::string const &getComponentName() const;
    };
}

#endif /* !_AComponent_H_ */
