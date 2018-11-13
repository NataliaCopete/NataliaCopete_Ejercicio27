#include <iostream>
#include <stdio.h>
#include "mpi.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]){
    
int rank, size;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
cout<<"Hello world from process"<<rank<<"of"<<size<<endl;  
MPI_Finalize();
    
return 0;   
}

