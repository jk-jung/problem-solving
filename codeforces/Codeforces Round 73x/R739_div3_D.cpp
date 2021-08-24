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

int calc(int x, ll k) {
    string a = to_string(x);
    string b = to_string(k);

    int n = (int)a.size();
    int m = (int)b.size();


    int r = 0;
    for(int i=0;i<a.size() && r < b.size();i++){
        if(a[i] == b[r]) r++;
    }

    return m + n - r * 2;
}

void solve() {
    int n;
    int r = 100000;

    cin >> n;
    for (ll i = 0, k = 1; i < 63; i++, k *= 2) {
        r = min(r, calc(n, k));
    }
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
