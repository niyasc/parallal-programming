    $ /usr/lib64/openmpi/bin/mpicc master_slave.c
    or
    $ /usr/lib64/openmpi/bin/mpicc master_slave.c -o master_slave

Run the executable with:

    $ /usr/lib64/openmpi/bin/mpirun a.out
    or
    $ /usr/lib64/openmpi/bin/mpirun master_slave
