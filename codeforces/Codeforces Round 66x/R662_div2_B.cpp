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

int cnt[100005];
priority_queue<pi> q;
int st[11];

void add(int x) {
    int k = ++cnt[x];
    if (k <= 8) {
        st[k - 1]--;
        st[k]++;
    }
}

void sub(int x) {
    int k = --cnt[x];
    if (k <= 7) {
        st[k + 1]--;
        st[k]++;
    }
}

vi l = {4, 2, 2};

void solve() {
    int n, m;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, add(x);
    cin >> m;
    for (int i = 0; i < m; i++) {
        char op;
        int x;
        cin >> op >> x;

        if (op == '+') add(x);
        else sub(x);

        queue<int> tt;
        for (int k = 8; k >= 2; k--) {
            for (int j = 0; j < st[k]; j++) {
                tt.push(k);
                if (tt.size() == 3)break;
            }
            if (tt.size() == 3)break;
        }
        bool ok = true;
        for (int k = 0; k < 3; k++) {
            while (!tt.empty() && tt.front() < l[k])tt.pop();
            if (tt.empty()) {
                ok = false;
                break;
            }
            tt.front() -= l[k];
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
