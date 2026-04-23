#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string dtos(double x) {
  stringstream ss;
  ss << fixed << setprecision(999) << x;
  return ss.str();
}