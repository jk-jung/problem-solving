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
    int n, k;
    cin >> n >> k;
    set<int> s;
    vector<vi> r(k);
    for (int i = 1; i <= n * k; i++)s.insert(i);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        r[i].pb(x);
        s.erase(x);
    }
    for (int i = 1, t = 0; i <= n * k; i++) {
        if (!s.count(i))continue;
        s.erase(i);
        while (r[t].size() == n)t++;
        r[t].pb(i);
    }
    for (int i = 0; i < k; i++) {
        for (int x: r[i])cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
