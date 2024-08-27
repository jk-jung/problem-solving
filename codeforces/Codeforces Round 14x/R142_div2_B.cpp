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
    while (n--) {
        ll k;
        cin >> k;
        ll t = sqrt(k);
        while (t * t < k)t++;
        bool ok = true;
        for (int i = 2; i * i <= t; i++) {
            if (t % i == 0)ok = false;
        }
        cout << (t * t == k && k != 1 && ok ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
