#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "headerMyFunc.cpp"
using namespace std;
struct product
{
    unsigned short int id;
    string name;
    unsigned short int price;
};
struct bill
{
    unsigned int id_bill;
    product detailP;
    //unsigned short int id_product;
    short int amount;
    string date;
};

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void createConnectForO()
{
    FILE *name_bat;
    name_bat = fopen("connectForO.bat","w");
    fprintf(name_bat, "echo off\n");
    fprintf(name_bat, "cd C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Uploads\n");
    fprintf(name_bat, "del querySQL.txt\n");
    fprintf(name_bat, "cd C:\\Users\\MSI-PS42-OEM\\Desktop\\project_compro\\shop\n");
    fprintf(name_bat, "mysql -u root -p123456 < sql.txt\n");
    //fprintf(name_bat, "pause\n");
    fprintf(name_bat, "echo all | copy \"C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Uploads\\querySQL.txt\" \"C:\\Users\\MSI-PS42-OEM\\Desktop\\project_compro\\shop\"\n");
    //fprintf(name_bat, "pause\n");
    fprintf(name_bat, "cls\n");
    fprintf(name_bat, "exit");
    fclose(name_bat);
}

void createConnect()
{
    FILE *name_bat;
    name_bat = fopen("connect.bat","w");
    fprintf(name_bat, "echo off\n");
    fprintf(name_bat, "mysql -u root -p123456 < sql.txt\n");
    //fprintf(name_bat, "pause\n");
    fprintf(name_bat, "cls\n");
    fprintf(name_bat, "exit");
    fclose(name_bat);
}

void insertProduct(unsigned short int id, const char* name, unsigned short int price)
{
    createConnect();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "insert into product values\(%d, \"%s\", %d);\n",id, name, price);
    fprintf(name_File, "\\q");
    fclose(name_File);
}

void insertBill(unsigned int id_bill, unsigned short int id_product, unsigned short int amount, const char* date)
{
    createConnect();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "insert into bill values\(%d, %d, %d, \"%s\");\n",id_bill, id_product, amount, date);
    fprintf(name_File, "\\q");
    fclose(name_File);
}

void editProduct(unsigned short int id, const char* name, unsigned short int price)
{
    createConnect();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "update product set name = \"%s\", price = %d where id = %d;\n",name, price, id);
    fprintf(name_File, "\\q");
    fclose(name_File);
}

void delProduct(unsigned short int id = 0, const char *name = "")
{
    createConnect();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "delete from product where name = \"%s\" or id = %d;\n",name, id);
    fprintf(name_File, "\\q");
    fclose(name_File);
}

void delBill(unsigned short int id_bill)
{
    createConnect();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "delete from bill where id_bill = %d;\n", id_bill);
    fprintf(name_File, "\\q");
    fclose(name_File);
}

void delAllBill_product()
{
    createConnect();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "delete from bill where 1;\n");
    fprintf(name_File, "delete from product where 1;\n");
    fprintf(name_File, "\\q");
    fclose(name_File);
}

void showProduct()
{
    createConnect();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "SELECT * FROM product;\n");
    fprintf(name_File, "\\q");
    fclose(name_File);
}

void outputProduct()
{
    createConnectForO();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "SELECT * FROM product order by id INTO OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/querySQL.txt' FIELDS TERMINATED BY ',' LINES TERMINATED BY '\r\n'");
    fprintf(name_File, "\\q");
    fclose(name_File);
    system("start connectForO.bat");
    system("pause");
}

void outputbill()
{
    createConnectForO();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "SELECT * FROM bill order by bill.id_bill INTO OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/querySQL.txt' FIELDS TERMINATED BY ',' LINES TERMINATED BY '\r\n'");
    fprintf(name_File, "\\q");
    fclose(name_File);
    system("start connectForO.bat");
}

void outputbill(unsigned int id_bill)
{
    createConnectForO();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    fprintf(name_File, "select bill.id_bill, bill.id, product.name, product.price, bill.amount, bill.date from shop_test.bill join shop_test.product on bill.id = product.id where bill.id_bill = %d INTO OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/querySQL.txt' FIELDS TERMINATED BY ',' LINES TERMINATED BY '\r\n'",id_bill);
    fprintf(name_File, "\\q");
    fclose(name_File);
    system("start connectForO.bat");
}
