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
    vi v(n);
    for (int &x: v)cin >> x;

    map<int, int> ck;
    for (int x: v)ck[x]++;
    if (ck.size() > k) {
        cout << -1 << endl;
    } else {
        for (int j = 1; j <= n; j++)if (ck.size() < k && !ck.count(j))ck[j]++;
        cout << n * ck.size() << endl;
        for (int i = 0; i < n; i++) {
            for (auto [x, y]: ck)cout << x << " ";
        }
        cout << endl;
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
