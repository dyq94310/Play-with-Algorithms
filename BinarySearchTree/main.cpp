#include <iostream>
#include <vector>
#include <ctime>
#include "BST.h"
#include "FileOps.h"
#include "SequenceST.h"

int main() {

    // 使用圣经作为我们的测试用例
    string filename = "bible.txt";
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;
    }

    // 测试 BST
    time_t startTime = clock();

    // 统计圣经中所有词的词频
    // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
    // 在这里只做性能测试用
    BST<string, int> bst = BST<string, int>();
    for (auto &word : words) {
        int *res = bst.search(word);
        if (res == nullptr) {
            bst.insert(word, 1);
        } else {
            (*res)++;
        }
    }

    // 输出圣经中god一词出现的频率
    if (bst.contain("god")) {
        cout << "'god' : " << *bst.search("god") << endl;
    } else {
        cout << "No word 'god' in " << filename << endl;
    }
//        time_t endTime = clock();
//
//        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
//        cout << endl;

//
//        // 测试顺序查找表 SST
//        startTime = clock();
//
//        // 统计圣经中所有词的词频
//        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
//        // 在这里只做性能测试用
//        SequenceST<string, int> sst = SequenceST<string, int>();
//        for (auto &word : words) {
//            int *res = sst.search(word);
//            if (res == nullptr)
//                sst.insert(word, 1);
//            else
//                (*res)++;
//        }
//
//        // 输出圣经中god一词出现的频率
//        if (sst.contain("god"))
//            cout << "'god' : " << *sst.search("god") << endl;
//        else
//            cout << "No word 'god' in " << filename << endl;
//
//        endTime = clock();
//
//        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
//

//}

    return 0;
}