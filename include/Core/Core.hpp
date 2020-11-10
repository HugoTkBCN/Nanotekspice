/*
** EPITECH PROJECT, 2020
** Core
** File description:
** hpp
*/

#ifndef _Core_HPP_
#define _Core_HPP_

#include "Parser.hpp"
#include "IComponent.hpp"
#include "AComponent.hpp"
#include "FactoryComponent.hpp"

namespace nts
{
    class Core {
    private:
        Parser parser;
        std::map<std::string, AComponent *> components;
        node_nts_s *root;
        FactoryComponent factory;
        void deleteNode();
        void deleteComp();

        void feed(const std::string &);
        void setComponents(int, char **);
        std::pair<std::string, std::string> getChipet(std::string) const;
        std::string searchComposent(std::string &);
        void createLinks(NTS_LIST);
        std::pair<std::string, size_t> createPairLink(std::string &);
        AComponent *getComponantWithName(std::string &);
        void setComponentsWithChipsets();
        Tristate getTristate(std::string &) const;

    public:
        Core(int ac, char **av);
        Core(const Core &) = delete;
        ~Core();
        Core &operator=(const Core &) = delete;

        void display() const;
        void setInput(const std::string &, Tristate);
        void compute();
        void dumps() const;
        void invertClock();

        std::map<std::string, AComponent *> getComponents() {return (components);}    
    };
}

#endif /* !_Core_HPP_ */
