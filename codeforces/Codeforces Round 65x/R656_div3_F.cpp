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
    int n, k;
    cin >> n >> k;
    vector<vi> v(n);
    vector<set<int>> xx(n), yy(n);
    for (int i = 0, x, y; i < n - 1; i++) {
        cin >> x >> y, x--, y--;
        v[x].pb(y);
        v[y].pb(x);
    }

    if(k == 1) {
        cout << n - 1 << endl;
        return;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        for (int x: v[i]) {
            if (v[x].size() == 1) xx[i].insert(x);
            else yy[i].insert(x);
        }

        if (xx[i].size() >= k)q.push(i);
    }

    int r = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        while (xx[x].size() >= k) {
            r++;
            vi tmp;
            auto it = xx[x].begin();
            for (int i = 0; i < k; i++, it++)tmp.pb(*it);
            for (int y: tmp)xx[x].erase(y);
        }

        if (xx[x].empty() && yy[x].size() == 1) {
            for(int y: yy[x]) {
                xx[y].insert(x);
                yy[y].erase(x);

                if(xx[y].size() == k)q.push(y);
            }
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
