#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree { // структура узла бинарного дерева
    char* word;
    int count;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createNode(char* word) { // для создания нового узла
    struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->word = strdup(word); //копируем строку word в структуру
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Tree* insertNode(struct Tree* root, char* word) { // вставка узла в бинарное дерево
    if (root == NULL) {
        return createNode(word);
    }

    int cmp = strcmp(word, root->word); //сравнение
    if (cmp < 0) { //вставляем в левое поддерево
        root->left = insertNode(root->left, word);
    } else if (cmp > 0) { //аналог для правого
        root->right = insertNode(root->right, word);
    } else { //счетчик
        root->count++;
    }

    return root;
}

void inorder(struct Tree* root) { // в порядке возрастания
    if (root != NULL) {
        inorder(root->left);
        printf("%s: %d\n", root->word, root->count);
        inorder(root->right);
    }
}

void reverse(struct Tree* root) { //в порядке убывания
    if (root != NULL) {
        reverse(root->right);
        printf("%s: %d\n", root->word, root->count);
        reverse(root->left);
    }
}

void freeTree(struct Tree* root) { // освобождение памяти
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root);
    }
}