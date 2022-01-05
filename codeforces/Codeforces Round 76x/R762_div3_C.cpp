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


ll go(ll a, ll s, ll c = 0, ll base = 1) {
    if(s == 0) return a ? -1 : c;

    for (int i = 0; i <= 9; i++) {
        int x = a % 10 + i;
        for (int b = 10; b <= 100; b *= 10) {
            if(x < 10 && b == 100)break;
            if (s % b == x) {
                ll r = go(a / 10, s / b, c + i * base, base * 10ll);
                if (r != -1) return r;
            }
        }
    }
    return -1;
}

void solve() {
    ll a, s;
    cin >> a >> s;
    cout << go(a, s) << endl;
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
