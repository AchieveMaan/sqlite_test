import sqlite3
import time

from sqlite3 import Error

def main():

    try:
        con = sqlite3.connect(":memory:")
        print("Database is active!")
        return con
    except Error:
        print(Error)

con = main()

cursor = con.cursor()

start_time = time.time()
cursor.execute("CREATE TABLE IF NOT EXISTS students ( id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, fio TEXT NOT NULL)")
con.commit()
print("Create time: [ %.10f sec ]" % (time.time() - start_time))

start_time = time.time()
for i in range(0, 100):
    cursor.execute("INSERT INTO students(fio) VALUES (\"SENYA\")")
con.commit()
duration = (time.time() - start_time)
print("Insert time: [ %.10f sec ]" % (duration / 100))

start_time = time.time()
#for row in 
cursor.execute("SELECT * FROM students")
#    print(row)
#con.commit()
print("Select time: [ %.10f sec ]" % (time.time() - start_time))

print("-----")
#    char* insert = "";
#    char* select = "";
con.close()