# project_cpp SET UP
1. download mysql and install -> https://dev.mysql.com/downloads/windows/installer/8.0.html
2. open cmd
3. open mysql in cmd -> mysql -u (username) -p
4. enter password
  
create database
-----------------------------------------------------------
in mysql command line -> copy command
create database shop_test;
use shop_test;
create table product(id smallint, name varchar(50), price smallint, primary key(id));
create table bill(id_bill int, id smallint, amount int, date datetime, primary key(id_bill, id, date));

-----------------------------------------------------------
5. in mysql command line -> show variables like 'secure_file_priv';
6. copy location file
7. open "sql.cpp"
8. replace C:\\\ProgramData\\\MySQL\\\MySQL Server 8.0\\\Uploads -> location value secure_file_priv
9. replace C:\\\Users\\\MSI-PS42-OEM\\\Desktop\\\project_compro\\shop -> location folder and convert to c style
10. replace root -> (username)
11. replace 123456 -> (password)
