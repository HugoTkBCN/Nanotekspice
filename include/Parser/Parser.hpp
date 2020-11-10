/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** hpp
*/

#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include "IParser.hpp"

#define NTS_LIST std::vector<std::pair<std::string, std::string>>

enum keyWordType {
    CHIPSETS,
    LINKS,
    NONE
};

namespace nts {
    class Parser : public IParser {
    public:
        Parser();
        Parser(const Parser &) = delete;
        ~Parser();
        Parser &operator=(const Parser &) = delete;

        void feed(const std::string &);
        void parse(node_nts_t &);
        node_nts_t *create();
        
        size_t getNbrInputs() const;
        NTS_LIST &getChipsets() {return (chipsets);}
        NTS_LIST &getLinks() {return (links);}
    private:
        node_nts_t *root;
        NTS_LIST chipsets;
        NTS_LIST links;

        std::string	deleteCom(const std::string &) const;
        bool isValid(const std::string &) const;
        bool isKeyWord(std::string &) const;
        void feedKeyWord(const std::string &);
        std::string getKey1(const std::string &) const;
        std::string getKey2(const std::string &) const;
        node_nts_t *CreateChipsets() const;
        node_nts_t *CreateLinks() const;
        node_nts_t *CreateNode(std::pair<std::string, std::string>) const;
        void removeVectors(std::vector<node_nts_s *> *vec);
        void isEmpty() const;
        bool iskey2(std::string key) const;
    };
}

#endif /* !_PARSER_HPP_ */
