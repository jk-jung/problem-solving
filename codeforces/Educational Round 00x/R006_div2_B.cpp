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

int d[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve() {
    int a, b;
    cin >> a >> b;
    vi c(10);
    for (int i = a; i <= b; i++) {
        int x = i;
        while (x) {
            c[x % 10]++;
            x /= 10;
        }
    }
    int r = 0;
    for (int i = 0; i < 10; i++)r += d[i] * c[i];
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
