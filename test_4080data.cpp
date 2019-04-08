#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

struct city{
    int id;
    string name;
    string code;
    string district;
    int population;
};

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

void outputtest_city()
{
    createConnectForO();
    FILE *name_File;
    name_File = fopen("sql.txt","w");
    fprintf(name_File, "use world;\n");
    fprintf(name_File, "select * from city order by ID INTO OUTFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/querySQL.txt' FIELDS TERMINATED BY ',' LINES TERMINATED BY '\r\n'");
    fprintf(name_File, "\\q");
    fclose(name_File);
    system("start connectForO.bat");
    delay(1000);
}

vector<city> useOutputBill(){
    outputtest_city();
    city inB;
    ifstream inF;
    string s;
    vector<city> m;
    inF.open("querySQL.txt");
    while(inF.good()){
        getline(inF, s, ',');
        if(s!=""){
        inB.id = stoi(s);
        getline(inF, s, ',');
        inB.name = s.c_str();
        getline(inF, s, ',');
        inB.code = s.c_str();
        getline(inF, s, ',');
        inB.district = s.c_str();
        getline(inF, s);
        inB.population = stoi(s);
        //printf("%s - %s\n",s.c_str(), inB.date.c_str());
        m.push_back(inB);
        }
    }
    inF.close();
    return m;
}

int main(){
    vector<city> cit = useOutputBill();
    for(int i=0; i<cit.size();i++){
        printf("%d, %s, %s, %s, %d\n", cit[i].id, cit[i].name.c_str(), cit[i].code.c_str(), cit[i].district.c_str(), cit[i].population);
    }
    return 0;
}
