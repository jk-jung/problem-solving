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
    vi st(10);
    cin >> n;
    int flag = 0;
    vector<char> o(n);
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> o[i] >> v[i];
    }
    for (int k = 0; k < 10; k++) {
        vector<char> a;
        for (int i = n - 1; i >= 0; i--) {
            if (o[i] == '|' && (v[i] >> k & 1))a.pb('|');
            if (o[i] == '^' && (v[i] >> k & 1))a.pb('^');
            if (o[i] == '&' && !(v[i] >> k & 1))a.pb('&');
        }
        if (a.empty()) continue;
        if (a[0] == '|')st[k] = 1;
        else if (a[0] == '&')st[k] = -1;
        else {
            int c = 0;
            for (char x: a) {
                if (x == '^') c ^= 1;
                if (x == '|') {
                    if (c == 0) st[k] = 1;
                    else st[k] = -1;
                    goto done;
                }
                if (x == '&') {
                    if (c == 1) st[k] = 1;
                    else st[k] = -1;
                    goto done;
                }
            }
            if (c)st[k] = 2;
            done:;
        }
    }
    cout << 3 << endl;
    int k = 1023;
    for (int i = 0; i < 10; i++) if (st[i] == -1) k ^= 1 << i;
    cout << "& " << k << endl;
    k = 0;
    for (int i = 0; i < 10; i++) if (st[i] == 1) k |= 1 << i;
    cout << "| " << k << endl;
    k = 0;
    for (int i = 0; i < 10; i++) if (st[i] == 2) k |= 1 << i;
    cout << "^ " << k << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
