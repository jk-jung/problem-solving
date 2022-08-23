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
    int n;
    cin >> n;
    vi v(n), used(n + 2);
    for (int &x: v)cin >> x;
    map<int, int> ck;
    for (int i = 0; i < n; i++)ck[v[i]] = i;

    int last = -1;
    used[n] = 1;
    for (int i = 1; i <= n; i++) {
        int idx = ck[i];
        if (last != -1 && last + 1 != idx) {
            cout << "No\n";
            return;
        }
        used[idx] = 1;
        last = idx;
        if(used[idx + 1])last = -1;
    }
    cout << "Yes\n";
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
