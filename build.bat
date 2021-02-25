@echo off
mkdir debug
cd debug
cmake -G "MinGW Makefiles" ../
make
clear 
.\TDA1.exe
pause
