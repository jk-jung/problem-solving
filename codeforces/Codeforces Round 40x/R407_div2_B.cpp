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
    ll b, q, l, m;
    cin >> b >> q >> l >> m;
    set<ll> s;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    if(b == 0 || q == 0){
        if(ab(b) > l)cout << 0;
        else if(s.count(0)){
            if(ab(b) <= l && !s.count(b))cout << 1;
            else cout << 0;
        }
        else cout << "inf" << endl;
    }else if(q == 1) {
        if (s.count(b) || ab(b) > l)cout << 0 << endl;
        else cout << "inf" << endl;
    }else if(q == -1) {
        if(ab(b) > l)cout << 0 << endl;
        else if (s.count(b) && s.count(-b))cout << 0 << endl;
        else cout << "inf" << endl;
    }else {
        int cnt = 0;
        while (ab(b) <= l) {
            if (!s.count(b))cnt++;
            b *= q;
        }
        cout << cnt << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
