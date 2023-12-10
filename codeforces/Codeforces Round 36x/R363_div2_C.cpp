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


int d[1005][3];

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    memset(d, 63, sizeof(d));
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            d[i][0] = 1;
            if (v[i] >> 0 & 1)d[i][1] = 0;
            if (v[i] >> 1 & 1)d[i][2] = 0;
        } else {
            for (int y = 0; y < 3; y++) {
                for(int x = 0; x < 3; x++){
                    if(x == 0) {
                        d[i][x] = min(d[i][x], d[i - 1][y] + 1);
                    }else if((v[i] >> (x - 1) & 1) && x != y){
                        d[i][x] = min(d[i][x], d[i - 1][y]);
                    }
                }
            }
        }
    }
    cout << min(d[n - 1][0], min(d[n - 1][1], d[n - 1][2])) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
