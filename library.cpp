#include <iostream>
#include <fstream>
#include "library.h"
#include <iomanip>
using namespace std;

//display a drivers data
void display_one_driver(Driver d) {
  cout << "\nDrivers position is " << d.position << ", " << "his name is " << d.name << ", " << "he is from " << d.country << ", " << "he is on team " << d.team << ", " << "with an overall points of " << d.points << endl;
}

//collect all of the drivers datas
void collect_all_drivers(Driver arr[], int& d) {
    ifstream input("input.dat");
  if (input.is_open()) {
    while(!input.eof()) {
      collect_one_driver(input, arr[d]);
      d++;
    } //end of while
  } //end of if
  input.close(); //end of while
}
//collect a drivers data
void collect_one_driver(ifstream& input, Driver& d) { 
  input >> d.position;
  input.ignore();
  getline(input, d.name, ',');
  getline(input, d.country, ',');
  getline(input, d.team, ',');
  input >> d.points;
}

//display of every driver
void display_all_drivers(Driver arr[], int d) {
  for (int i = 0; i < d; i++) {
    display_one_driver(arr[i]);
  } //end of for
}

//searching for driver
void search_driver(Driver arr[], int& d, string name) {
  bool dri = false;
  int dri_pos = d;
  for (int i = 0; i < d && dri != true; i++) {
    if (arr[i].name == name) {
    dri = true;
    dri_pos = i; //searching for driver
    display_one_driver(arr[i]);
    } //end of if
  } //end of for
} 

//erasing a driver by his name
void erase_driver(Driver arr[], int& d, string name) {
  bool dri = false;
  int dri_pos = d;
  for (int i = 0; i < d && dri != true; i++) {
    cout << i << ", " << arr[i].name << endl;
  if (arr[i].name == name) {
    dri = true;
    dri_pos = i; //position of driver
  } //end of if
  } //end of for
  for ( int i = dri_pos; i < d - 1; i++)
    arr[i] = arr[i + 1];
  //adjusting the size based on who is being erased
  if (dri_pos != d)
  d--;  
} //end of if and for

//inserting a new element into the array
void insert_driver(Driver arr[], int& d, Driver dr) {
  for (int i = d; i > dr.position; i--)
    arr[i] = arr[i - 1];
    arr[dr.position] = dr;
    d++;
  cout << "\nDrivers position is " << dr.position << ", " << "his name is " << dr.name << ", " << "he is from " << dr.country << ", " << "he is on team " << dr.team << ", " << "with an overall points of " << dr.points << endl;
} //end of for

//return data for the highest points collected
double hi_point(Driver arr[], int d) {
  int highest= arr[0].points;
  for (int i = 1; i < d; i++) {
    if(highest < arr[i].points)
      highest = arr[i].points;
 } //end of for
  cout << "\nThe driver with the most amount of points is Lewis Hamilton with a total of " << highest << " points for Mercedes." << endl;
return highest;
}

//return data for the lowest points collected
double low_point(Driver arr[], int d) {
 int lowest = arr[d-1].points;
 for (int i = 0; i < d; i++) {
   if(lowest > arr[i].points)
    lowest = arr[i].points;
 } //end of for
  cout << "\nThe driver with the least amount of points is Nicholas Latifi with a total of " << lowest << " points for Williams Racing." << endl;
 return lowest;
}
//return data for the average points 
double point_avg(const Driver arr[], int d) {
  double total = 0;
  for (int i = 0; i < d; i++) {
    total += arr[i].points;
} //end of for
  cout << "\nThe average amount of points accumulated during the 2020 Formula 1 Season was about " << total/d << " points." << endl;
  return total/d;
}
