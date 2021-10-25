#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
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

int n;
set<int> st;
int a[300005];
int b[300005];
int d[300005];
int from[300005];
int from2[300005];
queue<int> q;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];

    for (int i = 0; i < n; i++)st.insert(i);
    q.push(n);
    d[n] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == 0) {
            cout << d[x] - 1<< endl;
            vi r;
            int x = 0;
            while(x != n){
                int z = from2[x];
                r.pb(z);
                x = from[x];
            }
            reverse(r.begin(), r.end());
            for(int k:r)cout << k <<" ";
            cout << endl;
            return;
        }

        if (st.empty())continue;
        auto it = st.lower_bound(x);
        if (it == st.end()) it--;
        int lim = max(0, x - a[x]);

        vi rm;
        while (*it >= lim) {
            int y = *it;
            int z = min(n, y + b[y]);

            if (d[z] == 0) {
                d[z] = d[x] + 1;
                from[z] = x;
                from2[z] = y;
                q.push(z);
            }
            rm.pb(y);

            if (it == st.begin()) break;
            it--;
        }

        for (int y: rm)st.erase(y);
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
