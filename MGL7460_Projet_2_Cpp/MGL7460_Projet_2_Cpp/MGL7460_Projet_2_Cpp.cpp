#pragma warning(disable : 4996)

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

struct TIME {
    int days;
    int hours;
    int minutes;
};

string readFile(string filePath) {
    string line;
    ifstream inFile;
    inFile.open(filePath);
    if (inFile.is_open()) {
        getline(inFile, line);
        inFile.close();
        if (!line.empty()) {
            cout << line << endl;
            return line;
        }
        else {
            cout << "File '" << filePath << "' is empty..." << endl;
        }
    }
    else {
        cout << "File '" << filePath << "' not found..." << endl;
        return "";
    }

    return "";
}

string* parseFile(string filePath) {
    string fileContent = readFile(filePath);
    string* times = new string[2];

    if (!fileContent.empty()) {
        int index(fileContent.find(' '));

        times[0] = fileContent.substr(0, index);
        times[1] = fileContent.substr(index + 1, fileContent.length());
    }
    
    return times;
}

TIME parseTime(string time_str) {
    string::size_type sz;
    int time = std::stoi(time_str, &sz);
    TIME result;

    result.days = time / 86400;
    time = time % 86400;

    result.hours = time / 3600;
    time = time % 3600;

    result.minutes = time / 60;
    time = time % 60;

    return result;
}

void displayTime(string timeType, TIME time) {
    auto now = std::chrono::system_clock::now();
    time_t test = chrono::system_clock::to_time_t(now);
    tm tmtest = *localtime(&test);

    cout << setw(2) << setfill('0') << tmtest.tm_hour << ":" << setw(2) << setfill('0') << tmtest.tm_min << ":" << setw(2) << setfill('0') << tmtest.tm_sec << timeType;

    if (time.days == 1) {
        cout << "1 day";
    }
    else if (time.days > 1) {
        cout << time.days << " days, ";
    }

    if (time.hours > 0) {
        cout << time.hours << ":";
    }

    cout << setw(2) << setfill('0') << time.minutes << ((time.hours == 0) ? " min" : "") << endl;
}

int main() {
    TIME uptime, idletime;
    string uptime_file = "../uptime_file.txt";
    string* times = parseFile(uptime_file);

    if (!times[0].empty()) {
        uptime = parseTime(times[0]);
        idletime = parseTime(times[1]);

        displayTime(" up ", uptime);
        displayTime(" idle ", idletime);
    }
}