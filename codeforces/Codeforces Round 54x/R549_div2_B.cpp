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

int f(string x) {
    int r = 1;
    if (x[0] == '0') x = x.substr(1);
    for (char y: x) {
        r *= (y - '0');
    }
    return r;
}

void solve() {
    string s;
    cin >> s;

    int r = f(s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > '0') {
            string t = s;
            t[i]--;
            for (int j = i + 1; j < t.size(); j++)t[j] = '9';
            r = max(r, f(t));
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
