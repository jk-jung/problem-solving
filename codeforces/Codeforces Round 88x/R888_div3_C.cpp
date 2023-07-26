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

    for (int i = 0, c = 0, d = 0; i < n; i++) {
        if (v[i] == v[0])c++;
        if (c >= k) {
            if(v[0] == v.back())d = k;
            for (; i < n; i++) {
                if (v[i] == v.back())d++;
                if (d >= k) {
                    cout << "YES\n";
                    return;
                }
            }
            break;
        }
    }
    cout << "NO\n";
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
