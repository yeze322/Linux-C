#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 { /*AC-1, 65ms*/
public:
	vector<vector<int>> vec_result;
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		vector<int> initialVector;
		vec_result.clear();
		onepath(root,sum,initialVector);
		return vec_result;
	}

	void onepath(TreeNode *root, int sum,vector<int>  father) {
		if(root==NULL)	/* because child may be empty, it can be empty */
			return;
		/* judge if reach the leaf */
		if(root->right==NULL&&root->left==NULL){
			if(root->val==sum){
				father.push_back(root->val);
				vec_result.push_back(father);
			}
			return;
		}
		father.push_back(root->val);
		sum-=root->val;
		onepath(root->left,sum,father);
		onepath(root->right,sum,father);
	}
};

class Solution2 { /* use queue, still very sllow */
public:	    
	vector<vector<int>> vec_result;
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		queue<int> history;
		onepath(root,sum,history);
		return vec_result;
	}

	void onepath(TreeNode *root, int sum, queue<int> father) {
		if(root==NULL)	/* because child may be empty, it can be empty */
			return;
		/* judge if reach the leaf */
		if(root->right==NULL&&root->left==NULL){
			if(root->val==sum){
				vector<int> findit;
				while(!father.empty()){
					int value = father.front();
					findit.push_back(value);
					father.pop();
				}
				findit.push_back(sum);
				vec_result.push_back(findit);
			}
			return;
		}
		father.push(root->val);
		sum-=root->val;
		onepath(root->left,sum,father);
		onepath(root->right,sum,father);
	}
};

class Solution { /* reference other one's solution, he pop the vector\
				 if suc, it's copy the vector that costs much time*/
public:
	vector<vector<int>> vec_result;
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		vector<int> initialVector;
		onepath(root,sum,initialVector);
		return vec_result;
	}

	void onepath(TreeNode *root, int sum,vector<int> &father) {
		if(root==NULL)	/* because child may be empty, it can be empty */
			return;
		/* judge if reach the leaf */
		if(root->right==NULL&&root->left==NULL){
			if(root->val==sum){
				father.push_back(root->val);
				vec_result.push_back(father);
				father.pop_back();
			}
			return;
		}
		father.push_back(root->val);
		sum-=root->val;
		onepath(root->left,sum,father);
		onepath(root->right,sum,father);
		father.pop_back();
		return;
	}
};
