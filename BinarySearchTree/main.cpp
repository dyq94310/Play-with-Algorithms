#include <iostream>
#include <vector>
#include <ctime>
#include "BST.h"
#include "FileOps.h"
#include "SequenceST.h"
#include "SortTestHelper.h"

int main() {

//    // 使用圣经作为我们的测试用例
//    string filename = "bible.txt";
//    vector<string> words;
//    if (FileOps::readFile(filename, words)) {
//        cout << "There are totally " << words.size() << " words in " << filename << endl;
//        cout << endl;
//    }
//
//    // 测试 BST
//    time_t startTime = clock();
//
//    // 统计圣经中所有词的词频
//    // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
//    // 在这里只做性能测试用
//    BST<string, int> bst = BST<string, int>();
//    for (auto &word : words) {
//        int *res = bst.search(word);
//        if (res == nullptr) {
//            bst.insert(word, 1);
//        } else {
//            (*res)++;
//        }
//    }
//
//    // 输出圣经中god一词出现的频率
//    if (bst.contain("god")) {
//        cout << "'god' : " << *bst.search("god") << endl;
//    } else {
//        cout << "No word 'god' in " << filename << endl;
//    }

    int n = 5;
//    int *arry = SortTestHelper::generateRandomArray(n, 1, n);
    int *arry = new int[5]{3, 1, 5, 4, 2};

    BST<int, int> bst = BST<int, int>();

    for (int i = 0; i < n; ++i) {
        bst.insert(arry[i], i);
    }

    cout << "count:" << bst.size() << endl;
//      bst.preOrder();
//    bst.inOrder();
//    bst.postOrder();
    bst.leverOrder();
    return 0;
}