#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    string s;
    cin >> s;
    string a, b, c;
    int st = 0;
    for (char x: s) {
        if (x == 'e' || x == '.')st++;
        else if (st == 0)a += x;
        else if (st == 1)b += x;
        else c += x;
    }

    if (b == "0")b = "";
    int C = stoi(c);
    for (int i = 0; i < C; i++) {
        if (!b.empty()) {
            a += b[0];
            b = b.substr(1);
        } else a += '0';
    }

    cout << a << (!b.empty() ? "." + b : "") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
