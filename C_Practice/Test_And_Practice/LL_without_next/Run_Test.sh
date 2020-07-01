#!/bin/bash

scons -c
scons
valgrind --leak-check=full ./main