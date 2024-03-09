/*
 *        File: encryption.cc
 *      Author: Alex Vano
 *        Date: 10/20/2023
 * Description: Encrypting data
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void displayMenu () {
    cout << "Choose which to run:" << endl;
    cout << "1. Set Key" << endl;
    cout << "2. Encrypt" << endl;
    cout << "3. Decrypt" << endl;
    cout << "4. Exit" << endl;
}

 int main() {
    ifstream inStream;
    ofstream outStream;

    int choice, key;
    key = 3; //default

    string fileName;
    do {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            //call the set key function and assign to key
                cout << "Current Key: " << key << endl;
                cout << "Set Key (1-10): ";
                cin >> key;
                choice = 0;
        } else if (choice == 2) {
            //call the encryption function
            string contents = "";

            cout << "Enter filename: ";
            cin >> fileName;

            cout << endl;

            inStream.open(fileName);

            char c;
            while(inStream.get(c)) {
                c = c + key;
                contents = contents + c;
            }

            cout << contents;

            inStream.close();

            outStream.open(fileName);
            outStream << contents;
            outStream.close();

            cout << endl;
            cout << endl;

        } else if (choice == 3) {
            //call the decryption function
            string contents = "";

            cout << "Enter filename: ";
            cin >> fileName;

            cout << endl;

            inStream.open(fileName);

            char c;
            while(inStream.get(c)) {
                c = c - key;
                contents = contents + c;
            }

            cout << contents;

            inStream.close();

            outStream.open(fileName);
            outStream << contents;
            outStream.close();

            cout << endl;
            cout << endl;
        }
    } while (choice != 4);
    return 0;
 }