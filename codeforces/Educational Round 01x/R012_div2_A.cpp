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
    int a, aa;
    int b, bb;
    int x, y;
    cin >> a >> aa >> b >> bb;
    scanf("%d:%d", &x, &y);
    x = x * 60 + y;
    y = x + aa;

    int r = 0;
    for (int z = 300; z <= 24 * 60 - 1; z += b) {
        if (z < y && z + bb > x)r++;
    }
    cout << r << endl;
}

int main() {
    solve();
}