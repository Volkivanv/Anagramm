#include <iostream>
#include <map>
#include <string>

bool anagramm(std::string fWord, std::string sWord){
    std::map<char,int>firstWord,secondWord;
    for(int i = 0; i < fWord.length(); i++){
        auto it = firstWord.find(fWord[i]);
        if (it == firstWord.end()){
            firstWord.insert(std::make_pair(fWord[i], 1));
        } else {
            it ->second++;
        }
    }

    for(int i = 0; i < sWord.length(); i++){
        auto it = secondWord.find(sWord[i]);
        if (it == secondWord.end()){
            secondWord.insert(std::make_pair(sWord[i], 1));
        } else {
            it ->second++;
        }
    }
    if(firstWord.size()!=secondWord.size()) {
        return false;
    } else {
        auto iter = secondWord.begin();
        for (auto it = firstWord.begin(); it != firstWord.end(); ++it) {
            if((it -> first != iter -> first)||(it -> second != iter -> second)) return false;
            ++iter;
        }
    }
    return true;
}

int main() {
    std::string firstWord, secondWord;
    std::cout << "Input first Word!" << std::endl;
    std::getline(std::cin,firstWord);
    std::cout << "Input second Word!" << std::endl;
    std::getline(std::cin,secondWord);
    std::cout << std::boolalpha << anagramm(firstWord,secondWord);

    return 0;
}
