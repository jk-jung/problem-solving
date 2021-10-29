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
    int n;
    string v;
    cin >> n >> v;
    int r = n + 1;

    for (char c = 'a' - 1; c <= 'z'; c++) {
        int s = 0, e = v.size() - 1;
        int er = 0;

        while(s < e) {
            if(v[s] != v[e]) {
                if(v[s] == c) s ++, er ++;
                else if(v[e] == c) e --, er ++;
                else { er = 1<<20; break; }
            } else {
                s ++;
                e --;
            }
        }
        r = min(r, er);
    }
    if (r == n + 1) r = -1;
    cout << r << endl;
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
