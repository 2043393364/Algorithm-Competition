#include<bits/stdc++.h>

using namespace std;

// 并查集
int par[27];

// 并查集初始化
void init()
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

string strs[105];

int main()
{
    int n;
    cin >> n;
    init();
    for(int i=0;i<n;i++) 
        cin >> strs[i];

    // 先将相等的变量合并
    for(int i=0;i<n;i++){
        if(strs[i][1] == '='){
            unionn((int)(strs[i][0] - 'a'),(int)(strs[i][3]-'a'));
        }
    }

    // 判断不等方程是否成立
    for(int i=0;i<n;i++){
        if(strs[i][1] == '!'){
            int index1_par = fd(strs[i][0] - 'a');
            int index2_par = fd(strs[i][3] - 'a');
            // 如果等式不等，但两变量同属于一个集合里，则方程不成立
            if(index1_par == index2_par){
                cout << "false" << endl;
                return 0;
            }
        }
    }
    cout << "true" << endl;
    return 0;
}
