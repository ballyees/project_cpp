#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
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

string timePresent(){
    time_t rawtime;
    time(&rawtime);
    return ctime(&rawtime);
}

string substr_TimeDMY(string strTime){ //Year-Month-Day hours:min:sec
    string month[] ={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string month_sub;
    for(int i=0; i<12 ;i++){
        if(strTime.substr(4,3)==month[i]){
            if((i+1)<10){
                month_sub = to_string(0)+to_string(i+1);
            }else{
                month_sub = to_string(i+1);
            }
        }
    }
    string substrTime = strTime.substr(20,4)+"-"+month_sub+"-"+strTime.substr(8,2)+" "+strTime.substr(11,2)+":"+strTime.substr(14,2)+":"+strTime.substr(17,2);
    return substrTime;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

string get_trueDate(short int cmd, const char *date){
    string sdate = date;
    if(sdate.length()==1){
        sdate = "0"+sdate;
    } //add 0
    if(cmd == 10) return "ALL";
    if(sdate.length()==2 && (cmd==4 || cmd== 7)){
        sdate = "2019/"+substr_TimeDMY(timePresent()).substr(5, 2)+"/"+sdate;
    }else if(sdate.length()==2 && (cmd == 5 || cmd== 8)){
        sdate = "2019/"+sdate+"/01";
    }else if(sdate.length()==4 && (cmd == 6 || cmd== 9)){
        sdate = sdate+"/01/01";
    }else if(sdate.length()==10 && (cmd==4 || cmd== 7)){
        if(sdate[2]=='/' || sdate[2]=='-'){
            sdate = sdate.substr(6, 4)+"/"+sdate.substr(3, 2)+"/"+sdate.substr(0, 2);
        }
    }else if(sdate.length()==7 && (cmd == 5 || cmd== 8)){
        if(sdate[2]=='/'||sdate[2]=='-'){
            sdate = sdate.substr(0,2)+"/"+sdate.substr(3,4);
        }
    }
    return sdate;
}

void get_trueDate2string(short int cmd, const char *date, string &sdate, string &temp){
    sdate = date;
    temp = date;
    if(sdate.length()==1){
        sdate = temp = "0"+sdate;
    } //add 0
    if(sdate.length()==2 && (cmd==4 || cmd== 7)){
        sdate = temp ="2019/"+substr_TimeDMY(timePresent()).substr(5, 2)+"/"+sdate;
    }else if(sdate.length()==2 && (cmd == 5 || cmd== 8)){
        sdate = "2019/"+sdate+"/01";
        temp = "2019/"+temp+"/31";
    }else if(sdate.length()==4 && (cmd == 6 || cmd== 9)){
        sdate = sdate+"/01/01";
        temp = temp+"/12/31";
    }else if(sdate.length()==10 && (cmd==4 || cmd== 7)){
        if(sdate[2]=='/' || sdate[2]=='-'){
            sdate = temp = sdate.substr(6, 4)+"/"+sdate.substr(3, 2)+"/"+sdate.substr(0, 2);
        }
    }else if(sdate.length()==7 && (cmd == 5 || cmd== 8)){
        if(sdate[2]=='/'||sdate[2]=='-'){
            sdate = sdate.substr(3,4)+"/"+sdate.substr(0,2)+"/01";
            temp = sdate.substr(0,8)+"31";
        }else{
            sdate = sdate+"/01";
            temp = sdate.substr(0,8)+"31";
        }
    }
}

void createConnectForO()
{
    FILE *name_bat;
    name_bat = fopen("connectForO.bat","w");
    fprintf(name_bat, "echo off\n");
    fprintf(name_bat, "cd C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Uploads\n");
    fprintf(name_bat, "del querySQL.txt\n");
    fprintf(name_bat, "cd C:\\Users\\MSI-PS42-OEM\\Desktop\\GitHub\\project_cpp\\Pie\n");
    fprintf(name_bat, "mysql -u root -p123456 < sql.txt\n");
    //fprintf(name_bat, "pause\n");
    fprintf(name_bat, "echo all | copy \"C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Uploads\\querySQL.txt\" \"C:\\Users\\MSI-PS42-OEM\\Desktop\\GitHub\\project_cpp\\Pie\"\n");
    //fprintf(name_bat, "pause\n");
    fprintf(name_bat, "cls\n");
    fprintf(name_bat, "exit");
    fclose(name_bat);
}

void getdataChart_SQL(short int cmd, const char *date){
    string sdate, temp;
    get_trueDate2string(cmd, date, sdate, temp);

    createConnectForO();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use shop_test;\n");
    if(cmd == 10){
        fprintf(name_File, "select product.name, count(*) as total_bill, sum(bill.amount) amountTotal, sum(bill.amount * product.price) priceTotal from bill join product on product.id = bill.id group by product.name order by product.id INTO OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/querySQL.txt' FIELDS TERMINATED BY ',' LINES TERMINATED BY '\\r\\n';\n");
    }else{
        fprintf(name_File, "select product.name, count(*) as total_bill, sum(bill.amount) amountTotal, sum(bill.amount * product.price) priceTotal from bill join product on product.id = bill.id where bill.date between '%s 00:00:00' and '%s 23:59:59' group by product.name order by product.id INTO OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/querySQL.txt' FIELDS TERMINATED BY ',' LINES TERMINATED BY '\\r\\n';\n",sdate.c_str(), temp.c_str());
    }
    fprintf(name_File, "\\q");
    fclose(name_File);
    system("start connectForO.bat");
    delay(1000);
}

vector<bill> getdataChart(short int cmd, const char* date){
    getdataChart_SQL(cmd, date);
    bill inB;
    ifstream inF;
    string s;
    vector<bill> m;
    inF.open("querySQL.txt");
    while(inF.good()){
        getline(inF, s, ',');
        if(s!=""){
        inB.detailP.name = s;
        getline(inF, s, ',');
        inB.detailP.id = stoi(s);
        getline(inF, s, ',');
        inB.amount = stoi(s);
        getline(inF, s);
        inB.detailP.price = stoi(s);
        //printf("%s - %s\n",s.c_str(), inB.date.c_str());
        m.push_back(inB);
        }
    }
    inF.close();
    return m;
}
