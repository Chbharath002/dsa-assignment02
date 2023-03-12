#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s,s1;
   cin>>s;
   for(int i=s.length()-1;i>=0;i--)
   {
       s1.push_back(s[i]);
   }
   if(s==s1)
   {
       cout<<"yes";
   }
   else
    cout<<"no";
}
