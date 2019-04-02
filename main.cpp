#include "use_sql.cpp"

using namespace std;

int main()
{
    int number;
    printf("input 0: Add menu\n");
    printf("input 1: Edit menu\n");
    printf("input 2: Delete menu\n");
    printf("input 3: Add bill\n");
    printf("input 4: Show Bill\n");
    printf("input : \n");
    printf("input : \n");
    printf("input : \n");
    printf("input : \n");
    printf("input : \n");
    printf("input -1: end program\n");
    printf("input : ");
    scanf("%d", &number);
    cin.ignore();
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

            break;
        case 5 :

            break;
        case 6 :

            break;

        default :
            printf("Invalid command...\n");
            break;

    }
    return 0;
}
