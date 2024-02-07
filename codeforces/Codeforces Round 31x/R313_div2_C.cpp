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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    //     a
    //  f     b
    //  e     c
    //     d

    int r = 0, t = a + a - 1;
    for (int i = 0; i < b + c; i++) {
        if (i < b)t++;
        else if(i == b);
        else t--;
        if (i < f) t++;
        else if(i == f);
        else t--;
        r += t;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
