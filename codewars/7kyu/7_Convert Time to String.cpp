#include <string>

using namespace std;

string convertTime(int t) {
    string r = "";
    int s = t % 60;
    t /= 60;
    int m = t % 60;
    t /= 60;
    int h = t % 24;
    t /= 24;

    return to_string(t) + " " + to_string(h) + " " + to_string(m) + " " + to_string(s);
}