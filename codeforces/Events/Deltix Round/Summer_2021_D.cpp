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

int a[10004];
int b[10004];
int r[10005];
int k, n, t;

int and_(int a, int b) {
    cout << "and" << " " << a + 1<< " " << b + 1<< endl;
    cin >> t;
    return t;
}

int or_(int a, int b) {
    cout << "or" << " " << a + 1<< " " << b+ 1 << endl;
    cin >> t;
    return t;
}

void solve() {
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        a[i] = and_(0, i);
        b[i] = or_(0, i);
    }
    a[0] = and_(1, 2);

    for (int i = 0; i < 31; i++) {
        int a01 = a[1] >> i & 1;
        int b01 = b[1] >> i & 1;

        int a02 = a[2] >> i & 1;
        int b02 = b[2] >> i & 1;

        int a12 = a[0] >> i & 1;

        if(a01 == 0 && b01 == 1 && a02 == 0 && b02 == 1){
            if(a12 == 0) r[0] |= (1 << i);
        }else {
            if(a01 == 1 || a02 == 1) r[0] |= (1 << i);
        }
    }

    for(int i=1;i<n;i++){
        r[i] = b[i] - r[0] + a[i] ;
    }
    sort(r, r+n);
    cout << "finish " << r[k-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
