#!/usr/bin/bash
echo "[Compiling...]"

if g++ -o main.exe main.cpp; then

echo "[Success :)]";
echo "[Executing...]";
./main.exe;

else

echo "[Failure :(]";

fi