## The UNIX Programming Environment

Code, examples and solutions from "The UNIX Programming Environment" by Kernighan and Pike, 1978, Prentice-Hall. ISBNs: 0-13-937681-X (paperback), 0-13-937699-2 (hardcover). 

https://www.pearson.com/en-us/subject-catalog/p/unix-programming-environment-the/P200000000349/9780139376818

Most of the exercises were run on Ubuntu 20.04 or Devuan 5. Many of the C code examples and excerpts were updated for a more modern style of C: C89/C90/ANSI/ISO. For a more accurate experience of the text, search for access to an older UNIX system more like the authors were familiar with at the time of publishing.

This is for my own learning and practice. You can find other places for the code and higher quality solutions, I'm sure.

After cloning, add the projects bin/ directory to the path. For example:
```
export PATH=$PATH:~/proj/tupe2/bin
```

Shell scripts tested with example code or at least tested with `sh -n <script>`

The Standard C library may have changed a little since this book was published. One of the test systems, Ubunut 20.04, used the following library:
```
$ ldd --version | head -n 1
ldd (Ubuntu GLIBC 2.31-0ubuntu9.16) 2.31
```

