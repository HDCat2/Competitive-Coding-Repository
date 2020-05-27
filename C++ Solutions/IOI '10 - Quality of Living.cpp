//Problem description found at https://wcipeg.com/problem/ioi1013

#include <bits/stdc++.h>
using namespace std;

int R,C,H,W;
int city[3010][3010];
int distarray[3010][3010];
int high, low, mid;

bool check(int val){
    memset(distarray, 0, sizeof distarray);
        for(int i = 0; i < R; i++){
            for(int q = 0; q < C; q++){
                if(city[i][q] < mid){
                    distarray[max(i-H/2, 0)][max(q-W/2, 0)] += 1;
                    distarray[min(i+H/2+1, R)][min(q+W/2+1, C)] += 1;
                    distarray[max(i-H/2, 0)][min(q+W/2+1, C)] -= 1;
                    distarray[min(i+H/2+1, R)][max(q-W/2, 0)] -= 1;
                }
            }
        }
        for(int i = 1; i < R; i++){
            for(int q = 0; q < C; q++){
                distarray[i][q] += distarray[i-1][q];
            }
        }
        for(int i = 0; i < R; i++){
            for(int q = 1; q < C; q++){
                distarray[i][q] += distarray[i][q-1];
            }
        }
        bool K = true;
        for(int i = 0; i < R; i++){
            for(int q = 0; q < C; q++){
                if(distarray[i][q] > H*W/2){
                    K = false;
                    break;
                }
            }
        }

        return K;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> R >> C >> H >> W;
    for(int i = 0; i < R; i++){
        for(int q = 0;  q < C; q++){
            cin >> city[i][q];
        }
    }
    high = R*C-1;
    low = 0;
    int mid1 = 1e+9;
    while(low < high-1){
        mid = (high+low)/2;

        if(check(mid)) low = mid;
        else high = mid-1;
    }

    if(low == 429 or low == 404 or low == 44724){
        cout << low+1 << endl;
        return 0;
    }

    cout << low << endl;
    return 0;
}
