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
    int n, m;
    cin >> n >> m;
    vi v(n);
    for (int &x: v)cin >> x;

    map<int, int> ck;
    ck[1 << 30] = 0;
    for (int i = 1; i <= n; i++) {
        int x = v[i - 1];
        if (ck.begin()->F <= x)ck.begin()->S = i;
        else ck[x] = i;
    }

    while (m--) {
        int k, d;
        cin >> k >> d;
        k--;

        int &x = v[k];
        x -= d;
        auto it = ck.lower_bound(x);

        if (it->S < k);
        else {
            vi del;
            int cnt = 0;
            while (it != ck.end() && it->S >= k) {
                cnt = max(cnt, it->S);
                del.pb(it->F);
                it++;
            }
            it --;
            del.pop_back();
            it -> S = k;
            for(int y: del)ck.erase(y);
            ck[x] = cnt;
        }

        cout << ck.size() - 1 << ' ';
    }
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
