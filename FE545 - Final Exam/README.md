# Project Compilation Guide

This guide provides instructions on how to compile the project using the GNU Compiler Collection (`g++`).

## Prerequisites

Ensure that you have `g++` installed on your system. You can check this by running the following command in your terminal:

```bash
g++ --version

g++ -std=c++14 -o ProjectExecutable Arrays.cpp BinomialTree.cpp BlackScholesFormulas.cpp Normals.cpp Parameters.cpp PayOff3.cpp PayOffBridge.cpp TreeAmerican.cpp TreeEuropean.cpp TreeMain1.cpp TreeProducts.cpp TrinomialTree.cpp RandomHighTree.cpp RandomLowTree.cpp -I.

./ProjectExecutable