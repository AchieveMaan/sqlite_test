#include "sqlite3.h"
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <ctime>

using namespace std;

static int callback(void *data, int argc, char**argv, char **azColName){
//    int i;
//    cout << (const char*) data << endl;

//    for(i =0; i<argc; i++) {
        //cout << azColName[i] << ":[ " << argv[i] << " ]" << endl;
//    }
    return 0;
}

int main() {
    sqlite3* db;
    int res = sqlite3_open("cpp.db", &db);

// "test_cpp.db", &db);
    if(res)
    {
        cout << "Can't open database for reading...\n" << sqlite3_errmsg(db) << endl;
        return res;
    }
    cout << "Database active!" << endl;

//    char* command = "CREATE TABLE IF NOT EXISTS students ( id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, fio TEXT NOT NULL);";

//    char* insert = "INSERT INTO students(fio) VALUES (\"SENYA\")";
//    char* select = "SELECT * FROM students";

    char* err = 0;
    cout << fixed;
    cout.precision(15);
    clock_t start;
    double duration;
    start = clock();

    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS students ( id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, fio TEXT NOT NULL);", 0, 0, &err);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Create time = [ " << duration << " sec ]" << endl;
    sqlite3_free(err);


    start = clock();
    for (int i = 0; i < 100; i++) {
        sqlite3_exec(db, "INSERT INTO students(fio) VALUES (\"SENYA\")", 0, 0, &err);
    }
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Insert time = [ " << duration / 100 << " sec ]" << endl;

    const char* data = "Callback function called";
    start = clock();
    sqlite3_exec(db, "SELECT * FROM students", callback, (void *) data, &err);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Select time = [ " << duration << " sec ]" << endl;
    cout << "-----";
    sqlite3_free(err);
    sqlite3_close(db);

}