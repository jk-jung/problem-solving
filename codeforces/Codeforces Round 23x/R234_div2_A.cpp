#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    string s;
    cin >> s;
    vi r;
    for (int i = 1; i <= 12; i++) {
        if(12 % i)continue;
        int j = 12 / i;

        bool ok = false;
        for(int k=0;k<j;k++){
            bool ok2 = true;
            for(int l=k;l<12;l+=j){
                if(s[l] == 'O'){
                    ok2 = false;
                    break;
                }
            }
            if(ok2){
                ok = true;
                break;
            }
        }
        if(ok)r.pb(i);
    }
    cout << r.size();
    for(int x: r){
        cout << " " << x << "x" << 12 / x;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
