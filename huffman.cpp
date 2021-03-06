#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

//tree struct
typedef struct node_t {
	struct node_t* parent;
	struct node_t* left;
	struct node_t* right;
	int weight;
	string* value;
	string* path;
}node_t;


//linked list struct
typedef struct list_struct {
	struct list_struct* prev;
	struct list_struct* next;
	node_t* data;
}list_struct;

string textTranslater(node_t* root, string i) {
    if(root == NULL) {
        return "";
    }

    if(root->value->compare(i) == 0) {
	    return *root->path;
    }

    string newString;
    newString = textTranslater(root->left, i);

    if( newString != "") {
        return newString;
    }else{
        newString = textTranslater(root->right , i);
        return newString;
    }
}

void charTranslater(node_t** temp){
    if ((*temp)->left == NULL && (*temp)->right == NULL) {
		cout << "\n" << *(*temp)->value << " : " << *(*temp)->path;
		return;
	}
	if ((*temp)->left != NULL) {
		(*(*temp)->left->path) = (*(*temp)->left->parent->path);
		(*temp)->left->path->append("0");

		charTranslater(&(*temp)->left);
	}
	if ((*temp)->right != NULL) {
		(*(*temp)->right->path) = (*(*temp)->right->parent->path);
		(*temp)->right->path->append("1");

		charTranslater(&(*temp)->right);
	}
}

void printHuffman(list_struct* head, char* argv[]) {
	//prints each character before and after encoding
	charTranslater(&head->data);

	//prints the full encoded text
	FILE *fp = fopen(argv[1], "r+");
	cout << "\n\n";

	for(char i ; (i = fgetc(fp)) != EOF ; ) {
        string b(1,i);	//super inefficient
		string encoded = textTranslater(head->data,b); // will return path for the given letter
		cout << encoded;
	}
    fclose(fp);
}

void print_nodes(list_struct* head) {
	list_struct* temp;
	cout << "\n";
	for (temp = head; temp != NULL; temp = temp->next) {
		cout << *temp->data->value << " : " << temp->data->weight << "\n";
	}
	cout << "\n";
	return;
}


list_struct organizer(list_struct** head) {
	list_struct** temp = head, ** temp2 = head;
    node_t* dataTemp;

	//removal of any empty data pointers
	for (; (*temp)->next != NULL; temp = &(*temp)->next) {
		if ((*temp)->data == NULL) {
			if ((*temp)->prev == NULL) {//in case we want to remove head node
				head = &(*temp)->next;
				(*head)->prev = NULL;
			}else {
				*temp2 = (*temp)->next;
				(*temp2)->prev = (*temp)->prev;
				(*temp)->prev = *temp2;
				temp = temp2;
			}
		}
	}
	//organizing list with selection sort
	for (temp = head; (*temp)->next != NULL; temp = &(*temp)->next) {
		for (temp2 = &(*temp)->next; (*temp2) != NULL; temp2 = &(*temp2)->next) {
			if ((*temp)->data->weight > (*temp2)->data->weight) {

                dataTemp = (*temp)->data;
                (*temp)->data = (*temp2)->data;
                (*temp2)->data = dataTemp;
			}
		}
	}
	return **head;
}

void create_tree(list_struct* head) {
	list_struct* temp, * temp2, * new_node;
	node_t* new_parent;
	short int size = 0;

	for (temp = head; temp != NULL; temp = temp->next) {
		size++;
	}

	for (short int i = 0; i != (size - 1); i++) {

		new_node = (list_struct*)malloc(sizeof(list_struct));
		new_parent = (node_t*)malloc(sizeof(node_t));

		if (new_parent == NULL || new_node == NULL){
			cout << "Unable to allocate memory.";
			return;
		}

		//node standardization
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->data = new_parent;
		new_node->data->path = new string();

		//join 1st 2 elements in linked list
		temp = head;
        temp2 = temp->next;

		if (temp != NULL && temp2 != NULL){
			new_parent->parent = NULL;

			new_parent->left = temp->data;
			new_parent->left->path = new string();

			new_parent->right = temp2->data;
			new_parent->right->path = new string();

			new_parent->weight = temp->data->weight + temp2->data->weight;
			new_parent->path = new string();

			temp->data->parent = new_parent;
			temp2->data->parent = new_parent;

			new_parent->value = new string(*temp->data->value);
			*new_parent->value += *temp2->data->value;

			//add new tree node at the end of linked list
			for (temp = head; ; temp = temp->next) {
				if (temp->next == NULL) {
					new_node->prev = temp;
					temp->next = new_node;
					new_node->next = NULL;
					new_node->data = new_parent;
					break;
				}
			}

			head->data = NULL;
			head->next->data = NULL;
			*head = organizer(&head);
            //remove this comment to see all the tree iterations and their corresponding weights
            //print_nodes(head);
		}
	}
	return;
}

list_struct* linked_list(int argc, char* argv[]) {
	list_struct* head, * new_node,* lastNode;
	node_t* tree_node;
	char i;
	FILE* fp = fopen(argv[1], "r+");

	if (argc != 2) {
		cout << "You called too many or too few arguments.";
		return NULL;
	}
	if (!fp) {
		cout << "Something went wrong while trying to open your file.";
		return NULL;
	}

	for (short int j = 0; (i = fgetc(fp)) != EOF; j++) {
		short int added = 0;
		if (j == 0) {//create head node
			head = (list_struct*)malloc(sizeof(list_struct));
			tree_node = (node_t*)malloc(sizeof(node_t));

			if (head == NULL) {
				cout << "Unable to allocate memory.";
				return NULL;
			}

			//node standardization
			head->prev = NULL;
			head->next = NULL;
			head->data = tree_node;

			head->data->left = NULL;
			head->data->right = NULL;
			head->data->parent = NULL;
			head->data->weight = 1;
			head->data->value = new string(1, i);
			lastNode = head;
			continue;
		}
		if (head != NULL)
			for (list_struct* it = head; it != NULL; it = it->next) {//cicle trough list to see if letter was already added
				string b(1, i);

				if (b.compare(it->data->value[0]) == 0) {
					it->data->weight += 1;
					added = 1;
					break;
				}
			}
		if (added == 0) {//in case the letter hasn't already been added
			new_node = (list_struct*)malloc(sizeof(list_struct));
			tree_node = (node_t*)malloc(sizeof(node_t));

			if (new_node == NULL || tree_node == NULL) {
				cout << "Unable to allocate memory.";
				return NULL;
			}

			//node standardization
			new_node->next = NULL;
			new_node->prev = lastNode;
			new_node->data = tree_node;

			new_node->data->left = NULL;
			new_node->data->right = NULL;
			new_node->data->parent = NULL;
			new_node->data->weight = 1;
			new_node->data->value = new string(1, i);
			lastNode->next = new_node;

			lastNode = new_node;
		}
	}

	//we will use the file again for the last function in the program so we wont close the it just yet
	return head;
}

int main(int argc, char* argv[]){
	//create a linked list with all the text's characters and their respective weights
	list_struct* connector = linked_list(argc, argv);

    if(connector != NULL){
        //remove print_nodes comment's to see the list changing troughout the program
        //print_nodes(connector);

        //organize our list from the least ocurring letter to the most and removes all empty data pointers
        organizer(&connector);

        //print_nodes(connector);

        //creates the full binary tree
        create_tree(connector);

        //print_nodes(connector);

        //print the binary value of each character and the original text encoded
        printHuffman(connector, argv);
    }
	return 0;
}