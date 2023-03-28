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
    vi v(55);
    int n, k;
    cin >> n >> k;
    for (int i = 30; i >= 0; i--)if (n >> i & 1)v[i]++, k--;
    for (int i = 30; i >= 1; i--) {
        if (k > 0 && v[i]) {
            int t = min(k, v[i]);
            v[i] -= t;
            v[i - 1] += t * 2;
            k -= t;
        }
    }
    if (k == 0) {
        cout << "YES\n";
        for (int i = 0; i <= 30; i++)while (v[i]--)cout << (1 << i) << " ";
    } else cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
