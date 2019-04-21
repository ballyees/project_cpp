echo off
cd C:\ProgramData\MySQL\MySQL Server 8.0\Uploads
del querySQL.txt
cd C:\Users\MSI-PS42-OEM\Desktop\GitHub\project_cpp
mysql -u root -p123456 < sql.txt
echo all | copy "C:\ProgramData\MySQL\MySQL Server 8.0\Uploads\querySQL.txt" "C:\Users\MSI-PS42-OEM\Desktop\GitHub\project_cpp"
cls
exit