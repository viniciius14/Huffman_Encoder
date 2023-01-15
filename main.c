#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>



struct TreeNode{
	struct TreeNode *left; // 0
	struct TreeNode *right; // 1
	char* letters;
};

struct LinkedListNode{
	struct LinkedListNode *next;
	struct LinkedListNode *prev;
	char *letter;
	uint8_t count;
};

void linked_list_append(const char letter_to_add, struct LinkedListNode *list_root){
	struct LinkedListNode *temp = list_root;
	if(list_root->letter == NULL){
		list_root->letter = letter_to_add;
		list_root->count = 1;
		return;
	}
	do{
		if(*temp->letter == letter_to_add){
			temp->count++;
			return;
		}
		if(temp->next == NULL){
			struct LinkedListNode *new = calloc(1, sizeof(struct TreeNode));
			new->next 	= NULL;
			new->prev 	= temp;
			*new->letter = letter_to_add;
			new->count 	= 1;

			temp->next 	= new;
			return;
		}
		temp = temp->next;
	}while(temp != NULL);
}

void swap_contents(struct LinkedListNode *a, struct LinkedListNode *b){
	char *temp = a->letter;
	unsigned char temp2 = a->count;

	*a->letter = *b->letter;
	a->count = b->count;

	*b->letter = *temp;
	b->count = temp2;
}

void linked_list_order(struct LinkedListNode *list_root){
	struct LinkedListNode *min = list_root;
	//find smallest put in first position proceed repeat

	for(struct LinkedListNode *temp1 = list_root ; temp1->next != NULL ; temp1=temp1->next){
		for(struct LinkedListNode *temp2 = temp1 ; temp2 != NULL ; temp2 = temp2->next){
			min = temp2->count < min->count ? temp2 : min;
		}
		swap_contents(min, temp1);
	}
}

void create_tree(){}



const char* huffman_encode(const char *to_encode, struct TreeNode *tree_root){
	
	struct LinkedListNode *linked_list_root = calloc(1, sizeof(struct LinkedListNode));

	for(unsigned char i = 0 ; to_encode[i] != '\0' ; i++){
		linked_list_append(to_encode[i], linked_list_root);
	}

	linked_list_order(linked_list_root);

	create_tree();


	/*
	itirate through every char
		add to linked list

	organize linked list

	iterate through every node
		add to tree
	*/
}
















int main(void){


    struct TreeNode *tree_root = calloc(1, sizeof(struct TreeNode));

    /*
    const char *encoded = huffman_encode(const char*, TreeNode *root);

    print_tree(TreeNode *root);

    const char *original = huffman_decode(const char* encoded, TreeNode *root); 
    */
	
	printf("sizeof struct TreeNode = %zu\n",sizeof(struct TreeNode));
	const char *encoded_text = huffman_encode("bacbccabac", tree_root);
    // printf("return from to encode = %d", );


	
	// TreeNode *root;
	// memset(root, 1, sizeof(TreeNode));
	
	// char *encoded = huffman_encode("string_teste", root);
	
	return 0;




}









