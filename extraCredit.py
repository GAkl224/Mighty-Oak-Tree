class Squirrel:
    def __init__(self, name):
        self.name = name

    def get_name(self):
        return self.name

class Node:
    def __init__(self, squirrel):
        self.squirrel = squirrel
        self.left_node = None
        self.right_node = None

    def set_left(self, node):
        self.left_node = node

    def set_right(self, node):
        self.right_node = node

    def left(self):
        return self.left_node

    def right(self):
        return self.right_node

    def get_squirrel(self):
        return self.squirrel

if __name__ == "__main__":
    rufus = Squirrel("rufus")
    node_one = Node(rufus)

    squeaks = Squirrel("squeaks")
    node_two = Node(squeaks)

    fluff = Squirrel("fluff")
    node_three = Node(fluff)

    node_one.set_left(node_two)
    node_one.set_right(node_three)

    retrieved_node_one = node_one.left()
    retrieved_node_two = node_one.right()

    if retrieved_node_one:
        print("Left node:", retrieved_node_one.get_squirrel().get_name())
    else:
        print("Left node is None")

    if retrieved_node_two:
        print("Right node:", retrieved_node_two.get_squirrel().get_name())
    else:
        print("Right node is None")
