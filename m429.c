
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};
 
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void findDepth(struct Node* root, int *depth, int curDepth) {

    if(root->numChildren == 0) {
        *depth = (curDepth > *depth ? curDepth : *depth);
    }
    else {
        for(int i = 0; i < root->numChildren; i++) {
            findDepth(root->children[i], depth, curDepth+1);
        }
    }
}

void findNodeNumEachLevel(struct Node* root, int** returnColumnSizes, int level) {
    if(!root) {
        return;
    }
    else {
        (*returnColumnSizes)[level] ++;
        for(int i = 0; i < root->numChildren; i++) {
            findNodeNumEachLevel(root->children[i], returnColumnSizes, level+1);
        }
    }
}

void levelOderTraverse(struct Node* root, int **ans, int** returnColumnSizes, int level, int **levelCurPos) {
    if(!root) {
        return;
    }
    else {
        ans[level][(*levelCurPos)[level]] = root->val;
        (*levelCurPos)[level]++;
        for(int i = 0; i < root->numChildren; i++) {
            levelOderTraverse(root->children[i], ans, returnColumnSizes, level+1, levelCurPos);
        }
    }
}



int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    
    //***********************************************************************//
    // Deals with the case of empty tree.
    if(!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    //***********************************************************************//
    // Step 1. Get the depth of the tree.
    //         i.e. Obtain the value of returnSize.

    int depth = 0;

    findDepth(root, &depth, 1);

    *returnSize = depth;

    //***********************************************************************//
    // Step 2. Get the number of nodes of each level.
    //         i.e. Decide the value of returnColumnSizes array.

    *returnColumnSizes = malloc(sizeof(int*) * depth);

    for(int i = 0; i < depth; i++) {
        (*returnColumnSizes)[i] = 0;
    }

    findNodeNumEachLevel(root, returnColumnSizes, 0);

    //***********************************************************************//
    // Step 3. Fill in the result 2d array by the correct value.
    //         Traverse the whole tree and fill the number to the correct
    //         position in the result 2d array.

    int **result;

    result = malloc(sizeof(int*) * depth);
    for(int i = 0; i < depth; i++) {
        result[i] = malloc(sizeof(int) * (*returnColumnSizes)[i]);
    }

    int *levelCurPos = malloc(sizeof(int)*depth);
    for(int i = 0; i < depth; i++) {
        levelCurPos[i] = 0;
    }

    levelOderTraverse(root, result, returnColumnSizes, 0, &levelCurPos);

    return result;
}


int main() {

    int *returnColumnSizes;
    int returnSize;

    levelOrder(0, &returnSize, &returnColumnSizes);

    return 0;
}

/*
Runtime: 12 ms, faster than 94.87% of C online submissions for N-ary Tree Level Order Traversal.
Memory Usage: 8.5 MB, less than 100.00% of C online submissions for N-ary Tree Level Order Traversal.
*/


// Note
// The total number of nodes is between [0, 10E4]
// it can be ZERO ...

/*
// Just a test of directly assigning the answer
// [1,null,3,2,4,null,5,6]

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    

    *returnSize = 3;

    *returnColumnSizes = malloc(sizeof(int)*3);

    (*returnColumnSizes)[0] = 1;
    (*returnColumnSizes)[1] = 3;
    (*returnColumnSizes)[2] = 2;

    int **result;

    result = malloc(sizeof(int*) * 3);

    result[0] = malloc(sizeof(int) * 1);
    result[1] = malloc(sizeof(int) * 3);
    result[2] = malloc(sizeof(int) * 2);

    result[0][0] = 1;

    result[1][0] = 3;
    result[1][1] = 2;
    result[1][2] = 4;

    result[2][0] = 5;
    result[2][1] = 6;

    return result;
}*/