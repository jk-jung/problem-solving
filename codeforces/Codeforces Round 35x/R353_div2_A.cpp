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
    ll a, b, c;
    cin >> a >> b >> c;
    if(c == 0) {
        cout << (a == b ? "YES" : "NO") << endl;
        return;
    }
    if(c > 0)
        cout << (b >= a && (b - a) % c == 0 ? "YES" : "NO") << endl;
    else
        cout << (b <= a && (a - b) % (-c) == 0 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
