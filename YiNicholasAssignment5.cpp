/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Lesson #5
** File: 	source.cpp
** Description: Final Assignment Group Project
**
** Author: 	Juno Presken, Tamala Scott, & Nicholas Yi
** Date: 	08.14.2026
** -------------------------------------------------------------------------*/
// YiNicholasAssignment5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Part 1: Generate Cipher Key
#include <iostream>
#include <string>
#include <cctype>

// Function Declarations
std::string generateCipherKey(const std::string& keyword);
char transformChar(char c, const std::string& cipherKey, bool decrypt);

int main() {
    std::string keyword = "FEATHER";
    std::string message = "Hello, World!";

    // 1. Generate the key
    std::string cipherKey = generateCipherKey(keyword);
    std::cout << "Generated Key: " << cipherKey << "\n";

    // 2. Encrypt test
    std::string encrypted = "";
    for (char c : message) {
        encrypted += transformChar(c, cipherKey, false);
    }
    std::cout << "Encrypted: " << encrypted << "\n";

    // 3. Decrypt test
    std::string decrypted = "";
    for (char c : encrypted) {
        decrypted += transformChar(c, cipherKey, true);
    }
    std::cout << "Decrypted: " << decrypted << "\n";

    return 0;
}

//Part 1: Generate Cipher Key

std::string generateCipherKey(const std::string& keyword) {
    std::string key = "";

    // Step 1: Append unique uppercase characters from keyword
    for (char c : keyword) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            char upper = std::toupper(static_cast<unsigned char>(c));
            if (key.find(upper) == std::string::npos) {
                key += upper;
            }
        }
    }

    // Step 2: Append remaining alphabet characters in reverse order (Z -> A)
    for (char c = 'Z'; c >= 'A'; --c) {
        if (key.find(c) == std::string::npos) {
            key += c;
        }
    }

    return key; // Result for "FEATHER": FEATHRZYXWVUSQPONMLKJIGDCB
}

//Part 2: Encrypt and Decrypt

char transformChar(char c, const std::string& cipherKey, bool decrypt) {
    if (!std::isalpha(static_cast<unsigned char>(c))) {
        return c; // Pass numbers, spaces, and punctuation through as-is
    }

    bool isLower = std::islower(static_cast<unsigned char>(c));
    char upperC = std::toupper(static_cast<unsigned char>(c));
    char resultC;

    if (!decrypt) {
        // ENCRYPTION: 'A'..'Z' index (0..25) maps to cipherKey[index]
        int index = upperC - 'A';
        resultC = cipherKey[index];
    }
    else {
        // DECRYPTION: Find position in cipherKey -> map back to 'A' + index
        size_t index = cipherKey.find(upperC);
        resultC = 'A' + static_cast<char>(index);
    }

    return isLower ? std::tolower(static_cast<unsigned char>(resultC)) : resultC;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
