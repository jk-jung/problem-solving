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
    int n, k;
    cin >> n >> k;

    vi d(n);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (!a) {
            d[i] = 1;
            q.push(i);
        }
    }

    int r = 0, cnt = 0;
    while (q.size()) {
        int x = q.front();
        int y = (x + k) % n;
        r = max(r, d[x]);
        q.pop();
        cnt++;

        if (!d[y]) {
            d[y] = d[x] + 1;
            q.push(y);
        }
    }

    cout << (cnt == n ? r - 1 : -1) << '\n';
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
