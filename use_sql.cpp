#include "sql.cpp"
using namespace std;

vector<bill> useOutputBill(int cmd, string datetime){
    if(cmd >= 4 && cmd !=7){
        printf("input date (year/month/day)(ex. 2019/01/01) : ");
        cin >> datetime;
        cin.ignore();
        printf("Please wait....\n");
    }
    if(cmd == 7) outputbill();
    else if(cmd >= 4 && cmd !=7) outputbill_day(cmd, datetime.c_str());
    bill inB;
    ifstream inF;
    string s;
    vector<bill> m;
    inF.open("querySQL.txt");
    while(inF.good()){
        getline(inF, s, ',');
        if(s!=""){
        inB.id_bill = stoi(s);
        getline(inF, s, ',');
        inB.detailP.id = stoi(s);
        getline(inF, s, ',');
        inB.detailP.name = s.c_str();
        getline(inF, s, ',');
        inB.detailP.price = stoi(s);
        getline(inF, s, ',');
        inB.amount = stoi(s);
        getline(inF, s);
        inB.date = s;
        //printf("%s - %s\n",s.c_str(), inB.date.c_str());
        m.push_back(inB);
        }
    }
    inF.close();
    return m;
}

void useOutputProduct()
{
    outputProduct();
    product inP;
    ifstream inF;
    string s;
    vector<product> m;
    inF.open("querySQL.txt");
    while(inF.good()){
        getline(inF, s, ',');
        if(s!=""){
        inP.id = stoi(s);
        getline(inF, s, ',');
        inP.name = s.c_str();
        getline(inF, s);
        inP.price = stoi(s);
        m.push_back(inP);
        }
        //printf("%d %s %d %d\n",inP.id, inP.name.c_str(), inP.price, inP.stock);
    }
    inF.close();
    char set = ' ';
    for(int i=0; i< m.size(); i++){
        printf("name: %10s, price: %d, input: %10d\n",m[i].name.c_str(), m[i].price, m[i].id);
    }
}

void useEditProduct()
{
    useOutputProduct();
    product inP;
    printf("product id: ");
    cin >> inP.id;
    cin.ignore();
    printf("input name: ");
    getline(cin, inP.name);
    printf("input price: ");
    cin >> inP.price;
    printf("Please wait...\n");
    editProduct(inP.id, (inP.name).c_str(), inP.price);
    system("start connect.bat");
    system("pause");
}

void useInsertProduct()
{
    product inP;
//  auto_id
    ifstream idF;
    idF.open("auto_product.txt");
    getline(idF, inP.name);
    inP.id = stoi(inP.name);
    idF.close();
    ofstream idO;
    idO.open("auto_product.txt");
    idO << inP.id+1;
    idO.close();
    printf("product id: %d\n", inP.id);
    printf("input name: ");
    getline(cin, inP.name);
    printf("input price: ");
    cin >> inP.price;
    printf("Please wait...\n");
    insertProduct(inP.id, (inP.name).c_str(), inP.price);
    system("start connect.bat");
//  printf("%d %s %d %d\n",inP.id,inP.name,inP.price,inP.stock);
    system("pause");
}

void useDelProduct()
{
    useOutputProduct();
    int id;
    char command;
    string name;
    printf("input i = delete by id, n = delete by name : ");
    cin >> command;
    if(command=='i'){
        printf("input id: ");
        cin >> id;
        delProduct(id);
    }else if(command=='n'){
        printf("input name: ");
        cin.ignore();
        getline(cin, name);
        delProduct(0,name.c_str());
    }else{
        printf("Invalid command...\n");
    }
    if(command=='i'||command=='n'){
        printf("Please wait...\n");
        system("start connect.bat");
        system("pause");
    }
}

void useInsertBill()
{
    ifstream idF;
    bill inB;
    idF.open("auto_bill.txt");
    getline(idF, inB.date);
    inB.id_bill = stoi(inB.date);
    idF.close();
    ofstream idO;
    idO.open("auto_bill.txt");
    idO << inB.id_bill+1;
    idO.close();
    vector<bill> bills;
    //get time
    inB.date = substr_TimeDMY(timePresent());
    useOutputProduct();
    do{
    //input bill
    printf("insert id_product = 0 to end program\n");
    printf("bill id: %d\n", inB.id_bill);
    printf("input id_product: ");
    cin >> inB.detailP.id;
    if(inB.detailP.id!=0){
        printf("input amount: ");
        cin >> inB.amount;
        bills.push_back(inB);
    }
    }while(inB.detailP.id!=0);
    for(int i=0; i<bills.size(); i++){
        insertBill(bills[i].id_bill, bills[i].detailP.id, bills[i].amount, inB.date.c_str());
        system("start connect.bat");
        delay(500);
    }
}

void showBill(int cmd, string datetime = ""){
    vector<bill> bill_vec = useOutputBill(cmd, datetime);
    string before = "";
    for(int i=0; i<bill_vec.size(); i++){
        if(bill_vec[i].date!=before){
        printf("\t\t\tdate and time : %s \t\tid_bill : %d\n", bill_vec[i].date.c_str(), bill_vec[i].id_bill);
        printf("\t\t\t___________________________________________________________\n");
        before = bill_vec[i].date;
        }
       // printf("")
    }
    if(bill_vec.empty()) printf("Not found...\n");
}
