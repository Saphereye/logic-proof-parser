#!/usr/bin/bash
echo "[Compiling Tests...]"

if g++ -pipe -O2 -o test.exe test.cpp; then

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
