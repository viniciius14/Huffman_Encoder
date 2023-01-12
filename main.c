#include <stdio.h>
#include <string.h>

typedef struct{
	struct TreeNode *left; // 0
	struct TreeNode *right; // 1
	char* letters;
}TreeNode;
// struct size is 12 if on 32 bit machine
//struct size is 20 8 per pointer + 1 (4) for the char
// now its 24?

// take note of every letter and cont its ocurrences

/*
void add_to_tree(char letter, TreeNode *root){
	if(root->letter) 
}


char *huffman_encode(const char *to_encode, TreeNode *root){
	char added_letters[64];
	int added_elems = 0;
	
	for(int i = 0 ; to_encode[i] ; i++){
		int j = 0;
		for( ; j != added_elems ; j++){
			if([added_letters[j] == to_encode[i]]) break;
		}
		added_letters[added_elems + 1] = to_encode[i];
		added_elems++;
		add_to_tree(to_encode[i], root);
	}


}
*/


char *huffman_encode(const char* to_encode, TreeNode *root){
	// count letters
	/*
	make an array of size to_encode
	*/
	size_t string_size = sizeof(to_encode)/sizeof(to_encode[0]);
	// make a 2D array where the first row is letters in int and second one is the number of ocurrences
	
	int letter_counter[string_size][1]; // max size should be 94 because thats the max number of elems in ascii table that we can receive though text
	memset(letter_counter, 0, sizeof(letter_counter));
	
	int added_elems = 0;		
	
  /* Example: 
	________________
	|a|b|e|f|...| | |
    |3|4|2|1|...| | |
	‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
  */
  
	for(int i = 0 ; i != string_size ; i++){
		for(int j = 0 ; j !=  string_size; j++){
			if( letter_counter[j][1] == 0) { // means we tranversed full array and didnt find the letter 
				letter_counter[j][0] = (int)to_encode[i];
				letter_counter[j][1] = 1;
				added_elems++;
				break;
			}
			if(letter_counter[j][1] != 0){ // we found the element
				letter_counter[j][1]++;
				break;
			}
		}
	}
	
	// need to sort array to get this
	/* Example: 
	________________
	|b|a|e|f|...| | |
	|4|3|2|1|...| | |
	‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
	*/
	// lazy and crappy bubble sort
	for(int j = 1 ; j != added_elems ; j++){
		for(int i = 1 ; i!= added_elems ; i++){
			if(letter_counter[i][1] > letter_counter[i - 1][1]){
				int temp_letter = letter_counter[i][0];
				int temp_value = letter_counter[i][1];
				
				letter_counter[i][0] = letter_counter[i - 1][0];
				letter_counter[i][1] = letter_counter[i - 1][1];
				
				letter_counter[i - 1][0] = temp_letter;
				letter_counter[i - 1][1] = temp_value;
			}
		}
	}

	
	
}









int main(void){
	
	printf("sizeof struct TreeNode = %zu",sizeof(TreeNode));
	
	
	TreeNode *root;
	memset(root, 1, sizeof(TreeNode));
	
	char *encoded = huffman_encode("string_teste", root);
	
	return 0;




}









