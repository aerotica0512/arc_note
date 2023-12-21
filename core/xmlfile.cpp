// by M1Rin(Aerotica), 2023.12

#include "notebook.h"
#include <exception>

Notebook::Notebook()
{
    using boost::property_tree::ptree;
    using boost::property_tree::xml_parser::read_xml;
    ptree pt;

    try {
        read_xml(xmlFileName, pt);
    } catch(std::exception &e) {
        return;
    }

    try {
        for(auto iter = pt.begin(); iter != pt.end(); iter++) {
            std::string keyValue = iter->first;
            
            if(keyValue == "word") {
                addWordFromXMLNode(iter->second);
            }
        }
    } catch(std::exception &e) {
        return;
    }

    return;
}

void Notebook::addWordFromXMLNode(boost::property_tree::ptree &childNode)
{
    std::string key, meaning;
    key = childNode.get("key", "");
    meaning = childNode.get("meaning", "");

    std::wstring wk = std::wstring(key.begin(), key.end());
    std::wstring wm = std::wstring(meaning.begin(), meaning.end());
    this->update(Word(wk, wm));

    return;
}

void Notebook::updateWordsToXMLFile(void)
{
    using boost::property_tree::ptree;
    using boost::property_tree::xml_parser::write_xml;

    ptree pt;

    for(auto iter = begin(words); iter != end(words); iter++) {
        ptree child = addElementsFromWord(iter->first, iter->second);
        pt.add_child("word", child);
    }

    try {
        write_xml(xmlFileName, pt);
    } catch(std::exception &e) {
    }

    return;
}

boost::property_tree::ptree Notebook::addElementsFromWord(std::wstring key, std::wstring meaning)
{
    using boost::property_tree::ptree;

    ptree child;
    std::string sk = std::string(begin(key), end(key));
    std::string sm = std::string(begin(meaning), end(meaning));

    child.put("key", sk);
    child.put("meaning", sm);
    return child;
}
