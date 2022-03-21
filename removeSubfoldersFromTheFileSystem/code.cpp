#include<bits/stdc++.h>
using namespace std;
class SortingSolution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        string prev = folder[0];
        for(int i=1;i<folder.size();i++){
            int l = prev.size();
            if(folder[i].substr(0,l)==prev and folder[i].size()>l and folder[i][l]=='/')
            {
                continue;
            }
            else
            {
                ans.push_back(folder[i]);
                prev = folder[i];
            }
        }
        return ans;
    }
};
struct Node{
    Node* links[26];
    bool isLeaf = false;
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
    bool insert(string word){
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(word[i]=='/')
                continue;
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
            if(word[i+1]=='/' && temp->isEnd()){
                return false;
            }
        }
        temp->setEnd();
        return true;
    }
};
class TrieSolution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        Trie* trie = new Trie();
        for(int i=0;i<folder.size();i++){
            if(trie->insert(folder[i])){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};