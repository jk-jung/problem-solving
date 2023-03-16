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

int a[100005];
map<ll, ll> ck;
ll n, k, A, B;

ll go(int s, int e, int idx, int L, int R) {
    if (ck.count(idx)) return ck[idx];
    ll &r = ck[idx];
    if (L > R) return r = A;

    int m = (s + e) / 2, m_idx = L - 1;
    for (int i = L; i <= R; i++) {
        if (a[i] <= m)m_idx = i;
        else break;
    }
    ll cost = B * (e - s + 1) * (R - L + 1);
    if(e == s)r = cost;
    else
        r = min(cost, go(s, m, idx * 2 + 1, L, m_idx) + go(m + 1, e, idx * 2 + 2, m_idx + 1, R));
    return r;
}

void solve() {
    cin >> n >> k >> A >> B;
    for (int i = 0; i < k; i++)cin >> a[i];

    sort(a, a + k);
    cout << go(1, 1 << n, 0, 0, k - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
