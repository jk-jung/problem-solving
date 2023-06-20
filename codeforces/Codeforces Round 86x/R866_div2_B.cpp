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
    string s;
    cin >> s;
    ll t = ll(s.size());
    ll c = 0;
    ll r = 0;
    if(s.find('0') == -1){
        cout << t * t << endl;
        return;
    }
    s = s + s + '0';
    for (char i: s) {
        if (i == '1') c++;
        else if (i == '0') {
            c = min(c, t);
            for (ll j = 1; j <= c; j++)r = max(r, j * (c - j + 1));
            c = 0;
        }
    }
    cout << r << endl;
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
