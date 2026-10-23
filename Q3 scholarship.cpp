/*
 * Name       : Zikriya Farooq
 * Reg No     : L1F25BSCS0986
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char path[100];
    cout << "Enter the file name: ";
    cin.getline(path, 100);
    ifstream inFile(path);
    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }
    int n = 0;
    inFile >> n;
    if (n > 30) {
        cout << "Too many students!" << endl;
        inFile.close();
        return 0;
    }
    inFile.ignore(100, '\n');
    ofstream scholarship("scholarship.txt");
    if (!scholarship) {
        inFile.close();
        return 1;
    }
    char name[30], topName[30];
    double cgpa, total = 0, highest = -1;
    int count = 0, eligible = 0;
    while (count < n && inFile.getline(name, 30, ',') && inFile >> cgpa) {
        inFile.ignore(100, '\n');
        cout << "[" << name << "] CGPA: " << cgpa << endl;
        count++;
        total = total + cgpa;
        if (cgpa >= 3.5) {
            eligible++;
            scholarship << name << "," << cgpa << endl;
        }
        if (cgpa > highest) {
            highest = cgpa;
            int i = 0;
            while (name[i] != '\0') {
                topName[i] = name[i];
                i++;
            }
            topName[i] = '\0';
        }
    }
    inFile.close();
    scholarship.close();
    if (count < n)
        cout << "Warning: only " << count << " of " << n << " records found." << endl;
    if (count == 0) {
        cout << "No students found!" << endl;
        return 0;
    }
    cout << "Students: " << count << endl;
    cout << "Average CGPA: " << total / count << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << topName << " (" << highest << ")" << endl;
    return 0;
}
