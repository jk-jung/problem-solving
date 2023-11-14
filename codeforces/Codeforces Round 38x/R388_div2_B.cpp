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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int dx = c - a, dy = d - b;

    set<pi> s;
    s.insert({e + dx, f + dy});
    s.insert({e - dx, f - dy});
    dx = e - a, dy = f - b;
    s.insert({c + dx, d + dy});
    s.insert({c - dx, d - dy});
    cout << s.size() << endl;
    for (auto [x, y]: s)cout << x << " " << y << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
