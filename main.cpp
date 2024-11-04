#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printToFile(string directory) {
    ifstream myfile(directory);
    if (!myfile.is_open()) {
        cout << "Error opening file: " << directory << endl;
        return;
    }

    string mytext, contents;
    while (getline(myfile, mytext)) {
        contents += mytext;
    }
    myfile.close();

    if (contents.empty()) {
        cout << "Error reading file: empty contents" << endl;
        return;
    }

    cout << contents << endl;
    string presum;
    int sum = 0;
    int count = 0;
    for (int x = 0; x < contents.size(); x++) {
        char input = contents[x];
        if (input != ',') {
            presum += input;
        }
        else if (input == ',') {
            if (!presum.empty()) {
                sum += stoi(presum);
                count++;
                presum = "";
            }
        }
    }
    if (!presum.empty()) {
        sum += stoi(presum);
        count++;
    }

    if (count == 0) {
        cout << "Error: no numbers found" << endl;
        return;
    }

    cout << "Sum: " << sum << endl;
    cout << "Count: " << count << endl;
    cout << "Avg: " << (double)sum / count << endl;
}

int main() {
    string myfile;
    cout << "Enter the name of the file: ";
    cin >> myfile;
    printToFile(myfile);
}