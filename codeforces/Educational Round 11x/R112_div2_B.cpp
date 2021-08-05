#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
    int W, H, x1, x2, y1, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    int w1 = x2 - x1;
    int h1 = y2 - y1;
    int ww[] = {x1, x1,     W - x2, W - x2};
    int hh[] = {y1, H - y2, y1,     H - y2};

    if (w1 + w > W && h1 + h > H) {
        cout << -1 << endl;
        return;
    }

    double r = 1e20;
    for (int i = 0; i < 4; i++) {
        double a = 0;
        double b = 0;
        if (w > ww[i]) a = w - ww[i];
        if (h > hh[i]) b = h - hh[i];
        if(w1 + w > W) a = 1e10;
        if(h1 + h > H) b = 1e10;
        r = min(r, sqrt(min(a, b) * min(a, b)));
    }

    printf("%.10lf\n", r);

}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
