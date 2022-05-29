#include <string.h>
#include <stdio.h>
#include <math.h>
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
    string s;
    int n;
    cin >> s >> n;
    vi v(n), r(n), c(255);
    for (int &x: v)cin >> x;
    for (char x: s)c[x]++;

    set<int> pos;
    while (true) {
        vi candi;
        for (int i = 0; i < n; i++) {
            if (pos.count(i)) continue;
            int val = 0;
            for (int j: pos) {
                val += ab(i - j);
            }
            if (val == v[i]) {
                candi.pb(i);
            }
        }

        if (candi.empty()) break;
        for (int i = 254; i >= 0; i--) {
            if (c[i] >= candi.size()) {
                c[i] = 0;
                for (int x: candi) {
                    pos.insert(x);
                    r[x] = i;
                }
                break;
            }
            c[i] = 0;
        }
    }
    for (int x: r)cout << char(x);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
