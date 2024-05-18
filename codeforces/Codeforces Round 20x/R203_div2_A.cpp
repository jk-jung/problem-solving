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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    for(int i=1;i<=100;i++){
        bool ok1 = false;
        bool ok = true;
        for(int x:a) {
            if(x > i)ok = false;
            if(x *2 <= i)ok1 = true;
        }
        for(int x: b){
            if(x <= i)ok = false;
        }
        if(ok && ok1){
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
