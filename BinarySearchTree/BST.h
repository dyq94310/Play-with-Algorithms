//
// Created by dyq94 on 2/6/2019.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

#include <iostream>
#include <queue>

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

        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
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
        //递归,如果元素相同则更新
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
        Node *sn = searchNode(node, key);
        return sn == nullptr ? nullptr : &node->value;
    }


    Node *searchNode(Node *node, KEY key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->key == key) {
            return node;
        }
        return node->key > key ? searchNode(node->left, key) : searchNode(node->right, key);
    }

    //前序遍历
    void preOrder(Node *node) {
        if (node != nullptr) {
            cout << node->key << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }


    //中序遍历
    void inOrder(Node *node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->key << endl;
            inOrder(node->right);
        }
    }


    void postOrder(Node *node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << endl;
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

    Node *mininum(Node *node) {
        if (node->left == nullptr) {
            return node;
        }
        mininum(node->left);
    }

    Node *maxinum(Node *node) {
        if (node->right == nullptr) {
            return node;
        }
        maxinum(node->right);
    }


    Node *deleteMin(Node *node) {
        //找到左边最小值
        if (node->left == nullptr) {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = deleteMin(node->left);
        return node;
    }


    Node *deleteMax(Node *node) {
        if (node->right == nullptr) {
            Node *pNode = node->left;
            delete node;
            count--;
            return pNode;
        }
        node->right = deleteMax(node->right);
        return node;
    }

    //删除Key
    Node *deleteValue(Node *node, KEY key) {
        //找到此Key所在的父亲节点
        if (node == nullptr) {
            return nullptr;
        }
        if (node->key > key) {
            node->left = deleteValue(node->left, key);
        } else if (node->key < key) {
            node->right = deleteValue(node->right, key);
        } else {
            //当前节点就为需要删除的节点
            //找右孩子的最小值，替换当前节点
            //如果当前没有右孩子，直接删除就可
            if (node->right == nullptr) {
                Node *leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }

            Node *newNode = new Node(mininum(node->right));
            newNode->right = deleteMin(node->right);
            newNode->left = node->left;

            delete node;

            return newNode;
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

    // 查看二分搜索树中是否存在键key
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

    int size() {
        return count;
    }

    //层级遍历
    void leverOrder() {
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();

            cout << node->key << endl;

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }

    //最小值
    KEY mininum() {
        return mininum(root)->key;
    }

    //最小值
    KEY maxinum() {
        return maxinum(root)->key;
    }

    void deleteMin() {
        deleteMin(root);
    }


    void deleteMax() {
        deleteMax(root);
    }

    void deleteValue(KEY key) {
        root = deleteValue(root, key);
    }

};


#endif //BINARYSEARCHTREE_BST_H
