#ifndef OTP_H
#define OTP_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <random>
#include <algorithm>

class OTP {
public:
    static const std::map<std::string, char> binary2asciiTable;
    static const std::map<char, std::string> ascii2binaryTable; 
    std::vector<std::string> binaryVector(const std::string &binary);
    int binary2dec(const std::string &binary);
    char binary2char(const std::string &binary);
    std::string char2binary(const char &c);
    std::string string2binary(const std::string &str);
    std::string binary2string(const std::string &binary);
    std::string XOR(char bitA, char bitB);
    std::string correctBinary(const std::string &binary);
    std::string revertBackToOriginalBinary(const std::string &binary);
    std::string oneTimePad(std::string textA, std::string textB);
    std::string generateOneTimePadKey(const std::string &text);
};

#endif