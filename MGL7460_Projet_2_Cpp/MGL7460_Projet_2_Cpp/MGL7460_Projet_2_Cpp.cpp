#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

struct TIME {
    int days;
    int hours;
    int minutes;
};

string readFile(string filePath) {
    return "";
}

string* parseFile(string filePath) {
    string fileContent = readFile(filePath);
    string times[2] = { "", "" };

    return times;
}

TIME parseTime(string time) {
    return {};
}

void displayTime(string timeType, TIME time) {
    auto now = std::chrono::system_clock::now();
    time_t test = chrono::system_clock::to_time_t(now);
    tm tmtest;
    localtime_s(&tmtest, &test);
    cout << tmtest.tm_hour<< ":"
        << tmtest.tm_min << ":"
        << tmtest.tm_sec << ":" << endl;
}

int main() {
    TIME uptime, idletime;
    string uptime_file = "uptime_file";
    string* times = parseFile(uptime_file);

    uptime = parseTime(times[0]);
    idletime = parseTime(times[1]);

    displayTime("up", uptime);
    displayTime("idle", idletime);
}
