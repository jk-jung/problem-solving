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
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    priority_queue<ll, vector<ll>, greater<>> q;

    ll s = 0;
    for (int i = 0; i < n; i++) {
        q.push(a[i] + s);
        ll r = 0;
        while (!q.empty() && q.top() <= s + b[i]) {
            r += q.top() - s;
            q.pop();
        }
        r += q.size() * (ll)b[i];
        s += b[i];
        cout << r << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
