#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool isLeaf = false;
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void add(char ch, Node* node){
        links[ch-'a'] = node;
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
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i]))
            {
                temp->add(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    bool helper(string word,int ind,int len,Node* temp){
        for(int i=ind;i<word.size();i++){
            if(word[i]=='.'){
                /*
					This piece of code is the key to solve this problem 
					so what this line basically do is it checks if our string has any possibilty 
					for any character between a to z where we get our desired results. 
					So we just make a recursive call to the same function for 
					every possible character at the place of "."!
				*/
                for(char ch='a';ch<='z';ch++){
                    if(temp->containsKey(ch) && helper(word,i+1,len,temp->get(ch))){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(!temp->containsKey(word[i]))
                {
                    return false;
                }
                temp = temp->get(word[i]);
            }
        }
        if(temp->isEnd())
            return true;
        return false;
    }
    bool search(string word){
        Node* temp = root;
        return helper(word,0,word.size(),temp);
    }
};
class WordDictionary {
private:
    Trie* trie;
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */