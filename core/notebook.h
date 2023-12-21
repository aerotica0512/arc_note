// by M1Rin(Aerotica), 2023.12

#pragma once

#include <string>
#include <vector>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

struct Word {
	Word() = default;
	Word(std::wstring key, std::wstring meaning) : key(key), meaning(meaning) {};

	std::wstring key, meaning;
};

class Notebook {
public:
	Notebook();
	~Notebook() 
	{
		updateWordsToXMLFile();
		return;
	}

	std::map<std::wstring, std::wstring> words;
	const std::string xmlFileName = "./arc_note.xml";

	std::wstring search(std::wstring key) 
	{
		if(isWordExist(key)) {
			return words[key];
		} else {
			return L"";
		}
	}

	const int ERROR = -1;
	const int SUCCED = 0;
	int update(Word word) 
	{
		if(!isValidWord(word)) {
			return ERROR;
		}

		words[word.key] = word.meaning;
		return SUCCED;
	}

	int erase(std::wstring key) 
	{
		words.erase(key);
		return 0;
	}

	size_t size(void) 
	{
		return words.size(); 
	}

	bool isWordExist(std::wstring key) 
	{
		if(words.count(key) == 1) {
			return true;
		} else {
			return false;
		}
	}

private:
	bool isValidWord(Word word)
	{
		if(word.key == L"" || word.meaning == L"") {
			return false;
		} else {
			return true;
		}
	}

	void addWordFromXMLNode(boost::property_tree::ptree &childNode);
	boost::property_tree::ptree addElementsFromWord(std::wstring key, std::wstring meaning);

	void updateWordsToXMLFile(void);
};
