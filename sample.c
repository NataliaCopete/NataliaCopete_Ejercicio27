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
for(int i=0; i<size;i++){
int n2=rank;
double* gaussiana=new double[N];
int cont=0;
gaussiana[0]=mu-sigma;

while(cont<N){

double f=(double)rand() / (double)RAND_MAX;
double propuesta=fMin + f * (fMax - fMin);
double F=gauss(propuesta,mu,sigma)/gauss(gaussiana[cont],mu,sigma);
if (F>1){
gaussiana[cont+1]=propuesta;
cont=cont+1;

}

else{
double r=(double)rand() / (double)RAND_MAX;
if(r<F){

gaussiana[cont+1]=propuesta;
cont=cont+1;
}

else{
gaussiana[cont+1]=gaussiana[cont];
cont=cont+1;
}
}
}
char buffer[50];
for (int i=0; i<N;i++){
ofstream (cuenta);
stringstream s1;
sprintf(buffer,"%d",rank);
s1<<buffer;
string s;
s1>>s;
string cadena= "sample"+s+".dat";
cuenta.open(cadena.c_str());
cuenta<<gaussiana[i]<<endl;
cuenta.close();
}
}
MPI_Finalize();
return 0;
}
