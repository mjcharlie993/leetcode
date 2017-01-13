// the binary tree is built with a node type like this... 
struct node {
    int data;
    struct node* left;
    struct node* right;
}

/// Lookup()
/*
  Given a binary tree, return true if a node 
  with the target data is found in the tree, Recurs
  down the tree, chooses the left or right branch
  by comparing the target to each node. 
*/
static int lookup(struct node* node, int target) {
    // 1. Base case == empty tree
    // in that case, the target is not found so return false
    if (node == nullptr) {
        return (false);
    } else {
        // 2. see if found here
        if (target == node->data)
            return (true);
        else {
            // 3. otherwise recur down the correct subtree
            if (target < node->data)
                return (lookup(node->left, target));
            else
                return (lookup(node->right, target));
        }
    }
}

/// newNode()
/*
  Helper function that allocates a new node 
  with the given data and NULL left and right
  pointers. 
*/
struct node* newNode(int data) {
    struct node* node = new(struct node);   // "new" is like "malloc"
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return (node);
}

/// Insett()
/*
  Give a binary search tree and a number, inserts a new code 
  with the given number in the correct place in the tree. 
  Returns the new root pointer which the caller should 
  then use (the standard trick to avoid using reference 
  parameters). 
*/
struct node* insert(struct node* node, int data) {
    // 1. If the tree is empty. return a new single node
    if (node == nullptr) {
        return (newNode(data));
    } else {
        // 2. otherwise, recur down the tree
        if (data <= node->data)
            node->left = insert(node->left, data);
        else 
            node->right = insert(node->right, data);
        return (node);  //return the (unchanged) node pointer
    }
}

/// build123()
// a: by calling newNode() three times, and using three pointer variables
struct node* build123() {
    struct node* root = newNode(2);
    struct node* lChild = newNode(1);
    struct node* rChild = newNode(3);

    root->left = lChild;
    root->right = rChild;

    return (root);
}

// b: by calling newNode() three times, and using only one pointer variables
struct node* build123() {
    struct node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    return (root);
}

// c: by calling insert() three times passing it the root pointer to build up the tree
struct node* build123() {
    struct node* root = nullptr;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);

    return (root);
}

/// size()
// Compute the number of nodes in a tree
int size(struct node* node) {
    if (node == nullptr) {
        return (0);
    } else {
        return (size(node->left) + 1 + size(node->right));
    }
}

/// maxDepth()
/*
  Compute the "maxDepth" of a tree -- the number of nodes along
  the longest path from the root node dowm to the farthest leaf node. 
*/
int maxDepth(struct node* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth)
            return lDepth + 1;
        else
            return rDepth + 1;
    }
}

/// minValue()
/* 
  Given a non-empty binary search tree,
  return the minimum data value found in that tree. 
  Note that the entire tree does not need to be searched. 
*/
int minValue(struct node* node) {
    struct node* current = node;

    // loop down to find the leftmost leaf
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

/// printTree()
/*
  Given a binary search tree, print out
  its data elements in increasing
  sorted order. 
*/
void printTree(struct node* node) {
    if (node == nullptr)
        return;
    printTree(node->left);
    std::cout << node->data << ' ';
    printTree(node->right);
}

/// printPostorder()
/*
  Given a binary tree, print its
  nodes according to the "bottom-up"
  postorder traversal. 
*/
void printPostorder(struct node* node) {
    if (node == nullptr) 
        return;
    
    // first recur on both subtrees
    printPostorder(node->left);
    printPostorder(node->right);

    // then deal with the node
    std::cout << node->data << ' ';
}

/// hasPathSum()
/*
  Given a tree and a sum, return true if there is a path from the root
  down to a leaf, such that adding up all the values along the path 
  equals the given sum. 

  Strategy subtract the node value from the sum when recurring down, 
  and check to see if the sum is 0 when you run out of tree. 
*/
int hasPathSum(struct node* node, int sum) {
    // return true if we run out of tree and sum == 0
    if (node == nullptr) {
        return sum == 0;
    }
    else {
        // otherwise check both subtrees
        int subSum = sum - node->data;
        return hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum);
    }
}

/// printPaths()
/*
  Given a binary tree, print out all of its root-to-leaf
  paths, one per line. Uses a recursive helper to do the work. 
*/
void printPaths(struct node* node) {
    int path[1000];
    printPathsRecur(node, path, 0);
}
/*
  Recursive helper function -- given a node, and an array containing
  the path from the root node up to but not including this node,
  print out all the root-leaf paths. 
*/
void printPathsRecur(struct node* node, int path[], int pathLen) {
    if (node == nullptr) 
        return;
    
    // append this node to path array
    path[pathLen] = node->data;
    pathLen++;

    // it's a leaf, so print the path that led to here
    if (node->left == nullptr && node->right == nullptr) {
        printArray(path, pathLen);
    }
    else {
        // otherwise try both subtree
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}
// Utility that prints out an array on a line. 
void printArray(int ints[], int len) {
    int i;
    for (i = 0; i < len, i++) {
        std::cout << ints[i] << ' ';
    }
    std::cout << std::endl;
}

/// mirror()
/*
  Change a tree so that the roles of the 
  left and right pointers are swapped at every node. 

  So the tree... 
               4
              / \
             2   5
            / \
           1   3
  is changed to... 
               4
              / \
             5   2
                / \ 
               3   1
*/
void mirror(struct node* node) {
    if (node == nullptr) {
        return;
    }
    else {
        struct node* temp;

        // do the subtrees
        mirror(node->left);
        mirror(node->right);

        // swap the pointers int this node
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

/// doubleTree()
/*
  For each node in a binary search tree,
  create a new duplicate node, and insert
  the duplicate as the left child of the original node. 
  The resulting tree should still be a binary search tree. 

  So the tree... 
      2
     / \
    1   3
  is changed to... 
      2
     / \
    2   3
   /   /
  1   3 
 /
1
*/
void doubleTree(struct node* node) {
    struct node* oldLeft;
    if (node == nullptr)
        return;
    
    // do the subtrees
    doubleTree(node->left);
    doubleTree(node->right);

    // duplicate this node to its left
    oldLeft = node->left;
    node->left = newNode(node->data);
    node->left->left = oldLeft;
}

/// sameTree()
/*
  Given two trees, return true if they are
  structurally identical. 
*/
int sameTree(struct node* a, struct node* b) {
    // 1. both empty -> true
    if (a == nullptr && b == nullptr)
        return true;
    
    // 2. both non-empty -> compare them 
    else if (a != nullptr && b != nullptr) {
        return a->data == b->data &&
               sameTree(a->left, b->left) &&
               sameTree(a->right, b->right); 
    }
    // 3. one empty, one not -> false
    else return false;
}

/// countTrees()
/*
  For the key values 1...numKeys, how many structurally uniquePaths
  binary search tree are possible that store those keys. 

  Strategy: consider that each value could be the root. 
  Recursively find the size of the left and right subtrees.
*/
int countTree(int numKeys) {
    if (numKeys <= 1) {
        return 1;
    }
    else {
        // there will be one value at the root, with whatever remains
        // on the left and right each forming their own subtrees. 
        // Iterate through all the values that could be the root... 
        int sum = 0;
        int left, right, root;
        for (root = 1; root <= numKeys; root++) {
            left = countTrees(root - 1);
            right = countTrees(numKeys - root);

            // number of possible trees with this root == left * right;
            sum += left * right;
        }
        return sum;
    }
}

/// isBST1()
/* 
  Return true if a binary tree is a binary search tree. 
*/
int isBST1(struct node* node) {
    if (node == nullptr) 
        return true;
    // false if the max of the left is > than use

    // (bug -- an earlier version had min/max backwards here)
    if (node->right != nullptr && minValue(node->right) <= node->data)
        return false;

    // passing all that, it's a BST
    return true;
}

/// isBST2()
/*
  Returns true if the given tree is a binary search tree
  (efficient version)
*/
int isBST2(struct node* node) {
    return isBSTUtil(node, INT_MIN, INT_MAX);
}
/*
  Returns true if the given tree is a BST and its
  values are >= min and <= max. 
*/
int isBSTUtil(struct node* node, int min, int max) {
    if (node == nullptr) 
        return true;
    
    // false if this node violates the min/max constraint
    if (node->data < min || node->data > max)
        return false;
    
    // otherwise check the subtrees recursively,
    // tightening the min or max constraint
    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data + 1, max);
}