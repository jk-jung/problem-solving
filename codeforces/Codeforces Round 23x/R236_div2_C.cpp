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
    int n, p;
    cin >> n >> p;
    int m = n * 2 + p;
    vector<pi> v;
    map<int, int> c;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            int j = (i + k) % n;
            int x = min(i, j);
            int y = max(i, j);
            if(x == y || c[x * n + y]) continue;
            c[x * n + y] = 1;
            v.pb(mp(x, y));
        }
    }
    for(int i=0;i<n*2+p;i++){
        cout << v[i].F + 1 << " " << v[i].S + 1 << endl;
    }
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
