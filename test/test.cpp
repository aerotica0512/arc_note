// by M1Rin(Aerotica), 2023.12

#include <iostream>
#include <cstdio>
#include <string>
#include "../core/notebook.h"
#include "../version.h"

void printVersion(void);
void printDict(Notebook &dict);
void printSearch(Notebook &dict, std::wstring key);

int main(void)
{
    Notebook dict = Notebook();
    printVersion();

    dict.add(Word(L"abcd", L"123456"));
    dict.add(Word(L"cdef", L"345678"));
    dict.add(Word(L"bcde", L"234567"));
    printDict(dict);

    dict.add(Word(L"abcd", L"012345"));
    dict.add(Word(L"defg", L"This is line 1, \nThis is line2, \nThis is line3"));
    printDict(dict);

    printSearch(dict, L"abcd");
    printSearch(dict, L"0000");
    std::cout << std::endl;

    dict.erase(L"defg");
    dict.erase(L"abcd");
    dict.erase(L"1111");
    printDict(dict);

    return 0;
}

void printVersion(void)
{
    std::cout << "Aerotica Word Notebook core test program" << std::endl;
    std::cout << "build_" << BUILD << ", s" << STAGE << std::endl << std::endl;

    return;
}

void printDict(Notebook &dict)
{
    std::cout << "The amount of words in this notebook is " << dict.words.size() << std::endl;
    for(auto iter = begin(dict.words); iter != end(dict.words); iter++) {
        std::wcout << L"[" << iter->first << L"] = " << iter->second << std::endl;
    }
    std::cout << std::endl;

    return;
}

void printSearch(Notebook &dict, std::wstring key)
{
    std::wstring meaning = dict.search(key);
    std::wcout << "{" << key << "} -> " << meaning << std::endl;

    return;
}
