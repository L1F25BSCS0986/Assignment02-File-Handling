/*
 * Name       : Zikriya Farooq
 * Reg No     : L1F25BSCS0986
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("parking.txt");
    if (!inFile) {
        cout << "parking.txt not found!" << endl;
        return 1;
    }
    int d, m, y;
    char slash;
    if (!(inFile >> d >> slash >> m >> slash >> y)) {
        inFile.close();
        cout << "No vehicles found!" << endl;
        return 0;
    }
    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');
    ofstream receipts("receipts.txt");
    if (!receipts) {
        inFile.close();
        return 1;
    }
    cout << "Parking report for " << d << "/" << m << "/" << y << endl;
    receipts << "Receipts for " << d << "/" << m << "/" << y << endl;
    char plate[15], longestPlate[15], type, colon;
    int inHour, inMinute, outHour, outMinute;
    int count = 0, cars = 0, bikes = 0, total = 0, longest = -1;
    while (count < 30 && inFile >> plate >> type
           >> inHour >> colon >> inMinute >> outHour >> colon >> outMinute) {
        int minutes = outHour * 60 + outMinute - inHour * 60 - inMinute;
        int hours = (minutes + 59) / 60;
        if (hours == 0)
            hours = 1;
        int fee;
        cout << plate;
        if (type == 'C') {
            cars++;
            fee = hours * 100;
            cout << " Car ";
        } else {
            bikes++;
            fee = hours * 40;
            cout << " Bike ";
        }
        cout << minutes / 60 << " h " << minutes % 60 << " min Fee: " << fee << endl;
        receipts << plate << " " << fee << endl;
        count++;
        total = total + fee;
        if (minutes > longest) {
            longest = minutes;
            int i = 0;
            while (plate[i] != '\0') {
                longestPlate[i] = plate[i];
                i++;
            }
            longestPlate[i] = '\0';
        }
    }
    inFile.close();
    receipts.close();
    if (count == 0) {
        cout << "No vehicles found!" << endl;
        return 0;
    }
    cout << "Vehicles: " << count << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << total << endl;
    cout << "Longest stay: " << longestPlate << " (" << longest / 60
         << " h " << longest % 60 << " min)" << endl;
    return 0;
}
