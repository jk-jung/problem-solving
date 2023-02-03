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
    int n;
    cin >> n;
    vi v(n), t = {-1};
    for (int &x: v)cin >> x;
    string r;
    int s = 0, e = n - 1;
    while (s <= e) {
        if (v[s] < v[e] && t.back() < v[s])t.pb(v[s++]), r += 'L';
        else if (v[s] > v[e] && t.back() < v[e])t.pb(v[e--]), r += 'R';
        else if (v[s] == v[e]) {
            if (t.back() < v[s]) {
                int L = 0, R = 0;
                for (int i = s, k = t.back(); i < n; i++) {
                    if (k < v[i]) L++;
                    else break;
                    k = v[i];
                }
                for (int i = e, k = t.back(); i >=0; i--) {
                    if (k < v[i]) R++;
                    else break;
                    k = v[i];
                }
                if(L < R)r += string(R, 'R');
                else r += string(L, 'L');
            }
            break;
        } else if (t.back() < v[s])t.pb(v[s++]), r += 'L';
        else if (t.back() < v[e])t.pb(v[e--]), r += 'R';
        else break;
    }
    cout << r.size() << endl;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
