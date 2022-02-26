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


int q(int x) {
    cout << "? " << x << endl;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vi a(n + 1), r(n + 1);

    for (int i = 1; i <= n; i++) {
        if (a[i]) continue;
        int x = i;

        vi v;
        while (1) {
            x = q(i);
            if(a[x]) break;
            a[x] = 1;
            v.pb(x);
        }

        for(int k=0;k<v.size();k++){
            int v1 = v[k];
            int v2 = v[(k + 1) % v.size()];
            r[v1] = v2;
        }
    }
    cout << "! ";
    for(int i=1;i<=n;i++) cout << r[i] <<" ";
    cout << endl;
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
