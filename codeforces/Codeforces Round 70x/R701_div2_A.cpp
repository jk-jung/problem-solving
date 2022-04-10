#include <string.h>
#include <stdio.h>
#include <math.h>
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

    int r = 1 << 30;
    for (int i = 0; i < 100; i++) {
        int aa = a;
        int bb = b + i;
        int t = i;

        if(bb == 1)continue;
        while(aa)aa/=bb, t++;
        r = min(r, t);
    }
    cout << r<< endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
