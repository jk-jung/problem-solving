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
    int n, k, y, x;
    cin >> n >> k >> y >> x;
    y--, x--;
    int z = x % k;
    int offset = (k + z - y % k);
    for (int i = 0; i < n; i++) {
        int pos = (i + offset) % k;
        for (int j = 0; j < n; j += k) {
            for (int t = 0; t < k; t++) {
                cout << (t == pos ? 'X': '.');
            }
        }
        cout <<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
