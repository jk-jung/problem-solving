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



bool check(ll a, ll b, ll x) {
    do {
        if (a < b)swap(a, b);
        if (x == b) return true;
        if (x <= a && x % b == a % b) return true;
        a %= b;
    } while (a);
    return false;
}

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;

    cout << (check(a, b, x) ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
