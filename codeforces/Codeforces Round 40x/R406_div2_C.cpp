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

int n;
vector<vi> v(2);

int d[7005][2];
int c[7005][2];

int go(int i, int t) {
//    cout << i <<" " << t << endl;
    if (i == 7 && t == 1) {
        i = i;
    }
    if (i == 0) return 0;
    int &r = d[i][t];
    if (r != -1) return r;

    r = 1;
    bool flag = false;
    for (int x: v[t]) {
        int k = 2 - go((i + x) % n, t ^ 1);
        if (k == 2) {
            r = 2;
            flag = true;
            break;
        }
        if (k == 1) {
            flag = true;
        }
    }
    if (!flag)r = 0;
    return r;
}

string qq[] = {"Loop", "Lose", "Win"};

void solve() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        int t;
        cin >> t;
        v[i].resize(t);
        for (int &x: v[i])cin >> x;
    }

    d[0][0] = d[0][1] = 1;
    queue<pi> q;
    q.push({0, 0}), q.push({0, 1});
    while (!q.empty()) {
        auto [i, t] = q.front();
        q.pop();
        int tt = t ^ 1;
        for (int x: v[tt]) {
            int k = (i - x + n) % n;
            if (d[i][t] == 1) {
                if (!d[k][tt]) {
                    d[k][tt] = 2;
                    q.push({k, tt});
                }
            } else {
                if (++c[k][tt] == v[tt].size()) {
                    d[k][tt] = 1;
                    q.push({k, tt});
                }
            }
        }
    }

    for (int i = 1; i < n; i++)cout << qq[d[i][0]] << " ";
    cout << endl;
    for (int i = 1; i < n; i++)cout << qq[d[i][1]] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
