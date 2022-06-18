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

    int r = 0;
    for (int a = 1; a <= 200; a++) {
        int s = 0, e = n - 1, c = 0;
        vi cnt(201);
        for (int x: v) r = max(r, ++cnt[x]);
        while (s < e) {
            while (s < n && v[s] != a) cnt[v[s++]]--;
            while (e >= 0 && v[e] != a) cnt[v[e--]]--;
            if (s >= e)break;
            cnt[v[s++]]--;
            cnt[v[e--]]--;

            c++;
            for (int x: cnt)r = max(r, c * 2 + x);
        }
    }
    cout << r << endl;
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
