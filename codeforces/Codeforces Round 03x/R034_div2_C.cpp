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
    set<int> r;
    string cur = "";
    for (char x: s) {
        if (x == ',')r.insert(stoi(cur)), cur = "";
        else cur += x;
    }
    if (!cur.empty())r.insert(stoi(cur));
    vector<pi> v;
    for (int x: r) {
        if (v.empty() || v.back().S + 1 != x)v.pb({x, x});
        else v.back().S = x;
    }
    for (int i = 0; i < v.size(); i++) {
        auto [x, y] = v[i];
        if (x == y)cout << x;
        else cout << x << "-" << y;
        cout << (i == v.size() - 1 ? "" : ",");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
