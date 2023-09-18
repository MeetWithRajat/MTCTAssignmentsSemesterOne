/*Question1: Take a matrix Mat1[NxN], Where each element is real positive number
    a) Find the rank of the matrix
    b) Transpose of the matrix
    c) Find the largest eigenvalue of the matrix
    d) Determinant of the matrix
    e) Inverse of the matrix
-------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>


// Create a copy of the original array
int ** copy_array(int ** original, int n){
    int **copy = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        copy[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            copy[i][j] = original[i][j];    // Copy the values from the original to the copy
    }
    return copy;
}

/*
// Return the rank of the matrix
int matrix_rank(int **mat, int n){
    int rows, cols, rank;

    def scale_row(matrix, row, factor):
        for i in range(len(matrix[row])):
            matrix[row][i] *= factor

    def add_scaled_row(matrix, source_row, target_row, factor):
        for i in range(len(matrix[target_row])):
            matrix[target_row][i] += factor * matrix[source_row][i]
    

    rows = n;
    cols = n;
    rank = 0;

    for (int col = 0; col < cols; col++){
        // Find the pivot row
        pivot_row = None
        for row in range(rank, rows):
            if mat[row][col] != 0:
                pivot_row = row
                break

        if pivot_row is not None:
            mat[rank], mat[pivot_row] = mat[pivot_row], mat[rank]
            scale_row(mat, rank, 1.0 / mat[rank][col])

            for row in range(rows):
                if row != rank and mat[row][col] != 0:
                    add_scaled_row(mat, rank, row, -mat[row][col])

            rank += 1
    }
    return rank
}
*/

int ** matrix_transpose(int **mat, int n){
    /*this will work only for nxn matrix
    :param mat: square matrix
    :param n: dimension nxn
    :return mat: transpose of mat*/
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    return mat;
}

/*
def matrix_largest_eigenvalue(mat, n, initial_guess=1.0, epsilon=1e-10):
    """
    power iteration method
    :param mat: square matrix
    :param n: dimension nxn
    :param initial_guess: any value we can guess except 0
    :param epsilon: error tolerance -> 1e-10 means the value will be correct up to 9 decimal places
    :return: largest eigenvalue
    """
    eigenvalue = initial_guess
    v = [initial_guess] * n

    while True:
        # Matrix-vector multiplication
        mul = [0] * n
        for i in range(n):
            for j in range(n):
                mul[i] += mat[i][j] * v[j]

        # Normalize the vector & calculate the new eigenvalue
        v = [x / eigenvalue for x in mul]
        new_eigenvalue = max(v)

        # Check if the difference between the new and old eigenvalues is within epsilon
        if abs(new_eigenvalue - eigenvalue) < epsilon:
            break

        eigenvalue = new_eigenvalue
    return eigenvalue


def matrix_determinant(mat, n):
    """
    co-factor expansion method
    :param mat: square matrix
    :param n: dimension nxn
    :return: determinant of mat
    """
    # Base case: for a 1x1 matrix
    if n == 1:
        return mat[0][0]

    # Base case: for a 2x2 matrix
    if n == 2:
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]

    determinant = 0
    # Iterate through the first row and compute the determinant
    for col in range(n):
        sub_matrix = [[mat[i][j] for j in range(n) if j != col] for i in range(1, n)]
        sign = 1 if col % 2 == 0 else -1
        determinant += sign * mat[0][col] * matrix_determinant(sub_matrix, n - 1)
    return determinant


def matrix_inverse(mat, n, det):
    """
    adjugate method
    :param mat: square matrix
    :param n: dimension nxn
    :param det: determinant of mat
    :return: inverse of mat
    """
    inverse = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            sub_matrix = [[mat[x][y] for y in range(n) if y != j] for x in range(n) if x != i]
            cofactor = (-1) ** (i + j) * matrix_determinant(sub_matrix, n - 1)
            inverse[j][i] = cofactor / det
    return inverse

*/


int main(){
    int N;
    char choice;
    // input -------------------------------------------------------------------------------------------
    printf("\nEnter the value of N (Dimension NxN): ");
    scanf("%d", &N);
    printf("Press m for manual input or anything for auto input: ");
    scanf(" %c", &choice);
    
    srand(time(NULL));  // Seed the random number generator with the current time
    
    int **Mat1 = (int **)malloc(N * sizeof(int *)); // Allocate memory for the 2D array
    for (int i = 0; i < N; i++){
        Mat1[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++){
            if (choice == 'm'){
                printf("Enter value for %d,%d: ", i, j);
                scanf("%d", &Mat1[i][j]);
            }
            else
                Mat1[i][j] = rand() % 10;   // Generate a random number within the specified range (0 to 10)            
        }
        
    }

    printf("\nThe matrix is:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%d ", Mat1[i][j]);
        printf("\n");
    }

    // a) rank of the matrix ---------------------------------------------------------------------------
    // int rank_of_Mat1 = matrix_rank(copy_array(Mat1, N), N);
    // printf("\nThe rank of the matrix is: %d", rank_of_Mat1);

    // b) transpose of the matrix ----------------------------------------------------------------------
    printf("\nThe matrix is:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%d ", Mat1[i][j]);
        printf("\n");
    }
    int **transpose_of_Mat1 = matrix_transpose(copy_array(Mat1, N), N);
    printf("\nThe transpose of the matrix is:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf("%d ", transpose_of_Mat1[i][j]);
        printf("\n");
    }
}
        





/*
# c) largest eigen value of the matrix ------------------------------------------------------------
print(f"\nThe matrix is:")
for r in range(N):
    for c in range(N):
        print(Mat1[r][c], end=" ")
    print()

copy_mat = copy.deepcopy(Mat1)
largest_eigen_value_of_Mat1 = matrix_largest_eigenvalue(copy_mat, N)
print(f"\nThe largest eigen value of the matrix is: {largest_eigen_value_of_Mat1}")

# d) determinant of the matrix --------------------------------------------------------------------
print(f"\nThe matrix is:")
for r in range(N):
    for c in range(N):
        print(Mat1[r][c], end=" ")
    print()

copy_mat = copy.deepcopy(Mat1)
determinant_of_Mat1 = matrix_determinant(copy_mat, N)
print(f"\nThe determinant of the matrix is: {determinant_of_Mat1}")

# e) inverse of the matrix ------------------------------------------------------------------------
print(f"\nThe matrix is:")
for r in range(N):
    for c in range(N):
        print(Mat1[r][c], end=" ")
    print()
if determinant_of_Mat1 == 0:
    print("The determinant of this matrix is 0 i.e; it's a singular matrix, therefore inverse is not possible")
else:
    copy_mat = copy.deepcopy(Mat1)
    inverse_of_Mat1 = matrix_inverse(copy_mat, N, determinant_of_Mat1)
    print("\nThe inverse of the matrix is:")
    for r in range(N):
        for c in range(N):
            print(f"{' ' if inverse_of_Mat1[r][c]>0 else ''}{inverse_of_Mat1[r][c]:.2f}", end=" ")
        print()
    return 0;
}
*/