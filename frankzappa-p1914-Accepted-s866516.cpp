#include<bits/stdc++.h>
using namespace std;

int main(){
    vector< pair<long long, long long> > pu;
    long long x, y, r;
    int N, C;

    scanf("%d%d",&N, &C);
    for(int i = 0; i < N; i++){
        scanf("%lld%lld",&x,&y);
        pu.push_back(make_pair(x,y));
    }
    for(int i = 0; i < C; i++){
        scanf("%lld%lld%lld",&x,&y,&r);
        int ans = 0;
        for(int i = 0; i < N; i++)
            if((((x - pu[i].first) * (x - pu[i].first)) + ((pu[i].second - y) * (pu[i].second - y))) <= (r * r))
                ans++;
        printf("%lld\n",ans);
    }
}
