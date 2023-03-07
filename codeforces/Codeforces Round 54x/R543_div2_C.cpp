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
    vi v(n), good(n), fin(n);
    vector<pi> on(k, {-1, -1});
    queue<int> q;
    int idx = 0;
    for (int &x: v)cin >> x, q.push(idx++);


    while (true) {
        for (int i = 0; i < k; i++)
            if (!q.empty() && on[i].S == -1)
                on[i] = {0, q.front()}, q.pop();
        int tot = 0;
        for (int x: fin)tot += x;

        int cur = int(100. * tot / n + 0.5);
        int go = 0;
        for (int i = 0; i < k; i++)
            if (on[i].S != -1) {
                go = 1;
                if (cur == ++on[i].F)good[on[i].S] = 1;
                if (on[i].F == v[on[i].S]) {
                    fin[on[i].S] = 1;
                    on[i] = {-1, -1};
                }
            }
        if (!go)break;
    }
    int r = 0;
    for (int x: good)r += x;
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
