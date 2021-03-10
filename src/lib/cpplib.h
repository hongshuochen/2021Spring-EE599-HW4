#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>

using namespace std;
/**
 *  Example class used for GTest demo
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CPPLib {
 public:
  //q1
  vector<int> keepOdd(const vector<int>& input);
  vector<int> transform(const vector<int>& input);
  int sum(const vector<int>& input);


  //q2
  int NumberOfNodes(TreeNode* root);
  int SumOfNodes(TreeNode* root);
  int DepthOfTree(TreeNode* root);
  int DiameterOfTree(TreeNode* root);

  //q4
  bool isBST(TreeNode* root);
  //optional
  int findLCA(TreeNode* root, int val_a, int val_b);

  private : 
};

// q3
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

#endif
