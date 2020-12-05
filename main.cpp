#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
#include <iomanip>
using namespace std;

int main() {
  cout << "Welcome to the 2020 Grand Prix! This is where you will find all the information you will need to become an expert with the stats on which Formula 1 driver is performing at there best and which driver is not performing at there best. In formula 1 it's all about which car is the fastest and how a team can improve their lap time and there engine.\n";

  Driver drivers[50];
  int num_drivers = 0;
  ifstream input("input.dat");
  if (input.is_open()) {
    while (!input.eof()) {
      collect_one_driver(input, drivers[num_drivers]);
      num_drivers++;
    }
  }
  input.close();

  for (int i = 0; i < num_drivers; i++)
    display_one_driver(drivers[i]);

  cout << "\nThere will be a total of 8 options to choose from.";
  cout << "\n1. Enter 1 if you would like to find out which player has the most points." << "\n2. Enter 2 if you would like to find out which player has the least amount of points." << "\n3. Enter 3 if you would like to find out who had the fastest lap." << "\n4. Enter 4 if you would like to find out who had the slowest lap." << "\n5. Enter 5 if you want to find out the average lap time." << "\n6. Enter 6 if you want me to show you the stats for the drivers." << "\n7. Enter 7 if you would like me to display the fastest lap for each race that has occured in the 2020 season." << "\n8. Enter 8 if you would like to exit the program." << endl;
  cout << "Which option would you like to go with? " << endl;

  return 0;
}