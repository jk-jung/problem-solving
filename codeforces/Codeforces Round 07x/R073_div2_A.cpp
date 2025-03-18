#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

string a, b, c;

map<string, int> k = {
        {"C",  0},
        {"C#", 1},
        {"D",  2},
        {"D#", 3},
        {"E",  4},
        {"F",  5},
        {"F#", 6},
        {"G",  7},
        {"G#", 8},
        {"A",  9},
        {"B",  10},
        {"H",  11},
};

void check(int a, int b, int c) {
    int x = b - a;
    int y = c - b;

    if (x == 4 && y == 3) cout << "major" << endl;
    else if (x == 3 && y == 4) cout << "minor" << endl;
    else return;
    exit(0);
}

void solve() {
    cin >> a >> b >> c;
    vi v = {k[a], k[b], k[c]};
    sort(v.begin(), v.end());

    check(v[0], v[1], v[2]);
    check(v[2] - 12, v[0], v[1]);
    check(v[1], v[2], v[0] + 12);

    cout << "strange" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
