#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    cin >> n;
    vi v(n), ck(n);
    int s = 0;
    for (int &x: v)cin >> x, s += x;
    sort(v.begin(), v.end());
    if (s % 3) {
        for (int i = 0; i < v.size(); i++) {
            if (ck[i])continue;
            if (v[i] % 3 == s % 3) {
                s -= v[i];
                ck[i] = 1;
                break;
            }
        }
    }
    if (s % 3) {
        for (int i = 0; i < v.size(); i++) {
            if (ck[i])continue;
            if (v[i] % 3) {
                s -= v[i];
                ck[i] = 1;
            }
            if (s % 3 == 0)break;
        }
    }
    deque<int> q;
    for (int i = n - 1; i >= 0; i--)if (!ck[i])q.pb(v[i]);
    while (q.size() >= 2 && q.front() == 0)q.pop_front();

    if (s % 3 || q.back() != 0)cout << -1;
    else for (int x: q)cout << x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
