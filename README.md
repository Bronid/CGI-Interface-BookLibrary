# CGI Interface BookLibrary
![image](https://user-images.githubusercontent.com/61603558/211165753-325a5643-54b2-4498-b598-ba646c6eb378.png)
## Table of Contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Site structure](#site-structure)
* [Setup](#setup)

## General-info
### Goal: 
Develop a C++ program that implements a CGI interface
Web server for creating and processing the database of library books.

### My solution:   
Using the capabilities of the sqlite3 library and the Apache server, I managed to write my own CGI interface in C ++ that provides the minimum functionality of a book library with the ability to add, delete, edit and search inside the database.

## Technologies
* C++ 14
* [sqlite](https://www.sqlite.org/) (version: 3.40.0)
* [cgicc](https://www.gnu.org/software/cgicc/) (version: 3.2.19#5)
* [xampp](https://www.apachefriends.org/) (implemented Apache server)
* To work with .db files used [DB Browser SQLite](https://sqlitebrowser.org/)

## Site-structure
1. [MainPage.cpp](https://github.com/Bronid/CGI-Interface-BookLibrary/blob/master/MainPage.cpp) - index.cgi file, main page with all information and from which all actions are performed. Have GET request to filter library searches by parameters for the title of the book and the name of the author.  
   `URL: hostname/index.cgi`
2. [AddToDB.cpp](https://github.com/Bronid/CGI-Interface-BookLibrary/blob/master/AddToDB.cpp) - AddToDB.cgi file, script gets data(book name, author, pages, etc...) from POST request and adds it to the database. 
   `URL: hostname/cgi-bin/AddToDB.cgi`
3. [DeleteFromDB.cpp](https://github.com/Bronid/CGI-Interface-BookLibrary/blob/master/DeleteFromDB.cpp) - DeleteFromDB.cgi file, script gets data(in this case - id) from POST request, then searches element by id in the table and deletes it. 
   `URL: hostname/cgi-bin/DeleteFromDB.cgi`
4. [DropTable.cpp](https://github.com/Bronid/CGI-Interface-BookLibrary/blob/master/DropTable.cpp) - DropTable.cgi file, script gets data(table name) from POST request, then drops table. 
   `URL: hostname/cgi-bin/DropTable.cgi`
5. [EditDB.cpp](https://github.com/Bronid/CGI-Interface-BookLibrary/blob/master/EditDB.cpp) - EditDB.cgi file, script gets data(id) from POST request, then searches element by id in the table and sets up their values in the HTML FORM, then gives possibility to change this datas. 
   `URL: hostname/cgi-bin/EditDB.cgi` 
6. [SaveEdit.cpp](https://github.com/Bronid/CGI-Interface-BookLibrary/blob/master/SaveEdit.cpp) - SaveEdit.cgi file, script gets data(data from EditDB.cgi) then does UPDATE table with new data from EditDB.cgi. 
   `URL: hostname/cgi-bin/SaveEdit.cgi`

## Setup
1. Download [xampp](https://www.apachefriends.org/) or use [this files](https://github.com/Bronid/CGI-Interface-BookLibrary/tree/master/xampp).
2. Compile .cpp files into .cgi file and rename it like in [Site structure](#site-structure).
3. Move all .cgi file in cgi-bin folder like [here](https://github.com/Bronid/CGI-Interface-BookLibrary/tree/master/xampp/cgi-bin).
4. Use this [config file](https://github.com/Bronid/CGI-Interface-BookLibrary/blob/master/xampp/apache/conf/httpd.conf) to use Apache server.
5. Start Apache server via xampp application.
6. Write into your URL: localhost
### Done! =)
