
#include <bits/stdc++.h>

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

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
  Node *lca(Node *root, int v1,int v2) {
		// Starting with the root node, compare v1 and v2 to the node value, see
    // which side they will go on. Keep going if they are on the same side.
    // If they are on different sides, stop there and return that node.
    Node *curr = root;
    while (curr!=NULL) {
      if ((v1 < curr->data)&&(v2 < curr->data)) {curr=curr->left;}
      else if ((v1 > curr->data)&&(v2 > curr->data)) {curr=curr->right;}
      else {return curr;}

    }
    return curr;  
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
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
