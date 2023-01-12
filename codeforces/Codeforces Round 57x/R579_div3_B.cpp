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
    vi v(n * 4);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    int r = -1;
    for (int s = 0, e = n * 4 - 1; s <= e; s += 2, e -= 2) {
        int x = v[s], y = v[e];
        if (x != v[s + 1] || y != v[e - 1]) {
            cout << "NO\n";
            return;
        }
        if (r == -1)r = x * y;
        else if(r != x * y){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
