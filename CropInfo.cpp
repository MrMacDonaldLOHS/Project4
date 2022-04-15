#include "CropInfo.h"
#include "ReadUtils.h"
#include <iostream>
using namespace std;
CropInfo::CropInfo(){
    cropCode = 0;
    for (int index = 0; index < MAX_NAME_LEN; index++) {
        name[index] = '\0';
    }
    for (int index = 0; index < NUM_YEARS; index++) {
        yieldsByYear[index] = 0;
    }
}

void CropInfo::readFromFile(istream &file) {
    file >> cropCode;
    file.ignore(100, ';');
    file.getline(name, MAX_NAME_LEN, ';');
    for (int index = 0; index < NUM_YEARS; index++) {
        file >> yieldsByYear[index];
        // Either ignore the ; or \n after each year.
        if (file.peek() != EOF) {
            file.ignore(1, file.peek());
        }
    }
}
void CropInfo::readFromUser(){
    cropCode = readDouble("Enter the crop code: ");
    cin.ignore(100, '\n');
    cout << "Enter the crop name: ";
    cin.getline(name, MAX_NAME_LEN);
    for (int index = 0; index < NUM_YEARS; index++) {
        // Create the prompt here, no prompt sent to readDouble.
        cout << "Enter the yield for the year " <<  START_YEAR + index << ": ";
        yieldsByYear[index] = readDouble("");
    }
}
void CropInfo::print(ostream &out){
    out << cropCode << ";";
    out << name;
    for (int index = 0; index < NUM_YEARS; index++) {
        out << ";"; // Print the semi-colon for the prior entry so we can end with \n
        out << yieldsByYear[index];
    }
    out << endl; // The last entry does not have a ';' instead it ends with a \n
}

// Returns whether the cropCode is between the two values passed in.
bool CropInfo::codeIsBetween(double lowerBound, double upperBound){
    return (cropCode >= lowerBound && cropCode <= upperBound);
}
