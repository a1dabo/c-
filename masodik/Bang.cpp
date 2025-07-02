#include <iostream>
#include <memory>
#include <queue>

template <typename T>
class BinaryTree {
public:
    struct Node {
        T data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

    // Konstruktor: üres fa, megadott szinttel
    BinaryTree(int levels) {
        if (levels > 0) {
            root = std::make_shared<Node>(T());
            buildLeftCompressed(root, levels - 1);
        }
    }

    // Balra tömörített fa építése rekurzívan
private:
    void buildLeftCompressed(std::shared_ptr<Node> node, int remainingLevels) {
        if (remainingLevels <= 0) return;
        node->left = std::make_shared<Node>(T());
        buildLeftCompressed(node->left, remainingLevels - 1);
    }

public:
    // Bejárás: preorder nézet
    void view() const {
        preorder(root);
        std::cout << std::endl;
    }

private:
    void preorder(std::shared_ptr<Node> node) const {
        if (!node) return;
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
};
