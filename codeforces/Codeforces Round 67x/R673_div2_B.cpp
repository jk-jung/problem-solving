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
    int n, t;
    cin >> n >> t;
    vi v(n);
    set<int> ck;
    for (int &x: v)cin >> x;

    int mid = t % 2 == 0 ? t / 2 : -1, st =0;
    for (int x: v) {
        int y = t - x;
        if (y == mid) {
            cout << st <<" ";
            st ^= 1;
        } else {
            if (ck.count(y)) cout << "1 ";
            else cout << "0 ", ck.insert(x);
        }
    }
    cout << endl;
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
