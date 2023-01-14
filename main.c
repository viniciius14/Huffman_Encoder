#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>



typedef struct{
	struct TreeNode *left; // 0
	struct TreeNode *right; // 1
	char* letters;
}TreeNode;

typedef struct{
	struct LinkedListNode* next;
	struct LinkedListNode* prev;
	char letter;
	uint8_t count;
}LinkedListNode;

void linked_list_append(const char letter_to_add, LinkedListNode *list_root){
	LinkedListNode *temp = list_root;
	// if(!list_root){
	// 	list_root->next = NULL;
	// 	list_root->prev = NULL;
	// 	list_root->letter = letter_to_add;
	// 	list_root->count = 1;		
	// }

	for( ; temp->next != NULL ; temp = temp->next){
		if(temp->letter == letter_to_add){
			temp->count++;
			return;
		}
	}

	LinkedListNode *new;
	new->next 	= NULL;
	new->prev 	= temp;
	new->letter = letter_to_add;
	new->count 	= 1;

	temp->next 	= new;

}



const char* huffman_encode(const char *to_encode, TreeNode *tree_root){
	
	LinkedListNode *linked_list_root = calloc(1, sizeof(LinkedListNode));

	for(unsigned char i = 0 ; to_encode[i] != '\0' ; i++){
		linked_list_append(to_encode[i], linked_list_root);
	}
		
	
	
	/*
	itirate through every char
		add to linked list

	organize linked list

	iterate through every node
		add to tree
	*/
}
















int main(void){


    TreeNode *tree_root = calloc(1, sizeof(TreeNode));

    /*
    const char *encoded = huffman_encode(const char*, TreeNode *root);

    print_tree(TreeNode *root);

    const char *original = huffman_decode(const char* encoded, TreeNode *root); 
    */
	
	printf("sizeof struct TreeNode = %zu\n",sizeof(TreeNode));
	const char *encoded_text = huffman_encode("acbcaa", tree_root);
    // printf("return from to encode = %d", );


	
	// TreeNode *root;
	// memset(root, 1, sizeof(TreeNode));
	
	// char *encoded = huffman_encode("string_teste", root);
	
	return 0;




}









