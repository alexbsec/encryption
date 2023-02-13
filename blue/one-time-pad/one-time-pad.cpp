#include "one-time-pad.h"

const std::map<std::string, char> OTP::binary2asciiTable {
        {"00000001", '0'},
        {"00000010", '1'},
        {"00000011", '2'},
        {"00000100", '3'},
        {"00000101", '4'},
        {"00000110", '5'},
        {"00000111", '6'},
        {"00001000", '7'},
        {"00001001", '8'},
        {"00001010", '9'},
        {"00001011", 'a'},
        {"00001100", 'b'},
        {"00001101", 'c'},
        {"00001110", 'd'},
        {"00001111", 'e'},
        {"00010000", 'f'},
        {"00010001", 'g'},
        {"00010010", 'h'},
        {"00010011", 'i'},
        {"00010100", 'j'},
        {"00010101", 'k'},
        {"00010110", 'l'},
        {"00010111", 'm'},
        {"00011000", 'n'},
        {"00011001", 'p'},
        {"00011010", 'q'},
        {"00011011", 'r'},
        {"00011100", 's'},
        {"00011101", 't'},
        {"00011110", 'u'},
        {"00011111", 'v'},

        {"11100011", 'w'},
        {"11100100", 'y'},
        {"11100101", 'z'},
        {"11100110", 'A'},
        {"11100111", 'B'},
        {"11101000", 'C'},
        {"11101001", 'D'},
        {"11101010", 'E'},
        {"11101011", 'F'},
        {"11101100", 'G'},
        {"11101101", 'H'},
        {"11101110", 'I'},
        {"11101111", 'J'},
        {"11110000", 'K'},
        {"11110001", 'L'},
        {"11110010", 'M'},
        {"11110011", 'N'},
        {"11110100", 'O'},
        {"11110101", 'P'},
        {"11110110", 'Q'},
        {"11110111", 'R'},
        {"11111000", 'S'},
        {"11111001", 'T'},
        {"11111010", 'U'},
        {"11111011", 'V'},
        {"11111100", 'X'},
        {"11111101", 'W'},
        {"11111110", 'Y'},
        {"11111111", 'Z'},
        {"01111111", char(162)},
        {"10000000", char(163)},
        {"10000001", char(164)},
        {"10000010", char(165)},
        {"10000011", char(166)},
        {"10000100", char(167)},
        {"10000101", char(168)},
        {"10000110", char(169)},
        {"10000111", char(170)},
        {"10001000", char(171)},
        {"10001001", char(172)},
        {"10001010", char(174)},
        {"10001011", char(177)},
        {"10001100", char(180)},
        {"10001101", char(187)},
        {"10001110", char(191)},
        {"10001111", char(192)},
        {"10010001", char(193)},
        {"10010010", char(194)},
        {"10010011", char(195)},
        {"10010100", char(196)},
        {"10010101", char(197)},
        {"10010110", char(198)},
        {"10010111", char(199)},
        {"10011000", char(200)},
        {"10011001", char(201)},
        {"10011010", char(202)},
        {"10011011", char(203)},
        {"10011100", char(204)},
        {"10011101", char(205)},
        {"10011110", char(206)},
        {"10011111", char(207)},
        {"10100000", char(208)},
        {"10100001", char(209)},
        {"10100010", char(210)},
        {"10100011", char(211)},
        {"10100100", char(212)},
        {"10100101", char(213)},
        {"10100110", char(214)},
        {"10100111", char(215)},
        {"10101000", char(216)},
        {"10101001", char(217)},
        {"10101010", char(218)},
        {"10101011", char(219)},
        {"10101100", char(220)},
        {"10101101", char(221)},
        {"10101110", char(222)},
        {"10101111", char(223)},
        {"10110000", char(224)},
        {"10110001", char(225)},
        {"10110010", char(226)},
        {"10110011", char(227)},
        {"10110100", char(228)},
        {"10110101", char(229)},
        {"10110110", char(230)},
        {"10110111", char(231)},
        {"10111000", char(232)},
        {"10111001", char(233)},
        {"10111010", char(234)},
        {"10111011", char(235)},
        {"10111100", char(236)},
        {"10111101", char(237)},
        {"10111110", char(238)},
        {"10111111", char(239)},
        {"11000000", char(240)},
        {"11000001", char(241)},
        {"11000010", char(242)},
        {"11000011", char(243)},
        {"11000100", char(244)},
        {"11000101", char(245)},
        {"10000101", char(246)},
        {"11000110", char(247)},
        {"11000111", char(248)},
        {"11001000", char(249)},
        {"11001001", char(250)},
        {"11001010", char(250)},
        {"11001011", char(251)},
        {"11001100", char(252)},
        {"11001101", char(253)},
        {"11001110", char(254)},
        {"11001111", char(255)},
        {"11010000", '!'},
        {"11010001", '@'},
        {"11010010", '#'},
        {"11010011", '$'},
        {"11010100", '%'},
        {"11010101", '^'},
        {"11010110", '&'},
        {"11010111", '*'},
        {"11011000", '('},
        {"11011001", ')'},
        {"11011010", '-'},
        {"11011011", '_'},
        {"11011100", '+'},
        {"11011101", '='},
        {"11011110", '['},
        {"11011111", '{'},
        {"11100000", ']'},
        {"11100001", '}'},
        {"11100010", '|'},
        {"11100011", '/'},    
    };
const std::map<char, std::string> OTP::ascii2binaryTable {
    {'0', "00000001"},
    {'1', "00000010"},
    {'2', "00000011"},
    {'3', "00000100"},
    {'4', "00000101"},
    {'5', "00000110"},
    {'6', "00000111"},
    {'7', "00001000"},
    {'8', "00001001"},
    {'9', "00001010"},
    {'a', "00001011"},
    {'b', "00001100"},
    {'c', "00001101"},
    {'d', "00001110"},
    {'e', "00001111"},
    {'f', "00010000"},
    {'g', "00010001"},
    {'h', "00010010"},
    {'i', "00010011"},
    {'j', "00010100"},
    {'k', "00010101"},
    {'l', "00010110"},
    {'m', "00010111"},
    {'n', "00011000"},
    {'p', "00011001"},
    {'q', "00011010"},
    {'r', "00011011"},
    {'s', "00011100"},
    {'t', "00011101"},
    {'u', "00011110"},
    {'v', "00011111"},
    {'w', "11100011"},
    {'y', "11100100"},
    {'z', "11100101"},
    {'A', "11100110"},
    {'B', "11100111"},
    {'C', "11101000"},
    {'D', "11101001"},
    {'E', "11101010"},
    {'F', "11101011"},
    {'G', "11101100"},
    {'H', "11101101"},
    {'I', "11101110"},
    {'J', "11101111"},
    {'K', "11110000"},
    {'L', "11110001"},
    {'M', "11110010"},
    {'N', "11110011"},
    {'O', "11110100"},
    {'P', "11110101"},
    {'Q', "11110110"},
    {'R', "11110111"},
    {'S', "11111000"},
    {'T', "11111001"},
    {'U', "11111010"},
    {'V', "11111011"},
    {'X', "11111100"},
    {'W', "11111101"},
    {'Y', "11111110"},
    {'Z', "11111111"},
    {char(162), "01111111",},
    {char(163), "10000000",},
    {char(164), "10000001",},
    {char(165), "10000010",},
    {char(166), "10000011",},
    {char(167), "10000100",},
    {char(168), "10000101",},
    {char(169), "10000110",},
    {char(170), "10000111",},
    {char(171), "10001000",},
    {char(172), "10001001",},
    {char(174), "10001010",},
    {char(177), "10001011",},
    {char(180), "10001100",},
    {char(187), "10001101",},
    {char(191), "10001110",},
    {char(192), "10001111",},
    {char(193), "10010001",},
    {char(194), "10010010",},
    {char(195), "10010011",},
    {char(196), "10010100",},
    {char(197), "10010101",},
    {char(198), "10010110",},
    {char(199), "10010111",},
    {char(200), "10011000",},
    {char(201), "10011001",},
    {char(202), "10011010",},
    {char(203), "10011011",},
    {char(204), "10011100",},
    {char(205), "10011101",},
    {char(206), "10011110",},
    {char(207), "10011111",},
    {char(208), "10100000",},
    {char(209), "10100001",},
    {char(210), "10100010",},
    {char(211), "10100011",},
    {char(212), "10100100",},
    {char(213), "10100101",},
    {char(214), "10100110",},
    {char(215), "10100111",},
    {char(216), "10101000",},
    {char(217), "10101001",},
    {char(218), "10101010",},
    {char(219), "10101011",},
    {char(220), "10101100",},
    {char(221), "10101101",},
    {char(222), "10101110",},
    {char(223), "10101111",},
    {char(224), "10110000",},
    {char(225), "10110001",},
    {char(226), "10110010",},
    {char(227), "10110011",},
    {char(228), "10110100",},
    {char(229), "10110101",},
    {char(230), "10110110",},
    {char(231), "10110111",},
    {char(232), "10111000",},
    {char(233), "10111001",},
    {char(234), "10111010",},
    {char(235), "10111011",},
    {char(236), "10111100",},
    {char(237), "10111101",},
    {char(238), "10111110",},
    {char(239), "10111111",},
    {char(240), "11000000",},
    {char(241), "11000001",},
    {char(242), "11000010",},
    {char(243), "11000011",},
    {char(244), "11000100",},
    {char(245), "11000101",},
    {char(246), "10000101",},
    {char(247), "11000110",},
    {char(248), "11000111",},
    {char(249), "11001000",},
    {char(250), "11001001",},
    {char(250), "11001010",},
    {char(251), "11001011",},
    {char(252), "11001100",},
    {char(253), "11001101",},
    {char(254), "11001110",},
    {char(255), "11001111",},
    {'!', "11010000"},
    {'@', "11010001"},
    {'#', "11010010"},
    {'$', "11010011"},
    {'%', "11010100"},
    {'^', "11010101"},
    {'&', "11010110"},
    {'*', "11010111"},
    {'(', "11011000"},
    {')', "11011001"},
    {'-', "11011010"},
    {'_', "11011011"},
    {'+', "11011100"},
    {'=', "11011101"},
    {'[', "11011110"},
    {'{', "11011111"},
    {']', "11100000"},
    {'}', "11100001"},
    {'/', "11100011"},    
    {'|', "11100010"},
};


std::vector<std::string> OTP::binaryVector(const std::string &binary) {
    std::string tempBinary = "";
    std::vector<std::string> binaryList;
    for (int i = 0; i < binary.length(); ++i) {
        if (binary[i] == ' ') {
            binaryList.push_back(tempBinary);
            tempBinary = ""; 
        } else {
            std::string s(1, binary[i]);
            tempBinary += s;
        }
        
    }
    return binaryList;
}

int OTP::binary2dec(const std::string &binary) {
    int decimal = 0;
    for (int i = 0; i < binary.length(); ++i) {
        if (binary[i] == '1') {
            decimal += std::pow(2, binary.length() - 1 - i);
        }
    }
    return decimal;
}

char OTP::binary2char(const std::string &binary) {
    char ascii = (char)binary2dec(binary);
    return ascii;
}

std::string OTP::char2binary(const char &c) {
    std::bitset<8> b(c);
    return b.to_string();
}

std::string OTP::string2binary(const std::string &str) {
    std::string binary;
    for (char c : str) {
        std::bitset<8> bits(c);
        binary += bits.to_string();
        binary += ' ';
    }
    return binary;
}

std::string OTP::binary2string(const std::string &binary) {
    std::string out;
    std::vector<std::string> binaryList = binaryVector(binary);
    for (int i = 0; i < binaryList.size(); ++i) {
        char c = binary2char(binaryList[i]);
        std::string s2(1, c);
        out += s2;
    }
    return out;
}

std::string OTP::XOR(char bitA, char bitB) {
    if (bitA == bitB) {
        return "0";
    }
    return "1";
}

std::string OTP::correctBinary(const std::string &binary) {
    std::string correctedBinary = "";
    char inBinaryChar;
    std::string nullBinary = "00000000";
    std::vector<std::string> binaryList = binaryVector(binary);
    for (int i = 0; i < binaryList.size(); ++i) {
        int decimal = binary2dec(binaryList[i]);
        if ((decimal < 32 || decimal > 126) && decimal != 0) {
            inBinaryChar = binary2asciiTable.at(binaryList[i]);
            correctedBinary +=  char2binary(inBinaryChar) + ' ' + nullBinary;
        } else {
            correctedBinary += binaryList[i];
        }
        correctedBinary += ' ';
    }   
    return correctedBinary;
}

std::string OTP::revertBackToOriginalBinary(const std::string &binary) {
    std::vector<std::string> binaryList = binaryVector(binary);
    int textLen = binaryList.size();
    std::string nullBinary = "00000000";
    std::string originalBinary = "";
    for (int i = 0; i < textLen; ++i) {
        if (i+1 < textLen && binaryList[i+1] == nullBinary && binaryList[i] != nullBinary) {
            if (i+2 < textLen && binaryList[i+1] == binaryList[i+2]) {
                try {
                    char c = binary2char(binaryList[i]);
                    originalBinary += ascii2binaryTable.at(c) + ' ' + binaryList[i+1] + ' ';
                } catch (...) {
                    originalBinary += binaryList[i] + ' ' + binaryList[i+1] + ' ';
                }
                i += 2;
            } else {
                char c = binary2char(binaryList[i]);
                originalBinary += ascii2binaryTable.at(c) + ' ';
                i++;
            }
        } else {
            if (i < textLen) {
                originalBinary += binaryList[i] + ' ';   
            }
        }

    }
    return originalBinary;
}

std::string OTP::oneTimePad(std::string textA, std::string textB) {
    std::string binaryA, binaryB;
    std::string out = "";
    binaryA = revertBackToOriginalBinary(string2binary(textA));
    binaryB = revertBackToOriginalBinary(string2binary(textB));
    for (int i = 0; i < binaryA.length(); i++) {
        if (binaryA[i] == ' ') {
            out += ' ';
        } else {
            out += XOR(binaryA[i], binaryB[i]);
        }
    }
    out = correctBinary(out);
    return binary2string(out);
}

std::string OTP::generateOneTimePadKey(const std::string &text) {
    std::string key;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(33, 126);
    for (int i = 0; i < text.length(); ++i) {
        key += char(dis(gen));
    }
    return key;
}

