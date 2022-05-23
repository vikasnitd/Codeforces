#include <iostream>
using namespace std;

struct TreeNode {

	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(NULL), right(NULL){}
	TreeNode(int _val): val(_val), left(NULL), right(NULL){}
	TreeNode(int _val, TreeNode *_left, TreeNode *_right): val(_val), left(_left), right(_right){}
};

class Solution {
public:
	void dfs(TreeNode *root) {

		if(root == NULL) {

			return;
		}
		cout<<root->val<<" ";
		dfs(root->left);
		dfs(root->right);
	}

};

int main() {
  
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

   	TreeNode *level2Left = new TreeNode(5);
   	TreeNode *level2Right = new TreeNode(7);
   	TreeNode *level1Left = new TreeNode(3, level2Left, NULL);
   	TreeNode *level1Right = new TreeNode(4, NULL, level2Right);
   	TreeNode *root = new TreeNode(1, level1Left, level1Right);
   	
   	Solution dfsObj;

   	dfsObj.dfs(root);

    return 0;
}