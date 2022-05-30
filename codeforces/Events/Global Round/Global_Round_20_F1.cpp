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
    vi v(n), r(n);
    map<int, queue<int>> mq;
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++) mq[v[i]].push(i);

    while (!mq.empty()) {
        vi rm, t;
        for (auto &[k, q]: mq) {
            t.pb(q.front());
            q.pop();
            if (q.empty())rm.pb(k);
        }
        for(int i=0;i<t.size();i++){
            r[t[i]] = v[t[(i + 1) % t.size()]];
        }
        for (int x: rm)mq.erase(x);
    }

    for (int x: r)cout << x << " ";
    cout << endl;
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
