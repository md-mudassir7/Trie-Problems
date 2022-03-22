#include<bits/stdc++.h>
using namespace std;
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
    bool isEnd(){
        return isLeaf;
    }
    void setEnd(){
        isLeaf = true;
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
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    string prefix(string word){
        Node* temp = root;
        string ans;
        for(int i=0;i<word.size();i++){
            if(temp->get(word[i])==NULL)
                break;
            else
            {
                ans.push_back(word[i]);
                temp = temp->get(word[i]);
                if(temp->isEnd())
                    return ans;
            }
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for(auto x : dictionary){
            trie->insert(x);
        }
        string ans = "";
        string prefix = "";
        for(auto x : sentence){
            if(x==' '){
                ans+=trie->prefix(prefix);
                ans+=" ";
                prefix = "";
            }
            else
            {
                prefix+=x;
            }
        }
        ans+=trie->prefix(prefix);
        return ans;
    }
};