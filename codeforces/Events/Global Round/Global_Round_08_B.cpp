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

string s = "codeforces";

ll mul(vi &v) {
    ll r = 1;
    for (int x: v)r *= x;
    return r;
}

void solve() {
    ll n;
    cin >> n;

    vi v(s.size(), 1);
    while (mul(v) < n) {
        sort(v.begin(), v.end());
        v[0]++;
    }
    for(int i=0;i<v.size();i++){
        cout << string(v[i], s[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
