//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    struct comparatorObject{
        bool operator()(const pair<int, char> &l, const pair<int, char> &r){
            return l.first < r.first;
        }
    };
    string rearrangeString(string str)
    {
        unordered_map<char, int> mp;
        for(auto &e: str){
            mp[e]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, comparatorObject> pq;
        for(auto &e : mp){
            pq.push({e.second, e.first});
        }
        string ans = "";
        auto prev = pq.top();
        pq.pop();
        ans += prev.second;
        prev.first--;
        while(pq.empty() == false){
            auto curr = pq.top();
            pq.pop();
            ans += curr.second;
            curr.first--;
            if(prev.first != 0){
                pq.push(prev);
            }
            prev = curr;
        }
        if(prev.first != 0){
            return "-1";
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends