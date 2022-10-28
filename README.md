# Atividade - MPI - IESB

Youtube
[Sistemas Distribuidos MPI](https://www.youtube.com/watch?v=yqPN9Fb57Ho)

Comandos

```
instalar mpi
sudo apt-get install libmpich-dev

gerar main.e de saida
mpicc main.c -o main.e  => !mpicc 

executar (n -> numero de processos)
mpirun -n 0 main.e

````
Help


error: 
```
The value of the MCA parameter "plm_rsh_agent" was set to a path
that could not be found:

  plm_rsh_agent: ssh : rsh

Please either unset the parameter, or check that the path is correct
```

Adicionando este comando é possível executar: [export OMPI_MCA_plm_rsh_agent=](https://github.com/open-mpi/ompi/issues/7330) <br>
```
export OMPI_MCA_plm_rsh_agent=

```




