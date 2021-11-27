#include <string.h>
#include <stdio.h>
#include <math.h>
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

int n;
ll d[5000005];
ll cnt[5000005];

void solve() {
    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int k = 1; k * k <= x; k++) {
            if (x % k == 0) {
                cnt[k]++;
                if (k != x / k)cnt[x/k]++;
            }
        }
    }

    ll r = n;
    d[1] = n;
    for (int i = 1; i <= 5000000; i++) {
        for (int j = i + i; j <= 5000000; j += i) {
            d[j] = max(d[j], d[i] + (j * cnt[j] - i * cnt[j]));
        }

        r = max(r, d[i]);
    }
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}
