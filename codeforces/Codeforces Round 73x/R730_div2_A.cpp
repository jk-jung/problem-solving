#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll c = ab(a - b);
        if ( c == 0) cout<< "0 0" << endl;
        else {
            ll x = min(a % c, c - (a%c));
            cout << c << " " << x << endl;
        }
    }
}
