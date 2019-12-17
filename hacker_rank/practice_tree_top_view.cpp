
#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    // This problem is very poorly described
    void leftView(Node * root) {
      if (root->left!=NULL) {
        leftView(root->left);
      }
      cout << root->data << " ";
    }

    void rightView(Node * root) {
      cout << root->data << " ";
      if (root->right!=NULL) {
        rightView(root->right);
      }
    }

    void topView(Node * root) {
        if (root==NULL) {return;}
        if (root->left!=NULL) {leftView(root->left);}
        cout << root->data << " ";
        if (root->right!=NULL) {rightView(root->right);}
        
        /*
        Node curr = *root;
        // do two while loops, one for left side, one for right side
        while (curr.left!=NULL) {
         curr = *curr.left;
         cout << curr.data << " ";
        }
        curr = *root;
        while (curr.right!=NULL) {
         curr = *curr.right;
         cout << curr.data << " ";
        }
        */
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}
