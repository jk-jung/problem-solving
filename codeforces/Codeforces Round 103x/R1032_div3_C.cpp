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


int check(map<int, int> &t) {
    for (auto &[x, y]: t) {
        if (y >= 2)return x;
    }
    return -1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> v(n, vi(m));
    int M = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            M = max(M, v[i][j]);
        }
    }
    vector<pi> t;
    map<int, int> x, y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == M) {
                y[i]++;
                x[j]++;
                t.pb(mp(i, j));
            }


    int X = check(x);
    int Y = check(y);

    if(X == -1 && Y == -1){
        cout << M - (t.size() <= 2) << endl;
        return;
    }

    for (auto [a, b]: t) {
        if (a == Y || b == X)continue;
        if(X == -1)X = b;
        if(Y == -1)Y = a;
        if (a == Y || b == X)continue;
        else {
            cout << M << endl;
            return;
        }
    }
    cout << M - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
