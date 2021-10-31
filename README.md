# Student Parser

## Description
This project is a basic software about Linked Lists class along with his methods.
The aim of this project was to review some C++ code and to improve my very poor knowledge of C++.

## Docs
```
int size()
```
Get list size

```
void print()
```
Print list

```
bool isEmpty()
```
Return 0 if list is not empty otherwise 1

```
void remove(int index)
```
Remove element in the specified position

```
student* get(int index)
```
Return element at index position

```
LinkedList* clone()
```
Create a clone of list and returns it

```
LinkedList* reverse()
```
Reverse list and returns it

```
void append(node* value)
```
Add new element to the end of the list

```
void preprend(node* value)
```
Add new element on top of the list

```
void set(int index, node* value)
```
Update element at 'index' position with 'value'

```
void forEach(void (*func) (node*))
```
Iterate over each item of the list executing func as callback.
The callback has to take a node* as parameter and can be a lambda or a function.


## Installation
Refer to INSTALL.md

## Author
Jacopo De Gattis
