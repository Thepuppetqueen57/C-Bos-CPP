// lib/cbos.hpp
#ifndef CBOS_HPP
#define CBOS_HPP

#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

using namespace std;

inline void msleep(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

inline string randomcolor() {
    static const vector<string> color_choices = {
        "\033[31m",  // RED
        "\033[32m",  // GREEN
        "\033[33m",  // YELLOW
        "\033[34m",  // BLUE
        "\033[35m",  // MAGENTA
        "\033[36m",  // CYAN
        "\033[94m",  // LIGHTBLUE_EX
        "\033[96m",  // LIGHTCYAN_EX
        "\033[92m",  // LIGHTGREEN_EX
        "\033[95m",  // LIGHTMAGENTA_EX
        "\033[91m",  // LIGHTRED_EX
        "\033[93m"   // LIGHTYELLOW_EX
    };
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<unsigned int>(time(nullptr)));
        initialized = true;
    }
    int random_index = rand() % color_choices.size();
    return color_choices[random_index];
}

inline string resetcolor() {
    return "\033[0m";
}

inline void ccout(string arg1) {
    cout << randomcolor() << arg1 << resetcolor();
}

// Function to encode a string to base64
inline string base64encode(const string &text) {
    static const char encode_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string encoded;
    int val = 0, valb = -6;
    for (unsigned char c : text) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            encoded.push_back(encode_table[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) encoded.push_back(encode_table[((val << 8) >> (valb + 8)) & 0x3F]);
    while (encoded.size() % 4) encoded.push_back('=');
    return encoded;
}

// Function to decode a base64 encoded string
inline string base64decode(const string &text) {
    static const int decode_table[] = {
        62, -1, -1, -1, 63, // +,/,0-9
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // 0-9
        -1, -1, -1, -1, -1, -1, -1, // illegal chars
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, // A-O
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // P-Z
        -1, -1, -1, -1, -1, -1, // illegal chars
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, // a-o
        42, 43, 44, 45, 46, 47, 48, 49, 50, 51 // p-z
    };

    string decoded;
    vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

    int val = 0, valb = -8;
    for (unsigned char c : text) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            decoded.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return decoded;
}

#endif // CBOS_HPP
