#include <iostream>
#include <string>

using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) {
        this->name = name;
    }

    string get_name() {
        return this->name;
    }
};

class Node {
private:
    Squirrel* squirrel;
    Node* left_node;
    Node* right_node;

public:
    Node(Squirrel* squirrel) {
        this->squirrel = squirrel;
        this->left_node = nullptr;
        this->right_node = nullptr;
    }

    void set_left(Node* node) {
        this->left_node = node;
    }

    void set_right(Node* node) {
        this->right_node = node;
    }

    Node* left() {
        return this->left_node;
    }

    Node* right() {
        return this->right_node;
    }

    Squirrel* get_squirrel() {
        return this->squirrel;
    }
};

int main() {
    Squirrel rufus = Squirrel("rufus");
    Node node_one = Node(&rufus);

    Squirrel squeaks = Squirrel("squeaks");
    Node node_two = Node(&squeaks);

    Squirrel fluff = Squirrel("fluff");
    Node node_three = Node(&fluff);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    Node* retrieved_node_one = node_one.left();
    Node* retrieved_node_two = node_one.right();

    if (retrieved_node_one) {
        cout << "Left node: " << retrieved_node_one->get_squirrel()->get_name() << endl;
    } else {
        cout << "Left node is null" << endl;
    }

    if (retrieved_node_two) {
        cout << "Right node: " << retrieved_node_two->get_squirrel()->get_name() << endl;
    } else {
        cout << "Right node is null" << endl;
    }

    return 0;
}
