# tokilib [UNDER CONSTRUCTION!]

## Description
**tokilib** is a C++ framework for generating test cases for competitive programming problems. It currently only support *batch* problems, i.e. problems whose test cases consist of .in and .out files.

## Usage
To create test cases for a single problem, you will require these files

### 1. testlib Header (testlib.h)
This framework uses [testlib](http://code.google.com/p/testlib/) version 0.9.5 (already included). It contains all methods used for generating the test cases.

### 2. tokilib Header (tokilib.h)
This header contains additional methods used for executing the test case generation and validating the resulting test cases.

### 3. Generator (generator.cpp)
This file generates the test cases. It must include **tokilib.h**. You can find a template for this file inside **template/** directory. 

#### Concepts
A **subtask** is a set of test cases which have the same constraints. This term originates from IOI 2010. A problem usually contains several subtasks. A test case belongs to exactly one subtask.

The subtasks are numbered from 1. Within a subtask, the test cases are numbered from 1. We can have a special subtask called **sample subtask** which serves as the example input/output test cases. This subtask will be numbered 0.

### 4. Validator (validator.cpp)

### 5. Solution
