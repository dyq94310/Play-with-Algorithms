//
// Created by dyq94 on 2/6/2019.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H


#include <iostream>

using namespace std;

//二分搜索树
template<typename KEY, typename VALUE>
class BST {
private:

    struct Node {
        KEY key;
        VALUE value;
        Node *left;
        Node *right;

        Node(KEY key, VALUE value) {
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }
    };

    Node *root;
    int count;

    //插入新的节点
    Node *insert(Node *node, KEY key, VALUE value) {

        if (node == nullptr) {
            count++;
            return new Node(key, value);
        }
        //递归
        if (node->key == key) {
            node->value = value;
        } else if (node->key > key) {
            //递归到底的时候 会新增一个新的节点
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }

        return node;
    }


    bool contain(Node *node, KEY key) {
        //递归到底
        if (node == nullptr) {
            return false;
        }
        if (node->key == key) {
            return true;
        }
        return (node->key > key) ? contain(node->left, key) : contain(node->right, key);
    }

    VALUE *search(Node *node, KEY key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->key == key) {
            return &(node->value);
        }
        return node->key > key ? search(node->left, key) : search(node->right, key);
    }


    //前序遍历
    void preOrder(Node *node) {
        if (node != nullptr) {
            cout << node->value << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }


    //中序遍历
    void inOrder(Node *node) {
        if (node != nullptr) {
            preOrder(node->left);
            cout << node->value << endl;
            preOrder(node->right);
        }
    }


    void postOrder(Node *node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->value << endl;
        }
    }

    void destroy(Node *node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
            count--;
        }
    }

public:
    BST() {
        root = nullptr;
        count = 0;
    }

    ~BST() {
        //使用后序遍历来释放Node资源
        destroy(root);
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(KEY key, VALUE value) {
        root = insert(root, key, value);
    }

    bool contain(KEY key) {
        return contain(root, key);
    }

    VALUE *search(KEY key) {
        return search(root, key);
    }

    void preOrder() {
        preOrder(root);
    }

    void inOrder() {
        inOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }

};


#endif //BINARYSEARCHTREE_BST_H
