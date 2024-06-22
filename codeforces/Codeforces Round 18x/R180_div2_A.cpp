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
    int n;
    string s;
    cin >> n >> s;
    s += "  ";
    char t = ' ';
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            if (a == 0)a = i + 1;
            b = i + 1;
        } else if (s[i] == 'L') {
            if (c == 0)c = i + 1;
            d = i + 1;
        }
    }
    if (a && c) {
        cout << a << " " << b << endl;
    } else if (a) {
        cout << a << " " << b + 1 << endl;
    } else {
        cout << d << " " << c - 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
