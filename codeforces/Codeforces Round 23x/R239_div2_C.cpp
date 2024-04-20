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

vector<pi> gen(int m) {
    vector<pi> r;
    for (int i = 1; i < m; i++) {
        int j = sqrt(m * m - i * i);
        if(j * j + i * i < m * m)j++;
        if (i * i + j * j == m * m) {
            r.pb(mp(i, j));
            r.pb(mp(-i, j));
            r.pb(mp(i, -j));
            r.pb(mp(-i, -j));
        }
    }
    return r;
}

void check_if_right_triangle(pi a, pi b) {
    if(a.F == b.F || a.S == b.S)return;
    if (a.F * b.F + a.S * b.S == 0) {
        cout << "YES\n";
        cout << "0 0\n";
        cout << a.F << " " << a.S << "\n";
        cout << b.F << " " << b.S << "\n";
        exit(0);
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    vector<pi> A = gen(a);
    vector<pi> B = gen(b);
    for(auto x:A) {
        for(auto y:B) {
            check_if_right_triangle(x, y);
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
