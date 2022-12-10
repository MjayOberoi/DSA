struct Node{
    int id;
    int time;
    Node *next=NULL;
    Node(int id,int time)
    {
        this->id=id;
        this->time=time;
        next=NULL;
    }
};
struct str{
    unordered_set<int> f;
    Node *post;
    str()
    {
        post=NULL;
    }
};
class Twitter {
private:
    Node* insert(Node *root,int key,int tm)
    {
        Node *h=new Node(key,tm);
        h->next=root;
        return h;
    }
public:
    str ds[501];
    int cnt=1;
    Twitter() {
        cnt=1;
    }
    
    void postTweet(int userId, int tweetId) {
        ds[userId].post=insert(ds[userId].post,tweetId,cnt);
        cnt+=1;
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,Node *>>pq;
        if(ds[userId].post)
            pq.push({ds[userId].post->time,ds[userId].post});
        
        for(auto x:ds[userId].f)
            if(ds[x].post)
                pq.push({ds[x].post->time,ds[x].post});
        
        vector<int>ans;
        while(!pq.empty() && ans.size()<10)
        {
            Node *curr=pq.top().second;
            ans.push_back(curr->id);
            pq.pop();
            curr=curr->next;
            if(curr)
                pq.push({curr->time,curr});
        }
        return ans; 
    }
    void follow(int followerId, int followeeId) {
        ds[followerId].f.insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if(ds[followerId].f.find(followeeId)!=ds[followerId].f.end())
            ds[followerId].f.erase(followeeId);
    }
};