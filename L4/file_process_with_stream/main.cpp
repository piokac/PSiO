#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::ifstream file("../../suplementary/license.txt");

    std::vector<std::string> words;
    if (file.is_open()) {
        //reading word by word using while loop

        //        while (!file.eof()) {
        //            string word;
        //            file >> word;
        //            words.emplace_back(word);
        //        }

        //Reading file in STL manner
        std::istream_iterator<std::string> in(file); //creates stream iterator

        copy(in, {}, back_inserter(words)); //copies word by word form in stream to vector of words
        sort(words.begin(), words.end());   //sorts words in alphabetic order
        std::vector<std::string> words_unique; //stores unique words (without replacements)
        unique_copy(words.begin(),
                    words.end(),
                    back_inserter(words_unique)); //emplace unique words into words_unique container

        for (auto &word : words_unique) {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
