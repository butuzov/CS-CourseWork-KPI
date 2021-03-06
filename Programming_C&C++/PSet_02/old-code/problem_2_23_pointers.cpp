#include <iostream>
#define N 9

void matrix_fill(int* matrix){
    for ( int row = 0; row < N; row++){
        for ( int col=0, stop=N-row; col < stop; col++ ) {
          *( matrix + row*N + row+col ) = col+1;
        }
        for (int col=0; col < row; col++){
          *( matrix + row*N + col ) = *( matrix + col*N + row );
        }
    }
}

void matrix_print(int* matrix){
  for (int row = 0; row < N; row++){
    for (int col = 0; col < N; col++){
      std::cout
        << *( matrix + row*N + col )
        << (col+1 == N ? "":" ");
    }
    std::cout << std::endl;
  }
}

int main(){

    int *matrix = (int *) calloc( N * N,  sizeof( int ) );

    matrix_fill(matrix);
    matrix_print(matrix);

    return 0;
}
