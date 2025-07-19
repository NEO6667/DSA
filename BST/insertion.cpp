#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node (int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Node* insertIntoBST(Node* root, int d){
//     if(!root){
//         root = new Node(d);
//     }
//     if(d > root->data){
//         root->right = insertIntoBST(root->right, d);
//     }
//     else{
//         root->left = insertIntoBST(root->left, d);
//     }
//     return root;
// }


Node* insertIntoBST(Node* root, int d){
    if(!root){
        return new Node(d);
    }
    if(d > root->data){
        root->right = insertIntoBST(root->right, d); // FIXED
    }
    else{
        root->left = insertIntoBST(root->left, d);   // FIXED
    }
    return root;
}



void takeInput(Node*& root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//helper for delete
Node* findMin(Node* root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int tar){
    if(!root) return nullptr;
    if(root->data < tar){
        root->right = deleteNode(root->right, tar);
    }
    else if(root->data > tar){
        root->left = deleteNode(root->left, tar);
    }
    else{
        //found the node
        if(!root->left && !root->right){
            //0 child case
            delete root;
            return nullptr;
        }
        else if(!root->right){
            // One child case for left child
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left){
            // One Child case for right child
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else{
            // Two Child case
            Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }

    return root;
    
}

int main(){
   Node* root = nullptr;
    cout << "Enter elements of BST (-1 to stop): ";
    takeInput(root);

    cout << "In-order traversal of BST: ";
    inorder(root);
    cout << endl;

    // Deleting a node
    int target;
    cout << "Enter value to delete: ";
    cin >> target;
    root = deleteNode(root, target);

    cout << "In-order after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}