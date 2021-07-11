#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

vector<map<int, int>> fac(1000005);

#define MAX_V 1000000

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void init() {
    for (int i = 2; i <= MAX_V; i++) {
        int m = int(sqrt(i));
        int n = i;
        for (int k = 2; k <= m; k++) {
            while (n % k == 0) {
                fac[i][k]++;
                n /= k;
            }
        }
        if (n != 1)
            fac[i][n]++;
    }
}

int get_count(int x, int k) {
    if (fac[x].find(k) == fac[x].end()) return 0;
    return fac[x][k];
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    int g = v[0];
    for (int i = 1; i < n; i++)g = gcd(g, v[i]);

    map<int, int> vv;
    int r = 0;
    for (int i = n * 2 - 1; i >= 0; i--) {
        auto ff = fac[v[i % n]];

        for (auto t : ff) {
            if (get_count(g, t.F) == t.S) {
                r = max(r, vv[t.F] - i);
                vv.erase(t.F);
            }else if(vv.find(t.F) == vv.end()) {
                vv[t.F] = i;
            }
        }

        vector<int> ee;
        for(auto t : vv) {
            if (ff.find(t.F) != ff.end())continue;
            r = max(r, vv[t.F] - i);
            ee.pb(t.F);
        }
        for(auto x: ee){
            vv.erase(x);
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
}
