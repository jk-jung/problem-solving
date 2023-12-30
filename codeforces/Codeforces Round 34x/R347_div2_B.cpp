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
#include <cctype>

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
    vector<string> v;
    string s;
    v.pb("+");
    while (cin >> s) {
        v.pb(s);
        if (std::isdigit(s[0]))break;
    }
    int n = stoi(v.back());
    v.pop_back();
    v.pop_back();
    vi r, c(2);
    for (int i = 0; i < v.size(); i += 2) {
        if (v[i] == "+")c[0]++;
        else c[1]++;
    }
    int nn = c[0] - c[1] * n;
    int mm = c[0] * n - c[1];
    if (nn <= n && n <= mm) {
        vi aa = vi(c[0], 1);
        vi bb = vi(c[1], n);
        while (nn < n) {
            for (int i = 0; i < aa.size(); i++) {
                int need = n - nn;
                int z = min(need, n - aa[i]);
                aa[i] += z;
                nn += z;
            }
            for (int i = 0; i < bb.size(); i++) {
                int need = n - nn;
                int z = min(need, n - 1);
                bb[i] -= z;
                nn += z;
            }
        }
        cout << "Possible" << endl;
        for (int i = 0; i < v.size(); i += 2) {
            if (i == 0)cout << aa.back(), aa.pop_back();
            else if (v[i] == "+")cout << " + " << aa.back(), aa.pop_back();
            else cout << " - " << bb.back(), bb.pop_back();
        }
        cout << " = " << n << endl;
    } else {
        cout << "Impossible" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
