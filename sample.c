#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include "mpi.h"
#include<sstream>

using std::cout;
using std::endl;
using namespace std;
const double pi=acos(-1);

double gauss(double x,double mu, double sigma){


return 1/(sqrt(2*pi)*sigma)*exp(-pow(x-mu,2)/(2*sigma*sigma));

}

int main(int argc,char* argv[]){
int rank, size;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
srand(time(0));

int N=atoi(argv[1]);
N=N/size;
double mu=atof(argv[2]);
double sigma=atof(argv[3]);

double fMin=mu-4*sigma;
double fMax=mu+4*sigma;
/*double max=gauss(mu,mu,sigma);*/
