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

int a[55];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    bool flag = 0;
    for (int i = 0; i < n; i++) if (i + 1 != a[i]) flag = 1;
    int r = 2;
    if (flag == 0) r = 0;
    else if (a[0] == 1 || a[n - 1] == n) r = 1;
    else if (a[0] == n && a[n - 1] == 1)r = 3;
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
