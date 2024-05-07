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
    ll r = 1;
    vi t;
    cin >> s;
    s += 'A';
    for(char x: s){
        int k = x - '0';
        if(t.empty() || t.back() + k == 9)t.pb(k);
        else{
            if(t.size() % 2)r *= (t.size() + 2) / 2;
            t.clear();
            t.pb(k);
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
