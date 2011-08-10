#!/bin/bash

echo "Chained ComputeItems..."
./MyApplyObservers -UseTimes=0 ApplyObservers.input
echo
echo "Single ComputeItem..."
./MyApplyObservers -UseTimes=0 ApplyObservers2.input
echo
echo "Diff'ing output:"
diff divQ.dat divQ2.dat
