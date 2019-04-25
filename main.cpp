#include "use_sql.cpp"
#include "pie.cpp"
using namespace std;

int main()
{
    string datetime;
    int number;
    printShop();
    system("pause");
    system("cls");
    do{
    printMenu();
    scanf("%d", &number);
    cin.ignore();
    system("cls");
    if(number >= 4 && number <=13 &&number!=10){
        printf("input date (year/month/day)(ex. 2019/01/01) : ");
        cin >> datetime;
        cin.ignore();
        printf("Please wait....\n");
    }
    switch (number)
    {
        case 0 :
            printf("Add menu :\n--------------------------------------\n");
            useInsertProduct();
            break;
        case 1 :
            printf("Edit menu :\n--------------------------------------\n");
            useEditProduct();
            break;
        case 2 :
            printf("Delete menu :\n--------------------------------------\n");
            useDelProduct();
            break;
        case 3 :
            printf("Add Bill :\n--------------------------------------\n");
            useInsertBill();
            break;
        case 4 :
            printf("Show Bill day :\n--------------------------------------\n");
            showBill(number, datetime);
            break;
        case 5 :
            printf("Show Bill month :\n--------------------------------------\n");
            showBill(number, datetime.c_str());
            break;
        case 6 :
            printf("Show Bill year :\n--------------------------------------\n");
            showBill(number, datetime.c_str());
            break;
        case 7 :
            printf("Show chart day - HTML :\n--------------------------------------\n");
            useGetdatachart_bar(number, datetime.c_str());
            break;
        case 8 :
            printf("Show chart month - HTML :\n--------------------------------------\n");
            useGetdatachart_bar(number, datetime.c_str());
            break;
        case 9 :
            printf("Show chart year - HTML :\n--------------------------------------\n");
            useGetdatachart_bar(number, datetime.c_str());
            break;
        case 10 :
            printf("Show chart all - HTML :\n--------------------------------------\n");
            useGetdatachart_bar(number, datetime.c_str());
            break;
        case 11 :
            printf("Show chart day - C++ :\n--------------------------------------\n");
            pieChartBGI(number, datetime.c_str());
            break;
        case 12 :
            printf("Show chart month - C++ :\n--------------------------------------\n");
            pieChartBGI(number, datetime.c_str());
            break;
        case 13 :
            printf("Show chart year - C++ :\n--------------------------------------\n");
            pieChartBGI(number, datetime.c_str());
            break;
        case 14 :
            printf("Show chart all - C++ :\n--------------------------------------\n");
            pieChartBGI(number, datetime.c_str());
            break;
        case 100 :
            printf("Show Bill All :\n--------------------------------------\n");
            showBill(number, datetime);
            break;
        case 111:
            printf("Change Shop Name :\n--------------------------------------\n");
            changeName();
        case -1:
            break;
        default :
            printf("Invalid command...\n");
            system("pause");
            break;
    }
    printf("\n--------------------------------------\n");
    system("cls");
    }while(number!=-1);
    printf("\n\t\t\t....Thank You....\n");
    return 0;
}
