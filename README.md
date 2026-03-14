# **Fraction Data Type in C++**

This project implements a **custom Fraction (Razlomak) data type in C++** that allows working with rational numbers using **object-oriented programming and operator overloading**.

The goal of the project is to demonstrate how **C++ classes can be used to model mathematical objects** and how operators can be overloaded so fractions behave like built-in numeric types.

## **Project Overview**

Fractions (rational numbers) are numbers that consist of:

* **Numerator** – the top part of the fraction  
* **Denominator** – the bottom part of the fraction

Example: 3/4

In this project, a custom class called **razlomak** represents a fraction and provides functionality for:

* arithmetic operations  
* comparisons  
* Simplification  
* input and output  
* assignment operations  
* increment and decrement operations

The class allows fractions to be manipulated **similarly to built-in numeric types in C++**.

## **Class Structure**

The fraction is implemented using a class with two private members:

int brojnik;   // numerator  
int nazivnik;  // denominator

These variables store the value of the fraction.

### **Constructor**

The class provides a constructor with default parameters:

razlomak(int B \= 0, int N \= 0);

This allows creating fractions such as:

razlomak a(3,4);  
razlomak b(1,2);

## **Implemented Features**

### **1\. Fraction Simplification**

The class includes a function for simplifying fractions using the **Greatest Common Divisor (GCD)**.

int nzd(int a, int b);  
razlomak skracen();

Example:

6/8 → 3/4

### **2\. Input and Output**

Operator overloading allows easy input and output of fractions.

friend ostream& operator\<\<(ostream&, const razlomak&);  
friend istream& operator\>\>(istream&, razlomak&);

Example usage:

razlomak r;  
cin \>\> r;  
cout \<\< r;

Input format: 3/4

Output format: 3 | 4

### **3\. Arithmetic Operations**

The following arithmetic operators are implemented:

| Operator | Description |
| ----- | ----- |
| \+ | Addition |
| \- | Subtraction |
| \* | Multiplication |
| / | Division |

Example:

razlomak a(1,2);  
razlomak b(3,4);

razlomak c \= a \+ b;

### **4\. Comparison Operators**

The project supports comparison between fractions:

| Operator | Meaning |
| ----- | ----- |
| \== | Equal |
| \!= | Not equal |
| \> | Greater than |
| \< | Less than |
| \>= | Greater or equal |
| \<= | Less or equal |

Fractions are compared by converting them into floating-point values.

Example:

if(a \> b){  
    cout \<\< "a is greater";  
}

### **5\. Assignment Operators**

The class implements assignment and compound assignment operators:

| Operator | Function |
| ----- | ----- |
| \= | Assignment |
| \+= | Add and assign |
| \-= | Subtract and assign |
| \*= | Multiply and assign |
| /= | Divide and assign |

Example:

a \+= b;

### **6\. Increment and Decrement**

The class also overloads:

\++  
\--

These operators increase or decrease the fraction by **one whole unit**.

Example:

a++;  
a--;

Internally this is implemented by adding or subtracting the denominator from the numerator.

## **Error Handling**

The program prevents invalid fractions such as:

denominator \= 0

If this occurs, the program throws an exception:

throw invalid\_argument("Nazivnik ne moze biti nula");

## **Example Usage**

razlomak a(1,2);  
razlomak b(3,4);

razlomak c \= a \+ b;

cout \<\< c;

Result: 5 | 4

## **Concepts Demonstrated**

This project demonstrates several important **C++ programming concepts**:

* Object-Oriented Programming (OOP)  
* Classes and constructors  
* Operator overloading  
* Friend functions  
* Exception handling  
* Mathematical abstraction in programming

## **Possible Improvements**

Future improvements could include:

* Support for **negative fractions**  
* Automatic **normalization of signs**  
* Using **templates for different numeric types**  
* Implementing **prefix increment/decrement**  
* Adding **conversion to floating-point numbers**  
* Creating a **separate implementation (.cpp) file**

## **License**

This project is intended for **educational purposes**.

