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

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    for (int t = -1; t <= 1; t++) {
        bool ok = true;
        for (int i = 1; i < n; i++) {
            int s = v[i] - 1, e = v[i] + 1;
            if (s <= v[0] + i + t && v[0] + i + t <= e);
            else ok = false;
        }
        if(ok) {
            cout <<"YES\n";
            return;
        }
    }
    cout <<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
