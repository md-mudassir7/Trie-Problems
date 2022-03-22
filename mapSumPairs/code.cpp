#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int value = 0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void assignValue(int val){
        value+= val;
    }
    int getVal(){
        return value;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word,int val){
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new Node());
            }
            temp->assignValue(val);
            temp = temp->get(word[i]);
        }
        temp->assignValue(val);
    }
    int storedValue(string prefix){
        Node* temp = root;
        for(int i=0;i<prefix.size();i++){
            if(!temp->get(prefix[i]))
                return 0;
            temp = temp->get(prefix[i]);
        }
        return temp->getVal();
    }
};
class MapSum {
private:
    Trie* trie;
    map<string,int> mp;
public:
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        if(mp.find(key)!=mp.end()){
            //If the map already has value lets say {"apple":1} and current key value pair from the params is {"apple":4}
            //then we should update the value of "apple" to 4, by writing the below statement we are storing (4-1 = 3)
            //in the variable map hence we should add 3 to the previous existense of "apple" to make it 4
            val = val - mp[key]; 
            //After updating the val we should make sure we insert the val(from the params) into the map
            //Hence we write the below statement
            mp[key] = val+mp[key];
        }
        else
            mp[key] = val;
        trie->insert(key,val);
    }
    
    int sum(string prefix) {
        return trie->storedValue(prefix);
    }
};
