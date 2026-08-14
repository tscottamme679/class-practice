// Assignment5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // 1. Open the dictionary file.
    std::ifstream dictFile("words.txt");

    // 2. Define a vector of strings called words.
    std::vector<std::string> words;
    std::string word;

    // 3. For each word in the dictionary file
    while (dictFile >> word) {
        // 4. Append the word to the words vector.
        words.push_back(word);
    }
    dictFile.close();

    // 5. Open the file to be checked.
    std::ifstream checkFile("input.txt");
    std::string checkWord;

    // 6. For each word in that file
    while (checkFile >> checkWord) {
        // 7. If the word is not contained in the words vector
        if (std::find(words.begin(), words.end(), checkWord) == words.end()) {
            // 8. Print the word.
            std::cout << checkWord << std::endl;
        }
    }
    checkFile.close();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
