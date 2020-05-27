//Problem description found at https://wcipeg.com/problem/ccc14s2p1

#include <bits/stdc++.h>
using namespace std;

char grid[2010][2010];
int dynarray[2010][2010];
int N;
int C = 0;

int main(){
    memset(dynarray, 0, sizeof dynarray);
    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> N;
    //cout << 1;
    for(int i = 0; i < N; i++){
        for(int q = 0; q < N; q++){
            cin >> grid[i][q];
        }
    }
    //cout << 1;
    for(int i = 0; i < N; i++){
        if(grid[N-1][i] == '#'){
            dynarray[N-1][i] = 1;
            C+=1;
        }
    }
    //cout << 1;
    for(int i = N-2; i >= 0; i--){
        if(grid[i][0] == '#'){
            dynarray[i][0] = 1;
            C+=1;
        }
        if(grid[i][N-1] == '#'){
            dynarray[i][N-1] = 1;
            C+=1;
        }
        for(int q = 1; q < N-1; q++){
            if(grid[i][q] == '#'){
                dynarray[i][q] = 1 + min(dynarray[i+1][q-1], min(dynarray[i+1][q+1], dynarray[i+1][q]));
                C+=dynarray[i][q];
            }
        }
    }
    cout << C;
}
