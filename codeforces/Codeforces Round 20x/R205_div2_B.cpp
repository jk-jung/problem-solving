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
    int n;
    cin >> n;
    vi v(n * 2), r(n * 2, 1);
    map<int, vi> c;
    for (int i = 0; i < n * 2; i++) {
        int x;
        cin >> x;
        v[i] = x;
        c[x].pb(i);
    }
    int aa = 0, bb = 0;
    map<int, int> ac, bc;
    for (auto &[x, y]: c) {
        if (y.size() >= 2) {
            aa++, bb++;
            ac[x] = 1;
            r[y.back()] = 1;
            y.pop_back();

            bc[x] = 1;
            r[y.back()] = 2;
            y.pop_back();
        }else if(ac.size() <= bc.size()){
            aa++;
            ac[x] = 1;
            r[y.back()] = 1;
            y.pop_back();
        }else{
            bb++;
            bc[x] = 1;
            r[y.back()] = 2;
            y.pop_back();
        };
    }
    for (auto &[x, y]: c) {
        for(int k: y) {
            if(bb < n){
                bb++;
                r[k] = 2;
            }
        }
    }
    cout << ac.size() * bc.size() << endl;
    for (int i = 0; i < n * 2; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
