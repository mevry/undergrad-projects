## Notes

When looking for a successor node and assuming **k** is the node we are interested in:

From C++ Data Structures and Algorithms:
>If k has a right subtree, the successor of k will be the **minimum integer** in the **right subtree** of k.

In other words, does this mean if k has a right subtree, navigate all the way left down that subtree?

>If k does not have a right subtree, we have to *traverse the ancestors of k* until we find the first node, n, which is greater than node k.



>If k is the maximum integer in the BST, there's no successor of k
### Removing a Node

#### Scenario 1:
>**Removing a leaf (a node that doesn't have any child).** In this case, we just need to remove the node. 
#### Scenario 2:
>**Removing a node that has only one child (either a left or right child).** In this case, we have to connect the child to the parent of the node. After that, we can remove the target node safely.

#### Scenario 3:
>**Removing a node that has two children (left and right children).** In this case, we have to find out the successor (or predecessor) of the node's key. After that, we can replace the target node with the successor (or predecessor) node.

Quotes from:

ANGGORO, W. (2018). *C++ DATA STRUCTURES AND ALGORITHMS: Build effective, maintainable and readable code in c++.** S.l.: PACKT PUBLISHING LIMITED.

### From Pluralsight:
#### Scenario 1:
>**Removing a node with no right child**. The current's left replaces current. ***Note:** This could include a null, as in the case of a leaf node w/no children*.

#### Scenario 2:
>**Removing a node with a right child with no left child**. The current's right replaces current.

#### Scenario 3:
>**Removing a node with a right child with a left child**. The current's right left-most child replaces current.

