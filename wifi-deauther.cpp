#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void usage() {
    cout << "Usage: wifi-deauther [-t] [-mM]\n     -t   Time to deauth in seconds, default is 15s (example: -t 120)\n     -m   MAC of specific device\n     -M   MAC of router/hotspot (deauth all connected devices)";
    exit(0);
}

void error1() {
    cout << "Error #1: Invalid arguments";
    exit(-1);
}
void error2() {
    cout << "Error #2: Invalid argument for time. Did you enter a word instead of a number?";
    exit(-2);
}
void error3() {
    cout << "Error #3: Time value is out of range. Please, enter a number in range of [1] - [9.223.372.036.854.775.807]";
    exit(-3);
}
void error4() {
    cout << "Error #4: Time value is smaller than 0. Please, enter a number in range of [1] - [9.223.372.036.854.775.807]";
    exit(-4);
}

int main(int argc, char *argv[])
{
    __int64 int_time_argv = 15;
    int i = 0, g = 1;
    bool help = false;
    string string_time_argv, temp, temp_next, device_mac_argv, hotspot_mac_argv;
    for (; i < argc; i++) {
        temp = argv[i];
        if (i != argc - 1)
        temp_next = argv[g];
        if (temp == "--help" || temp == "-h" || argc <= 2) {
            usage();
        }
        else {
            if (temp == "-t") {
                if (temp_next == "-m" || temp_next == "-M")
                    error1();
                string_time_argv = temp_next;
            }
            if (temp == "-m") {
                if (temp_next == "-t" || temp_next == "-M")
                    error1();
                device_mac_argv = temp_next;
            }
            if (temp == "-M") {
                if (temp_next == "-t" || temp_next == "-m")
                    error1();
                hotspot_mac_argv = temp_next;
            }
        }
        g++;
    }
    try {
        if (string_time_argv.size() != 0) {
            int_time_argv = stoi(string_time_argv);
            if (int_time_argv <= 0)
                error4();
        }
    }
    catch(const invalid_argument& ia) {
        error2();
    }
    catch (const out_of_range& oor) {
        error3();
    }
}
