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