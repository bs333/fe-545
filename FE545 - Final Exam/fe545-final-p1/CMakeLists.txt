cmake_minimum_required(VERSION 3.21)
project(ch8_tree_trinomial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ch8_tree_trinomial
        Arrays.cpp
        Arrays.h
        BinomialTree.cpp
        BinomialTree.h
        BlackScholesFormulas.cpp
        BlackScholesFormulas.h
        Normals.cpp
        Normals.h
        Parameters.cpp
        Parameters.h
        PayOff3.cpp
        PayOff3.h
        PayOffBridge.cpp
        PayOffBridge.h
        TreeAmerican.cpp
        TreeAmerican.h
        TreeEuropean.cpp
        TreeEuropean.h
        TreeMain1.cpp
        TreeProducts.cpp
        TreeProducts.h
        TrinomialTree.cpp
        TrinomialTree.h)
