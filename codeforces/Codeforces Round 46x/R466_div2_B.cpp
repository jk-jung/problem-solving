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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    ll r = 0;
    if(k == 1) {
        cout << a * (n - 1) << endl;
        return;
    }
    while (n != 1) {
        if (n < k) {
            r += a * (n - 1);
            break;
        }
        if (n % k)r += n % k * a;
        n -= n % k;

        r += min(b, a * (n - n / k));
        n /= k;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
