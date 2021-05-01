#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int n;


vector<vector<char>> grid;
set<string> foundWords;

/*********************************************/
struct TrieNode {
    unordered_map<char, TrieNode*> mp;
    bool eow;
    TrieNode() {
        eow = false;
    }
};

TrieNode *root = nullptr;

void addWord(string word) {
    TrieNode *current = root;
    for(char ch: word) {
        if(!current->mp[ch]) {
            current->mp[ch] = new TrieNode();
        }
        current = current->mp[ch];
    }
    current->eow = true;
}

bool searchFun(string word, int pos, TrieNode *root) {  
    if(pos == word.size()) {
        if(root->eow == true)
            return true;
        return false;
    }

    if(!root->mp.count(word[pos])) 
        return false;

    return searchFun(word, pos + 1, root->mp[word[pos]]);
}
/*********************************************/

int getIndex(char ch) {
    return ch - 'a';
}

void preProcess() {
    cout << "Preprocessing...";

    root = new TrieNode();

    string word;
    ifstream word_file("corncob_lowercase.txt");
    
    while (word_file >> word) {
        addWord(word);
    }
    
    word_file.close();
    cout << "Done." << endl;
}

bool isSafe(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '*') 
        return false;
    return true;
}

void dfs(int i, int j, string word) {
    if(!isSafe(i, j)) {
        return;
    }

    char temp = grid[i][j];
    word += temp;

    // custom check
    if(foundWords.size() >= 50) return;

    if (searchFun(word, 0, root)) {
        foundWords.insert(word);
    }


    grid[i][j] = '*';

    for (int z = 0; z < 8; z++) {
        dfs(i + dx[z], j + dy[z], word);
    }

    grid[i][j] = temp;
    word.pop_back();
}

int main() {
    preProcess();

    n = 4;
    grid.resize(n, vector<char>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            string temp = "";
            dfs(i, j, temp);
        }
    }

    cout << "foundWords.size() = " << foundWords.size() << endl;
    for(auto i: foundWords) 
        cout << i << endl;

    return 0;
} 