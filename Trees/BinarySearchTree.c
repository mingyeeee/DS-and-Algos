/* Mingye Chen 2021-02-14
 * Binary search tree
 * Features: create tree, insertion, printInorder, delete tree, search, delete node, find min
 */

//https://www.youtube.com/watch?v=gcULXE7ViZw&ab_channel=mycodeschool video for understanding how deletion works
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int key;
    struct Node* left, *right;
}Node;

//use this to make a new node as it initializes newNode->right and left to NULL automatically
Node* createRoot(int key){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = newNode->right = NULL;
    newNode->key = key;
    return newNode;
}

Node* insert(Node* root,int key){
    //check if root is null and if the key is already present in the tree
    if(root == NULL)return createRoot(key);
    if(root->key > key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}
void printInorder(Node* root){
    if (root != NULL) 
    { 
        printInorder(root->left); 
        fputs("key: ", stdout);
        printf("%d\n", root->key); 
        printInorder(root->right); 
    } 
}
//basically a printpreorder but with printf replaced with free()
void deleteTree(Node* root){
    if(root == NULL) return;
	if(root->left!=NULL){
        deleteTree(root->left);
    }
    if(root->right!=NULL){
        deleteTree(root->right);
    }
    fputs("deleting root with key: ",stdout); 
    printf("%d\n", root->key);
    free(root);
}

Node* search(Node* root, int key){
    if(root==NULL) return NULL;
    else if (root->key ==key) return root;
    else if(root->key > key) return search(root->left, key);
    else return search(root->right, key);
}

//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
struct Node* delete(struct Node *root, int key) {
	if(root == NULL) return root;
    /*
    because the return values of delete are assigned to the root->right and left, the function which
    is called before the one which deletes a node can have its children readdress to maintain the tree
    structure.
    */
	else if(key < root->key) root->left = delete(root->left,key);
	else if (key > root->key) root->right = delete(root->right,key);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			free(root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			free(temp);
		}
		// case 3: 2 children
		else { 
            //Findmin finds the replacement node which is copies to the node which has been deleted
			struct Node *temp = FindMin(root->right);
			root->key = temp->key;
			root->right = delete(root->right,temp->key);
		}
	}
    //when the root is returned to the previous delete function, the previous delete function can 
    //rewrite its children nodes, therefore restructuring the tree
	return root;
}
int main(){
    Node* root_ref = createRoot(10);
    insert(root_ref, 20);
    insert(root_ref, 3);
    insert(root_ref, 19);
    insert(root_ref, 100);
    insert(root_ref, 2);
    printInorder(root_ref);
    puts("------deleting node with key: 20-------");
    root_ref = delete(root_ref, 20);
    printInorder(root_ref);
    puts("-------deleting node with key: 2-------");
    root_ref = delete(root_ref, 2);
    printInorder(root_ref);

    int searchKey = 100;
    Node* searchTemp = search(root_ref, searchKey);
    if(searchTemp != NULL){
        fputs("search result: ", stdout);
        printf("%d\n", searchTemp->key);
    }
    else 
        puts("not found");
    printInorder(root_ref);
    deleteTree(root_ref);
    return 0;
}
