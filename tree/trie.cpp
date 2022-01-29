/*
前缀树 顾名思义主要用来查找前缀，是一种树形结构，典型应用是用于统计和排序大量的字符串。经常被搜索引擎用于文本词频统计，有点事查询效率比哈希表高，主要思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销

# 前缀树的性质
1. 跟节点不包含字符，除根节点每个节点都代表一个字符
2. 从根节点到某一节点，路径上所以的字符连起来为该节点对应的字符串
3. 对于同一节点的所有根节点，每个根节点代表不同的字符

# 字典树的构建
对于英文，用长度为26的数组代表26个字符，若字符串在当前深度出现该字符，则该字符对应的位置建立子树

*/
#include <vector>
#include <string>
#include <iostream>

class Trie
{
public:
    Trie* characters[26];
    bool isEnd = false;
    Trie()
    {
        memset(characters, 0, sizeof(characters));
    }
    void insert(std::string &word)
    {
        Trie *node = this;
        for (auto &c : word)
        {
            int index = c - 'a';
            if (node->characters[index] == nullptr)
                node->characters[index] = new Trie();
            node = node->characters[index];
        }
        node->isEnd = true;
    }
    bool find(std::string word)
    {
        Trie *node = this;
        for (auto &c : word)
        {
            int index = c - 'a';
            if (node->characters[index] == nullptr)
                return false;
            node = node->characters[index];
        }
        return node->isEnd;
    }
};
int main()
{
    std::cout<<"Start Test Trie"<<std::endl;
    std::vector<std::string> words = {"abcd", "abed", "aef", "eef", "klo"};
    Trie trie;
    for (auto &word : words)
        trie.insert(word);
    assert(trie.find("abcd"));
    assert(!trie.find("abc"));
    assert(trie.find("eef"));
    assert(!trie.find("abe"));
    std::cout<<"End Test Trie"<<std::endl;
}