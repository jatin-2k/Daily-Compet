class Solution
{   
    public:
    //Function for finding determinant of matrix.
    
    void getCofactor(int n, vector<vector<int> > &mat, vector<vector<int> > &temp, int p,
                     int q )
    {
        int i = 0, j = 0;
     
        // Looping for each element of the matrix
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                //  Copying into temporary matrix only those
                //  element which are not in given row and
                //  column
                if (row != p && col != q)
                {
                    temp[i][j++] = mat[row][col];
     
                    // Row is filled, so increase row index and
                    // reset col index
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > mat, int n)
    {
        int D = 0; // Initialize result
     
        //  Base case : if matrix contains single element
        if (n == 1)
            return mat[0][0];
     
        vector<vector<int> > temp(n,vector<int>(n)); // To store cofactors
     
        int sign = 1; // To store sign multiplier
     
        // Iterate for each element of first row
        for (int f = 0; f < n; f++)
        {
            // Getting Cofactor of mat[0][f]
            getCofactor(n, mat, temp, 0, f);
            D += sign * mat[0][f]
                 * determinantOfMatrix(temp,n-1);
     
            // terms are to be added with alternate sign
            sign = -sign;
        }
     
        return D;
    }
};