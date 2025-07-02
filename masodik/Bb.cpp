#include <iostream>
#include <memory>
#include <vector>

template <typename Vec> // például std::vector<T>
class BinaryTree {
public:
    using T = typename Vec::value_type;  // Vektor elemtípusa

    struct Node {
        T data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

    // Konstruktor: vektor alapján épít balra tömörített fát
    BinaryTree(const Vec& values) {
        if (!values.empty()) {
            root = std::make_shared<Node>(values[0]);
            auto current = root;
            for (size_t i = 1; i < values.size(); ++i) {
                current->left = std::make_shared<Node>(values[i]);
                current = current->left;
            }
        }
    }

    // Kiíró nézet: preorder
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
