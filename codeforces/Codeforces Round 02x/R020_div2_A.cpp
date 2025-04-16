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
    string s, r;
    cin >> s;
    char y = ' ';
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (y == '/' && x == '/') continue;
        r += x;
        y = x;
    }
    while (r.size() > 1 && r.back() == '/')r.pop_back();
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
