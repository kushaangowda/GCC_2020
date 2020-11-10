#include<bits/stdc++.h>
using namespace std;
double maximumExpectedMoney(int n, int m, double p[], double x[], double y[] )
{
    for(int i=0;i<n;i++){
        x[i] = (p[i]*x[i])-((1-p[i])*y[i]);
    }
    sort(x,x+n);
    reverse(x,x+n);
    float ans = 0;
    for(int i=0;i<min(m,n);i++){
        if(x[i]>0){
            ans+=x[i];
        }else{
            break;
        }
    }
    //Complete the maximumExpectedMoney function.
    return ans;

}


int main(){
    int n, m;

    cin >> n >> m;
    double p[n], x[n], y[n];

    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        cin >> y[i];

    double result=maximumExpectedMoney(n,m,p,x,y);

    // Do not remove below line
    cout << fixed<<setprecision(2)<<result << endl;
    // Do not print anything after this line

    return 0;
}

//85/90 test cases successful