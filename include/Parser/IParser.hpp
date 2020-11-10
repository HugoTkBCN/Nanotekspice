/*
** EPITECH PROJECT, 2020
** IParser
** File description:
** hpp
*/

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
#define CPP_NANOTEKSPICE_PARSER_HPP

#include <string>
#include <vector>

namespace nts {
    enum class NodeType : int {
        DEFAULT = -1,
        NEWLINE = 0,
        SECTION,
        COMPONENT,
        LINK,
        LINK_END,
        STRING
    };

    typedef struct node_nts_s {
        node_nts_s(std::vector<struct node_nts_s*> *child) : child(child) {}

        std::string	_run;
        NodeType type;
        std::string	value;
        std::vector<struct node_nts_s*>	*child;
    } node_nts_t;

    class IParser {
    public:
        virtual void feed(std::string const& input) = 0;
        virtual void parse(node_nts_t& root) = 0;
        virtual node_nts_t *create() = 0;
        virtual ~IParser() {}
    };
}

#endif //CPP_NANOTEKSPICE_PARSER_HPP
