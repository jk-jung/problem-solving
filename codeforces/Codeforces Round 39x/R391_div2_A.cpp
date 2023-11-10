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
    map<char, int> c;
    for (char x: s)c[x]++;
    int r = 1 << 30;
    r = min(r, c['B']);
    r = min(r, c['u'] / 2);
    r = min(r, c['l']);
    r = min(r, c['b']);
    r = min(r, c['a'] / 2);
    r = min(r, c['s']);
    r = min(r, c['r']);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
