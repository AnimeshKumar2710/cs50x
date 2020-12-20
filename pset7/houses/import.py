# TODO

from sys import argv, exit
import csv
from cs50 import SQL

if (len(argv) != 2):
    exit("Usage: a csv file needed")

db = SQL("sqlite:///students.db")


with open(argv[1], "r") as characters:
    reader = csv.DictReader(characters)

    for row in reader:
        name = []

        for position in row["name"].split(" "):
            name.append(position)

        if len(name) == 2:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)",
                       name[0], name[1], row["house"], row["birth"])
        else:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       name[0], name[1], name[2], row["house"], row["birth"])
