/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** cpp
*/

#include <iostream>
#include "Parser.hpp"
#include "ExceptionParser.hpp"

static keyWordType keyWord = NONE;

namespace nts
{
    Parser::Parser() : root(nullptr)
    {
    }

    Parser::~Parser()
    {
    }

    void Parser::feed(const std::string &line)
    {
        std::string	noCom(deleteCom(line));

        if (isValid(noCom) && isKeyWord(noCom))
            feedKeyWord(noCom);
    }

    std::string	Parser::deleteCom(const std::string &line) const
    {
        std::string	noCom(line);
        int isFind = line.find('#');
        return (isFind == -1 ? noCom : line.substr(0, isFind));
    }

    bool Parser::isValid(const std::string &line) const
    {
        return (line.empty() == false && line[0] != '\n' && line[0] != '\0');
    }

    bool Parser::isKeyWord(std::string &line) const
    {
        keyWord = line.compare(".chipsets:") == 0 ? CHIPSETS : line.compare(".links:") == 0 ? LINKS : keyWord;
        return ((line.compare(".chipsets:") == 0 || line.compare(".links:") == 0) ? false : (keyWord == CHIPSETS || keyWord == LINKS));
    }

    void Parser::feedKeyWord(const std::string &line)
    {
        std::string key1(getKey1(line));
        std::string key2(getKey2(line));

        if (iskey2(key2))
            throw ExceptionParser("Components have same name : " + key2 + ".");
        if (keyWord == CHIPSETS)
            chipsets.push_back(make_pair(key1, key2));
        else if (keyWord == LINKS)
            links.push_back(make_pair(key1, key2));
    }

    std::string	Parser::getKey1(const std::string &line) const
    {
        size_t key1 = line.find_first_not_of(" \t\n");
        size_t key2 = line.find_first_of(" \t\n", key1);

        return (line.substr(key1, (key1 > 0) ? key2 - key1 : key2));
    }

    std::string	Parser::getKey2(const std::string &line) const
    {
        int key2 = line.find_first_of(" \t\n", line.find_first_not_of(" \t\n"));
        if ((key2 = line.find_first_not_of(" \t\n", key2)) == -1)
            key2 = line.length();
        int endkey2 = line.find_first_of(" \t\n", key2);
        endkey2 = endkey2 == -1 ? line.length() : endkey2 - key2;

        return (line.substr(key2, endkey2));
    }

    bool Parser::iskey2(std::string key) const
    {
        size_t i = 0;

        while (i < chipsets.size())
            if (chipsets[i++].second.compare(key) == 0)
                return (true);
        return (false);
    }

    void Parser::parse(node_nts_t &root)
    {
        node_nts_s *chipsets = root.child->at(0);
        node_nts_s *links = root.child->at(1);
        size_t i = 0;

        while (i < chipsets->child->size()) {
            std::cout << "chipset n°" << i;
            std::cout << ", lexem : " << chipsets->child->at(i)->_run;
            std::cout << ", value : " << chipsets->child->at(i)->value << std::endl;
            i++;
        }
        i = 0;
        while (i < links->child->size()) {
            std::cout << "link n°" << i;
            std::cout << ", lexem : " << links->child->at(i)->_run;
            std::cout << ", value : " << links->child->at(i)->value << std::endl;
            i++;
        }
    }

    node_nts_t *Parser::create()
    {
        node_nts_t *to_create = new node_nts_t(new std::vector<node_nts_t *>);

        this->isEmpty();
        to_create->type = NodeType::DEFAULT;
        to_create->child->push_back(CreateChipsets());
        to_create->child->push_back(CreateLinks());
        return (to_create);
    }

    void Parser::isEmpty() const
    {
        (chipsets.empty() == true) ? throw ExceptionParser("No chipset section.") :
        (links.empty() == true) ? throw ExceptionParser("No links section.") :
        0;
    }

    node_nts_t *Parser::CreateChipsets() const
    {
        node_nts_t *new_chipsets = new node_nts_t(new std::vector<node_nts_t *>);
        size_t i = 0;

        new_chipsets->type = NodeType::SECTION;
        while (i < this->chipsets.size())
            new_chipsets->child->push_back(CreateNode(this->chipsets[i++]));
        return (new_chipsets);
    }

    node_nts_t *Parser::CreateLinks() const
    {
        node_nts_t *new_links = new node_nts_t(new std::vector<node_nts_t *>);
        size_t i = 0;

        new_links->type = NodeType::SECTION;
        while (i < this->links.size())
            new_links->child->push_back(CreateNode(this->links[i++]));
        return (new_links);
    }

    node_nts_t *Parser::CreateNode(std::pair<std::string, std::string> nodes) const
    {
        node_nts_t *new_node = new node_nts_t(nullptr);

        new_node->_run = nodes.first;
        new_node->type = NodeType::COMPONENT;
        new_node->value = nodes.second;
        new_node->child = nullptr;
        return (new_node);
    }

    size_t Parser::getNbrInputs() const
    {
        size_t count = 0;
        size_t i = 0;
        
        while (i != chipsets.size())
            count = (chipsets[i++].first.compare("input") == 0) ?
            count + 1 : count;
        return (count);
    }
}
