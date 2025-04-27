





# C++ Project 04 - Typecasting in c++

###  General Rules for these projects: 
The purpose of these c++ projects is to get introduced into OOP. We are allowed to use standard c++17. 

- code must be coiled with `c++` and the flags `-Wall -Werror -Wextra`.
- there must be a Makefile for each exercise.
- Class names and corresponding filenames must be written in UpperCamelCase format.
- The `using namespace <ns_name>` and `friend` keywords are forbidden.
- There must be no memory leaks.
- Classes must be designed in the Orthodox Canonical Form.
- There can be no function implementations in headerfiles.
- Headers must be able to be used independently from others.
- Use of STL in the Module 08 and 09 only->no containers / Algorithm header


## 🔶 ex00 Conversion of scalar types
### Objective: Write a class ScalarConverter that will contain only one static method "convert" that will takes as parameter a string representation of a C++ literal in its most common form and output its value in the following serie of scalar types : char int float double
### Usage:
  ```
  cd ex00
  make
  ./convert <char/int/float/double>
```
### Example:
```
./convert 654
char: impossible
int: 654
float: 654.0f
double: 654.0
```

```
./convert p  
char: p
int: 112
float: 112.0f
double: 112.0
```


### My thoughts: 
-  This was way more tricky than anticipated. I solved it in a complicated way in that i didnt know about regex yet. but it was interesting to learn about the formating capabilities of std::cout;

## 🔶 ex01 Serialization
### Ojective: Implement a class Serialize with the following static methods: uintptr_t serialize(Data* ptr); Data* deserialize(uintptr_t raw);
  ```
  cd ex01
  make
  ./Serializer
```

### My thoughts:
- this was really easy as i just used the reinterpret_cast. But interesting to learn that there are different types of casting in c++ in comparison to C.

## 🔶 ex02 Identify real type
### Ojective: Implement a Base class and dreved classes A, B, C. Implement funcitons to identify which of these tyes is coming in as an argument.
### Usage:
  ```
  cd ex02
  make
  ./BaseGenerator
```

### My thoughts:
- This was intersiting to use the dynamic cast and to see its usecases. Also it was now to me to use the random number generation in C++ and its confusing functionality.


  
