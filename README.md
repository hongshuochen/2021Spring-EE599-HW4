
# HW4 EE599 - Computing Principles for Electrical Engineers

- Please clone the repository, edit [README.md](README.md) to answer the questions, and fill up functions to finish the hw.
- For non-coding questions, you will find **Answer** below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests).
- For submission, please push your answers to Github before the deadline.
- Deadline: Monday, March 22nd by 06:30 pm
- Total: 130 points. 100 points is considered full credit.

## Question 1 (10 Points. Easy)

Implement following functions in [cpplib.cc](src/lib/cpplib.cc).
Do not use any loops but try to with the help of STL functions like **accumulate**, **transform** and **copy_if** etc.

- **Filter:** Write a function ```vector<int> keepOdd(const vector<int>& input);``` that filters out the numbers that are even and keeps the odd numbers in vector and returns a new vector that contains the result.
- **Map:** Write a function ```vector<int> transform(const vector<int>& input);``` that takes a vector of integers as input and outputs a new vector where output[i] = input[i] + 1 if input[i] is odd or output[i] = input[i]-1 if input[i] is even.
- **Sum:** Write a function ```int sum(const vector<int>& input);``` that sums up all elements in a vector.

Write several tests using GTest for your function in [tests/q1_student_test.cc](tests/q1_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program.

```shell
bazel test tests:q1_student_test
```

## Question 2 (30 Points. Medium)

In this question, we will write a few recursive functions on a given binary tree. The definition of ```TreeNode``` could be found in ```cpplib.h```.

- Given a binary tree, find its total number of nodes.
- Given a binary tree of integers, find the sum of numbers from all of its nodes.
- Given a binary tree, find its maximum depth. 
  - The maximum depth is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.

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
- Given a binary tree, find the length of the diameter of the tree. The diameter of a binary tree is defined as the number of nodes on the longest path between any two nodes in a tree. This path may or may not pass through the tree root.

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

  Expected output: 5 (the nodes on the longest path are 6-5-2-1-3, and it passes the tree root.)

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

  Expected output: 7 (the nodes on the longest path are 8-7-4-2-5-6-9, and it does not pass the tree root.)

  Hint: 
  You can write a recursive function that calculates the diameter based on the following observation:

  The diameter of a binary tree T is the largest of the following quantities:

  - the diameter of T’s left subtree.
  - the diameter of T’s right subtree.
  - The height of the left subtree + the height of the right subtree + 1. This is the longest path between leaves that goes through the root of T.


Write several tests using GTest for your function in tests/q2_student_test.cc.

Please create your test cases and run the following command to verify the functionality of your program.

```shell
bazel test tests:q2_student_test
```

## Question 3 (30 Points. Medium)

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
      bool find(int key); // **GT** Returns true if the key is in the Tree.
      bool erase(int key); // **GT** Removes the key from the tree. If not successful, returns false.
};
```

Write several tests using GTest for your function in [tests/q3_student_test.cc](tests/q3_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program.

```shell
bazel test tests:q3_student_test
```

## Question 4 (20 Points. Medium)

- You are given the definition of a Binary Search Tree:
  - The left subtree of a node k contains nodes with keys less than the node k's value.
  - The right subtree of a node k contains nodes with keys greater than the node k's value.
  - Both left subtree and right subtree are also valid BSTs.

If you are given a binary tree, try to determine whether the given binary tree is a valid BST. Write a function `bool CPPLib::isBST(TreeNode* root)`

- We store binary tree using pointers, using `struct TreeNode`
- Assume there are no duplicate values in the BST.

Hint: You can use either of the following solutions:

- Use the recursive definition above and write a recursive function based on that.
- Try to find an inorder traversal of a BST. What is so special about this traversal? 
  How can you use it to see if the tree was BST or not

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

Result is true, as we define 'nullptr' as a valid BST.

Write several tests using GTest for your function in [tests/q4student_test.cc](tests/q4_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program.

```shell
bazel test tests:q4_student_test
```

## Question 5 (30 Points. Medium)

Please implement the following class for MaxHeap:
- Provide Gtest for methods that are marked with "GT".
```c++
class MaxHeap {
 public:
  MaxHeap(); // default constructor

  int getParentIndex(int i); //GT
  int getLeftIndex(int i); //GT
  int getRightIndex(int i); //GT
  int getLargestChildIndex(int i); //GT

  int getLeft(int i);
  int getRight(int i);
  int getParent(int i);

  int top(); //GT
  void push(int v); //GT
  void pop(); //GT
  void TrickleUp(int i);
  void TrickleDown(int i);

  vector<int> data_;
};
```

Write several tests using GTest for your function in [tests/q1_student_test.cc](tests/q1_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program.
```
bazel test tests:q1_student_test
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
