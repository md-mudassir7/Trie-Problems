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
int ans = 0;
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    bool insert(string word){
        Node* temp = root;
        int n = word.size();
        bool isNewWord = false;
        for(int i=n-1;i>=0;i--){
            if(!temp->containsKey(word[i])){
                if (!isNewWord)
                    isNewWord = true;
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        return isNewWord;
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* trie = new Trie();
        int ans = 0;
        sort(words.begin(), words.end(),[](const string &a, const string &b) { return a.size() > b.size();});
        for(auto x : words){
            bool isNewWord = trie->insert(x);
            if(isNewWord)
                ans+= x.size()+1;
        }
        return ans;
    }
};