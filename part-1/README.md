# Find Minimum Element

The FindMinimum() function from last week will only work on C++ arrays of a very specific size and will only work with arrays. This is quite a significant limitation if you consider that you may wish to reuse this algorithm for different data types such as floats, doubles, and strings. More practically, it's hard to predict precisely how large or small our input will be so the function is very rigid.

Bottom line, if we want to reuse that function for anything other than an array of 10 integers, we'll have to re-write it from scratch. Can you imagine being the library writer who is writing function after function of simple operations just because we can't come up with a generic way to express the idea of "find the smallest element in a list of length N"?

This very problem haunted programmers. You come up with a nifty little algorithm to sort something and you have to completely rewrite it to make it work with this other data type. As software libraries and programming languages evolved, by the 1970s the question of how to write libraries flexibly became common place. New programming languages such as [ML](https://en.wikipedia.org/wiki/ML_(programming_language)) and [ADA](https://en.wikipedia.org/wiki/Ada_(programming_language)) had baked into the design of the language and idea of generic programming.

It wasn't until 1989 that David Musser and Alexander Stepanov wrote a paper which coined the phrase [Generic Programming](https://en.wikipedia.org/wiki/Generic_programming).

> Generic programming centers around the idea of abstracting from concrete, efficient algorithms to obtain generic algorithms that can be combined with different data representations to produce a wide variety of useful software. — Musser & Stepanov, Generic Programming

Remember, C++ was born in 1985 at Bell Labs. Musser, Stepanov and others started working on a generic programming libraries in the 1970s. While Stepanov was working at Bell Labs and Hewlett-Packard, he created a library for C++ called the [Standard Template Library](https://en.wikipedia.org/wiki/Standard_Template_Library), commonly referred to as the STL. In 1994, the STL was incorporated into a draft ANSI/ISO C++ standard and Hewlett-Pakard published their implementation of the STL on the Internet.

When people communicate with one another, we can learn from other's experience and wisdom by applying what we learn in situations that the original teller couldn't imagine. We have the ability to take an idea (an algorithm) and apply it in innovative ways. A programming language is very rigid in how it describes ideas and if you explain an algorithm one way, you have to completely rewrite it for changes human beings will consider inconsequential.

You may be interested in learning more about [design patterns](https://en.wikipedia.org/wiki/Design_Patterns) and picking up Stepanov's latest book [From Mathematics to Generic Programming](http://fm2gp.com/) which is accessible to any college student. (You may be able to borrow it [from our library](https://csuf-primo.hosted.exlibrisgroup.com/permalink/f/43rjjt/TN_cdi_askewsholts_vlebooks_9780133491784).) 

In this exercise, we will do exactly what we did last week except we shall use the STL to do all the work.

Previously, we used a C++ Array (which is actually an STL Array) to hold on to our data. The problem with the array was that it was a fixed sized. This is inflexible because we couldn't change the size of the array unless we recompiled the program.

Instead of using a C++ STL Array, we shall use a [C++ STL Vector](https://en.cppreference.com/w/cpp/container/vector). A vector is like an array in many ways yet it can change its size dynamically. This means that we can have a vector that starts out holding 5 elements and then later it can hold 20 elements and even later it can have zero elements. Additionally, just like the C++ STL Array, the vector can hold any type that we would like to use. 

Let's declare a vector of ten integers. To use vectors, remember to `#include <vector>`. The code below will fetch the value 8 from the fourth location. Remember we start counting from 0. In the example below, the vector `my_vector` has been statically initialized to have the even numbers from 2 to 20. Notice the type is `vector<int>` which tells the compiler that the variable `my_vector` is a vector. Unlike arrays, we don't have to specify the size of the vector.

```c++
vector<int> my_vector{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
int fourth_element = 0;
try{
  fourth_element = my_vector.at(3);
}catch(const exception& e){
  ErrorMessage("There's nothing there!");
  exit(1);
}
```

Notice that the [`at()`](https://en.cppreference.com/w/cpp/container/vector/at) method is wrapped with a try/catch so if by accident you attempt to fetch an item that doesn't exist you'll be able to recover from your error.


On the other hand, if we want to make a vector of a specific size, we can do so just like an array. In the example below, the vector `my_vector` is created and has space for 12 elements. Using the C++ Standard Library function [`fill()`](https://en.cppreference.com/w/cpp/algorithm/fill), `my_vector` is filled with the value `42`. Accessing the fourth element will retrieve the value 42.

```c++
vector<int> my_vector(12);
fill(my_vector.begin(), my_vector.end(), 42);
try{
  fourth_element = my_vector.at(3);
}catch(const exception& e){
  ErrorMessage("There's nothing there!");
  exit(1);
}
```


Looping through a vector is just like a C++ array so you can reuse the strategies from the previous lab to look through a vector should you need to.

We shall re-write the functions from last week to take advantage of generic algorithms available in the C++ STL Algorithms library.

For instance, to fill our vector with random numbers, `FillVector()`, we will use [`generate()`](https://en.cppreference.com/w/cpp/algorithm/generate) and [C++ Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda).

To print out the values in the vector to the terminal, `PrintVector()`, we will use [`copy()`](https://en.cppreference.com/w/cpp/algorithm/copy) and [`ostream_iterator()`](https://en.cppreference.com/w/cpp/iterator/ostream_iterator) to write the elements of the vector to the terminal.

To find the smallest element, `FindMinimum()`, we will use [`min_element()`](https://en.cppreference.com/w/cpp/algorithm/min_element) and [`distance()`](https://en.cppreference.com/w/cpp/iterator/distance) to extract the smallest element.

## Requirements

Using a C++ vector and a random number generator, create an vector of random integers. Then print out the vector with one element from the vector on a line. Next find the minimum value in the vector. Once the minimum value is found, return it to the main function and print it out.

Using the inline documentation, implement the following functions.

* `int FindMinimum(vector<int>&the_vector);`
* `void FillVector(vector<int>&the_vector,const int nelements,RandomNumberGenerator&random_number_generator);`
* `void PrintVector(const vector<int>&the_vector);`
* `void ErrorMessage(const string&message);`

The program takes three command line arguments other than the program's name:

1. `argv[1]` is the minimum value generated by the random number generator
1. `argv[2]` is the maximum value generated by the random number generator
1. `argv[3]` is the number of random numbers to generate and save into the vector.

Use only C++ Standard Library functions to complete this exercise. Do not use any loops.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* doc: generate HTML documentation from the source code using Doxygen
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header

## Inline Documentation
The project is thoroughly documented inline using the [Doxygen](https://en.wikipedia.org/wiki/Doxygen) format. The documentation establishes a framework for you to follow so that you can implement all the details of the program. To generate HTML formatted documents to view on your computer use the make target `doc`. For example:

```
$ ls
Doxyfile	Makefile	README.md	find_min.cc
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  find_min.cc \
	| sed 's/\(find_min\)\.o[ :]*/\1.o find_min.d : /g' > find_min.d; \
	[ -s find_min.d ] || rm -f find_min.d
doxygen Doxyfile
$ ls
Doxyfile	README.md	find_min.cc
Makefile	doc/		find_min.d
```

The inline documentation is saved in `doc/html`. To view the documentation, use the command `gio open doc/html/index.html` which will open the index file in your web browser.

If the `doxygen` command is not available, for instance when you use `make doc` the output looks like:

```
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  find_min.cc \
	| sed 's/\(find_min\)\.o[ :]*/\1.o find_min.d : /g' > find_min.d; \
	[ -s find_min.d ] || rm -f find_min.d
doxygen Doxyfile
make: doxygen: No such file or directory
make: *** [doc] Error 1
```

Then you can install `doxygen` using the command `sudo apt install doxygen doxygen-latex graphviz`.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -Wall -pipe -std=c++14  find_min_element.cc \
	| sed 's/\(find_min_element\)\.o[ :]*/\1.o find_min_element.d : /g' > find_min_element.d; \
	[ -s find_min_element.d ] || rm -f find_min_element.d
clang++ -g -Wall -pipe -std=c++14  -c find_min_element.cc
clang++ -g -Wall -pipe -std=c++14 -o find_min_element find_min_element.o 
$ ./find_min_element 
Please provide two positive integers as the maximum and minimum for this exercise and the number of integers to generate.
There was an error. Exiting.
$ ./find_min_element 1
Please provide two positive integers as the maximum and minimum for this exercise and the number of integers to generate.
There was an error. Exiting.
$ ./find_min_element 1 100
Please provide two positive integers as the maximum and minimum for this exercise and the number of integers to generate.
There was an error. Exiting.
$ ./find_min_element 1 100 4
44
81
48
21
The minimum value in the vector is 21
$ ./find_min_element 1 10 15
4
8
10
2
10
5
3
6
3
10
7
5
5
6
3
The minimum value in the vector is 2
$ ./find_min_element 1 100 12
86
76
89
53
81
98
39
54
57
22
82
32
The minimum value in the vector is 22
```

