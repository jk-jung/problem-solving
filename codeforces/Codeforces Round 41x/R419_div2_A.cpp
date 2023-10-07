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

int a, b;

bool ck() {
    int c = a / 10 + (a % 10) * 10;
    return c == b;
}

void solve() {
    char c;
    cin >> a >> c >> b;
    int r = 0;
    while (!ck()) {
        r++;
        if (++b == 60) {
            b = 0;
            if (++a == 24)a = 0;
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
