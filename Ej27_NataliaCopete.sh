!/bin/bash
#PBS -l nodes=1:intel:ppn=4, mem=64gb
#PBS -l walltime=00:05:00
#PBS -M n.copete@uniandes.edu.co
#PBS -m abe
#PBS -N ncpexo27
#PBS -j oe

module load anaconda/python3
cd n.copete
cd ej27
make
mpirun -np 4 ./list122.x
mpirun -np 2 ./list123.x
