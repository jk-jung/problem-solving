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

void solve() {
    string s;
    cin >> s;
    string t;

    for (char x: s) {
        if (x == '>') t += "1000";
        if (x == '<') t += "1001";
        if (x == '+') t += "1010";
        if (x == '-') t += "1011";
        if (x == '.') t += "1100";
        if (x == ',') t += "1101";
        if (x == '[') t += "1110";
        if (x == ']') t += "1111";
    }

    int r = 0;
    for (char x: t) {
        if (x == '1')r = (r * 2 + 1) % 1000003;
        else r = (r * 2) % 1000003;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
