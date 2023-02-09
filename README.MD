# My first ever AI project

## About this repo

This will be my repo where I will post my experience about learning *Artificial Intelligence* and *Machine Learning*.

## Projects

### First ML Neural Network

#### Problem

The idea for this problem was taken from the channel [giant_neural_network](https://www.youtube.com/@giantneuralnetwork), please check them out for more information :)

There was a farmer who liked to measure the length and the width of her flowers; she really liked plotting the lenght and the width of the measured flowers and their color as well!
However one day she noticed that one of her measurements she had an flower that had no color assigned to it :(; Our task it to help her figure out or at least try to predict what color should
the given flower be.

The data file for this problem can be found [here](https://github.com/EmreArapcicUevak/First-Project-About-AI/blob/readMe/data/data.txt).

| length | width | color |
|:------:|:-----:|:-----:|
|    3   |  1.5  |  red  |
|    2   |   1   |  blue |
|    4   |  1.5  |  red  |
|    3   |   1   |  blue |
|   3.5  |  0.5  |  red  |
|    2   |  0.5  |  blue |
|   5.5  |   1   |  red  |
|    1   |   1   |  blue |

*Plots to be added!*

#### How to test this repo's code

The solution for the given problem was written in *C++* meaning that you will need a compiler to compile the C++ code. Once you get a C++ compiler, compiler [./code/cpp/main.cpp](https://github.com/EmreArapcicUevak/First-Project-About-AI/tree/readMe/code/cpp).

##### Step 1

Clone the repository and move into the repository.

```bash
git clone https://github.com/EmreArapcicUevak/First-Project-About-AI.git
cd First-Project-About-AI
```

##### Step 2

Go into the folder containing the cpp file and compile the cpp file

```bash
cd code/cpp
g++ main.cpp -o main.exe
```

##### Step 3

Run the .exe file

For windows you can either use the file explorer and double click the exe, or execture the following commands

```bash
start main.exe
```

For apple users you will have to execute the following line of code
```bash
.\main.exe
```

##### Step 4

After you execture Step 3 just wait for the program to finish running and you are all set :)

In the [data](https://github.com/EmreArapcicUevak/First-Project-About-AI/tree/main/data) folder there should be a savedWeights and a log file.

The log file has all the errors and is used for plotting the error plot which we will see how to do right after this.

The saved weights contains all the weights and the bias at the end for the neural network.
 
### Plotting the error

As of right now I only have the matlab / octave code which is used for plotting the given error. All that u have to do is run the [plotError.m](https://github.com/EmreArapcicUevak/First-Project-About-AI/tree/main/code/OctaveMatlab) file and a figure should appear.

I will try to make a python script some time soon as well that would also display the needed figures

### Note from me

Since I am a first year computer science student (while writing this) I wanted to dip my feet in the field of AI and ML that I found very interesting.
The youtube channel that I took this problem from helped me greatly to understand the concept of ML, however I did hit some limitations because at the moment of writing this I only
have had experience with Calculus 1, and it was reccomended to also have knowledge in Linear Algebra and Multi Variable Calculus which I did not fully lack but certanly did not have a high level
understanding of. I will surely be coming back to this project after I finish my 2nd semester that is coming up (After my first academic year) equiped with Calculus 2 and Linear Algebra under my belt
to try to solve a more complex version of this problem. I will also try to get a better understanding of R, Matlab, and Python for better upcoming plots but as of right now I have found my self
occupied learning Vim, and advance Git; I also have had a problem with not having a laptop nor a pc for 2 weeks but I finally got a new laptop so I should get back on track :).
