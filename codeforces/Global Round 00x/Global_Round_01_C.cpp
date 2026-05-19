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

int d[1 << 25];

int go(int x) {
    if (d[x]) return d[x];
    int r = 1;
    for(int i=3;i*i<=x;i++){
        if(x % i == 0){
            r = x / i;
            break;
        }
    }
    d[x] = r;
    return r;
}

void solve() {
    int n, m = 0;
    cin >> n;
    for (int i = 1; i < 30; i++) {
        if ((1 << i) - 1 >= n) {
            m = (1 << i) - 1;
            break;
        }
    }
    if (n == m) {
        cout << go(n) << endl;
    } else {
        cout << m << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
