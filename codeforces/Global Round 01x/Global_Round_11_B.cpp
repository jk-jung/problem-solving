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
    string s;
    cin >> n >> k >> s;
    vi ck(n);
    int r = 0;

    priority_queue<int> q;
    int flag = 0, cnt = 0, el = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            if (cnt > 0) {
                if (flag) q.push(-cnt);
                else el += cnt;
            }
            cnt = 0;
            flag = 1;
            r += (i == 0 || s[i - 1] != 'W' ? 1 : 2);
        } else {
            cnt++;
        }
    }
    el += cnt;

    while (!q.empty()) {
        auto cnt = -q.top();
        q.pop();
        if (cnt <= k) {
            k -= cnt;
            r += cnt * 2 + 1;
        } else {
            r += k * 2;
            k = 0;
        }

        if (k == 0)break;
    }
    k = min(k, el);
    r += k * 2;
    if (el == n && k) r--;
    cout << r << endl;
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
