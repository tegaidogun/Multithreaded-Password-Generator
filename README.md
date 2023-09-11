<!DOCTYPE html>
<html>
<head>
    <title>Synced-Hashset-PasswordGenerator - COP 4338 Programming Assignment 4</title>
</head>
<body>

<h1>Synced-Hashset-PasswordGenerator</h1>
<p>A synchronized multi-threaded C program that generates sequences of meaningful English words as passwords, with controlled access to a shared hash table.</p>

<h2>Table of Contents</h2>
<ol>
    <li>Project Overview</li>
    <li>Installation</li>
    <li>Usage</li>
    <li>File Structure</li>
    <li>Contributing</li>
    <li>License</li>
</ol>

<h2>Project Overview</h2>
<p>This project, a part of the COP 4338 System Programming course at the FIU Knight Foundation School of Computer & Information Sciences, entails the development of a multithreaded program that generates random passwords formed by sequences of meaningful English words separated by whitespace. The program ensures synchronized access to a global hash table, preventing race conditions and data corruption.</p>

<h2>Installation</h2>
<p>To install and set up the project on your local machine, follow these steps:</p>
<ol>
    <li>Clone the repository to your local machine.</li>
    <li>Navigate to the project directory in the terminal.</li>
    <li>Run the command <code>make</code> to compile the program and generate the executable file named "passgenerator".</li>
</ol>

<h2>Usage</h2>
<p>Run the compiled program with the appropriate command-line arguments to specify the number of producer and consumer threads, the dictionary file name, the number of passwords to generate, and the number of words per password. The program will display the generated passwords on the console, one password per line.</p>

<h2>File Structure</h2>
<p>The repository contains the following primary files:</p>
<ul>
    <li><code>dict.txt</code> - The dictionary file with a list of English words used to generate passwords.</li>
    <li><code>hash.h</code> - Header file with the declarations for the hash table data structure.</li>
    <li><code>hashset.c</code> - C source file with the implementation of the hash table data structure.</li>
    <li><code>passwordgen.c</code> - Main C source file with the multithreaded password generator program implementation.</li>
    <li><code>makefile</code> - File organizing the compilation process of the program.</li>
</ul>

<h2>Contributing</h2>
<p>If you would like to contribute to this project, please fork the repository and submit a pull request.</p>

<h2>License</h2>
<p>This project is licensed under the MIT License.</p>

</body>
</html>
