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
    ll n, q;
    cin >> n >> q;
    while (q--) {
        ll y, x;
        cin >> y >> x;
        x--, y--;
        ll t = y * n + x;
        if (n % 2) {
            if (t % 2 == 0) {
                cout << t / 2 + 1 << endl;
            } else {
                cout << t / 2 + (n * n + 1) / 2 + 1 << endl;
            }
        } else {
            ll offset = y * (n / 2) + x / 2 + 1;
            if ((x + y) % 2 == 0) {
                cout << offset << endl;
            }else {
                cout << offset + (n * n + 1) / 2  << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
