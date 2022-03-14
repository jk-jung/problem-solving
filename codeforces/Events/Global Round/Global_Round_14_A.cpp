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
    int n, k, s = 0;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x, s += x;
    sort(v.begin(), v.end());
    if (s == k) {
        cout << "NO" << endl;
    }else {
        int t = 0, r = 0;
        cout << "YES" << endl;
        for(int x: v) {
            if(t + x == k){
                r = x;
            }else {
                cout << x << " ";
                t += x;
            }
        }
        if(r)cout << r << " ";
        cout << endl;
    }


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
