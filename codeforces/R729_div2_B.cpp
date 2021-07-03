#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a>> b;

        ll k = 1;
        bool flag = false;

        while(true) {
            if (k > n)break;
            if((n - k) % b == 0){
                flag = true;
                break;
            }
            k *= a;
            if (a == 1)break;
        }

        if (flag) cout << "Yes" <<endl;
        else cout <<"No"<<endl;

    }

}
