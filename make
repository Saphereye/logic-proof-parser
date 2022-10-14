#!/usr/bin/bash
# Compiler flags g++ : https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html

    # (-O0) - Optimization Level 0 (No optimization, default)
    #     Better for debugging builds during development, since it provides faster compile-time.
    # (-O1) - Optimization Level 1
    # (-O2) - Optimization Level 2
    #     Enables (-O1); inline small functions;
    # (-O3) - Optimization Level 3 (Most aggressive optimization, Highest level of optmization and speed)
    #     Problem: Slower compile-time and large binary size.
    #     More function inlining; loop vectorization and SIMD instructions.
    # (-OS) - Code Size Optimization
    #     Enable (-O2), but disable some optimizations flags in order to reduce object-code size.
    # (-Oz) [CLANG-ONLY] - Optimizes for size even further than (-OS)
    # (-Ofast) - Activate (-O3) optimization disregarding strict standard compliance.
    # (-Og) - Optmizing for debugging.
    #     Enables all optimization that does not conflicts with debugging. It can be used with the (-g) flag for enabling debugging symbols.

echo "[Compiling Tests...]"

if g++ -pipe -O0 -Wall -o test.exe test.cpp; then

    echo "[Compilation Successful :)]";
    echo "[Testing...]";
    if ./test.exe; then
	echo "[Tests Succesful :)]"
    else
	echo "[Tests Failed :(]"
    fi

else

    echo "[Compilation Failure :(]";

fi
