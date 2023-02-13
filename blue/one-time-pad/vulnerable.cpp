#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include "one-time-pad.h"

static OTP otp;

int main() {
    std::string filename = "key.txt";
    std::string filename2 = "secret-text.txt";
    std::string filename3 = "secret-not-null.txt";
    std::string filename4 = "fake-secret-not-null.txt";
    std::string databasename = "database.txt";
    std::ifstream file(filename);
    std::ifstream file2(filename2);
    std::ifstream file3(filename3);
    std::ifstream file4(filename4);
    std::string secret_text, input1, input2, input3, fake_secret, masterKey, secretNotNull, database, fakeSecretNotNull;
    std::string tempPass = "0";

    std::getline(file3, secretNotNull);
    std::getline(file2, fake_secret);
    std::getline(file, masterKey);
    std::getline(file4, fakeSecretNotNull);

    secret_text = otp.oneTimePad(masterKey, fake_secret);

    int attempts = 3;
    bool correct = false;

    while (input1 != "Q") {
        std::cout << "Please provide an option to continue [C (Check admin password) | E (Encrypt text)) | L (Admin Panel) | Q (Quit)]: ";
        std::cin >> input1;
        std::cout << std::endl;


        if (input1 == "C") {
            std::cout << "Please type the key to retrieve password: ";
            std::cin >> input2;
            std::cout << std::endl;
            std::string pass_try = otp.oneTimePad(fake_secret, input2);
            if (pass_try != secret_text) {
                std::cout << "Admin password is: " << fake_secret << std::endl;
            } else {
                std::cout << "Admin password is: " << secret_text << std::endl;
            }
            input2 = "";
            
        } else if (input1 == "E") {
            std::string key;
            while (tempPass.length() < 5 || tempPass.length() > 50) {
                int default_pass_len = 30;
                std::cout << "Provide text to be encrypted: ";
                std::cin >> tempPass;
                if (tempPass.length() != default_pass_len && (tempPass.length() < 50 && tempPass.length() > 3)) {
                    key = masterKey;
                } else if (tempPass.length() == default_pass_len) {
                    key = otp.generateOneTimePadKey(tempPass);
                } else {
                    std::cout << "Password is too short or too long. Try again (recommended 24 characters password)." << std::endl;
                    std::cout << std::endl;
                }
            }

            if (tempPass == fakeSecretNotNull) {
                tempPass = fake_secret;
            }

            std::cout << "Encrypted: " << otp.oneTimePad(tempPass, key) << std::endl;
            
        } else if (input1 == "L") {
            while (attempts > 0 || correct) {
                std::string input_password;
                std::cout << "Input admin password: ";
                std::cin >> input_password;
                std::cout << std::endl;

                if (input_password != secretNotNull) {
                    attempts--;
                    std::cout << "Wrong password. " << attempts << " attempts remaining" << std::endl;
                    std::cout << std::endl;
                } else {
                    correct = true;
                    bool init = true;
                    while (input3 != "Q") {
                        if (init) {
                            std::cout << "Welcome to the key manager. Please provide option [V (View admin secret) | M (Retrieve master key) | Q (Quit)]: ";
                        }
                        else {
                            std::cout << "Provide option [V (View admin secret) | M (Retrieve master key) | Q (Quit)]: ";
                        }         
                        std::cin >> input3;
                        std::cout << std::endl;
                        init = false;
                        if (input3 == "M") {
                            std::cout << "Master key: " << masterKey << std::endl;
                            std::cout << std::endl;
                        } else if (input3 == "V") {
                            std::string content;
                            std::ifstream database(databasename);
                            std::getline(database, content);
                            std::cout << content << std::endl;
                            std::cout << std::endl;
                        }  else {
                            std::cout << "Quitting..." << std::endl;
                            return 0;
                        }

                    }

                }
            }

            if (!correct) {
                std::cout << "You have been blocked." << std::endl;
                return 1;
            }
        } else {
            std::cout << "Quitting..." << std::endl;
            return 0;
        }
        tempPass = "";
        input1 = "";

    }

}

