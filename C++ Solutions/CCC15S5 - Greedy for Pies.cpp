//Problem description found at https://wcipeg.com/problem/ccc15s5

#include <bits/stdc++.h>
using namespace std;

int pielist[3010];
vector<int> piebag;
int dynmap[3010][2][105][105];
int N,M,C,OP;

int recurse(int TL, int PBS, int PBE, int PLP){
    int W = 0, X = 0, Y = 0, Z = 0,A;
    A = TL - 1;
    if(dynmap[PLP][A][PBS][PBE] != -1){
        //cout << TL << " " << PBS << " " << PBE << " " << PLP << " " << dynmap[PLP][A][PBS][PBE] << " " << 1 << endl;
        return dynmap[PLP][A][PBS][PBE];
    }
    if(PLP == N){
        if(PBS <= PBE){
            if(TL == 1){
                return piebag[PBE] + recurse(2,PBS,PBE-1,PLP);
            }
            return recurse(1,PBS+1,PBE,PLP);
        }
        return 0;
    }
    else{
        if(TL == 1){
            W = pielist[PLP] + recurse(2,PBS,PBE,PLP + 1);
            X = recurse(1,PBS,PBE,PLP + 1);
            if(PBS <= PBE){
                Y = piebag[PBE] + recurse(1,PBS,PBE-1,PLP+1);
            }
            dynmap[PLP][A][PBS][PBE] = max(max(W,X),Y);
            //cout << PLP << "|" << A << "|" << PBS << "|" << PBE << endl;
            //cout << TL << " " << PBS << " " << PBE << " " << PLP << " " << max(max(W,X),Y) << " " << 4 << endl;
            return max(max(W,X),Y);
        }
        if(TL == 2){
            W = recurse(1,PBS,PBE,PLP+1);
            if(PBS <= PBE){
                X = pielist[PLP] + recurse(2,PBS+1,PBE,PLP+1);
            }
            dynmap[PLP][A][PBS][PBE] = max(W,X);
            //cout << PLP << "|" << A << "|" << PBS << "|" << PBE << endl;
            //cout << TL << " " << PBS << " " << PBE << " " << PLP << " " << max(W,X) << " " << 5 << endl;
            return max(W,X);
        }
    }
}

int main(){
    memset(dynmap, -1, sizeof dynmap);
    //freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", pielist+i);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &OP);
        piebag.push_back(OP);
    }
    if(piebag.size() == 0){
        recurse(1, 1, 0,0);
        cout << dynmap[0][0][1][0];
        return 0;
    }
    sort(piebag.begin(),piebag.end());
    recurse(1, 0, max(M-1,0),0);
    cout << dynmap[0][0][0][max(M-1,0)];
}
