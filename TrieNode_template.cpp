#include<iostream>
using namespace std;

struct TrieNode {

	TrieNode *letter[26];
	bool wordEnd;
	TrieNode() {
		wordEnd = false;
		for(int index = 0; index < 26; index++) {

			letter[index] = NULL;
		}
	}
};

class Trie {
public:
	TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode *currRoot = root;
        for(int index = 0; index < word.length(); index++) {
            
            char currChar = word[index];
            if(currRoot->letter[currChar - 'a'] != NULL) {
                
                currRoot = currRoot->letter[currChar - 'a'];
            } else {
                
                currRoot->letter[currChar - 'a'] = new TrieNode();
                currRoot = currRoot->letter[currChar - 'a'];
            }
        }
        currRoot->wordEnd = true;
    }
    
    bool search(string word) {
    	TrieNode *currRoot = root;
        for(int index = 0; index < word.length(); index++) {
            
            char currChar = word[index];
            if(currRoot->letter[currChar - 'a'] != NULL) {
                
                currRoot = currRoot->letter[currChar - 'a'];
            } else {
                
                return false;
            }
        }
        return currRoot->wordEnd;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode *currRoot = root;
        for(int index = 0; index < prefix.length(); index++) {
            
            char currChar = prefix[index];
            if(currRoot->letter[currChar - 'a'] != NULL) {
                
                currRoot = currRoot->letter[currChar - 'a'];
            } else {
                
                return false;
            }
        }
        return true;
    }
};

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Trie *trie = new Trie();
    trie->insert("abcd");
    trie->insert("abe");
    trie->insert("abc");
    cout<<trie->startsWith("b")<<"\n";
    cout<<trie->search("abe");

	return 0;
}