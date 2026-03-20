#include <stdio.h>
#include <stdlib.h>

/* ── Node definition ── */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* ── Create a new node ── */
Node* newNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data  = val;
    n->left  = n->right = NULL;
    return n;
}

/* ── Count leaf nodes recursively ── */
int countLeaves(Node *root) {
    if (root == NULL)
        return 0;                        /* empty tree → 0 leaves     */
    if (root->left == NULL && root->right == NULL)
        return 1;                        /* leaf node found → count 1 */
    return countLeaves(root->left) + countLeaves(root->right);
}

/* ── Build tree from level-order input (-1 = NULL) ── */
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node **q = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0, i = 1;
    Node *root = newNode(arr[0]);
    q[rear++] = root;
    while (front < rear && i < n) {
        Node *curr = q[front++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++]  = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++]   = curr->right;
        }
        i++;
    }
    free(q);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node *root = buildTree(arr, n);
    printf("Leaf node count: %d\n", countLeaves(root));
    return 0;
}