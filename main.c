#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "Extras/quicksort.h"


typedef struct{
	struct TreeNode *left; // 0
	struct TreeNode *right; // 1
	char* letters;
}TreeNode;








int main(void){


    TreeNode *root;
    /*
    const char *encoded = huffman_encode(const char*, TreeNode *root);

    print_tree(TreeNode *root);

    const char *original = huffman_decode(const char* encoded, TreeNode *root); 
    */
	
	printf("sizeof struct TreeNode = %zu\n",sizeof(TreeNode));
	huffman_encode("acbc", root);
    // printf("return from to encode = %d", );


	
	// TreeNode *root;
	// memset(root, 1, sizeof(TreeNode));
	
	// char *encoded = huffman_encode("string_teste", root);
	
	return 0;




}









