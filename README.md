# Donation Analytics
The program analyzes loyalty trends in campaign trends in campaign contributions, i.e. identifying areas of repeat donors and calculating how much they're spending.

The program reads in the information of every individual that has contributed to any political party in the past few years. Then, each of them is checked for repeat donors, i.e. if the same individual has donated any amount to a political organization. In case, a repeat donor is recognized, a profile is generated for the political organization that has received that donation. Also, if any more repeat donor is found to donate to a political organization that already has a profile, the total donation received until that point is calculated and a percentile amount is determined based on the user's percentile input. After analyzing all of the information, all the profiles of recipient political organizations are printed onto an output file.

## Directory

### Input Files:
1. itcont.txt - Information of every donation above $200 made to a political organization 
2. percentile.txt - A percentile value set for output

### Output File:
1. repeat_donors.txt - Receipient profiles with their Committee ID, Zip Code, Year, Percentile Amount, Total Amount, and Number of                        Contributions. 

### Source Files:
1. main.cpp - Main engine that run all the processes
2. Data.cpp - Implementing different objects' processes
3. Data.h - Declaring different objects to be used in the program
4. split.h - A function to separate strings in the input file.

### Run File:
1. run.sh - shell commands to compile and run the program in C++ format. It uses a g++ compiler from the linux library.
