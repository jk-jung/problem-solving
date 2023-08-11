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

int d[1000005];
int s[10][1000005];

int g(int x) {
    if (x < 10)return x;
    int &r = d[x];
    if (r != -1)return r;
    int n = 1;
    while (x) {
        if (x % 10) n *= x % 10;
        x /= 10;
    }
    return r = g(n);
}

void solve() {
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= 1000000; i++){
        int t = g(i);
        for(int k=0;k<10;k++)s[k][i] = s[k][i - 1] + (t == k);
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << s[k][b] - s[k][a - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
