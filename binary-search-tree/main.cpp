#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

class Node
{
public:
    Node *left, *right, *parent;
    int key;
    Node(int key) : left(NULL), right(NULL), key(key)
    {
        this->parent = NULL;
    }
};

void insert(Node *N, int key)
{
    if (N->key == key)
        return;
    if (N->key < key)
        if (N->right)
            insert(N->right, key);
        else
        {
            N->right = new Node(key);
            N->right->parent = N;
        }
    else
    if (N->left)
        insert(N->left, key);
    else
    {
        N->left = new Node(key);
        N->left->parent = N;
    }
}

Node* search(Node* N, int key)
{
    if (N == NULL)
        return NULL;
    if (N->key == key)
        return N;
    if (N->key < key)
        return search(N->right, key);
    return search(N->left, key);
}

int height(Node* N)
{
    if (N == NULL)
        return -1;
    else
    {
        int leftNode;
        int rightNode;
        leftNode = height(N->left);
        rightNode = height(N->right);

        if (rightNode > leftNode)
            return(rightNode + 1);
        else return(leftNode + 1);
    }
}

void inOrder(Node* N)
{
    if (N == NULL)
    {
        return;
    }
    inOrder(N->left);
    printf("%d ", N->key);
    inOrder(N->right);
}

void path(Node* N)
{
    if (N->parent == NULL)
    {
        printf("%d\n", N->key);
        return;
    }
    printf("%d ", N->key);
    path(N->parent);
}

void countPath(Node* N)
{
    if (N->parent == NULL)
    {
        printf("%d\n", 1);
        return;
    }
    else
    {
        int temp = 1;
        Node* node = N;
        while (node->parent != NULL)
        {
            temp++;
            node = node->parent;
        }
        printf("%d\n", temp);
    }
}

void sum(Node* N, int &leafSum)
{
    if (N == NULL)
        return;
    if (N->left == NULL && N->right == NULL)
        leafSum += N->key;
    sum(N->left, leafSum);
    sum(N->right, leafSum);
}

void preorder(Node* N)
{
    if (N == NULL)
        return;
    printf("%d ", N->key);
    preorder(N->left);
    preorder(N->right);
}

int max(Node* N)
{
    int max = 0;
    Node* node = N;
    while (node->right != NULL)
    {
        node = node->right;
    }
    max = node->key;
    return max;
}

int main()
{
    char cmd;
    int key;
    Node *root = NULL, *out;

    while (scanf("%c %d", &cmd, &key) > 0)
    {
        if (cmd == 'I')
            if (root != NULL)
                insert(root, key);
            else
                root = new Node(key);
        else if (cmd == 'S')
            out = search(root, key);
        else if (cmd == 'H')
        {
            Node* node = search(root, key);
            int temp = height(node);
            if (temp == -1)
                printf("%c\n", '-');
            else
                printf("%d\n", temp);
        }
        else if (cmd == 'O')
        {
            Node* node = search(root, key);
            if (node == NULL)
                printf("%c\n", '-');
            else
            {
                inOrder(node);
                printf("\n");
            }
        }
        else if (cmd == 'P')
        {
            Node* node = search(root, key);
            if (node == NULL)
                printf("%c\n", '-');
            else
            {
                path(node);
            }
        }
        else if (cmd == 'D')
        {
            Node* node = search(root, key);
            if (node == NULL)
                printf("%c\n", '-');
            else
            {
                countPath(node);
            }
        }
        else if (cmd == 'V')
        {
            Node* node = search(root, key);
            if (node == NULL)
                printf("%c\n", '-');
            else
            {
                int leafSum = 0;
                sum(node, leafSum);
                printf("%d\n", leafSum);
                leafSum = 0;
            }
        }
        else if (cmd == 'E')
        {
            Node* node = search(root, key);
            if (node == NULL)
                printf("%c\n", '-');
            else
            {
                preorder(node);
                printf("\n");
            }
        }
        else if (cmd == 'X')
        {
            Node* node = search(root, key);
            if (node == NULL)
                printf("%c\n", '-');
            else
            {
                printf("%d\n", max(node));
            }
        }
    }
    return 0;
}