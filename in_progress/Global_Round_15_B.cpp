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

int a[50005][5];

int cc(int y, int x) {
    int r = 0;
    for (int i = 0; i < 5; i++)if (a[y][i] < a[x][i]) r++;
    return r >= 3;
}

int win(int y, int x) {
    if (cc(y, x)) return y;
    if (cc(x, y)) return x;
    return -1;
}

bool sf(int y, int x) {
    return cc(y, x);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    for (int i = 0; i < n; i++)v1.pb(i);

    sort(v1.begin(), v1.end(), sf);

    int r = 0;
    int x = v1[0];
    for(int i=0;i<n;i++) {
        if(i == x)continue;
        if(cc(x, i)) r ++;
    }

    cout<< (r== n-1 ? x+1 : -1)<<endl;
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
