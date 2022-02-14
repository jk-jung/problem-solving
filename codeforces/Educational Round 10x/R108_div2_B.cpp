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
    queue<vi> q;
    int n, m, k;
    cin >> n >> m >> k;

    q.push(vi{1, 1, 0});

    map<vi, int> ck;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        if (t[0] == n && t[1] == m && t[2] == k) {
            cout << "YES\n";
            return;
        }


        if (t[0] < n) {
            auto nt = vi{t[0] + 1, t[1], t[2] + t[1]};
            if (!ck.count(nt)) {
                q.push(nt);
                ck[nt] = 1;
            }
        }
        if (t[1] < m) {
            auto nt = vi{t[0], t[1] + 1, t[2] + t[0]};
            if (!ck.count(nt)) {
                q.push(nt);
                ck[nt] = 1;
            }
        }
    }
    cout << "NO\n";
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
