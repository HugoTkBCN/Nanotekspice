/*
** EPITECH PROJECT, 2020
** Core
** File description:
** cpp
*/

#include "Core.hpp"
#include "Clock.hpp"
#include "ExceptionParser.hpp"
#include <iostream>
#include <string>
#include <fstream>

namespace nts
{
    Core::Core(int ac, char **av) : parser(), root(nullptr)
    {
        if (ac >= 2) {
            feed(av[1]);
            setComponentsWithChipsets();
            setComponents(ac, av);
            root = parser.create();
            createLinks(parser.getLinks());
        } else
            throw ExceptionParser("Forgot file parameter.");
    }

    Core::~Core()
    {
        deleteComp();
        deleteNode();
    }

    void Core::deleteComp()
    {
        for (auto &tmp : components)
            delete tmp.second;
    }

    void Core::deleteNode()
    {
        for (unsigned int y = 0; y < root->child->size(); y++) {
            for (unsigned int x = 0; x < root->child->at(y)->child->size(); x++)
                delete root->child->at(y)->child->at(x);
            delete root->child->at(y)->child;
            delete root->child->at(y);
        }
        delete root->child;
        delete root;
    }

    void Core::feed(const std::string &filepath)
    {
        std::ifstream file(filepath.c_str(), std::ios::in);

        (!file) ? throw ExceptionParser("Can not open '" + filepath + "'.") : 0;
        for (std::string line; getline(file, line); parser.feed(line)){}
    }

    void Core::setComponentsWithChipsets()
    {
        NTS_LIST &chip = parser.getChipsets();
        int i = 0;
        
        while (i != (int)chip.size()) {
            components[chip[i].second] = (AComponent *)factory.createComponent(chip[i].first, "-1");
            i++;
        }
    }

    void Core::setComponents(int ac, char **av)
    {
        int i = 2;
        std::pair<std::string, std::string>	chipsetValue;

        (ac - 2 < (int)parser.getNbrInputs()) ? throw ExceptionParser("Chipsets are not set.") : 0;
        while (i != ac) {
            chipsetValue = getChipet(av[i++]);
            (components.count(chipsetValue.first) == 0) ? throw ExceptionParser("The chipset '" + chipsetValue.first + "' does not exist.") : 0;
            components[chipsetValue.first]->setValue(getTristate(chipsetValue.second));
        }
        (components.size() < parser.getNbrInputs()) ? throw ExceptionParser("Chipsets must be set.") : 0;
    }

    std::pair<std::string, std::string>	Core::getChipet(std::string str) const
    {
        int tmp_key = 0;

        if ((tmp_key = str.find_first_of("=")) == -1)
            throw ExceptionParser("Operator '=' not find.");
        std::string	key1 = str.substr(0, tmp_key);
        std::string	key2 = str.substr(tmp_key + 1);
        (!key2.size()) ? 
        throw ExceptionParser("Value '" + key1 + "' do not have key.") : (key2.compare("0") && key2.compare("1")) ?
        throw ExceptionParser("Value '" + key1 + "' must be 0 or 1.") : 0;
        return (std::make_pair(key1, key2));
    }

    Tristate Core::getTristate(std::string &value) const
    {
        return ((value.compare("1") == 0) ?
        TRUE : (value.compare("0") == 0) ?
        FALSE : UNDEFINED);
    }

    void Core::invertClock()
    {
        for (auto &tmp : components)
            if (tmp.second->getComponentName() == "clock")
                (dynamic_cast<Clock *>(tmp.second))->setValue();
    }

    std::string	Core::searchComposent(std::string &chipsetName)
    {
        int i = 0;
        NTS_LIST list = parser.getChipsets();

        while (i != (int)list.size()) {
            if (chipsetName.compare(list[i].second) == 0)
                return (list[i].first);
            i++;
        }
        return ("");
    }

    void Core::createLinks(NTS_LIST links)
    {
        std::pair<std::string, size_t> tmp_input;
        std::pair<std::string, size_t> tmp_output;
        AComponent *component_input;
        AComponent *component_output;

        for (int i = 0; i != (int)links.size(); i++) {
            tmp_input = createPairLink(links[i].first);
            component_input = getComponantWithName(tmp_input.first);
            tmp_output = createPairLink(links[i].second);
            component_output = getComponantWithName(tmp_output.first);
            component_input->setLink(tmp_input.second, *component_output, tmp_output.second);
        }
    }

    std::pair<std::string, size_t> Core::createPairLink(std::string &link)
    {
        int tmp_key = link.find_first_of(":");

        (tmp_key == -1) ? throw ExceptionParser("Operator ':' not find in link : '" + link + "'.") : 0;
        (link.substr(tmp_key + 1).size() == 0) ? throw ExceptionParser("No key to value '" + link.substr(0, tmp_key) + "'.") : 0;
        return (make_pair(link.substr(0, tmp_key), std::atoi(link.substr(tmp_key + 1).c_str())));
    }

    AComponent *Core::getComponantWithName(std::string &name)
    {
        (components.count(name) == 0) ? throw ExceptionParser("Key '" + name + "' not find.") : 0;
        return (components[name]);
    }

    void Core::display() const
    {
        for (auto &tmp : components)
            (tmp.second->getComponentName().compare("output") == 0) ? 
            (void)(std::cout << tmp.first << "=" << tmp.second->getValue() << std::endl) : (void)0;
    }

    void Core::setInput(const std::string &name, Tristate value)
    {
        for (auto &tmp : components)
            (tmp.first.compare(name) == 0) ? tmp.second->setValue(value) : (void) 0;
    }

    void Core::compute()
    {
        for (auto &tmp : components)
            (tmp.second->getComponentName().compare("output") == 0) ? tmp.second->compute(1) : 0;
    }

    void Core::dumps() const
    {
        for (auto &tmp : components) {
            tmp.second->dump();
            std::cout << std::endl;
        }
    }
}
