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
    vector<string> v(n);
    for (auto &s: v)cin >> s;

    int r = 1 << 30;
    for (auto x: v) {
        int t = 0;
        for (auto s: v) {
            bool ok = false;
            for (int i = 0; i < s.size(); i++) {
                if (x == s) {
                    t += i;
                    ok = true;
                    break;
                }
                s = s.substr(1) + s.substr(0, 1);
            }
            if(!ok)t = 1 << 30;
        }
        r = min(r, t);
    }
    if (r == (1 << 30))r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
