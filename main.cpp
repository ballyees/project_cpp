#include "use_sql.cpp"

using namespace std;

int main()
{
    string datetime;
    int number;
    do{
    printf("input 0: Add menu\n");
    printf("input 1: Edit menu\n");
    printf("input 2: Delete menu\n");
    printf("input 3: Add bill\n");
    printf("input 4: Show Bill day\n");
    printf("input 5: Show Bill month\n");
    printf("input 6: Show Bill year\n");
    printf("input 7: Show chart d test\n");
    printf("input 8: Show chart m test\n");
    printf("input 9: Show chart y test\n");
    printf("input 10: Show chart all test\n");
    printf("input : \n");
    printf("input 100: Show Bill All\n");
    printf("input -1: end program\n");
    printf("input : ");
    scanf("%d", &number);
    cin.ignore();
    if(number >= 4 && number !=100 && number != 10){
        printf("input date (year/month/day)(ex. 2019/01/01) : ");
        cin >> datetime;
        cin.ignore();
        printf("Please wait....\n");
    }
    switch (number)
    {
        case 0 :
            useInsertProduct();
            break;
        case 1 :
            useEditProduct();
            break;
        case 2 :
            useDelProduct();
            break;
        case 3 :
            useInsertBill();
            break;
        case 4 :
            //useOutputBill();
            showBill(number, datetime);
            break;
        case 5 :
            showBill(number, datetime.c_str());
            break;
        case 6 :
            showBill(number, datetime.c_str());
            break;
        case 7 :
            useGetdatachart_bar(number, datetime.c_str());
            //getdataChart_SQL(9, "2019");
            break;
        case 8 :
            useGetdatachart_bar(number, datetime.c_str());
            break;
        case 9 :
            useGetdatachart_bar(number, datetime.c_str());
            break;
        case 10 :
            useGetdatachart_bar(number, datetime.c_str());
            break;
        case 100 :
            showBill(number, datetime);
            break;
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
