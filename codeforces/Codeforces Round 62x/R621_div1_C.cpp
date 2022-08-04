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

int cnt[100005][26];

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll r =0;
    for (int i = n - 1; i >= 0; i--) {
        for (int k = 0; k < 26; k++) {
            cnt[i][k] += cnt[i + 1][k] + (s[i] == 'a' + k);
            r = max(r, (ll)cnt[i][k]);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            ll t =0 ;
            for (int c = 0; c < n; c++) {
                if(s[c] == 'a' + i) t += cnt[c + 1][j];
            }
            r = max(r, t);
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
