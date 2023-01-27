#include<bits/stdc++.h>

using namespace std;

// 并查集
int par[105];

// 并查集初始化
void init(int n)
{
    for(int i=0;i<n;i++)
        par[i] = i;
}

// 并查集查找
int fd(int index){
    if(par[index] == index){
        return index;
    }
    par[index] = fd(par[index]);
    return par[index];
}

// 并查集合并
void unionn(int index1,int index2){
    if(par[index1] == par[index2]) return;

    // 找到index1的root
    int index1_par = fd(index1);
    // 找到index2的root
    int index2_par = fd(index2);
    // 将index2的祖先 赋值为index1的祖先
    par[index2_par] = index1_par;

}

// 计算连通分量的个数

int cnt(int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        if(par[i] == i){
            ans++;
        }
    }
    return ans;
}

int mp[105][105];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> mp[i][j];
    init(n);
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(mp[i][j]){
                unionn(i,j);
            }
        }
    }
    cout << cnt(n) << endl;
    return 0;
}
