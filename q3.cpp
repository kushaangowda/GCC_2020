#include<bits/stdc++.h>
using namespace std;
string find_min_days(int profit[], int price[], int d)
{
	map <int,int> m;
    int i=1,p[d],q[d],c[d];
    for(int j=0;j<d;j++){
        c[j]=0;
    }
    m.insert(pair<int, int>(price[0], 1));
    while(price[i]){
        for(int j=0;j<d;j++){
            if(m[price[i]-profit[j]]>0 && c[j]==0){
                p[j] = m[price[i]-profit[j]];
                q[j] = i+1;
                c[j] = 1;
            }
        }
        m[price[i]] = i+1;
        i++;
    }
    
    string a;
    for(int j=0;j<d;j++){
        if(c[j]){
            a.append(to_string(p[j]));
            a.append(" ");
            a.append(to_string(q[j]));
            a.append(",");
        }else{
            a.append(to_string(-1));
            a.append(",");
        }
    }
    a.pop_back();
	//Participants code will be here
    return a;

}

int main ()
{
	int n,d,i;
	string answer="";
	cin>>n>>d;
	int price[n];
	int profit[d];
	for (i=0;i<n;i++)
		cin>>price[i];
	for (i=0;i<d;i++)
	    cin>>profit[i];
    answer = find_min_days(profit,price,d);

    // Do not remove below line
	cout<<answer<<endl;
    // Do not print anything after this line

	return 0;
}

// 90/90 test cases successful