/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> &v)
{
    int n=v.size();
    stack<pair<int,int>> s;
    int count=1;
    int i,j;
    vector <int> v1;
    for(i=0;i<n;i++)
    {
        if(s.size()==0)
        {
            v1.push_back(1);
           s.push(make_pair(v[i],i));
            cout<<v[i]<<"1 ";
        }
        if(v[i]<s.top().first)
        {
            v1.push_back(abs(s.top().second-i));
           s.push(make_pair(v[i],i));
            cout<<v[i]<<"2 ";
        }
        else if(i!=0)
        {
            count=1;
            while(v[i]>=s.top().first)
            {
                count++;
                s.pop();
                if(s.size()==0)
                break;
            }
            if(s.size()==0)
            {
                  v1.push_back(1);
               s.push(make_pair(v[i],i));
                cout<<v[i]<<"3 ";
            }
            else if(v[i]<s.top().first){
                v1.push_back(abs(s.top().second-i));
                s.push(make_pair(v[i],i));
                cout<<v[i]<<"4 ";
                
            }
            count=1;
        }
    }
    return v1;
}

int main()
{
    int i,j,n;
    cin>>n;
    vector<int>v,v1;
    for(i=0;i<n;i++)
    {
        cin>>j;
        v.push_back(j);
    }
    
    v1=stockSpan(v);

for(i=0;i<v1.size();i++)
{
    cout<<v1[i]<<" ";
}
    return 0;
}

