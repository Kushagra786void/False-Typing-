#include<bits/stdc++.h>
using namespace std;
class Trie{
    struct Node{
       bool wc=false;
       vector<Node*> child{vector<Node*>(26,NULL)};
    }*root,*curr;
    void dfs(){
        if(ans.size()==3)
        return ;
        if(curr->wc)
        ans.push_back(word);
        for(char c='a';c<='z';c++)
        {
            if(curr->child[c-'a'])
             word+=c;
            dfs()
            word.pop_back(); 
        }
    }
    public:
     Trie()
     {root=new Node();}
    void insert(string &s) 
    {
        curr=root;
        for(char c:s)
        {
            if(!curr->child[c-'a'])
             curr->child[c-'a']=new Node();
            curr=curr->child[c-'a'];
        }
        curr->wc=true;
    }
    vector<string> getWord(string &prefix)
    {
        curr=root;
        vector<string> ans;
        for(char c:prefix)
        {
            if(!curr->child[c-'a'])
             return ans;
            curr=curr->child[c-'a']; 
        }
        dfs(curr,prefix,ans);
    }
};
void solve(vector<string> words,string searchWord)
{
  Trie trie= Trie();
  vector<vector<string>>ans;
  for(string w:words)
   trie.insert(w);
  string prefix;
  for(char c:searchWord)
  {
    prefix+=c;
    ans.push_back(Trie.getWord(prefix));
  }
  return ans;

}

int main()
{
  return 0;
}