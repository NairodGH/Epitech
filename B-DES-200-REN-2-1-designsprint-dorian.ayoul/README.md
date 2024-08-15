##  How to start the Database

-   cd app/
-   docker-compose up

/!\ Make sure nothing is already running on port 3306

If mysql is running on this port, try:
-   service mysql stop


##  How to start the server
-   *make sure the Database is running
-   cd server/
-   npm start
