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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll need = (4 - (n % 4)) % 4;

    ll r = a * need;
    if (need == 1) {
        r = min(r, b + c);
        r = min(r, c * 3);
    } else if (need == 2) {
        r = min(r, b);
        r = min(r, a * 2);
        r = min(r, c * 2);
    } else if (need == 3) {
        r = min(r, a * 3);
        r = min(r, a + b);
        r = min(r, c);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
