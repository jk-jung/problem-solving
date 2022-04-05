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
    ll s = 0, n;
    cin >> n;
    map<ll, int> ck;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        ck[x] ++;
    }

    for (auto [k, x]: ck) {
        ll need = s / 2 - k;
        if((need + k) * 2 == s && ck.count(need)) {
            if(need == k && x == 1)continue;
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
