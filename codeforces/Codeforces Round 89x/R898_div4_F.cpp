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
    vi a(n), h(n);
    for (int &x: a)cin >> x;
    for (int &x: h)cin >> x;
    int r = 0, st = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            q.push(i);
            st = a[i];
        } else if (h[i - 1] % h[i] == 0) {
            q.push(i);
            st += a[i];
        } else {
            while (!q.empty()) q.pop();
            q.push(i);
            st = a[i];
        }
        while (!q.empty() && st > k) {
            int x = q.front();
            q.pop();
            st -= a[x];
        }
        if(q.size() == 6){
            q=q;
        }
        r = max(r, (int) q.size());
    }
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
