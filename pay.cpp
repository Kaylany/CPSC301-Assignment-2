#include "person.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void readData(Person array[], int size);
void writeData(Person array[], int size);

void readData(Person array[], int size) {
  string fName, lName;
  float hours, rate;
  int i = 0;
  
  ifstream inputFile;
  inputFile.open("input.txt");

    if (inputFile.is_open())
    {
      while (!inputFile.eof())
      {
          inputFile >> fName >> lName >> hours >> rate;
          array[i].setFirstName(fName);
          array[i].setLastName(lName);
          array[i].setHoursWorked(hours);
          array[i].setPayRate(rate);
          i++;
      }
      inputFile.close();
    }
    else {
      cout << "Unable to open file";
    }
  }

void writeData(Person array[], int size)
{
  ofstream outputFile;
  outputFile.open("output.txt");
  if (outputFile.is_open())
  {
    for (int i = 0; i < size; i++)
    {
      outputFile << array[i].fullName() << " " << fixed << setprecision(2) << array[i].totalPay() << endl;
      cout << array[i].fullName() << " " << fixed << setprecision(2) << array[i].totalPay() << endl;
    }
    outputFile.close();
  }
  else
  {
    cout << "Unable to open file";
  }
}

int main()
{
  int size = 20;
  Person array[size];
  readData(array, 6);
  writeData(array, 6);
  return 0;
}
