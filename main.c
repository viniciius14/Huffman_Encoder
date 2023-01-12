#include <stdio.h>
#include <string.h>
#include <stdint.h>

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


int huffman_encode(const char* to_encode, TreeNode *root){
  // make a 2D array where the first row is letters in __uint8_t and second one is the number of ocurrences
  /* Example: 
	________________
	|a|b|e|f|...| | |
    |3|4|2|1|...| | |
	‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
  */
	size_t string_size = strlen(to_encode);	
	// max size should be 94 because thats the max number of elems in ascii table that we can receive though text
    uint8_t letter_counter[2][string_size - 1]; 
	memset  (letter_counter, 0, sizeof(letter_counter));
	

    // add elements to 2D array
	int added_elems = 0;		
	  
	for(int i = 0 ; i != string_size ; i++){
		for(int j = 0 ; j !=  string_size; j++){
			if(letter_counter[1][j] == 0) { // means we tranversed full array and didnt find the letter 
				letter_counter[0][j] = (uint8_t)to_encode[i];
				letter_counter[1][j] = 1;
				added_elems++;
				break;
			}
			if(letter_counter[0][j] == (uint8_t)to_encode[i] && letter_counter[1][j] != 0){ // we found the element
				letter_counter[1][j]++;
				break;
			}
		}
	}


    for(int i = 0 ; i != added_elems ; i++){
        printf("%c\t%d\n",(char)letter_counter[0][i], letter_counter[1][i]);
    }


	
	// need to sort array to get this
	/* Example: 
	________________
	|b|a|e|f|...| | |
	|4|3|2|1|...| | |
	‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
	*/
	// lazy and crappy bubble sort
// 	for(int j = 1 ; j != added_elems ; j++){
// 		for(int i = 1 ; i!= added_elems ; i++){
// 			if(letter_counter[i][1] > letter_counter[i - 1][1]){
// 				int temp_letter = letter_counter[i][0];
// 				int temp_value = letter_counter[i][1];
				
// 				letter_counter[i][0] = letter_counter[i - 1][0];
// 				letter_counter[i][1] = letter_counter[i - 1][1];
				
// 				letter_counter[i - 1][0] = temp_letter;
// 				letter_counter[i - 1][1] = temp_value;
// 			}
// 		}
// 	}

	
	
}









int main(void){


    TreeNode *root;
    /*
    const char *encoded = huffman_encode(const char*, TreeNode *root);

    print_tree(TreeNode *root);

    const char *original = huffman_decode(const char* encoded, TreeNode *root); 
    */
	
	printf("\nsizeof struct TreeNode = %zu\n",sizeof(TreeNode));
	huffman_encode("acbc", root);
    // printf("return from to encode = %d", );


	
	// TreeNode *root;
	// memset(root, 1, sizeof(TreeNode));
	
	// char *encoded = huffman_encode("string_teste", root);
	
	return 0;




}









