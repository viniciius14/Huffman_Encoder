#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>



typedef struct TreeNode{
	struct TreeNode *left; // 0
	struct TreeNode *right; // 1
	char* letters;
}TreeNode;

typedef struct LinkedListNode{
	struct LinkedListNode *next;
	struct LinkedListNode *prev;
	char letter;
	uint8_t count;
}LinkedListNode;

void linked_list_append(const char letter_to_add, LinkedListNode *list_root){
	LinkedListNode *temp = list_root;
	if(list_root->letter == '\000'){
		list_root->letter = letter_to_add;
		list_root->count = 1;	
		return;	
	}

	for( ; temp->next != NULL ; temp = temp->next){
		if(temp->letter == letter_to_add){
			temp->count++;
			return;
		}
	}

	LinkedListNode *new = calloc(1, sizeof(TreeNode));
	new->next 	= NULL;
	new->prev 	= temp;
	new->letter = letter_to_add;
	new->count 	= 1;

	temp->next 	= new;


}

void swap_contents(LinkedListNode *a, LinkedListNode *b){
	char temp = a->letter;
	unsigned char temp2 = a->count;

	a->letter = b->letter;
	a->count = b->count;

	b->letter = temp;
	b->count = temp2;
}

void linked_list_order(LinkedListNode *list_root){
	LinkedListNode *min = list_root;
	for(LinkedListNode *temp1 = list_root ; temp1->next != NULL ; temp1 = temp1->next){
		for(LinkedListNode *temp2 = temp1 ; temp2 != NULL ; temp2 = temp2->next){
			if(min->count == temp2->count){
				min = min->letter > temp2->letter ? temp2 : min;
				continue;
			}
				
			if(min->count > temp2->count) min = temp2;
		}
		swap_contents(temp1, min);
	}
}





const char* huffman_encode(const char *to_encode, TreeNode *tree_root){
	
	LinkedListNode *linked_list_root = calloc(1, sizeof(LinkedListNode));

	for(unsigned char i = 0 ; to_encode[i] != '\0' ; i++){
		linked_list_append(to_encode[i], linked_list_root);
	}
		
	linked_list_order(linked_list_root);
	
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
	const char *encoded_text = huffman_encode("bacbccabac", tree_root);
    // printf("return from to encode = %d", );


	
	// TreeNode *root;
	// memset(root, 1, sizeof(TreeNode));
	
	// char *encoded = huffman_encode("string_teste", root);
	
	return 0;




}









