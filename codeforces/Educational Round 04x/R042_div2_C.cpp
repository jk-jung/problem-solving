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
    int n, r = -1;
    cin >> n;
    string s = to_string(n);
    for (int i = 1; i * i <= n; i++) {
        string t = to_string(i * i);
        int pos = 0, ok = 1;
        for (char x: t) {
            while (pos < s.size() && s[pos] != x)pos++;
            if (pos == s.size()) {
                ok = 0;
                break;
            }
            pos++;
        }
        if (ok) {
            r = max(r, (int) t.size());
        }
    }
    if (r == -1)cout << -1;
    else cout << s.size() - r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
