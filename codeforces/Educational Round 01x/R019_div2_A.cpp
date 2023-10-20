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
    vi v;
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        while (v.size() < k - 1 && n % i == 0) {
            v.pb(i);
            n /= i;
        }
    }
    v.pb(n);
    if (v.size() != k || v.back() == 1) {
        cout << -1;
    } else {
        for (int x: v)cout << x << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
