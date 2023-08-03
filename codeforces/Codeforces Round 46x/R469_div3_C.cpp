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

int p[200005];
int ck[200005];

void go(int x, vi &v) {
    ck[x] = 1;
    v.pb(x);
    if(p[x]) go(p[x], v);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    queue<int> a, b;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            if (a.empty()) {
                b.push(i + 1);
            } else {
                int x = a.front();
                a.pop();
                p[i + 1] = x;
                b.push(i + 1);
            }
        } else {
            if (b.empty()) {
                cout << -1;
                return;
            }
            int x = b.front();
            b.pop();
            p[i + 1] = x;
            a.push(i + 1);
        }
    }
    if (!a.empty()) {
        cout << -1 << endl;
        return;
    }
    vector<vi> r;
    for (int i = 0; i < n; i++) {

        if (!ck[i + 1]) {
            r.pb(vi());
            go(i + 1, r.back());
        }
    }
    cout << r.size() << endl;
    for (auto &v: r) {
        cout << v.size() << " ";
        for (auto x: v)cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
