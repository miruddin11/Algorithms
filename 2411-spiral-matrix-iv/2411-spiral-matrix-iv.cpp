/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int id=0;
        int top=0,down=m-1,left=0,right=n-1;
        while(top<=down&&left<=right)
        {
            if(id==0){
                for(int j=left;j<=right&&head!=NULL;j++){
                    ans[top][j]=head->val;
                    head=head->next;
                }
                top++;
            }
            else if(id==1)
            {
                for(int i=top;i<=down&&head!=NULL;i++){
                    ans[i][right]=head->val;
                    head=head->next;
                }
                right--;
            }
            else if(id==2){
                for(int j=right;j>=left&&head!=NULL;j--)
                {
                    ans[down][j]=head->val;
                    head=head->next;
                }
                down--;
            }
            else{
                for(int i=down;i>=top&&head!=NULL;i--){
                    ans[i][left]=head->val;
                    head=head->next;
                }
                left++;
            }
            id=(id+1)%4;
        }
        return ans;
    }
};