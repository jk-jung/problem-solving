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
    int x;
    cin >> x;
    int h, m;
    cin >> h >> m;

    int r = 0;
    while (true) {
        int a = h / 10;
        int b = h % 10;
        int c = m / 10;
        int d = m % 10;

        if (a == 7 || b == 7 || c == 7 || d == 7)break;
        r++;

        int nxt = h * 60 + m - x;
        if(nxt < 0) nxt += 24 * 60;
        h = nxt / 60;
        m = nxt % 60;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
