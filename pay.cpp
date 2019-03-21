// Kayla Nguyen
// Section 1

#include "person.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Read data"<< endl;
    cout << "2. Write data"<< endl;
    cout << "3. Exit the program" << endl;
}

void readData(vector<Person> &list) {
  ifstream inputFile;
  inputFile.open("input.txt");
  string fName, lName, line;
  float hours, rate;

    if (inputFile)
    {
      inputFile >> fName;
      while (!inputFile.eof())
      {
        //push_back may construct a temporary
        //object which then will need to get
        //moved into the vector v whereas emplace_back
        //just forwards the argument and construct it
        //directly in place with no copies or moves needed.
          inputFile >> lName >> hours >> rate;
          getline(inputFile, line);
          list.emplace_back(fName, lName, hours, rate);
          inputFile >> fName;
      }
  }
  inputFile.close();
}

void writeData(vector<Person> &list)
{
  ofstream outputFile;
  outputFile.open("output.txt");
  string fullName;
  float totalPay;

  if (outputFile)
  {
    for (int i = 0; i < list.size(); i++)
    {
      fullName = list[i].fullName();
      totalPay = list[i].totalPay();
      outputFile << fullName << " " << fixed << setprecision(2) << totalPay << endl;
      cout << fullName << " " << fixed << setprecision(2) << totalPay << endl;
    }
    outputFile.close();
  }
}

int main()
{
    int choice;
    vector<Person> list;
    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                readData(list);
                break;

            case 2:
                if (list.size() != 0) {
                  cout << endl;
                  cout << "Data has been read" << endl;
                  cout << "Writing results to output.txt" << endl;
                  cout << endl;
                  writeData(list);
                }
                else {
                  cout << endl;
                  cout << "Error: Data not read" << endl;
                }
                break;
            case 3:
                cout << endl;
                cout << "Exiting program" << endl;
                break;

            default:
                cout << endl;
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 3);
      return 0;
}
