# Simple Shell

Simple Shell is a simple UNIX command interpreter, created as a project for Holberton School.

## Usage

```c
./hsh
```

## Examples

Interactive mode:

```c
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

Non-interactive mode:

```c
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Authors
Sang Nguyen and Valerie Nierenberg

## Date
Repository created 11/11/2020
