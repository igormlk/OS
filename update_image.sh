#!/bin/bash

make clean -C src/
make -C src/
cp src/kernel isodir/boot/
grub-mkrescue -o myos.iso isodir

