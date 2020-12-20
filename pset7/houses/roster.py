# TODO
from sys import argv, exit
from cs50 import SQL
import sqlite3

if (len(argv) != 2):
    exit("Usage: roster.py house_name")

db = sqlite3.connect("students.db")
cur = db.cursor()
houses = ["gryffindor", "ravenclaw", "slytherin", "hufflepuff"]

if argv[1].lower() not in houses:
    exit("input a valid house name")
    
cur.execute('SELECT first, middle, last, birth FROM students WHERE lower(house) = "{}" ORDER BY last, first;'
            .format(argv[1].lower()))

output = cur.fetchall()

for row in output:
    if not row[1]:
        print(row[0] + " " + row[2] + ", born " + str(row[3]))
    else:
        print(row[0] + " " + row[1] + " " + row[2] + ", born " + str(row[3]))

db.close()
