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
    int n;
    cin >> n;
    int m = n / 2 + 1;
    if (n % 2 == 0) {
        cout << m * m;
    } else {
        cout << m * m + (m + 1) * (m + 1) - 1;
    }
    return;
    set<tuple<int, int, int>> d;
    d.insert({0, 0, 1});
    d.insert({0, 0, 0});
    while (n--) {
        set<tuple<int, int, int>> nt;
        for (auto [x, y, z]: d) {
            if (z == 0) {
                nt.insert({x - 1, y, 1});
                nt.insert({x + 1, y, 1});
            } else {
                nt.insert({x, y - 1, 0});
                nt.insert({x, y + 1, 0});
            }
        }
        d = nt;
    }
    set<pi> r;
    for (auto [x, y, z]: d)r.insert({x, y});
    cout << r.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
