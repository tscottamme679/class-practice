/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Lesson 5
** File: 	Assignment5.cpp
** Description: Group Project, Week 4: Tamala Scott, Nicholas Yi, and Juno Presken
**
** Author: 	Tamala Scott
** Date: 	8-14-2026
** -------------------------------------------------------------------------*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

int main() {
    // Defined vector/string called words
    std::vector<std::string> words = {
        "the", "last", "yellow", "fellow", "fell",
        "bumped", "his", "head", "and", "dog",
        "a", "ate", "bread"
    };

    //file to be checked
    std::string documentContent = "the last yellow fella fell and bumped his head and a dog ates bread";

    // We use a stringstream to read the words one by one, exactly like a file stream
    std::stringstream checkStream(documentContent);
    std::string word;

    std::cout << "Misspelled words found:\n";
    std::cout << "-----------------------\n";

    // 3. For each word, if it's not in our words vector, print it
    while (checkStream >> word) {
        if (std::find(words.begin(), words.end(), word) == words.end()) {
            std::cout << word << "\n";
        }
    }

    return 0;
}