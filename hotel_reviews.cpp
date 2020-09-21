#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    vector<node*> m;
    int count;
    node()
    {
        count=0;
        m=vector<node*>(26,NULL);
    }
};
struct comp
{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        if(a.first==b.first)
        return a.second<b.second;
        else
        return a.first>b.first;
    }
};
void insert(node* root,string str,int ind)
{
    if(ind==str.size())
    {
        root->count++;
        return ;
    }
    if(root->m[str[ind]-'a']!=NULL)
    {
        insert(root->m[str[ind]-'a'],str,ind+1);
    }
    else
    {
        root->m[str[ind]-'a']=new node();
        insert(root->m[str[ind]-'a'],str,ind+1);
    }
}
void print_util(node* root,string &pre)
{
    //vector<string> mtemp;
    if(root->count!=0)
    cout<<pre<<endl;
    for(int i=0;i<26;i++)
    {
        //vector<string> temp;
        if(root->m[i]!=NULL)
        {
            pre.push_back('a'+i);
            print_util(root->m[i],pre);
            pre.pop_back();
            //for(auto z:temp)
            //mtemp.push_back(to_string(char('a'+i))+z);
        }
    }
}
vector<string> tokenize(string a)
{
    int n=a.size(),i;
    string temp;
    vector<string> x;
    for(i=0;i<n;i++)
    {
        if(a[i]=='_')
        {
            if(temp.size()!=0)
            {
                x.push_back(temp);
            }
            temp="";
        }
        else
        temp.push_back(a[i]);
    }
    if(temp.size()!=0)
    x.push_back(temp);
    return x;
}
void print(node* root)
{
    string temp="";
    print_util(root,temp);
}
int find_util(node* root,string pre,int ind)
{
    if(ind==pre.size())
    {
        if(root->count>0)
        return 1;
        else
        return 0;
    }
    if(root->m[pre[ind]-'a']==NULL)
    return 0;
    else
    return find_util(root->m[pre[ind]-'a'],pre,ind+1);
}
int find(node* root,string pre)
{
    return find_util(root,pre,0);
}
int main()
{
    string a="cool_ice_wifi";
    vector<string> b{"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
    node *root=new node();
    vector<string> x=tokenize(a);
    for(int i=0;i<x.size();i++)
    {
        insert(root,x[i],0);
    }
   //string temp="";
   // print(root);
    vector<pair<int,int>> ans; 
    cout<<"given string is "<<a<<endl;
    for(int i=0;i<b.size();i++)
    {
        vector<string> temp=tokenize(b[i]);
        int count=0;
        for(int j=0;j<temp.size();j++)
        {
 
            count+=find(root,temp[j]);
            //cout<<count<<endl;
        }
        ans.push_back({count,i});
    }
    //sort(ans.begin(),ans.end(),comp());
   // vector<int> mans;
    for(int i=0;i<ans.size();i++)
    {
        cout<<"goodness value of "<<b[i]<<" is "<<ans[i].first<<endl;
    }
    return 0;
    
}