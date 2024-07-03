#include <iostream>
#include <string>
#include <algorithm>
#include "lib/cboslib.hpp"

using namespace std;

int main() {
    ccout("Booting cbos the crappy os\n");
    msleep(500);
    ccout("Loading libraries and variables\n");
    float version = 1.01;
    msleep(300);
    ccout("Done!\n");
    msleep(200);
    ccout("Welcome to C-Bos v1.0.1!\n");
    msleep(200);
    ccout("Type help for a list of commands!\n");

    bool cmdloop = true;
    while (cmdloop) {
        string cmd;
        cout << "\033[32m> \033[0m";  // Yellow color for the prompt
        getline(cin, cmd);
        string lowercmd = cmd;
        transform(lowercmd.begin(), lowercmd.end(), lowercmd.begin(), ::tolower);
        
        if (lowercmd == "run test") {
            cout << "It is working!" << endl;
        }
        
        else if (lowercmd == "shut down" || lowercmd == "exit") {
            cout << "Shutting Down..." << endl;
            msleep(500);
            return 0;
        }

        else if (lowercmd == "help") {
            ccout("1: Run test (it was in the original so I put it here idk)\n");
            msleep(100);
            ccout("2: Exit (Exits the program wowie)\n");
            msleep(100);
            ccout("3: How to add a command (Shows a guide on how to add a command)\n");
            msleep(100);
            ccout("4: Base64 encode (encodes text)\n");
            msleep(100);
            ccout("5: Base64 decode (decodes text)\n");
        }

        else if (lowercmd == "how to add a command") {
            ccout("First you need to decide if you want to publish it\n");
            msleep(500);
            string publishchoice;
            ccout("Do you want to publish it? [Y/N]: ");
            getline(cin, publishchoice);
            transform(publishchoice.begin(), publishchoice.end(), publishchoice.begin(), ::tolower);
            msleep(500);
            if(publishchoice == "y") {
                ccout("Fork the cbos github repo\n");
                msleep(500);
                ccout("Then install the github desktop app\n");
                msleep(500);
                ccout("Then use github desktop to clone your fork to your machine\n");
                msleep(500);
            } else if (publishchoice == "n") {
                ccout("Download the cbos source code from github\n");
                msleep(500);
            } else {
                ccout("Not y or n. Too lazy to make it exit the command so this just leaves out some of the guide\n");
            }

            ccout("Then go into main.cpp\n");
            msleep(500);
            ccout("And right below the bottom else if add another elseif\n");
            msleep(500);
            ccout("Example: else if (lowercmd == \"this can be whatever you want the command to be\") {code to run}\n");
            msleep(500);
            ccout("You can probably figure out how to make a function in cboslib.hpp and if not tell me to add a guide for that\n");
            msleep(500);
        }

        else if (lowercmd == "base64 encode") {
            string encodestring;
            cout << ("String to encode: ");
            getline(cin, encodestring);
            cout << base64encode(encodestring);
            cout << "\n";
        }

        else if (lowercmd == "base64 decode") {
            string decodestring;
            cout << ("String to decode: ");
            getline(cin, decodestring);
            cout << base64decode(decodestring);
            cout << "\n";
        }



        else {
            cout << cmd + " is stupid! please try again!\n";
        }
    }
}
