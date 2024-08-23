# EncryptionLibraryinC
RC4 Encryption Program
Overview
This repository contains a C program that demonstrates the RC4 stream cipher encryption. The code consists of three main files:

arcfour.c: Implements the core RC4 algorithm, encryption, and decryption functions.
arcfour.h: Header file defining structures and function prototypes.
example.c: A simple example to demonstrate the usage of the RC4 algorithm for encryption and decryption.
Files
1. arcfour.c
This file includes the main RC4 encryption logic:

rc4init(): Initializes the RC4 state with a given key.
rc4byte(): Generates the next pseudo-random byte from the RC4 stream.
rc4encrypt(): Encrypts or decrypts data using RC4. The same function is used for both encryption and decryption since the RC4 cipher is symmetric.
2. arcfour.h
This header file contains:

The Arcfour structure, which holds the state of the RC4 algorithm.
Function prototypes for rc4init, rc4byte, and rc4encrypt.
Several macros including rc4decrypt and rc4unint.
3. example.c
This example demonstrates the use of the RC4 implementation:

It encrypts a string using a specified key.
It then decrypts the string, showing the original message.
Compilation and Execution
