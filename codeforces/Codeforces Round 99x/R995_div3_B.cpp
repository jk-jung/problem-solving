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

void solve() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll d = a + b + c;
    ll t = n / d * 3;
    n = n % d;
    if (n == 0) {
        cout << t << endl;
        return;
    }
    else if(n <= a) {
        cout << t + 1 << endl;
    } else if(n <= a + b) {
        cout << t + 2 << endl;
    } else {
        cout << t + 3 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
