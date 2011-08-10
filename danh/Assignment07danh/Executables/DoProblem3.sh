#!/bin/bash

for i in 1 2 3; do
    echo -e "\nRunning on $i processor(s)..." | tee -a AvgRadius.dat
    mpirun -np $i ./ApplyObservers -UseTimes 0.0 ApplyObservers.input
done
