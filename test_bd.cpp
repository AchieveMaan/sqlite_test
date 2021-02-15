#include "sqlite3.h"
#include <iostream>

using namespace std;

int main() {
    sqlite3* db;
    int res = sqlite3_open("test.db", &db);
    if(res) 
    {
        cout << "Can't open database for reading...\n" << sqlite3_errmsg(db) << endl;
        return res;
    }
    cout << "Database active!" << endl;

    char* command = "CREATE TABLE IF NOT EXISTS students ( id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, fio TEXT NOT NULL);";

    char* insert = "INSERT INTO students(fio) VALUES (\"MAXIM\")";
    char* select = "SELECT * FROM students";

    char* err = 0;

    if(sqlite3_exec(db, command, 0, 0, &err)) cout << "error:" << err << endl;

    if(sqlite3_exec(db, insert, 0, 0, &err)) cout << "error:" << err << endl;



    sqlite3_stmt * selectState;


    if(sqlite3_exec(db, select, 0, &selectState, &err)) cout << "error:" << err << endl;

    while(sqlite3_step(selectState) == SQLITE_ROW) {
        int id = sqlite3_column_int(selectState, 0);
        char* fio = (char *) sqlite3_column_text(selectState, 1);
        cout << "id: [" << id << "]___FIO: [" << fio << "]" << endl;
    }

    sqlite3_free(err);
    sqlite3_close(db);

}