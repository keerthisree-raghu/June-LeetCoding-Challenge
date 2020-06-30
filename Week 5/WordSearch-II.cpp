// WORD SEARCH II

/*  PROBLEM:
    Given a 2D board and a list of words from the dictionary, find all words in the board.

    Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those 
    horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

    Note:
    All inputs are consist of lowercase letters a-z.
    The values of words are distinct.
*/

/*  EXAMPLES:

    Input: 
    board = [
    ['o','a','a','n'],
    ['e','t','a','e'],
    ['i','h','k','r'],
    ['i','f','l','v']
    ]
    words = ["oath","pea","eat","rain"]

    Output: ["eat","oath"]
*/

/*  APPROACH 1: Depth-First-Search
    1. Identify the unique words from the given list of words using a set.
    2. Iterate through each word in the list.
    3. Check if the word exists on the board.
        a. Iterate through each cell on the board.
        b. Perform DFS from each letter to see if the word can be constructed.
    
    DFS Helper Function:
    1. Mark the letters that have already been visited.
    2. Iteratively check the adjacent nodes to see if a word can be constructed.
    3. If the required word is found, return true. Otherwise, return false and check for other words. 
*/

// SOLUTION 1:
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int row, col;
    // Check if the word exists in the board
    bool wordExists(vector<vector<char>>& board, string word) {
        // There is no board
        if(board.size() == 0) {
            return false;
        }
        row = board.size();
        col = board[0].size();
        // Iterate through every cell on the board
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                // Perform DFS from each letter to see if the word can be constructed
                if(DFS(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    // DFS helper function
    bool DFS(vector<vector<char>>& board, const string& word, int len, int i, int j) {
        // Conditions to check if the current position is out of bounds
        if(i < 0 || j < 0 || i == row || j == col || word[len] != board[i][j]) {
            return false;
        }
        // The word has been found if the length of the word found is the same as the length of the word being searched
        if(len == word.length() - 1) {
            return true;
        }
        // Keep track of each letter that has been visited
        char current_letter = board[i][j];
        board[i][j] = 'X';
        // DFS from each letter
        // Return true if found and false if not found
        bool found_letter = DFS(board, word, len + 1, i + 1, j)
                         || DFS(board, word, len + 1, i - 1, j)
                         || DFS(board, word, len + 1, i, j + 1)
                         || DFS(board, word, len + 1, i, j - 1);
        board[i][j] = current_letter;
        return found_letter;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> words_found;
        // Eliminate any duplicate words in the given list
        unordered_set<string> unique_words(words.begin(), words.end());
        // Iterate through each word in the given word list
        for(auto word : unique_words) {
            // If the word is found, push it into the resultant vector
            if(wordExists(board, word)) {
                words_found.push_back(word);
            }
        }
        return words_found;
    }
};

/*  APPROACH 2: Trie
    1. Build the trie using the constructWord() function.
    2. Iterate through each cell of the board using DFS and search for the letters needed to form a word.
    
    Construct Word Function:
    1. Iterate through each letter of each word in the given list.
    2. If the letter does not exist in the trie already, add it to the appropriate branch of the trie.
    3. Store the letters and words in the trie structure.

    DFS Helper Function:
    1. If the node has already been visited, return.
    2. Recursively check each adjacent cell on the board to see if the letters will form a word from the given list.
    3. Mark the node that has already been visited.
    4. If a word has successfully been constructed, add it to the resultant vector.

*/

// SOLUTION 2:
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // Define the structure of the trie
    struct TrieNode {
        TrieNode* letter[26];
        string word;
    };
    // Build the trie
    TrieNode* constructWord(vector<string>& words) {
        // Initialize the root node of the trie
        TrieNode* root = new TrieNode();
        // Iterate through each word in the list
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            TrieNode *node = root;
            // Iterate through each letter of a word
            for(int j = 0; j < word.size(); j++) {
                char ch = word[j] - 'a';
                // If the letter does not exist already, add it to the trie
                if(node->letter[ch] == nullptr) {
                    node->letter[ch] = new TrieNode();
                }
                // Store the letter in the trie node
                node = node->letter[ch];
            }
            // Store the word in the trie node
            node->word = word;
        }
        return root;
    }
    // Use DFS to search for the word in the board
    void search(vector<vector<char>>& board, TrieNode* node, int i, int j, vector<string>& words_found) {
        // Check if the current position is out of bounds
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }
        char current_letter = board[i][j];
        char ch = current_letter - 'a';
        // Check if the letter has already been visited
        if(current_letter == 'X' || node->letter[ch] == nullptr) {
            return;
        }
        node = node->letter[ch];
        // Add the word found to the resultant array of words
        if(node->word.size() > 0) {
            words_found.push_back(node->word);
            node->word = "";
        }
        // Mark visited nodes
        board[i][j] = 'X';
        // Perform DFS on each letter to check if it forms the given word
        search(board, node, i + 1, j, words_found);
        search(board, node, i, j + 1, words_found);
        search(board, node, i - 1, j, words_found);
        search(board, node, i, j - 1, words_found);
        board[i][j] = current_letter;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> words_found;
        // Build the trie using the given list words
        TrieNode* root = constructWord(words);
        if(board.size() == 0) {
            return words_found;
        }
        // Iterate through each cell of the board and search for the required letters to form a word
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                search(board, root, i, j, words_found);
            }
        }
        return words_found;
    }
};

