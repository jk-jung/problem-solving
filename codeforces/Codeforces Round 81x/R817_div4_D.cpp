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
    string s;
    cin >> n >> s;

    ll r = 0;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int a = i, b = n - i - 1;
        if (s[i] == 'L') {
            r += a;
            q.push(b - a);
        } else {
            r += b;
            q.push(a - b);
        }
    }
    vector<ll> v;
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        if (x <= 0)break;
        r += x;
        v.pb(r);
    }
    while (v.size() < n)v.pb(r);
    for (ll x: v)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
