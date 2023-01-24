#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>



struct TreeNode{
	struct TreeNode *left; 	// 0
	struct TreeNode *right; // 1
	char            *letters;
	unsigned char 	 count;
};

struct LinkedListNode{
	struct LinkedListNode *next;
	struct LinkedListNode *prev;
	struct TreeNode		  *tree;
	char 				  *letter;
	uint8_t 			   count;
};

void linked_list_append(char letter_to_add, struct LinkedListNode *list_root){
	struct LinkedListNode *temp = list_root;
	if(list_root->letter == NULL){
		list_root->letter = malloc(sizeof(char));
		*list_root->letter = letter_to_add; 
		list_root->count = 1;
		return;
	}
	do{
		if(*(temp->letter) == letter_to_add){
			temp->count++;
			return;
		}
		if(temp->next == NULL){
			struct LinkedListNode *new = calloc(1, sizeof(struct TreeNode));
			new->next 	= NULL;
			new->prev 	= temp;
			new->letter = malloc(sizeof(char));
			*new->letter = letter_to_add;
			new->count 	= 1;

			temp->next 	= new;
			return;
		}
		temp = temp->next;
	}while(temp != NULL);
}

void swap_contents(struct LinkedListNode *a, struct LinkedListNode *b){
	char *letter = a->letter;
	unsigned char count = a->count;

	a->letter = b->letter;
	a->count  = b->count;
	
	b->letter = letter;
	b->count  = count;
}

void linked_list_order(struct LinkedListNode *list_root){
	struct LinkedListNode *min = list_root;

	for(struct LinkedListNode *temp1 = list_root ; temp1 != NULL ; temp1 = temp1->next){
		for(struct LinkedListNode *temp2 = temp1 ; temp2 != NULL ; temp2 = temp2->next){
			if(!min) min = temp2;
			min = temp2->count < min->count ? temp2 : min;
		}

		if(min != temp1)swap_contents(min, temp1);
		min = NULL;
	}
}


struct TreeNode *convert_to_tree(struct LinkedListNode *node){
	struct TreeNode *new = calloc(1, sizeof(struct TreeNode));
	strcpy(new->letters, node->letter);
	return new;
}

void add_tree_parent(struct TreeNode *tree_root, struct LinkedListNode *first, struct LinkedListNode *second){

	struct TreeNode *new_parent = calloc(1, sizeof(struct TreeNode));
	/*
	make new tree node
		aglormerate everything in the double linked list
		remove element in the linked list
	*/
	struct TreeNode *new_left  = convert_to_tree(first);
	struct TreeNode *new_right = convert_to_tree(second);
	
	char *new_tree_string;
	strcpy(new_tree_string, first->letter);
	strcat(new_tree_string, second->letter);

	new_parent->left  	= new_left;
	new_parent->right 	= new_right;
	new_parent->letters = new_tree_string;

	tree_root = new_parent;
}


// struct TreeNode{
// 	struct TreeNode *left; 	// 0
// 	struct TreeNode *right; // 1
// 	char            *letters;
//	
// };

void create_tree(struct LinkedListNode *list_root, struct TreeNode *tree_root){
	struct LinkedListNode *list_pt = list_root;
	
	/*
		if we cant add straight away to the tree
		add to the tree* pointer in the linked list
		means will have to check everytime if tree* is NULL 
	*/
	
	
	while(list_pt != NULL){
		if(tree_root->letters == NULL){
			tree_root->letters = list_pt->letter;
		}
		add_tree_parent(tree_root, list_pt, list_pt->next);



		list_pt = list_pt->next;
	}

		

}



const char* huffman_encode(const char *to_encode, struct TreeNode *tree_root){
	
	struct LinkedListNode *linked_list_root = calloc(1, sizeof(struct LinkedListNode));

	for(unsigned char i = 0 ; to_encode[i] != '\0' ; i++){
		linked_list_append(to_encode[i], linked_list_root);
	}

	// printf("Before sorting\n");
	// for(struct LinkedListNode *temp = linked_list_root ; temp != NULL ; temp = temp->next){
	// 	printf("%s -> %d\n",temp->letter, temp->count);
	// }

	linked_list_order(linked_list_root);

	// printf("\nAfter sorting\n");
	// for(struct LinkedListNode *temp = linked_list_root ; temp != NULL ; temp = temp->next){
	// 	printf("%s -> %d\n",temp->letter, temp->count);
	// }

	create_tree(linked_list_root, tree_root);


	/*
	itirate through every char
		add to linked list
	organize linked list
	iterate through every node
		add to tree
	*/
	return "aaaa";
}
















int main(void){

    struct TreeNode *tree_root = calloc(1, sizeof(struct TreeNode));

	const char *encoded_text = huffman_encode("A_DEAD_DAD_CEDED_A_BAD_BABE_A_BEADED_ABACA_BED", tree_root);





	return 0;
}









