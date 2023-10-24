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
    int n, k;
    cin >> n >> k;
    vi v(k);
    for (int &x: v)cin >> x;
    vi r(n);
    for (int i = 0; i < n; i++)r[i] = i;
    int pos = 0;
    for (int x: v) {
        int nxt = (pos + x) % r.size();
        cout << r[nxt] + 1 << " ";
        r.erase(r.begin() + nxt);
        pos = nxt % r.size();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
