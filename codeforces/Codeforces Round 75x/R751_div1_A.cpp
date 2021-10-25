#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
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
    int n;
    cin >> n;
    vi v(n), cnt(36);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) if (v[i] >> j & 1)cnt[j]++;
    }

    int g = 0;
    for(int i=0;i<31;i++){
        g = gcd(g, cnt[i]);
    }
    if (g == 0) {
        for(int i=1;i<=n;i++){
            cout << i <<" ";
        }
    }else {
        for(int i=1;i<=g;i++) {
            if(g % i == 0 || g == 0)cout << i << " ";
        }
    }

    cout << '\n';

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
