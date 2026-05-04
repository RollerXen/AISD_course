#include <gtest/gtest.h>
#include "binTrees.h"

// ============= ТЕСТЫ СОЗДАНИЯ ОБЪЕКТА =============

TEST(BinTreeTest, CreateEmptyTree) {
    binTree<int> tree;
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(tree.getSize(), 0);
}

TEST(BinTreeTest, CreateTreeAndDestroy) {
    binTree<int>* tree = new binTree<int>();
    EXPECT_TRUE(tree->isEmpty());
    delete tree;  // Проверка деструктора (не должно быть утечек)
}

// ============= ТЕСТЫ ВСТАВКИ =============

TEST(BinTreeTest, InsertSingleElement) {
    binTree<int> tree;
    tree.insert(42);

    EXPECT_FALSE(tree.isEmpty());
    EXPECT_EQ(tree.getSize(), 1);
    EXPECT_TRUE(tree.find(42));
}

TEST(BinTreeTest, InsertMultipleElements) {
    binTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    EXPECT_EQ(tree.getSize(), 5);
    EXPECT_TRUE(tree.find(50));
    EXPECT_TRUE(tree.find(30));
    EXPECT_TRUE(tree.find(70));
    EXPECT_TRUE(tree.find(20));
    EXPECT_TRUE(tree.find(40));
}

TEST(BinTreeTest, InsertDuplicateElement) {
    binTree<int> tree;
    tree.insert(10);
    tree.insert(10);  // дубликат не должен увеличивать размер

    EXPECT_EQ(tree.getSize(), 1);
    EXPECT_TRUE(tree.find(10));
}

TEST(BinTreeTest, InsertNegativeNumbers) {
    binTree<int> tree;
    tree.insert(-5);
    tree.insert(-10);
    tree.insert(-3);

    EXPECT_EQ(tree.getSize(), 3);
    EXPECT_TRUE(tree.find(-5));
    EXPECT_TRUE(tree.find(-10));
    EXPECT_TRUE(tree.find(-3));
}

TEST(BinTreeTest, InsertStringType) {
    binTree<std::string> tree;
    tree.insert("apple");
    tree.insert("banana");
    tree.insert("cherry");

    EXPECT_EQ(tree.getSize(), 3);
    EXPECT_TRUE(tree.find("banana"));
    EXPECT_FALSE(tree.find("grape"));
}

// ============= ТЕСТЫ ПОИСКА =============

TEST(BinTreeTest, FindInEmptyTree) {
    binTree<int> tree;
    EXPECT_FALSE(tree.find(5));
}

TEST(BinTreeTest, FindRoot) {
    binTree<int> tree;
    tree.insert(100);
    EXPECT_TRUE(tree.find(100));
}

TEST(BinTreeTest, FindLeaf) {
    binTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);

    EXPECT_TRUE(tree.find(20));
    EXPECT_TRUE(tree.find(70));
}

TEST(BinTreeTest, FindNonExistent) {
    binTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);

    EXPECT_FALSE(tree.find(99));
    EXPECT_FALSE(tree.find(15));
    EXPECT_FALSE(tree.find(1));
}

// ============= ТЕСТЫ УДАЛЕНИЯ =============

TEST(BinTreeTest, RemoveFromEmptyTree) {
    binTree<int> tree;
    EXPECT_FALSE(tree.remove(5));
    EXPECT_EQ(tree.getSize(), 0);
}

TEST(BinTreeTest, RemoveLeafNode) {
    binTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);  // лист

    EXPECT_TRUE(tree.remove(20));
    EXPECT_FALSE(tree.find(20));
    EXPECT_EQ(tree.getSize(), 3);

    // Проверяем, что остальные элементы на месте
    EXPECT_TRUE(tree.find(50));
    EXPECT_TRUE(tree.find(30));
    EXPECT_TRUE(tree.find(70));
}

TEST(BinTreeTest, RemoveNodeWithOneChildLeft) {
    binTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);  // 30 имеет только левого ребенка

    EXPECT_TRUE(tree.remove(30));
    EXPECT_FALSE(tree.find(30));
    EXPECT_TRUE(tree.find(20));
    EXPECT_EQ(tree.getSize(), 2);
}

TEST(BinTreeTest, RemoveNodeWithOneChildRight) {
    binTree<int> tree;
    tree.insert(50);
    tree.insert(70);
    tree.insert(80);  // 70 имеет только правого ребенка

    EXPECT_TRUE(tree.remove(70));
    EXPECT_FALSE(tree.find(70));
    EXPECT_TRUE(tree.find(80));
    EXPECT_EQ(tree.getSize(), 2);
}

TEST(BinTreeTest, RemoveNodeWithTwoChildren) {
    binTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    EXPECT_TRUE(tree.remove(50));
    EXPECT_FALSE(tree.find(50));
    EXPECT_EQ(tree.getSize(), 6);

    // Проверяем, что дерево всё ещё корректно
    EXPECT_TRUE(tree.find(30));
    EXPECT_TRUE(tree.find(70));
    EXPECT_TRUE(tree.find(20));
    EXPECT_TRUE(tree.find(40));
    EXPECT_TRUE(tree.find(60));
    EXPECT_TRUE(tree.find(80));
}

TEST(BinTreeTest, RemoveRootWhenTreeHasOneNode) {
    binTree<int> tree;
    tree.insert(42);

    EXPECT_TRUE(tree.remove(42));
    EXPECT_FALSE(tree.find(42));
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(tree.getSize(), 0);
}

TEST(BinTreeTest, RemoveNonExistentElement) {
    binTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_FALSE(tree.remove(99));
    EXPECT_EQ(tree.getSize(), 3);
}

TEST(BinTreeTest, RemoveAllElementsSequentially) {
    binTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.remove(5));
    EXPECT_EQ(tree.getSize(), 2);

    EXPECT_TRUE(tree.remove(15));
    EXPECT_EQ(tree.getSize(), 1);

    EXPECT_TRUE(tree.remove(10));
    EXPECT_EQ(tree.getSize(), 0);
    EXPECT_TRUE(tree.isEmpty());
}

// ============= ТЕСТЫ РАЗНЫХ ТИПОВ =============

TEST(BinTreeTest, CharType) {
    binTree<char> tree;
    tree.insert('A');
    tree.insert('C');
    tree.insert('B');

    EXPECT_EQ(tree.getSize(), 3);
    EXPECT_TRUE(tree.find('B'));
    EXPECT_FALSE(tree.find('Z'));
}

TEST(BinTreeTest, DoubleType) {
    binTree<double> tree;
    tree.insert(3.14);
    tree.insert(2.71);
    tree.insert(1.41);

    EXPECT_EQ(tree.getSize(), 3);
    EXPECT_TRUE(tree.find(3.14));
    EXPECT_TRUE(tree.find(2.71));
    EXPECT_FALSE(tree.find(9.99));
}

// ============= ОСНОВНАЯ ФУНКЦИЯ =============

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}