#include <iostream>

class Node
{
    public:
        Node(int value) : value(value) { this->left = NULL; this->right = NULL; } 
        ~Node() {}

        int value;
        Node *left;
        Node *right;
};

class BinaryTree
{
    private:
        Node *root;
    public:
        BinaryTree() { this->root = NULL; }
        ~BinaryTree() {}

        Node *Insert(Node *node, int value)
        {
            if (node == NULL)
                return new Node(value);

            if (value <= node->value)
                node->left = Insert(node->left, value);
            else
                node->right = Insert(node->right, value);                
            
            return node;
        }
    
        void Insert(int value)
        {
            this->root = Insert(this->root, value);
        }

        void Inorder(Node *node)
        {
            if (node != NULL)
            {
                Inorder(node->left);
                std::cout << node->value << " ";
                Inorder(node->right);
            }
        }

        void Inorder()
        {
            Inorder(this->root);
            std::cout << std::endl;
        }

        void InorderInverse(Node *node)
        {
            if (node != NULL)
            {
                InorderInverse(node->right);
                std::cout << node->value << " ";
                InorderInverse(node->left);
            }
        }

        void InorderInverse()
        {
            InorderInverse(this->root);
            std::cout << std::endl;
        }

        void Preorder(Node *node)
        {
            if (node != NULL)
            {
                std::cout << node->value << " ";
                Preorder(node->left);
                Preorder(node->right);
            }
        }

        void Preorder()
        {
            Preorder(this->root);
            std::cout << std::endl;
        }

        void Postorder(Node *node)
        {
            if (node != NULL)
            {
                Postorder(node->left);
                Postorder(node->right);
                std::cout << node->value << " ";
            }
        }

        void Postorder()
        {
            Postorder(this->root);
            std::cout << std::endl;
        }
};

int main()
{
    int N, val;
    BinaryTree tree;


    std::cout << "Zadajte pocet prvkov: ";
    std::cin >> N;

    std::cout << "Zadajte prvky: ";
    for (int i = 0; i < N; i++)
    {
        std::cin >> val;
        tree.Insert(val);
    }
    std::cout << std::endl;

    tree.Inorder();
    tree.InorderInverse();
    tree.Preorder();
    tree.Postorder();

    return 0;
}