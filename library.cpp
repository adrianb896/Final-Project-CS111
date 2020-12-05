#include <iostream>
#include <fstream>
#include "library.h"
using namespace std;

void collect_one_driver(ifstream& input, Driver& d) {
  input >> d.position;
  input.ignore();
  getline(input, d.name, ',');
  getline(input, d.team, ',');
  input >> d.points;
}

void display_one_driver(Driver d) {
  cout << "\nDrivers position is: " << d.position << ", " << "his name is " << d.name << ", " << "they are on team " << d.team << ", " << "with an overall points of " << d.points << endl;
}