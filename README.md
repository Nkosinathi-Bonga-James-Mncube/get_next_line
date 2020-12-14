# get_next_line
# What is GNL?


![wtc](https://user-images.githubusercontent.com/50704452/101298456-b6ba8a80-3836-11eb-8d68-e8e74b8897f5.gif) ![42](https://user-images.githubusercontent.com/50704452/101329754-77159200-387a-11eb-8c1a-c929b9050800.png)
- `get_next_line`(GNL) is a program that is able to read from a textfile and display each line ending with a newline character. This this project done with only using `read()`, `malloc()`,`free()` and our own library [libft](https://github.com/Nkosinathi-Bonga-James-Mncube/libft) we build previously.
- Project done at WeThinkCode JHB campus (based on 42 france coding curriculum)
***
- More info on WeThinkCode: https://www.wethinkcode.co.za/
- More info on 42 school(US based school English site): https://www.42.us.org/
- More info on 42 school(France based school French site): https://www.42.fr/
***
# Table of contents
<!-- TOC -->
  1. [Requirements of the project](#requirements-of-the-project)
  2. [How it works](#how-it-works)
  3. [Installation](#installation)
  4. [How to run GNL](#how-to-run-get_next_line)
  
 <!-- /TOC -->
 ***
# Language used
![c_programming2](https://user-images.githubusercontent.com/50704452/101298658-bff82700-3837-11eb-82ea-529432360815.jpg)
- C

 
 # Requirements of the project:
 - Create a function that returns a line read from a file descriptor
 - The following prototype must be used:
 ```C
 int get_next_line(const int fd, char **line);
 ```
 fd = file descriptor used | line = the pointer used to store line read
 - Your function `get_next_line()` must return its result without `\n`
 - To get a full project detailed outline, please refer to the [pdf](https://drive.google.com/file/d/14zgjjrF6lV5T90iCVkL3s2zNRqKDXAoM/view?usp=sharing)
 ***
 # How it works
 The main goal of the project is to replicate the function [fgets()](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm) to read a line from a texfile similar to the  example code. 
```C
//EXAMPLE CODE
int main(int argc,char **argv)
{
        FILE * x;
        x=fopen("myfile.txt","r");
        char hold[256]; // Step 2
        while(fgets(hold,sizeof(hold),x) != NULL) // Step 1 +2
        {
                printf("%s",hold); // Step 3
        }
        fclose(x);
        return (0);
}
```


 `fgets()` is function that reads a line from a stream (e.g the `mytextfile.txt` in this case) at "x" number of characters at a time (i.e size of string or `BUFF_SIZE`).On success, the function returns a line which is indentified by the `\n` representing end of a line.The line is stored in a variable with a allocated size(i.e `hold` with length of 256).When it reaches the 'End of File(EOF)' indicated by `\0` it simply returns `NULL`.
 ```C
 char *fgets(char *str, int n, FILE *stream)
 ```
***
 #### How to create fget()
To replicate `fget()` GNL is broken down into the following steps: 

Step1. In `main.py`, the called function `get_next_line()` is used read each line until EOF which returns a value of -1
  ```C
  while ((x = get_next_line(fd, &line2)) > 0)
  ```
Step2. In `get_next_line.c` the function `get_next_line()` copies characters from file descriptor into a pointer called `temp`according to `BUFF_SIZE` found in `get_next_line.h`
Here is an example for how it would work :

1. If the `BUFF_SIZE = 3`

```
    line = "Hi\nMy name is Nathi"
    s1=[H][i][\n](first loop)
```
   - If no nextline character is found, the function `get_next_line()` keeps reading new characters and concatenates them with `temp`
   - If the nextline character is found the function `ft_cpy()`is used to create a new temp variable without the `\n` and returned to `ft_leftover`.   
   - `ft_leftover()` is used to create new pointer,allocate memory for pointer and return pointer without nextline.
   - Lastly, the final line 'Hi' is returned in `line2`.

Step3. In `main.py` `get_next_line()` returns `line2` to display all lines in textfile with `\n` added at the end
```C
while ((x = get_next_line(fd, &line2)) > 0)
{
	ft_putstr(line2); // function from libft to display string to standard output
	ft_putchar('\n'); // function from libft to display char to standard output
	free(line2);
}
```
***
# Installation
![gnl_1](https://user-images.githubusercontent.com/50704452/102021685-24f8d300-3d8a-11eb-91d5-93d0cc1fd42e.gif)
 1. `git clone` repo
 2. Enter `/get_next_line` folder
 3. `git clone` [libft](https://github.com/Nkosinathi-Bonga-James-Mncube/libft)
 4. Enter `/libft` folder
 5. To compile `Makefile` of `libft` type:
 ```C
 make re
 ```
 6. Go back to  `/get_next_line` folder
 7. To compile `Makefile` of `get_next_line` type:
 ```C
 make all
 ```
 ***
 # How to run get_next_line
 ![gnl_2](https://user-images.githubusercontent.com/50704452/102021697-3b069380-3d8a-11eb-99cc-d6cb9265c98d.gif)
 1. To execute file type:
 ```C
 ./run.a mytext.txt
 ```
 You should see 
 ```
 aaa
 bbb
 ccc
 ```
 displayed to standard output from `myfile.txt`
 
# Makefile commands
 - `make re` - recompile library when changes are made to functions
 - `make clean` - removes all function objects
 - `make fclean` - removes all function objects created with library object
 
