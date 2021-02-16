import sqlite3

from sqlite3 import Error

def main():

    try:
        con = sqlite3.connect("test.db")
        print("Database is active!")
        return con
    except Error:
        print(Error)

con = main()

cursor = con.cursor()

cursor.execute("CREATE TABLE IF NOT EXISTS studentss ( id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, fio TEXT NOT NULL)")
con.commit()
#    char* insert = "INSERT INTO students(fio) VALUES (\"SENYA\")";
#    char* select = "SELECT * FROM students";
con.close()