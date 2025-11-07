#include <algorithm>    // for std::find method
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    // Handle arguments
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    const std::vector<std::string> listofArgs{"-h", "--help", "--version", "-i",
                                              "-o"};

    // -h and --help flag handling
    const char* helptext = "Usage: mpags-cipher [-h/--help]\n"
                           "Options:\n"
                           "    --help: Displays this message.";
    // change to for loop with boolean flag
    for (std::size_t i = 1; i != cmdLineArgs.size(); i++) {
        std::string option{cmdLineArgs[i]};

        if (option == "-h" || option == "--help") {
            std::cout << helptext << std::endl;
            return 0;
        }
        if (option == "--version") {
            std::cout << "mpags-cipher version 0.1.0" << "\n";
            return 0;
        }
        if (option == "-i") {
            const std::string input_file{cmdLineArgs[i + 1]};
            i++;
            if (std::find(listofArgs.begin(), listofArgs.end(), input_file) !=
                listofArgs.end()) {
                // if the element following -i is another option
                std::cout << "Argument Error: missing input file" << "\n";
                return 1;
            } else if (input_file == "") {
                std::cout << "Argument Error: missing input file" << "\n";
                return 1;
            }
        }
        if (option == "-o") {
            const std::string output_file{cmdLineArgs[i + 1]};
            i++;
            if (std::find(listofArgs.begin(), listofArgs.end(), output_file) !=
                listofArgs.end()) {
                // if the element following -i is another option
                std::cout << "Argument Error: missing output file" << "\n";
                return 1;
            } else if (output_file == "") {
                std::cout << "Argument Error: missing output file" << "\n";
                return 1;
            }
        }
    }

    // Initialise variables
    char c{'x'};
    std::string out_text;

    // loop over each character from user input
    while (std::cin >> c) {
        // Uppercase alphabetic characters
        if (std::isalpha(c)) {
            out_text += std::toupper(c);
            continue;
        }

        // Transliterate digits to English words
        switch (c) {
            case '0':
                out_text += "ZERO";
                break;
            case '1':
                out_text += "ONE";
                break;
            case '2':
                out_text += "TWO";
                break;
            case '3':
                out_text += "THREE";
                break;
            case '4':
                out_text += "FOUR";
                break;
            case '5':
                out_text += "FIVE";
                break;
            case '6':
                out_text += "SIX";
                break;
            case '7':
                out_text += "SEVEN";
                break;
            case '8':
                out_text += "EIGHT";
                break;
            case '9':
                out_text += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << out_text << std::endl;
}