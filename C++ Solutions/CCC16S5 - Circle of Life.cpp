//Problem description found at https://wcipeg.com/problem/ccc16s5

#include <bits/stdc++.h>
using namespace std;

int n;
long long t;
string c;

string toBinary(long long n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

string sim(string C, int N, long long T){
    string K = "";
    for(int i = 0; i < N; i++){
        long long c1 = 0;
        long long oo = i - T, op = i + T;
        oo %= N;
        op %= N;
        if(oo < 0) oo += N;
        if(C[oo] == '1') c1 += 1;
        if(C[op] == '1') c1 += 1;

        //cout << oo << " " << op << endl;;
        if(c1 == 1) K += "1";
        else K += "0";
    }
    return K;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> n >> t >> c;

    while(t > 0){
        long long y = pow(2, toBinary(t).length()-1);
        t -= y;
        //cout << y << " " << t << endl;
        c = sim(c,n,y);
        //cout << c << endl;
    }

    cout << c << endl;

    return 0;
}
