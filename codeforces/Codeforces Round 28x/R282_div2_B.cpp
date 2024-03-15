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
    int a, b;
    cin >> a >> b;
    if (a == b)cout << "infinity";
    else if (a < b)cout << 0;
    else {
        a -= b;
        int r = 0;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                if (i > b)r++;
                if (a / i > b && i != a / i)r++;
            }
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
