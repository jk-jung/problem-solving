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
    ll n, k, m;
    string s;
    cin >> n >> k >> m;
    cin >> s;
    vi v;
    char y = ' ';
    for (char x: s) {
        if (x == 'a') v.pb(0);
        else if (y == x) v.back()++;
        else v.pb(1);
        y = x;
    }
    m--;
    string r;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0)r += 'a';
        else {
            ll t = 1;
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j]) {
                    ll q = (k * v[j] + 1);
                    if(t > m / q)t = m + 1;
                    else t *= q;
                }
            }
            for (int j = 0; j < m / t; j++)r += 'b';
            m %= t;
        }
    }

    cout << r << endl;
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
