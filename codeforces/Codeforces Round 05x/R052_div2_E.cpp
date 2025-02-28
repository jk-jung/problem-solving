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

map<int, int> rr;


void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);
    vi org(n);

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        v[i] = mp(x, y);
        org[i] = x;
    }
    sort(v.rbegin(), v.rend());

    vector<pi> st;
    for(int i=0;i<n;i++){
        int x = v[i].F;
        int y = v[i].S;

        if (st.empty()) {
            st.pb(mp(i, i));
            rr[x] = 1;
        } else {
            int j = i;
            while(!st.empty() && v[st.back().F].F < x + y){
                j = st.back().S;
                st.pop_back();
            }
            st.pb(mp(i, j));
            rr[x] = i - j + 1;
        }
    }
    for (int x: org)cout << rr[x] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
