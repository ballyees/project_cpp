//File Function
//#include <ctime>
//#include <string>

//function time all
using namespace std;

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


/*
string substr_TimeDMY(string strTime){ //Day-Month-Year
    string substrTime = strTime.substr(8,2)+"-"+strTime.substr(4,3)+"-"+strTime.substr(20,4);
    return substrTime;
}

string substr_TimeDMYnotHyphen(string strTime){ //DayMonthYear
    string substrTime = strTime.substr(8,2)+strTime.substr(4,3)+strTime.substr(20,4);
    return substrTime;
}

string substr_Time(string strTime){ //hours-min-sec
    string substrTime = strTime.substr(11,2)+"-"+strTime.substr(14,2)+"-"+strTime.substr(17,2);
    return substrTime;
}

string substr_TimenotHyphen(string strTime){ //HoursMinSec
    string substrTime = strTime.substr(11,2)+strTime.substr(14,2)+strTime.substr(17,2);
    return substrTime;
}

//function time end

//function for Main record -> bin
string getline_vec(string str){
    string strsub;
    for(int i=0;i<str.length();i++){
        if(int(str[i])==32) break;
        strsub = str.substr(0,i+1);
    }
    return strsub;
}
string get_int(string str){
    string strsub;
    for(int i=str.length();i>=0;i--){
        if(int(str[i])==32) break;
        strsub = str.substr(i,str.length()-i);
    }
    return strsub;
}

bool search_sub(string strmain, string strsub){
    int mainEqsub=0;
    for(int i=0;i<strmain.length();i++){
        if(strmain[i]==strsub[0]){
            for(int j=0; j<strsub.length();j++){
                if(strmain[i+j]==strsub[j]){
                    mainEqsub++;
                }else{
                    i+=mainEqsub;
                    mainEqsub=0;
                    break;
                }
            }
            if(mainEqsub==strsub.length()) return 1;
        }
    }
    return 0;
}

//ต้องปรับปรุง
bool search_sub2(string strmain, string strsub){
    int mainEqsub=0;
    for(int i=0;i<strmain.length();i++){
        if(strmain[i]==strsub[0]){
            for(int j=0; j<strsub.length();j++){
                if((strmain[i+j]==strsub[j])||(int(strmain[i+j])==int(strsub[j])-32)||(int(strmain[i+j])==int(strsub[j])+32)){
                    mainEqsub++;
                }else{
                    i+=mainEqsub-1;
                    mainEqsub=0;
                    break;
                }
            }
            if(mainEqsub==strsub.length()) return 1;
        }
    }
    return 0;
}

bool search_subAll(string strmain, string strsub){
    int mainEqsub=0;
    for(int i=0;i<strmain.length();i++){
        if(strmain[i]==strsub[mainEqsub]){
            mainEqsub++;
        }
        if(mainEqsub==strsub.length()) return 1;
    }
    return 0;
}
/*template <typename t>
int linearSearch_vector()*/
