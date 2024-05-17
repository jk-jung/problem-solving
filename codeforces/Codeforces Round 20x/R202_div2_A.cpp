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
    vi v(n);
    map<int,int> ck;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 25)ck[25]++;
        else if(x == 50) {
            if(ck[25] == 0){
                cout << "NO" << endl;
                return;
            }
            ck[25]--;
            ck[50]++;
        }else {
            if(ck[50] > 0 && ck[25] > 0){
                ck[50]--;
                ck[25]--;
            }else if(ck[25] >= 3){
                ck[25] -= 3;
            }else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}