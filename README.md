<!DOCTYPE html>
<html>

<body>

<h1>Multithreaded Password Generator</h1>
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
<p>This project, a part of a Systems Programming course at the FIU Knight Foundation School of Computer & Information Sciences at Florida International University, entails the development of a multithreaded program that generates random passwords formed by sequences of meaningful English words separated by whitespace. The program ensures synchronized access to a global hash table, preventing race conditions and data corruption.</p>

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
    <li><code>hash.h</code> - Header file with the declarations for
