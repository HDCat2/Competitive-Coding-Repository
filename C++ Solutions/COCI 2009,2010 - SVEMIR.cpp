//Problem description found at https://wcipeg.com/problem/coci097p4

#include <bits/stdc++.h>
using namespace std;

class UF    {
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int finder(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merger(int x, int y)	{
        int i = finder(x);
        int j = finder(y);
        if (i == j) return;

		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{
		id[i] = j;
		sz[j] += sz[i];
	} else	{
		id[j] = i;
		sz[i] += sz[j];
	}
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return finder(x) == finder(y);
    }
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};

#define f first
#define s second

int N,x,y,z;
vector<pair<int, int>> tx,ty,tz;
vector<pair<int, pair<int, int>>> mstg;
int main(){
    //freopen("input.txt","r",stdin);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y >> z;
        tx.push_back({x,i});
        ty.push_back({y,i});
        tz.push_back({z,i});
    }

    sort(tx.begin(), tx.end());
    sort(ty.begin(), ty.end());
    sort(tz.begin(), tz.end());

    for(int i = 1; i < N; i++){
        mstg.push_back({tx[i].f - tx[i-1].f, {tx[i].s, tx[i-1].s}});
        mstg.push_back({ty[i].f - ty[i-1].f, {ty[i].s, ty[i-1].s}});
        mstg.push_back({tz[i].f - tz[i-1].f, {tz[i].s, tz[i-1].s}});
    }

    sort(mstg.begin(), mstg.end());
    UF uf(N);
    int tots = 0;
    for(int i = 0; i < mstg.size(); i++){
        if(uf.finder(mstg[i].s.f) != uf.finder(mstg[i].s.s)){
            tots += mstg[i].f;
            uf.merger(mstg[i].s.f, mstg[i].s.s);
        }
    }

    cout << tots << endl;
    return 0;
}
