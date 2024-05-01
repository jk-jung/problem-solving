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
    int n, m, x, y, z, p;
    cin >> n >> m >> x >> y >> z >> p;
    vector<pi> v(p);
    for (int i = 0; i < p; i++) {
        cin >> v[i].F >> v[i].S;
    }
    x %= 4;
    y %= 2;
    z %= 4;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < p; j++) {
            int a = v[j].F;
            int b = v[j].S;
            v[j].F = b;
            v[j].S = n - a + 1;
        }
        swap(n, m);
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < p; j++) {
            v[j].S = m - v[j].S + 1;
        }
    }
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < p; j++) {
            int a = v[j].F;
            int b = v[j].S;
            v[j].F = m - b + 1;
            v[j].S = a;
        }
        swap(n, m);
    }
    for (int i = 0; i < p; i++) {
        cout << v[i].F << " " << v[i].S << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
