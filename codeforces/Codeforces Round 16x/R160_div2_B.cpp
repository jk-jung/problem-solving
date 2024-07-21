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
    vi v(n);
    for (int &x: v) {
        cin >> x;
        if (x < 0 && k) {
            k--;
            x *= -1;
        }
    }
    sort(v.begin(), v.end());
    while (k--)v[0] *= -1;
    int r = 0;
    for (int x: v)r += x;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
