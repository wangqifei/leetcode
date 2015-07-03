/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class BinaryTree{
public:
	TreeNode* BuildBinaryTree(vector<char> BinaryTreeVec) {
		if(BinaryTreeVec.empty() || BinaryTreeVec[0] == '#') return NULL;
		TreeNode* root = new TreeNode(BinaryTreeVec[0]-'0');
		queue<TreeNode*> q;
		q.push(root);
		int i = 1;
		while(q.empty() == false && i < BinaryTreeVec.size()) {
			TreeNode* cur = q.front();
			q.pop();
			if(BinaryTreeVec[i] != '#') {
				TreeNode* node =  new TreeNode(BinaryTreeVec[i]-'0');
				cur->left = node;
				q.push(node);
			}
			i++;
			if(BinaryTreeVec[i] != '#') {
				TreeNode* node =  new TreeNode(BinaryTreeVec[i]-'0');
				cur->right = node;
				q.push(node);
			}
			i++;
		}
		return root;
	}

	void BinaryTreeLevelTraverse(TreeNode* root) {
		if(root == NULL) return;
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		cout<<"binary tree level traversal results:"<<endl;
		while(q.empty() == false) {
			TreeNode* node = q.front();
			q.pop();
			if(node == NULL)
				cout<<endl;
			else 
				cout<<node->val<<" ";
			if(node->left) {
				q.push(node->left);
			}
			if(node->right) {
				q.push(node->right);
			}
		}
	}

	void BinaryTreeLevelTraverseSeq(TreeNode* root) {
		if(root == NULL) return;
		queue<TreeNode*> q;
		q.push(root);
		cout<<"binary tree level traversal sequential results:"<<endl;
		string str;
		while(q.empty() == false) {
			TreeNode* node = q.front();
			q.pop();
			if(node == NULL)
				str += '#';
			else 
				str += node->val+'0';
			if(node != NULL) {
				if(node->left) {
					q.push(node->left);
				}
				else {
					q.push(NULL);
				}
				if(node->right) {
					q.push(node->right);
				}
				else {
					q.push(NULL);
				}
			}
		}
		int ed = str.size()-1;
		while(str[ed] == '#') ed--;
		str = str.substr(0, ed+1);
		cout<<str<<endl;
	}
};
