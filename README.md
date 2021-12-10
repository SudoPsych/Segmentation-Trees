## csc212-final-project
An implmentation of Segment Trees in c++

## Segment Trees

This program algorithmically generates a segement tree using recursion and performs sum queries and alter requests

The `Segment_Tree` class can be instantiated with an input array

`generate` creates a new array within the object that holds data for the completed tree

`sum` returns the sum of values over a given index of the original input array

`alter` changes a value at a given index for the original input array and all parent nodes

`output_to_file` generates a dot file of segement tree

## Usage

Program successfully compiles with

    $g++ -std=c++11 -o prog *.cpp
    $./main data_files/data1.txt

Any given or user created data text file can be compiled for testing

An output file is generated that can be input into a dot visualizer
Nodes are formatted as such
\[index in array] value

Output lines to terminal answer sum queries and validate alter requests

## Input File format

1st line: values for input array

Consecutive Lines:

__FOR SUM QUERY__

First value: 0

Second Value: Lower bound index of input array

Third Value: Upper value index of input array


__FOR ALTER REQUEST__

First Value: 1

Second Value: Index of value to be altered

Third Value: New value

