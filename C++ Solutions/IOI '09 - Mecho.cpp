//Problem description found at https://wcipeg.com/problem/ioi0922

#include <bits/stdc++.h>
using namespace std;

#define s second
#define f first

bool trav[810][810];
char field[810][810];
int N,S,bfsarr[810][810];
queue<pair<int,int>> Q;
pair<int, int> pos,start;

bool check(int P){
    for(int i = 0; i < 810; i++){
        for(int q = 0; q < 810; q++){
            trav[i][q] = 0;
        }
    }
    queue<pair<int,int>> Q2;
    if(bfsarr[start.f][start.s] > P) Q2.push(start);
    int ccc = 0;
    while(!Q2.empty()){
        ccc += 1;
        int kk = Q2.size();
        for(int i = 0; i < kk; i++){
            pair<int,int> p = Q2.front();
            Q2.pop();
            if(p == pos && bfsarr[pos.f][pos.s] - P - ccc/S > 0) return true;

            if(p.f < N-1){
                if(!trav[p.f+1][p.s] && bfsarr[p.f+1][p.s] - P - ccc/S > 0){
                    Q2.push({p.f+1,p.s});
                    trav[p.f+1][p.s] = true;
                }
            }
            if(p.f > 0){
                if(!trav[p.f-1][p.s] && bfsarr[p.f-1][p.s] - P - ccc/S > 0){
                    Q2.push({p.f-1,p.s});
                    trav[p.f-1][p.s] = true;
                }
            }
            if(p.s < N-1){
                if(!trav[p.f][p.s+1] && bfsarr[p.f][p.s+1] - P - ccc/S > 0){
                    Q2.push({p.f,p.s+1});
                    trav[p.f][p.s+1] = true;
                }
            }
            if(p.s > 0){
                if(!trav[p.f][p.s-1] && bfsarr[p.f][p.s-1] - P - ccc/S > 0){
                    Q2.push({p.f,p.s-1});
                    trav[p.f][p.s-1] = true;
                }
            }
        }
    }

    return false;
}

int main(){
    //freopen("input.txt","r",stdin);
    for(int i = 0; i < 810; i++){
        for(int q = 0; q < 810; q++){
            bfsarr[i][q] = 1e+9;
        }
    }
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;

    for(int i = 0; i < N; i++){
        for(int q = 0; q < N; q++){
            cin >> field[i][q];
            if(field[i][q] == 'T'){
                bfsarr[i][q] = -1;
            }
            if(field[i][q] == 'D'){
                bfsarr[i][q] = 1e+8;
                pos = {i,q};
            }
            if(field[i][q] == 'M'){
                start = {i,q};
            }
            if(field[i][q] == 'H') Q.push({i,q});
        }
    }

    int c = 0;
    while(!Q.empty()){
        int k = Q.size();
        for(int i = 0; i < k; i++){
            pair<int,int> m = Q.front();
            Q.pop();
            if(bfsarr[m.f][m.s] == 1e+9){
                bfsarr[m.f][m.s] = c;
                if(m.f + 1 < N){
                    if(bfsarr[m.f+1][m.s] == 1e+9) Q.push({m.f+1,m.s});
                }
                if(m.f - 1 >= 0){
                    if(bfsarr[m.f-1][m.s] == 1e+9) Q.push({m.f-1,m.s});
                }
                if(m.s + 1 < N){
                    if(bfsarr[m.f][m.s+1] == 1e+9) Q.push({m.f,m.s+1});
                }
                if(m.s - 1 >= 0){
                    if(bfsarr[m.f][m.s-1] == 1e+9) Q.push({m.f,m.s-1});
                }
            }
        }
        c+=1;
    }
    int mid = 0;
    int high = N*N*4, low = -1;

    while(high > low+1){
        mid = floor((high + low)/2.0);
        if(check(mid)) low = mid;
        else high = mid;
    }
    vector<int> sc = {mid,low,high,low+1,high+1,low+2,high+2};
    sort(sc.begin(),sc.end(),greater<int>());
    for(int i = 0; i < sc.size(); i++){
        if(check(sc[i])){
            cout << sc[i] << endl; return 0;
        }
    }
    cout << -1 << endl;
}
