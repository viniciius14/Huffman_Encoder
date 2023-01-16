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


void add_tree_parent(struct TreeNode *tree_root, struct LinkedListNode *first, struct LinkedListNode *second){

	struct TreeNode *new_parent = calloc(1, sizeof(struct TreeNode));
	/*
	make new tree node
		aglormerate everything in the double linked list
		remove element in the linked list
	*/
	unsigned char new_tree_count = first->count + second->count;

	char *new_tree_string;
	strcpy(new_tree_string, first->letter);
	strcat(new_tree_string, second->letter);

	new_parent->letters = new_tree_string;
	new_parent->right   = tree_root;



}




void create_tree(struct LinkedListNode *list_root, struct TreeNode *tree_root){
	struct LinkedListNode *pt = list_root;
	while(pt != NULL){
		if(tree_root->letters == NULL){
			tree_root->letters = pt->letter;
		}
		add_tree_parent(tree_root, pt, pt->next);



		pt = pt->next;
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
}
















int main(void){

    struct TreeNode *tree_root = calloc(1, sizeof(struct TreeNode));

	const char *encoded_text = huffman_encode("A_DEAD_DAD_CEDED_A_BAD_BABE_A_BEADED_ABACA_BED", tree_root);





	return 0;
}









