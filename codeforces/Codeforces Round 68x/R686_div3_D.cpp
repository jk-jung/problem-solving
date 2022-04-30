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
    ll n, r = -1;
    cin >> n;
    ll m = n;
    map<ll, int> ck;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ck[i]++;
            n /= i;
            if (ck[i] >= ck[r])r = i;
        }
    }
    if (r == -1) {
        cout << "1\n" << m << endl;
    } else {
        cout << ck[r] << endl;
        for(int i=1;i<ck[r];i++)cout << r <<" ", m /= r;
        cout << m << endl;
    }
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
