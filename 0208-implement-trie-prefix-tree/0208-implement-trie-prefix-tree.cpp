class TrieNode{
public:
    char zimu;
    bool has;
    vector<TrieNode*>next;
    TrieNode():has(false){next.resize(26,nullptr);}
    TrieNode(char a):zimu(a),has(false){next.resize(26,nullptr);}
};

class Trie {
    TrieNode*root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*tmp=root;
        for(auto i:word){
            if(tmp->next[i-'a'])tmp=tmp->next[i-'a'];
            else {
                tmp->next[i-'a']=new TrieNode(i);
                tmp=tmp->next[i-'a'];
            }
        }
        tmp->has=true;
    }
    
    bool search(string word) {
        TrieNode*tmp=root;
        for(auto i:word){
            if(tmp->next[i-'a']){
                tmp=tmp->next[i-'a'];
            }
            else return false;
        }
        return tmp->has;
    }
    
    bool startsWith(string prefix) {
        TrieNode*tmp=root;
        for(auto i:prefix){
            if(tmp->next[i-'a']){
                tmp=tmp->next[i-'a'];
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */