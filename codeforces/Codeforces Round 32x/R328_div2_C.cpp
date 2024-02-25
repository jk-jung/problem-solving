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
    ll n, a, b;
    cin >> n >> a >> b;

    ll m = min(a, b);

    ll g = gcd(a, b);
    ll lcm = 1e19 / (a / g) < b ? n + 1 : a / g * b;


    ll r = n / lcm * m - 1;
    r += min(n % lcm + 1, m);
    if (a == b)r = n;
    g = gcd(n, r);
    cout << r / g << "/" << n / g << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
