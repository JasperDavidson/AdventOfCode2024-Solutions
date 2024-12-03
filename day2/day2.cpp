#include <iostream>
#include <fstream>

#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

bool valid_report(std::vector<int> report, bool secondTime) {
    int trend = 0; // 0 if decreasing, 1 if increasing
    if (report [1] - report[0] > 0) {
        trend = 1;
    }

    for (int i = 0; i < report.size() - 1; i++) {
        int value = report[i + 1] - report[i];

        if ((value < 0) && trend) {
            if (!secondTime) {
                for (int i = 0; i < report.size(); i++) {
                    std::vector<int> temp = report;
                    temp.erase(temp.begin() + i);
                    if (valid_report(temp, true)) {
                        return true;
                    }
                }
            }

            return false;
        } else if ((value > 0 && !trend)) {
            if (!secondTime) {
                for (int i = 0; i < report.size(); i++) {
                    std::vector<int> temp = report;
                    temp.erase(temp.begin() + i);
                    if (valid_report(temp, true)) {
                        return true;
                    }
                }
            }

            return false;
        }

        if (std::abs(value) > 3 || std::abs(value) == 0) {
            if (!secondTime) {
                for (int i = 0; i < report.size(); i++) {
                    std::vector<int> temp = report;
                    temp.erase(temp.begin() + i);
                    if (valid_report(temp, true)) {
                        return true;
                    }
                }
            }

            return false;
        }
    }

    return true;
}

void count(std::ifstream &file) {
    std::string line;
    int valid_report_count = 0;
    int processed_reports = 0;

    while (std::getline(file, line)) {
        std::vector<int> report;

        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            report.push_back(number);
        }

        if (valid_report(report, false)) {
            valid_report_count++;
        }
    }

    std::cout << valid_report_count << std::endl;
}

int main() {
    std::ifstream file("input.txt");
    
    if (file.is_open()) {
        count(file);
    }

    return 0;
}