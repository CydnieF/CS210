#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inFS;  // input file stream
    ofstream outFS; // output file stream
    string city;    // city value from file
    int degrees;    // degrees in fahrenheit value from file

    // open file to be read from
    inFS.open("FahrenheitTemperature.txt");

    // vectors to store values
    vector<string> cities;
    vector<int> degreesF;

    // add values from file
    while (!inFS.eof()) {
        // read cities and degrees
        inFS >> city >> degrees;
        // place values in perspective vectors
        cities.push_back(city);
        degreesF.push_back(degrees);
    }
    // close input file
    inFS.close();

    // open file to be written to
    outFS.open("CelsiusTemperature.txt");

    // iterate through vectors and output cities and temperature to file
    int i;
    for (i=0; i < degreesF.size(); i++) {
        // convert celsius to fahrenheit
        double degreesC = (degreesF[i] - 32) * 5.0 / 9.0;
        outFS << cities[i] << " " << degreesC << endl;
    }

    // close output file
    outFS.close();

    return 0;
}
