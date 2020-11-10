#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<bits/stdc++.h>

using namespace std;
string organizingContainers(vector< vector<int> > M, int n) {
// Complete the organizingContainers function .
    int c=1,a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=accumulate(M[i].begin(), M[i].end(), 0);
        a[i]-=M[i][i];
        for(int j=0;j<n;j++){
            if(i!=j)
            a[i]-=M[j][i];
        }
        if(a[i]!=0){
            c=0;
            break;
        }
    }
    if(c)
    return "Possible";
    else
    return "Impossible";
}

int main(){
    int q;
    cin >> q;
    string answer ="";
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector< vector<int> > M(n,vector<int>(n));
        for(int M_i = 0;M_i < n;M_i++){
           for(int M_j = 0;M_j < n;M_j++){
              cin >> M[M_i][M_j];
           }
        }

		string result=organizingContainers(M,n);
        if (answer =="")
            answer = result;
        else
            answer = answer + "," + result;
    }

    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line

    return 0;
}

// 90/90 test cases successful