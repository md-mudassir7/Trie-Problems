#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool isLeaf;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        isLeaf = true;
    }
    bool isEnd(){
        return isLeaf;
    }
};
class Trie{
private:
  Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* temp  = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    void dfs(string &word,Node* temp,vector<string>& ans){
        if(ans.size()==3)
            return;
        if(temp->isEnd()){
            ans.push_back(word);
        }
        for(char c = 'a';c<='z';c++){
            if(temp->containsKey(c)){
                word += c;
				dfs(word, temp->get(c), ans);
				word.pop_back();
            }
        }
        return;
    }
    vector<string> search(string &word){
        int n = word.size();
        vector<string> ans;
        Node* temp = root;
        for(int i=0;i<n;i++){
            if(!temp->containsKey(word[i])){
                return ans;
            }
            else
            {
                temp = temp->get(word[i]);
            }
        }
        dfs(word,temp,ans);
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
		int m = searchWord.length();
        Trie* trie = new Trie();
        for(int i=0;i<n;i++){
            trie->insert(products[i]);
        }
        vector<vector<string> > ans;
		string prefix = "";
        for(int i=0; i<m; i++){
            char c = searchWord[i];
			prefix += c;
			ans.push_back(trie->search(prefix));
	    }
        return ans;
    }
};