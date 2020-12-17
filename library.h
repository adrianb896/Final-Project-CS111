#include <string>
#include <fstream>
using namespace std;

//struct supporting variables
struct Driver {
  int position;
  string name;
  string country;
  string team;
  double points;
};

//Function Prototypes

//display a drivers data
void display_one_driver(Driver d);

//collect all of the drivers datas
void collect_all_drivers(Driver arr[], int& d);

//collect a drivers data
void collect_one_driver(ifstream& input, Driver& d);

//display all of the drivers data
void display_all_drivers(Driver arr[], int d);

//searching for a driver
void search_driver(Driver arr[], int& d, string name);

//erase a drivers name from the array
void erase_driver(Driver arr[], int& d, string name);

//insert a drivers name of your desire
void insert_driver(Driver arr[], int& d, Driver dr);

//return the highest points 
double hi_point(Driver arr[], int d);

//return the lowest points
double low_point(Driver arr[], int d);

//return the average points accumulated throughout the season
double point_avg(const Driver arr[], int d);
