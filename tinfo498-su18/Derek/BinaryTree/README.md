# Binary Search Tree (BST)
## Description
Generic tree data structure (C++ template) that can add, remove, search, and enumerate nodes of comparable type.

## Methods
The BST class includes several methods:

### insert()
Takes a value, adds it to appropriate node branch. Returns void.

### remove()
Takes a value, searches for it in the tree and removes it if it exists. Returns true if removed, false if it could not find it.

### contains()
Takes a value, searches for it in the tree and returns true if it finds it. Returns false if it cannot find it.

### enumerate()
Prints out values of nodes in tree (in sort order). Takes no arguments, returns void. Values must be printable (std::cout).

#### [Notes/References](./NodeRemoval.md)