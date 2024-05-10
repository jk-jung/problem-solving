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
int n;

ll calc(vector<int> &v) {
    ll r = 0, c =0 ;
    for(int x:v) {
        if(x) c++;
        else r += c;
    }
    return r;
}

void solve() {

    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    ll r = calc(v);
    for (int &x: v)x ^= 1;
    reverse(v.begin(), v.end());
    r = min(r, calc(v));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
