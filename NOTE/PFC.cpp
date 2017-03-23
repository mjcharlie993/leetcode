/*******************************************************************************************
 * PFC编码使用的数据结构
 ******************************************************************************************/
#include ".../BinTree/BinTree.h"    // 用BinTree实现PFC树
typedef BinTree<char> PFCTree;      // PFC树

#include ".../Vector/Vector.h"      // 用Vector实现PFC森林
typedef Vector<PFCTree*> PFCForest; // PFC森林

#include ".../Bitmap/Bitmap.h"        // 使用位图结构实现二进制编码串
#include ".../Skiplist/Skiplist.h"    // 引入Skiplist式字典结构实现
typedef Skiplist<char, char*> PFCTable; // PFC编码表，词条格式为：（key = 字符， value = 编码串）

#define N_CHAR (0x80 - 0x20)        // 只考虑可打印字符


// PFC编码、解码算法统一测试入口
int main(int argc, char* argv[]) {  // PFC编码、解码算法统一测试入口
    PFCForest* forest = initForest();   // 初始化PFC森林
    PFCTree* tree = generateTree(forest); release(forest);  // 生成PFC编码树
    PFCTable* table = generateTree(tree); // 将PFC编码树转换为编码表
    for (int i = 1; i < argc; i++) {  // 对于命令行传入的每一明文串
        Bitmap codeString;      // 二进制编码串
        int n = encode(table, codeString, argv[i]);     // 将根据编码表生成（长度为n）
        decode(tree, codeString, n);    // 利用编码树，对长度为n的二进制编码串解码（直接输出）
    }
    release(table); release(tree); return 0;    // 释放编码表、编码树
}

// PFC编码森林初始化
PFCForest* initForest() {   // PFC编码森林初始化
    PFCForest* forest = new PFCForest;  // 首先创建空森林，然后
    for (int i = 0; i < N_CHAR; i++) {  // 对每一个可打印字符[0x20, 0x80]
        forest->insert(i, new PFCTree());   // 创建一课对应的PFC编码树，初始时其中
        (*forest)[i]->insertAsRoot(0x20 + i);   // 只包含对应的一个（叶、根）节点
    }
    return forest;  // 返回包含N_CHAR课树的森林，其中每棵树各包含一个字符
}

// 构造PFC树
PFCTree* generateTree(PFCForest* forest) {
    srand ((unsigned int)time(NULL));
    while (1 < forest->size()) {
        PFCTree* s = new PFCTree;
        s->insertAsRoot('^');
        Rank r1 = rand() % forest->size();
        s->attachAsLC(s->root(), (*forest)[r1]);
        forest->remove(r1);
        Rank r2 = rand() % forest->size();
        s->attachAsRC(s->root(), (*forest)[r2]);
        forest->remove(r2);
        forest->insert(forest->size(), s);
    }
    return (*forest)[0];
}