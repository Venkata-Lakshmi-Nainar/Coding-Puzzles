/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if ( k == 1 && ( root -> left == NULL && root -> right == NULL ) ) {
            return root -> val ;
        }
        int Data = 0 ;
        stack <TreeNode*> S ;
        S.push(root) ;
        TreeNode *R = root -> left ;
        while ( true ) {
            if ( R ) {
                S.push(R) ;
                R = R -> left ;
            }
            else {
                R = S.top() ; S.pop() ;
                k -= 1 ;
                if ( k <= 0 ) {
                    //Data = R -> val ;
                    return R -> val ;
                    break ;
                }
                R = R -> right ;
            }
        }
        //return Data ;
    }
};
