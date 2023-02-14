#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HEIGHT 50

struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
};

struct HuffmanTree {
    unsigned size;
    unsigned capacity;
    struct HuffmanNode **array;
};

struct HuffmanNode *newNode(char data, unsigned freq){
    struct HuffmanNode *temp = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

struct HuffmanTree *createHuffmanTree(unsigned capacity){
    struct HuffmanTree *tree = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));

    tree->size     = 0;
    tree->capacity = capacity;
    tree->array    = (struct HuffmanNode**)malloc(tree->capacity * sizeof(struct HuffmanNode*));

    return tree;
}
void swapNodes(struct HuffmanNode **a, struct HuffmanNode **b){
    struct HuffmanNode *t = *a;

    *a = *b;
    *b = t;
}

void HuffmanTreeify(struct HuffmanTree *tree, int idx){
    int smallest = idx;
    int left  = 2 * idx + 1;
    int right = 2 * idx + 2;

    if(left  < tree->size && tree->array[left]->freq  < tree->array[smallest]->freq){
        smallest = left;
    }

    if(right < tree->size && tree->array[right]->freq < tree->array[smallest]->freq){
        smallest = right;
    }
        
    if(smallest != idx){
        swapNodes( & tree->array[smallest], &tree->array[idx]);
        HuffmanTreeify(tree, smallest);
    }
}

int sizeOne(struct HuffmanTree *tree){
    return (tree->size == 1);
}

struct HuffmanNode *getMin(struct HuffmanTree *tree){
    struct HuffmanNode *temp = tree->array[0];

    tree->array[0] = tree->array[tree->size - 1];
    --tree->size;

    HuffmanTreeify(tree, 0);

    return temp;
}

void insertInTree(struct HuffmanTree *tree, struct HuffmanNode *HuffmanNode){
    ++tree->size;

    int i = tree->size - 1;

    while(i && HuffmanNode->freq < tree->array[(i - 1) / 2]->freq){
        tree->array[i] = tree->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    tree->array[i] = HuffmanNode;
}

void buildTree(struct HuffmanTree *tree){
    int i, n = tree->size - 1;
    
    for(i = (n - 1) / 2; i >= 0; --i){
        HuffmanTreeify(tree, i);
    }
}

void arrPrint(int arr[], int n){
    int i;

    for(i = 0; i < n; ++i){
        printf("%d", arr[i]);
    }

    printf("\n");
}

int leaf(struct HuffmanNode *root){
    return !(root->left) && !(root->right);
}

struct HuffmanTree *HuffmanTreeCreator(char data[], int freq[], int size){
    struct HuffmanTree *tree = createHuffmanTree(size);

    for(int i = 0; i < size; ++i){
        tree->array[i] = newNode(data[i], freq[i]);
    }

    tree->size = size;
    buildTree(tree);

    return tree;
}

struct HuffmanNode *buildHuffmanTree(char data[], int freq[], int size){
    struct HuffmanNode *left, *right, *top;
    struct HuffmanTree *tree = HuffmanTreeCreator(data, freq, size);

    while(!sizeOne(tree)){
        left  = getMin(tree);
        right = getMin(tree);

        top   = newNode('$', left->freq + right->freq);
        top->left  = left;
        top->right = right;
        
        insertInTree(tree, top);
    }
    return getMin(tree);
}

void printLetters(struct HuffmanNode *root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printLetters(root->left, arr, top + 1);
    }

    if(root->right){
        arr[top] = 1;
        printLetters(root->right, arr, top + 1);
    }

    if(leaf(root)){
        printf("%c: ", root->data);
        arrPrint(arr, top);
    }
}

void Huffman(char data[], int freq[], int size){
    int arr[MAX_HEIGHT], top = 0;

    struct HuffmanNode *root = buildHuffmanTree(data, freq, size);

    printLetters(root, arr, top);
}

void convertToFreq(char *phrase, char *arr, int *freq){
    for(int i = 0 ; phrase[i] != '\0' ; i++){
        if(i == 0){
            arr[0]  = phrase[0];
            freq[0] = 1;
            continue;
        }
        for(int x = 0 ; arr[x] != '\0' ; x++){
            if(arr[x] == phrase[i]){
                freq[x] += 1;
                break;
            }
            if(arr[x + 1] == '\0'){
                arr[x + 1]  = phrase[i];
                freq[x + 1] = 1;
            }
        }
    }
}


int main(){
    char *phrase = "A_DEAD_DAD_CEDED_A_BAD_BABE_A_BEADED_ABACA_BED";
    char *arr    = calloc(strlen(phrase) + 1, sizeof(char));
    int  *freq   = calloc(strlen(phrase) + 1, sizeof(char));
    
    convertToFreq(phrase, arr, freq);

    int size = strlen(arr);



    Huffman(arr, freq, size);

    return 0;
}