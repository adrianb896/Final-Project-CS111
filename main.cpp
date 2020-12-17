#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "library.h"
using namespace std;

int main() {
  Driver one_driver; //to use as my universal variable
  Driver drivers[50]; //array for amount of drivers
  int num_drivers = 0; 
  int option;

    //quick summary 
    cout << "\nWelcome to the 2020 Formula 1 Season! This is where you will find all the information you need to become an expert with the data on which Formula 1 driver is performing at there best and which driver is not performing at there best. In Formula 1 it's all about which car is the fastest and which team can capture the most amount of points throughout the season.\n" << endl;

    cout << "\nBelow is the data you will be analyzing: \n" << endl;

  ifstream input;
  input.open("input.dat"); //calling for the file
  if (!input.is_open()) {
    cout << "Can't open the input.dat file.\n";
    return 1; //if code doesn't follow through 
  } //end of if

  int column_width = 20;
    cout << fixed << showpoint << setprecision(1);
    cout << "Place" << setw(17) << "Drivers" << setw(22) << "Country" << setw(17) << "Team" << setw(22) << "Points" << endl;

  while(!input.eof()) {
    collect_one_driver(input, one_driver);
    cout << left << setw(15) << one_driver.position;
    cout << left << setw(22) << one_driver.name;
    cout << left << setw(column_width) << one_driver.country;
    cout << left << setw(column_width) << one_driver.team;
    cout << left << setw(column_width) << one_driver.points << endl;
  } //end of while
  input.close(); //closing the file grab

  //options to choose from
    cout << "\nOption Menu: \n";
    cout << "\n1. Display a driver's data\n" << endl;
    cout << "2. Display every driver\n" << endl;
    cout << "3. Erase a driver by his name\n" << endl;
    cout << "4. Add a new driver by desired name\n" << endl;
    cout << "5. Display who has the highest points\n" << endl;
    cout << "6. Display who has the lowest points\n" << endl;
    cout << "7. Display the average amount of points\n" << endl;
    cout << "8. Exit the program.\n" << endl;
    cout << "Please select from the Option Menu 1 - 8: " << endl;
    cin >> option;
    cin.ignore();
    
    //to define
    collect_all_drivers(drivers, num_drivers);
    string driver;


  switch(option) //switch-case statement
  {
    case 1: //to display one driver
      cout << "You have chosen to display only one driver \n";
      cout << "Which driver would you like to display?: \n";
      getline(cin, driver);
      search_driver(drivers, num_drivers, driver);
    break;
    case 2: //to display every driver
      cout << "You have chosen to display all drivers";
      display_all_drivers(drivers, num_drivers);  
    break;
    case 3: //to erase a driver from our list
      cout << "You have chosen to erase a driver from our list\n";
      cout << "Which driver would you like to erase and make the list stop at?: \n";
      getline(cin, driver);
      erase_driver(drivers, num_drivers, driver);
      cout << "The list has stopped at " << driver << endl;
    break;
    case 4: //to add your own desired driver data
      cout << "You have chosen to add your own desired driver\n";
      cout << "What position do you want your driver to be in: \n";
      cin >> one_driver.position;
      cin.ignore();
      cout << "Add the desired name to our list: \n";
      getline(cin, one_driver.name);
      cout << "What country is this player from: \n";
      getline(cin, one_driver.country);
      cout << "What team is this player on: \n";
      getline(cin, one_driver.team);
      cout << "How many points would you want: \n";
      cin >> one_driver.points; 
      insert_driver(drivers, num_drivers, one_driver);
    break;
    case 5: //to find the driver with the most amount of points
      cout << "You have chosen to display the player with the most amount of points \n";
      hi_point(drivers, one_driver.points);
    break;
    case 6: //to find the driver with least amount of points
      cout << "You have chosen to display the player with the least amount of points \n";
      low_point(drivers, one_driver.points);
    break;
    case 7: //to show the average amount of points accumulated
      cout << "You have chosen to show the average amount of points of the overall spectrum of the 10 teams. \n";
      point_avg(drivers, num_drivers);
     break;
    case 8: //to exit the program
      return 0;
  }

  //DrO Need to create a function to collect all drivers
  //DrO need to create a function to display all drivers along with some summarny data
  //created the functions that you mentioned and added the files into my library.cpp file.
return 0;
} //fin
