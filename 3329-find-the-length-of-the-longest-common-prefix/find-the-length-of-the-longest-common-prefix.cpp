class TrieNode {
public: 
    TrieNode* children[10];
    TrieNode() {
        for(int i=0; i<10; i++){
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num){
        TrieNode* node = root;
        string numStr = to_string(num);
        
        for(char ch : numStr){
            int idx = ch - '0';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }
    
    int findlongestPrefix(int num){
        TrieNode* node = root;
        string numStr = to_string(num);
        
        int len = 0;
        for(char ch : numStr){
            int idx = ch - '0';
            if(node->children[idx]){
                len++;
                node = node->children[idx];
            }
            else break;
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int num : arr1){
            trie.insert(num);
        }
        
        int ans = 0;
        for(int num : arr2){
            ans = max(ans, trie.findlongestPrefix(num));
        }
        
        return ans;
    }
};