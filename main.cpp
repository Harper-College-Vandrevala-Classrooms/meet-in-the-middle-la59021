#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<int> makeArray(string rawString) {
    string digits;
    vector<int> contents;
    for (auto i : rawString) {
        if (i != ',') {
            digits += i;
        }
        else if (i == ',' && !digits.empty()) {
            contents.insert(contents.end(), stoi(digits));
            digits = "";
        }
        else if (i == ',' && digits.empty()) {}
    }
    if (!digits.empty()) {
        contents.insert(contents.end(), stoi(digits));
    }
    if (contents.size() == 0) {
        cout << "Error: no numbers found" << endl;
    }
    return contents;
}


void printToFile(string directory) {
    ifstream myfile(directory);
    if (!myfile.is_open()) {
        cout << "Error opening file: " << directory << endl;
        return;
    }

    string line, raw;
    while (getline(myfile, line)) {
        raw += line;
        raw += ",";
    }
    myfile.close();

    if (raw.empty()) {
        cout << "Error reading file: empty contents" << endl;
        return;
    }

    vector<int> contents = makeArray(raw);
    int sum = 0, count = 0;
    double median = 0, mean = 0;

    // sum
    for (int i : contents) {
        sum += i;
    }

    // count
    count = contents.size();

    //median
    if (count % 2 == 0) {
        int middleUp = contents[(count + 1) / 2];
        int middleDown = contents[(count - 1) / 2];
        median = (middleUp + middleDown) / 2;
    }
    else {
        median = contents[count / 2];
    }

    //mean
    mean = sum/count;

    cout << "Sum: " << sum << endl;
    cout << "Count: " << count << endl;
    cout << "Median: " << median << endl;
    cout << "Mean: " << mean << endl;
}

int main() {
    string myfile;
    cout << "Enter the name of the file: ";
    getline(cin, myfile);
    printToFile(myfile);
}