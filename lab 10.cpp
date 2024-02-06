#include <iostream>

template <class T>
class MyBinaryTree {
private:
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;

        explicit TreeNode(const T& item) : data(item), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    void addTo(TreeNode*& node, const T& item) {
        if (node == nullptr) {
            node = new TreeNode(item);
        } else if (item < node->data) {
            addTo(node->left, item);
        } else {
            addTo(node->right, item);
        }
    }

    void printTree(TreeNode* node, std::ostream& os, int depth = 0) const {
        if (node != nullptr) {
            printTree(node->right, os, depth + 1);
            os << std::string(depth, '\t') << node->data << std::endl;
            printTree(node->left, os, depth + 1);
        }
    }

    void clearTree(TreeNode* node) {
        if (node) {
            clearTree(node->right);
            clearTree(node->left);
            delete node;
        }
    }

public:
    MyBinaryTree() : root(nullptr) {}

    ~MyBinaryTree() {
        clearTree(root);
    }

    void push(const T& item) {
        addTo(root, item);
    }

    friend std::ostream& operator<<(std::ostream& os, const MyBinaryTree& tree) {
        tree.printTree(tree.root, os);
        return os;
    }
};

int main() {
    MyBinaryTree<int> tree1;
    tree1.push(5);
    tree1.push(7);
    tree1.push(3);
    tree1.push(8);
    tree1.push(6);
    tree1.push(4);
    tree1.push(2);

    std::cout << "Your binary tree1:" << std::endl;
    std::cout << tree1 << std::endl;

    MyBinaryTree<double> tree2;
    tree2.push(5.5);
    tree2.push(7.51);
    tree2.push(3.01);
    tree2.push(8.14);
    tree2.push(6.9);
    tree2.push(4.61);
    tree2.push(2.1);

    std::cout << "Your binary tree2:" << std::endl;
    std::cout << tree2 << std::endl;

    MyBinaryTree<std::string> tree3;
    tree3.push("51");
    tree3.push("7");
    tree3.push("36");
    tree3.push("85");
    tree3.push("631");
    tree3.push("40");
    tree3.push("244");

    std::cout << "Your binary tree3:" << std::endl;
    std::cout << tree3 << std::endl;

    return 0;
}
