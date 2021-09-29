#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    string s;
    vi v;
    cin >> n >> s;
    int cnt = 0;
    ll r = 0, cur;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            v.pb(i - cnt++);
            r += v.back();
        }
    }

    int pos = 0;
    cur = r;
    for (int i = 0; i < n - cnt; i++) {
        while(pos < cnt && v[pos] == i)pos ++;
        cur += pos - (cnt -pos);
        r = min(r, cur);
    }

    cout << r << '\n';
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
