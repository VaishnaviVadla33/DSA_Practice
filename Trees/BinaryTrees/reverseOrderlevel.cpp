#include <iostream>
#include <vector>
#include <string>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};

node* newNode(int data) {
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

int height(node* node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
    }
}

void CurrentLevel(node* root, int level, string &result) {
    if (root == NULL)
        return;
    if (level == 1)
        result += to_string(root->data) + " ";
    else if (level > 1) {
        CurrentLevel(root->left, level - 1, result);
        CurrentLevel(root->right, level - 1, result);
    }
}

void LevelOrder(node* root) {
    int h = height(root);
    vector<string> levels;

    for (int i = 1; i <= h; i++) {
        string result;
        CurrentLevel(root, i, result);
        levels.push_back("Level " + to_string(i) + ": " + result);
    }

    // Print levels in reverse order
    for (int i = levels.size() - 1; i >= 0; i--) {
        cout << levels[i] << endl;
    }
}

int main() {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    LevelOrder(root);
    return 0;
}
