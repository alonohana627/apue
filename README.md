# APUE in MY style

I learn the book `Advanced Programming in the Unix Environment` by the great W. Richard Stevens.
I learn it in a non-conventional way. What I do different is:

- I do not have `apue.h` as header file.
- Most of what I do is written as standalone library tools, and not as executables.
- There are A LOT of things that are not related, not covered in the book, or just in my personal style (such as safe
  String array [which tbh is not that safe]).
- I use clang.

## Why?

The examples in the book are great, but I like in many cases to make my own expanded version of them. For example, the
basic shell from chapter 1 - my "shell" can get arguments from the user, while the trivial shell from the first chapter
can't.

It helps me to learn it since my examples and approaches is more fit for me.
