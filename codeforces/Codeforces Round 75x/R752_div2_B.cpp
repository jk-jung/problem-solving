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

int a[100005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    int r = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i + 1])r = 1;
    }

    if( n% 2 == 0 || r == 1) {
        cout << "YES\n";
    }
    else {
        cout <<"NO\n";
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
