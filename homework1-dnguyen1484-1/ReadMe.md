# Homework 1: Comparison of Sorting Algorithms
In this homework assignment, you will implement and compare various sorting algorithms covered in our lectures. The primary goal is to gain hands-on experience with the following sorting algorithms:
1. Selection Sort
2. Insertion Sort
3. Merge Sort
4. Quick Sort

You will find that the starter code I have provided includes the necessary input-output setup. Your main task is to implement each of these sorting algorithms in their respective files.

## Getting Started

To begin working on this assignment, follow these steps:

1. **Clone the Repository**: Start by cloning this GitHub repository to your local machine using the following command:
```bash
git clone https:github.com/csuf-cpsc335/homework1-username.git
```

2. **Navigate to the Homework Repository**: Move into the directory for this specific homework assignment:
```bash
cd homework1-username
```

3. **Review the Start Code**: Refer to `src/inbuilt_sort.cpp` file, which implements the sorting algorithm using the inbuilt function.

4. **Implement Sorting Algorithms**: In `src` folder, you will find files named `selection_sort.cpp`, `insertion_sort.cpp`, `merge_sort.cpp`, `quick_sort.cpp`. Your task is to finish implementing those functions.  <br>
The functions definitions are already defined in `src/sorting_algorithms.h`. Your task is to implement the functions in their respective files in `src` folder. <br>
**DO NOT** change the files in any other folder.

## Testing Guidelines
Once you have successfully implemented all four sorting algorithms, follow these steps to see if your implementation is correct.

### Run Tests
`test` folder contains `grader.cpp` file, which will run your test. `input_generator.cpp` file will generate input set to test your implementations. (You do not need to understand the code in these files). <br>
To run the test, go to `homework1-username` directory (if you are in `src` folder, you need to go back) and run the command
```bash
g++ -std=c++11 -I/src ./src/*.cpp ./test/*.cpp -o grader
```
If your code compiles successfully, you will have a' grader' file in your `homework1-username` folder.
Run the following command to run tests.
```bash
./grader
```

### Graphs (Optional)
**Note**: If you don't want to compare the running time of the algorithm, you can skip this step. And refer to `Submission Guidelines` section. <br>

After you have passed all the tests, check your `out` directory, it should have csv files. These files contains running time data of all the test you ran. <br>
To make the graphs, install python and run the following command to install `matplotlib` and `pandas` modules.
```bash
pip install matplotlib pandas
```
After the installation is successfull, you can run the `graph.py` file using this command
```bash
python ./test/graph.py
```

# Submission Guidelines
Make sure to test locally before submitting to the github.

1. **Commit Your Changes**: Use Git to commit your changes to your local repository
```bash
git add .
git commit -m "Submission"
```

2. **Push to Github**: Push your changes to your GitHub repository
```bash
git push
```

**Make sure to submit the homework before deadline, as github won't allow you to commit after the deadline has passed.**
