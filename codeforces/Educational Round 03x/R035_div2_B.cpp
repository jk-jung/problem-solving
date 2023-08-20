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

void solve() {
    int a, b, n;
    cin >> n >> a >> b;

    int r = 1;
    if (n == 2) r = min(a, b);
    else if (n == 3){
        r = min(max(a, b) / 2, min(a, b));
    }else {
        for (int i = 2; i <= min(a, b); i++) {
            int x = a / i;
            int y = b / i;
            if (x + y >= n)
                r = i;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
