#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
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

int n;
ll v[1005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> v[i];
    ll r = 0;

    for (int i = 1; i < n; i += 2) {
        ll dif = v[i] - v[i-1];
        r += min(v[i-1], v[i]);

        if(dif >= 0){
            ll st = 0;
            for (int j = i - 2; j >= 0; j--) {
                if (j % 2 == 0) {
                    st += v[j];
                    if( st >= 0) {
                        r += min(dif, st) + 1;
                        dif -= st;
                        st = 0;
                    }

                    if( dif < 0)break;
                } else {
                    st -= v[j];
                }
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
