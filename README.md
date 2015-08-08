# tokilib - Test Case Framework


### WARNING - THIS PROJECT IS DEPRECATED

The next generation of test framework is available in https://github.com/fushar/tcframe. This repository is still here as a legacy.


***

**tokilib** is a C++ framework for generating test cases for competitive programming problems. It currently only support *batch* problems, i.e. problems whose test cases consist of .in and .out files. It works in UNIX and Windows. It has been used for IOI training camps in Indonesia.

This framework is essentially a wrapper for [testlib](http://code.google.com/p/testlib/) framework.

tokilib is licensed using GNU LGPL v3.0.

## Concepts
First, let's introduce some terms used in tokilib.

- A **test case** consists of one input and one output files. A test case belongs to exactly one batch. Within a batch, the test cases are numbered starting from 1.
- A **batch** is a set of test cases. All test cases in a batch conform to the same set of subtasks. The batches are numbered starting from 1.
- A **sample batch** is a special batch which serves as the sample input/output test cases. Each test case in a batch does not have to conform to the same set of subtasks. This sample batch is numbered 0.
- A **subtask** is a set of constraints for variables in a problem. This term originates from IOI 2010. A problem usually consists of several subtasks. The subtasks are numbered starting from 1.
- A **generator** is a C++ file that when executed, will generate the test cases for a problem.
- A **validator** is a C++ file that takes a single test case input file, and when executed, will verify whether the test case is valid according to the specified constraints in the subtask.
- A **slug** is the codename of the problem, preferrably in lowercase letters and has no spaces.

## Usage
Here are the steps for generating test cases for a single problem.

### Setting up the framework
You will need a directory containing the solution, generator, and validator. You can copy the **template**/ directory for reference. You will also need testlib.h, generator.h, and validator.h in the same directory. Typically they are placed outside the problem directories so that you can use one copy of each for all problems.

### Writing the validator
The template for a validator can be found in **template/validator.cpp**. It must include validator.h. You must begin the ``main()`` function with ``beginValidator(argc, argv)`` call and end it with ``endValidator()`` call.

A validator consists of two parts:

1. Subtask definitions
2. Test case validation

#### 1. Subtask definitions
A subtask definition is a set of statements inside the ``main()`` function with the following structure:
- ``beginSubtask()`` call.
- A set of variable assignments as the constraints. The variables are typically the minimum and maximum bounds of variables in the problem.
- ``endSubtask()`` call.

Best practices:
- Name your variables like this: ``N_min``, ``N_max`` where N is a variable in problem statement.
- Surround the variable assignments with curly braces ``{`` ``}``.
- Write the subtask definitions in one line like this:  
  ``beginSubtask(); { N_min = 1; N_max = 100; } endSubtask();``
- or in multiple line like this:  

    ```
    beginSubtask();
    {
      N_min = 1;
      N_max = 1;
    }
    endSubtask();
    ```

#### 2. Test case validation
You must write a function ``void validateCase()`` that reads and verifies the input. Here are examples of most commonly used function calls for this purpose. Please refer to testlib.h for full documentation.

- `int N = inf.readInt(N_min, N_max, "N")`  
Reads an int named N, and verifies that N_min &le; N &le; N_max (or abort otherwise).
- `long N = inf.readLong(N_min, N_max, "N")`  
Reads a long long named N, and verifies that N_min &le; N &le; N_max (or abort otherwise).
- `double N = inf.readDouble(N_min, N_max, "N")`  
Reads a double named N, and verifies that N_min &le; N &le; N_max (or abort otherwise).
- `string S = inf.readToken(format("[a-zA-Z]{1, %d}", N_max), "S")`  
Reads a token named S, and verifies that S contains between 1 and N_max characters 'a'-'z', 'A'-'Z' (or abort otherwise).
- `ensuref(condition, message)`  
Verifies that condition is satisifed, or aborts and outputs message otherwise.
- `readSpace()`  
Reads a space (or abort if no space found).
- `readEoln()`  
Reads a new line (or abort if no new line found).
- `readEof()`  
Verifies that EOF has been reached (or abort otherwise).

Best practices:
- There is a function ``format()`` that behaves similar to ``printf()`` except that it returns the string. Use this in ``readXXX()`` calls when reading elements of array to include the index, like this:
    ```
    inf.readInt(Si_min, Si_max, format("S[%d]", i));
    ```

### Writing the generator
The template for a generator can be found in **template/generator.cpp**. It must include generator.h. You must begin the ``main()`` function with ``beginGenerator(argc, argv)`` call and end it with ``endGenerator()`` call.

A generator consists of eight parts:

1. Sample batch definition
2. Batch definitions
3. Sample test case definitions
4. Test case generations
5. Test case definitions
6. Sample test case printing
7. Test case printing
8. Problem configuration

#### 1. Sample batch definition
A sample batch definition is a function with the following structure:
- ``beginSampleBatch()`` call.
- Sample test case definitions.
- ``endBatch()`` call.

#### 2. Batch definitions
A batch definition is a function with the following structure:
- ``beginBatch()`` call.
- ``setSubtasks()`` call that takes a string of space- or comma-separated subtask numbers. For example, call ``setSubtasks("1, 2, 4")`` to indicate that this batch conforms to subtasks 1, 2, and 4.
- Test case definitions.
- ``endBatch()`` call.

Best practices:
- Name your batch functions ``batchX()`` where X is the batch number.

#### 3. Sample test case definitions
A sample test case definition is a set of statements with the following structure:
- ``beginCase()`` call.
- ``setSubtasks()`` call as defined in the previous section. This is due to the fact that sample test cases do not have to conform to the same set of subtasks.
- ``endCase()`` call.

Best practices:
- Write the sample test case definition in one line like this:  
  ``beginCase(); { setSubtasks("1, 2"); } endCase();``

#### 4. Test case generations
Test case generations are just functions that generates the values of each variables from the problem statement. Here are examples of most commonly used function calls for this purpose. Please refer to testlib.h for full documentation.

- ``rnd.next()``  
Generates a random double value in range [0, 1).
- ``rnd.next(X)``  
Generates a random value in range [0, X).
- ``rnd.next(from, to)``  
Generates a random value in range [from, to].
- ``rnd.next(format("[a-z]{minl, maxl}"))``  
Generates a random string of [minl, maxl] characters 'a'-'z'.
- ``shuffle(begin, end)``  
Random shuffle elements in [begin, end) iterators.

The type of value returned by **rnd.next()** calls depends on the type of the parameters.

Best practices:
- Separate your variables into several components. For example, if the input consists of a tree each of whose node has an associative value, then you have two components: a tree and an array of values.
- Create test case generations for each component independently.
- Create global variables for the components.
- Name the test case generation as an adjective followed by the name of the component. For example: ``randomArray()``, ``binaryTree()``.
- Each test case generation should returns void and does not take parameters. Its purpose is to construct the components based on some settings. The settings are specified in test case definitions.
- See the provided examples for further reference.

#### 5. Test case definition
A test case definition is a set of statements with the following structure:
- ``beginCase()`` call.
- Test case generation calls.
- ``endCase()`` call.
- Surround the test case generation calls with curly braces ``{`` ``}``.
- Write the test case definitions in one line like this:  
  ``beginCase(); { N = 100; randomTree(); } endCase();``
- or in multiple line like this:  

    ```
    beginCase();
    {
      N = 100;
      randomTree();
    }
    endCase();
    ```
- Write each test case explicitly -- do not use loops.

#### 6. Sample test case printing
You must write a function ``void printSampleCase(int tc)`` that takes the sample test case number as the parameter. It should print the sample test case number tc.

Best practices:
- Just print the sample test cases as they appear in problem statement. Do not use loops or function calls at all.

#### 7. Test case printing
You must write a function ``void printCase()`` It should print the test case based on the current state of constructed components.

#### 8. Problem configuration
Inside the ``main()`` function, you should call these functions (between ``beginGenerator()`` and ``endGenerator()``):
- ``setSlug(slug)``  
Sets the slug (codename). 
- ``setMode(mode)``  
Sets the mode. It should be either "single" (each test case in a single file) or "multiple" (all test cases in a subtask are in a single file, preceded with the number of test cases).
- ``setSolution(executable)``  
Sets the executable for running the solution. Typically it is "solution". The executable must be present in the working directory.
- ``setValidator(executable)``  
Sets the executable for running the validator. Typically it is "validator". The executable must be present in the working directory.

Best practices
- Do not use "./" as the prefix of validator and solution executables. It won't work in Windows.

### Writing the solution
Write the reference solution for the problem.

### Running the generator
To actually generate the test cases, perform these steps:

- Compile the solution.
- Compile the validator.
- Compile the generator.
- Run the generator: ``./generator`` in UNIX or ``generator`` in Windows. You can also specify the initial seed for the random number generation as its first argument.

Then, you can see the status of the test case generation. The test cases will be stored in **tc/** directory.

## Examples
Please see the examples provided in **examples/** directory for a better understanding of the best-practice structure of good generators and validators.

## Feedback
Any feedback? Mail me at fushar@gmail.com or post it as an issue :)
