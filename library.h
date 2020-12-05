#include <string>
#include <fstream>
using namespace std;

struct Driver {
  double position;
  string name;
  string team;
  double points;
};

void collect_one_driver(ifstream& input, Driver& d);

void display_one_driver(Driver d);