# ft_printf

## Table of contents

* [Introduction](#Introduction)
* [Setup] (#setup)
* Features (#features)

## Introduction
My very own implementation of the printf from the C Standard Library.

## Setup
Build project:
```
$ make
```
Remove object files:
```
$ make clean
```
Remove everything:
```
$ make fclean
```
Remove everything and build again:
```
$ make re
```

*libftprintf.a* is a compiled ft_printf function file.

## Features
Implemented:
- cspdiuxX% conversions
- 0- flags
- Minimal width and precision parsing
- Asterisk precision modifier

```
ft_printf("%*.*d\n", 5,9, 12345567);
ft_printf("%10.2s\n", "test");
ft_printf("%-2.5X %09.21x\n", 123, 124);
```
