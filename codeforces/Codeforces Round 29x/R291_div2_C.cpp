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

#define mod 100000000000001ll
ll P = 3;

map<ll, int> S[7000000];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll c = 0, p = 1;

        for (char x: s) {
            c = (c + (x - 'a' + 1) * p) % mod;
            p = (p * P) % mod;
        }
        S[s.size()][c] = 1;
    }
    for(int i=0;i<m;i++) {
        string s;
        cin>>s;

        ll c = 0, p = 1;

        for (char x: s) {
            c = (c + (x - 'a' + 1) * p) % mod;
            p = (p * P) % mod;
        }
        bool ok = false;
        p = 1;
        for (char x: s) {
            for (char y = 'a'; y <= 'c'; y++) {
                if (y == x)continue;
                ll t = (c - (x - 'a' + 1) * p + mod * 10) % mod;
                t = (t + (y - 'a' + 1) * p) % mod;
                if (S[s.size()].count(t)) {
                    ok = true;
                    break;
                }
            }
            if (ok)break;
            p = (p * P) % mod;
        }
        if (ok)cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
