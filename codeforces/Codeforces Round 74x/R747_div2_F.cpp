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

void solve() {
    ll s, n, k;
    cin >> s >> n >> k;

    if(s == k){
        cout <<"YES" << endl;
        return;
    }

    ll rem = min(k, s % (2 * k) + 1);
    ll cnt = s / (2 * k);
    ll tot = k * cnt + rem;
    cout << (tot >= n + 1 ? "NO" : "YES") << '\n';
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
