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
    map<int, int> ck;
    vi v(n * 2);
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    ll r = 1ll << 60;
    queue<int> q;
    for (int i = 0; i < v.size(); i++) {
        if (q.size() == n)q.pop();
        q.push(i);
        int x = q.front();
        if (q.size() < n)continue;

        ll w = v[i] - v[x];
        ll hs, he;
        if (x == 0) hs = v[i + 1];
        else hs = v[0];
        if (i == n * 2 - 1)he = v[x - 1];
        else he = v.back();
        r = min(r, w * (he - hs));
    }
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
