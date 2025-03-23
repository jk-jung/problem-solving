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


string A = "Dasha";
string B = "Masha";

void solve() {
    ll a, b;
    cin >> a >> b;

    if (a > b)swap(a, b), swap(A, B);
    ll r = 0;
    ll bb = 0;
    for (ll i = 1; i <= b; i++) {
        ll aa = a * i;
        while(bb <= a * (i - 1))bb += b;
        if(aa < bb){
            r += a;
        }else if(bb <= aa){
            r += aa - bb;
        }
    }
    if(r + r == a * b)cout << "Equal";
    else if(r + r > a * b)cout << A;
    else cout << B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
