
# HW4 EE599 - Computing Principles for Electrical Engineers

- Please clone the repository, edit [README.md](README.md) to answer the questions, and fill up functions to finish the hw.
- For non-coding questions, you will find **Answer** below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests).
- For submission, please push your answers to Github before the deadline.
- Deadline: Friday, October 9th by 06:30 pm
- Total: 120 points. 100 points is considered full credit.

## Question 1 (20 Points. Easy)

Write several functions in [cpplib.cc](src/lib/cpplib.cc) to satisfy the following requirements:
Do not use any loops but try to with the help of stl algorithm like accumulate, transform and copy_if etc.

- **filter:** Write a function ```vector<int> keepOdd(const vector<int>& input);``` that filters out the numbers that are even and keeps the odd numbers in vector and returns a new vector that contains the result.
- **map:** Write a function ```vector<int> transform(const vector<int>& input);``` that takes a vector of integers as input and outputs a new vector where output[i] = input[i] + 1 if input[i] is odd or output[i] = input[i]-1 if input[i] is even.
- **sum:** Write a function ```int sum(const vector<int>& input);``` that sums up all elements in a vector.

Write several tests using GTest for your function in [tests/q1_student_test.cc](tests/q1_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program.

```shell
bazel test tests:q1_student_test
```

## Question 2 (40 Points. Medium)

In this question, we will write a few recursive functions to *measure* a given binary tree. The definition of ```TreeNode``` could be found in ```cpplib.h```.

- Given a binary tree, find its total number of nodes.
- Given a binary tree, find the sum of numbers from all its nodes.
- Given a binary tree, find its maximum depth. The maximum depth is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.

  Example:
  Input:

  ```
            1
           / \
          2   3
         / \ 
        4   5
             \ 
              6
  ```

  Expected output: 4
- Given a binary tree, find the length of the diameter of the tree. The diameter of a binary tree is defined as the length of the longest path between any two nodes in a tree. This path may or may not pass through the tree root.

  Example - 1:
  Input:

  ```
            1
           / \
          2   3
         / \
        4   5
             \
              6
  ```

  Expected output: 4 (the path is 6-5-2-1-3, and it passes the tree root.)

  Example - 2:
  Input:

  ```
            1
           / \
          2   3
         / \
        4   5
       / \   \
      7   0   6
     /         \
    8           9
  ```

  Expected output: 6 (the path is 8-7-4-2-5-6-9, and it does not pass the tree root.)

  Hint: Unlike previous questions, you may want to write a helper function.

Write several tests using GTest for your function in tests/q2_student_test.cc.

Please create your test cases and run the following command to verify the functionality of your program.

```shell
bazel test tests:q2_student_test
```

## Question 3 (30 Points. Easy)

Please implement the following class for a Binary Search Tree (BST):
Only methods that are marked with “GT” should be tested.

```cpp
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BST
{
private:
      TreeNode *root_;
public:
      BST();

      // Insert elements of initial_values
      // one by one into the Tree
      BST(std::vector<int> initial_values);
      ~BST();

      void push(int key); // **GT** Inserts a key inside Tree
      bool find(int key); // **GT** Returns true if key is in the Tree.
      bool erase(int key); // **GT** Remove the key from the tree. If not successful, return false.
};
```

Write several tests using GTest for your function in [tests/q3_student_test.cc](tests/q3_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program.

```shell
bazel test tests:q3_student_test
```

## Question 4 (30 Points. Medium)

- You are given the definition of Binary Search Tree:
  - The left subtree of a node k contains nodes with key less than the node k's value.
  - The right subtree of a node k contains nodes with key more than the node k's value.
  - Both left subtree and right subtree are also valid BSTs.

If you are given a binary tree, try to determine whether the given binary tree is a valid BST. Write a function `bool CPPLib::isBST(TreeNode* root)`

- We store binary tree using pointers, using `struct TreeNode`
- Try to find inorder traversal solution of BST, what and why does it happen?

Example:

Input:

```
          4
         / \
        2   5
       / \
      1   3
```
Result is true, because it is a valid BST.

Input:

```
nullptr
```

Result is true, as we define 'nullptr' is a valid BST.

Write several tests using GTest for your function in [tests/q4student_test.cc](tests/q4_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program.

```shell
bazel test tests:q4_student_test
```

# Optional Question

## Question 1 (No Points. Medium)

If you are given a valid Binary Search Tree(BST), find the lowest common ancestor of the two given nodes value a and b `int CPPLib::findLCA(TreeNode* root, int val_a, int val_b)`.

- We store binary tree using pointers, using `struct TreeNode`
- Definition of [Lowest Common Ancestor](https://en.wikipedia.org/wiki/Lowest_common_ancestor): "The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
- Notice that value of nodes (instead of nodes), are used to pass parameter into our function.
- The value of nodes `int val_a, int val_b` are **guaranteed** to be found in the Binary Search Tree.
  
Example:

Input:

```
          4
         / \
        2   5
       / \
      1   3
```

LCA of node 1 and node 3 is 2. We expect to return the value of left child of root node, which is 2.

LCA of node 4 and node 1 is 4. We expect to return the value of root, which is 4.
