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
    vi v(n), r;
    for (int &x: v)cin >> x;
    map<int, int> ck;

    int cnt = 0, st = 0;
    for (int x: v) {
        int k = ab(x);

        if (x > 0) {
            if(ck.count(k)) {
                cout << -1;
                return;
            }
            cnt ++;
            st ++;
            ck[k] = 1;
        }
        else {
            if (ck[k] != 1) {
                cout << -1;
                return;
            }
            ck[k] = 2;
            st --;
        }

        if(st == 0) {
            r.pb(cnt * 2);
            cnt = 0;
            ck.clear();
        }
    }
    if(!ck.empty()){
        cout << -1;
        return;
    }

    cout << r.size() << endl;
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
