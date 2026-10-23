/*
 * Name       : Zikriya Farooq
 * Reg No     : L1F25BSCS0986
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
// Added fstream so the file streams can be used.
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("stock.txt");
    // The error should appear when the file does not open.
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }
    // Use append mode so the old entries are not erased.
    ofstream reorder("reorder.txt", ios::app);
    char code[10];
    int qty, count = 0, low = 0;
    double price;
    // Use double because prices can have decimal values.
    double total = 0;
    // Skip the first line because it contains column names.
    inFile.ignore(100, '\n');
    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            // Add a new line after each low-stock item.
            reorder << code << " " << qty << endl;
            low++;
        }
    }
    inFile.close();
    reorder.close();
    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}
