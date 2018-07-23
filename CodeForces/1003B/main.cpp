#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a,b,x;
    string s,t,c;

    cin>>a>>b>>x;
    s="";
    if(a>b)
        t="1",s="0",a--;
    else
        t="0",s="1",b--;
    while(x>1)
    {
        s+=t;
        x--;
        //a--;
        //b--;
        if(t=="0")
            t="1",a--;
        else
            t="0",b--;
    }
    c = s[s.size()-1];
    if(c=="0")
    {
        while(a--)
            s+="0";
        while(b--)
            s+="1";
    }
    else
    {
        while(b--)
            s+="1";
        while(a--)
            s+="0";

    }
    cout<<s<<endl;

    return 0;
}