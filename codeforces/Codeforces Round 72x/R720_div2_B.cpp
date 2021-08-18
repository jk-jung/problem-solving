#include <string.h>
#include <stdio.h>
#include <math.h>
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
    vector<pi> v(n);
    for (int i = 0; i < n; i++)cin >> v[i].F, v[i].S = i;

    sort(v.begin(), v.end());


    cout << n - 1 << '\n';
    for (int i = 1; i < n; i++) {
        int s = v[0].S + 1;
        int e = v[i].S + 1;
        cout << s << " " << e << " " << v[0].F << " " << v[0].F + ab(s - e) << '\n';
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
