#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <random>



std::string stringToBinary(std::string const &text) {
	std::string binary = "";
	for (char const &c: text) {
		binary  += std::bitset<8>(c).to_string() + ' ';
	}
	return binary;
}

std::string binaryToString(std::string const &binaryStr) {
	std::string text = "";
	std::string binaryValue = "";
	std::vector<std::string> binaryList;
	int textLen = 0;

	for (int i = 0; i < binaryStr.length(); ++i) {
		if (binaryStr[i] == ' ') {
			textLen += 1;
			binaryList.push_back(binaryValue);
			binaryValue = "";
		} else {
			std::string s(1,binaryStr[i]);
			binaryValue += s;
		}
	}



	for (int j = 0; j < textLen; ++j) {
		std::bitset<8> binary(binaryList[j]);
		char c = static_cast<char>(binary.to_ulong());
		std::string s2(1, c);
		text += s2;
	}

	return text;
}

std::string exclusiveOr(char bitA, char bitB) {
	std::string output;

	if (bitA == bitB) {
		return "0";
	}

	return "1";
}

std::string bitwiseXOR(std::string textA, std::string textB) {
	if (textA.length() != textB.length()) {
		throw std::invalid_argument("Length of textA and textB do not match.");
	}

	std::string output = "";
	std::string textBinaryA, textBinaryB;

	textBinaryA = stringToBinary(textA);
	textBinaryB = stringToBinary(textB);


	for (int i = 0; i < textBinaryA.length(); ++i) {
		if (textBinaryA[i] == ' ') {
			output += ' ';
		} else {
		output += exclusiveOr(textBinaryA[i], textBinaryB[i]);
		}
	}
	return output;
}

std::string generateOneTimePadKey(const std::string &text) {
	std::string key;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(33, 126);

	for (int i = 0; i < text.length(); i++) {
 		key += char(dis(gen));
	}

	return key;
}


int main() {
	std::string plainText, key, output;
	std::cout << "Enter a string: ";
	std::getline(std::cin, plainText);

	key = generateOneTimePadKey(plainText);

	std::cout << "Plain text input: " << plainText << std::endl;
	
	std::cout << "Key generated is: " << key << std::endl;

	std::string ciphertextBinary = bitwiseXOR(plainText, key);

	std::string ciphertext = binaryToString(ciphertextBinary);

	std::cout << "Cipher text generated: " << ciphertext << std::endl;
	
	return 0;
	
}
