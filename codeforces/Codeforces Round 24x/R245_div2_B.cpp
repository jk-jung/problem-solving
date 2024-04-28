#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int calc(vi &v) {
    int r =0 ;
    while (true) {
        bool ok = false;
        for (int i = 0; i < v.size(); i++) {
            int j = i;
            while (j < v.size() && v[i] == v[j])j++;
            if(j - i >= 3){
                ok = true;
                vi t;
                for (int k = 0; k < v.size(); k++)
                    if (k < i || k >= j)t.pb(v[k]);
                v = t;
                r += j - i;
                break;
            }
        }
        if(!ok)break;
    }
    return r - 1;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    int r = 0;
    vi t;
    for (int i = 0; i < n; i++) {
        vi a = t;
        a.pb(k);
        for (int j = i; j < n; j++)a.pb(v[j]);

        r = max(r, calc(a));
        t.pb(v[i]);
    }
    t.pb(k);
    r = max(r, calc(t));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
