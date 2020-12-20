import csv
from sys import argv, exit
import re

if len(argv) != 3:
    print("Need a Database and a sequence as input")  # files not provided
    exit(1)

with open(argv[2], "r") as sequence:
    testdna = csv.reader(sequence)  # opening the sequence
    for row in testdna:
        dnalist = row
DNA = dnalist[0]  # storing as a string

i = 0
dnaset = []
people = {}
database = open(argv[1], "r")
for i, row in enumerate(database):
    if i == 0:
        dnaset = row.strip().split(',')
    else:
        person = row.strip().split(',')
        people[person[0]] = [int(x) for x in person[1:]]
dnaset.pop(0)

# test output
# print(dnaset)
# print(people)
# print(DNA)
# print(len(dnaset))
finalcount = []
for j in range(len(dnaset)):  # for every DNA set
    temp = 1
    count = 0
    
    k = 1
    while k > 0:
            
        if re.search(dnaset[j] * k, DNA[:len(DNA)]):
            k += 1
        else:
            count = k
            k = 0
    finalcount.insert(j, count - 1)

# print(people)
# print(finalcount)

names = people.keys()
for key in names:
    if people[key] == finalcount:
        print(key)
        exit()
print("No match")
