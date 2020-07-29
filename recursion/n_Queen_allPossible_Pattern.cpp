
#include<bits/stdc++.h> 
using namespace std; 
bool isSafe(int board[10][10], int row, int col , int n ) 
{ 
	int i, j; 
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	/* Check upper diagonal on left side */
	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 

	/* Check lower diagonal on left side */
	for (i=row, j=col; j>=0 && i<n; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 
bool solveNQUtil(int board[10][10], int col  , int n  , vector<int> &ans) 
{ 
	if (col == n) 
	{ 
		static int k = 1; 
	printf("%d-\n",k++); 
	for (int i = 0; i < n; i++) 
	{ 
		for (int j = 0; j < n; j++) 
			printf(" %d ", board[i][j]); 
		printf("\n"); 
	} 
	printf("\n"); 
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
if(board[i][j] == true){
	ans.push_back(j+1);
}
		}
	}
		return true; 
	} 
	bool res = false; 
	for (int i = 0; i < n; i++) 
	{ 
		if ( isSafe(board, i, col , n ) ) 
		{ 
			board[i][col] = 1; 
			res = solveNQUtil(board, col + 1 , n , ans) || res ; 
			board[i][col] = 0; // BACKTRACK 
		} 
	} 
	return res; 
} 
void solveNQ() 
{ 
	int board[10][10]; 
    int n ;
    cin>>n;
	memset(board, 0, sizeof(board)); 
vector<int> ans ;
	if (solveNQUtil(board, 0 , n , ans) == false) 
	{ 
		printf("Solution does not exist"); 
		return ; 
	} 
	
	return ; 
} 

// driver program to test above function 
int main() 
{ 
	solveNQ(); 
	return 0; 
} 
