#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    int r = n + n - 1;

    for (int i = 2; i < n; i++) {
        int a = v[i - 2];
        int b = v[i - 1];
        int c = v[i];

        if (a <= b && b <= c)continue;
        if (a >= b && b >= c)continue;
        r++;
    }

    for (int i = 3; i < n; i++) {
        int a = v[i - 3];
        int b = v[i - 2];
        int c = v[i - 1];
        int d = v[i];

        if (a <= b && b <= c)continue;
        if (a <= b && b <= d)continue;
        if (a <= c && c <= d)continue;
        if (b <= c && c <= d)continue;

        if (a >= b && b >= c)continue;
        if (a >= b && b >= d)continue;
        if (a >= c && c >= d)continue;
        if (b >= c && c >= d)continue;

        r ++ ;
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
