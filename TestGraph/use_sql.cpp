#include "sql.cpp"
using namespace std;

int linear_bill(vector<bill> b, int key){
    for(int i=0; i<b.size(); i++){
        if(b[i].detailP.id==key) return i;
    }
    return -1;
}

vector<bill> useOutputBill_detail(const char* datetime){
    outputbill_detail(datetime);
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

vector<bill> useOutputBill(int cmd, string datetime){
    /*
    if(cmd >= 4 && cmd !=100){
        printf("input date (year/month/day)(ex. 2019/01/01) : ");
        cin >> datetime;
        cin.ignore();
        printf("Please wait....\n");
    }*/
    if(cmd == 100) outputbill();
    else if(cmd >= 4 && cmd !=100) outputbill_day(cmd, datetime.c_str());
    bill inB;
    ifstream inF;
    string s;
    vector<bill> m;
    inF.open("querySQL.txt");
    while(inF.good()){
        getline(inF, s);
        if(s!=""){
        inB.date = s;
        m.push_back(inB);
        }
    }
    inF.close();
    return m;
}

vector<product> useOutputProduct()
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
        //printf("%d %s %d\n",inP.id, inP.name.c_str(), inP.price);
    }
    inF.close();
    /*for(int i=0; i< m.size(); i++){
        printf("name: %10s, price: %d, input: %10d\n",m[i].name.c_str(), m[i].price, m[i].id);
    }*/
    return m;
}

void useEditProduct()
{
    vector<product> m = useOutputProduct();
    for(int i=0; i< m.size(); i++){
        printf("name: %10s, price: %d, input: %10d\n",m[i].name.c_str(), m[i].price, m[i].id);
    }
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
    vector<product> m = useOutputProduct();
    for(int i=0; i< m.size(); i++){
        printf("name: %10s, price: %d, input: %10d\n",m[i].name.c_str(), m[i].price, m[i].id);
    }
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
    vector<product> m = useOutputProduct();
    for(int i=0; i< m.size(); i++){
        printf("name: %10s, price: %d, input: %10d\n",m[i].name.c_str(), m[i].price, m[i].id);
    }
    do{
    //input bill
    printf("insert id_product = 0 to end program\n");
    printf("bill id: %d\n", inB.id_bill);
    printf("input id_product: ");
    cin >> inB.detailP.id;
    cin.ignore();
    if(inB.detailP.id!=0){
        printf("input amount: ");
        cin >> inB.amount;
        cin.ignore();
        bills.push_back(inB);
    }
    }while(inB.detailP.id!=0);
    vector<bill> bill_insert;
    for(int i=0; i<bills.size(); i++){
        int index = linear_bill(bill_insert, bills[i].detailP.id);
        if(index==-1){
            //cout << "true" <<endl;
            bill_insert.push_back(bills[i]);
        }else{
            //cout << "F" <<endl;
            bill_insert[index].amount = bill_insert[index].amount+bills[i].amount;
        }
    }
    bills.clear();
    for(int i=0; i<bill_insert.size(); i++){
        insertBill(inB.id_bill, bill_insert[i].detailP.id, bill_insert[i].amount, inB.date.c_str());
        system("start connect.bat");
        delay(500);
    }
}

void showBill(int cmd, string datetime = ""){
    vector<bill> bill_vec = useOutputBill(cmd, datetime);
    for(int i=0; i<bill_vec.size(); i++){
        printf("\t\t\tdate and time : %s \tshow detail Enter : %d\n", bill_vec[i].date.c_str(),i);
        printf("\t\t\t------------------------------------------------------------\n");
    }
    if(bill_vec.empty()){
        printf("Not found...\n");
    }else{
        //delete &bill_vec;
        int num;
        printf("Enter number -1 for end : ");
        cin >> num;
        cin.ignore();
        if(num!=-1){
        vector<bill> bill_detail = useOutputBill_detail(bill_vec[num].date.c_str());
        if(num!=-1&&!bill_detail.empty()){
            bill_vec.clear();
            printf("\t\t\tdate and time : %s \t id_bill : %d\n", bill_detail[0].date.c_str(), bill_detail[0].id_bill);
            printf("\t\t\t-----------------------------------------------------------------------\n");
            int total=0;
            for(int i=0; i < bill_detail.size(); i++){
                total+=bill_detail[i].detailP.price * bill_detail[i].amount;
                printf("\t\t\tname : %10s \tprice : %d \tamount : %d \tcalPrice : %d\n",bill_detail[i].detailP.name.c_str(), bill_detail[i].detailP.price, bill_detail[i].amount, bill_detail[i].detailP.price * bill_detail[i].amount);
            }
                printf("\t\t\t-----------------------------------------------------------------------\n");
                printf("\t\t\ttotal : %d\n", total);
            printf("want delete (Y/N) : ");
            char yesno;
            cin >> yesno;
            if(yesno=='y' || yesno=='Y'){
                delBill(bill_detail[0].date.c_str());
                printf("delete complete...\n");
            }
            bill_detail.clear();
        }else if(bill_detail.empty()){
            printf("Not found...\n");
        }
    }
    }
}

void useGetdatachart_bar(short int cmd, const char *date){
    vector<bill> data = getdataChart(cmd, date);
    delay(500);
    if(data.size()>0){
    FILE *name_File;
    name_File = fopen("chart.html","w");
    fprintf(name_File, "<html><head>");
    fprintf(name_File, "<script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>");
    fprintf(name_File, "<script type=\"text/javascript\">");
    fprintf(name_File, "google.charts.load('current', {'packages':['bar']});");
    fprintf(name_File, "google.charts.setOnLoadCallback(drawChart);");

    fprintf(name_File, "function drawChart() {");
    fprintf(name_File, "var data = google.visualization.arrayToDataTable([");
    //fprintf(name_File, "['Product', 'sumBill', 'sumAmount', 'sumPrice'],");
    fprintf(name_File, "['Product', 'sumPrice'],");
    /*for(int i=0; i<data.size(); i++){
        if(i!=data.size()-1){
            fprintf(name_File, "['%s',%d,%d,%d],", data[i].detailP.name.c_str(), data[i].detailP.id, data[i].amount, data[i].detailP.price);
        }else{
            fprintf(name_File, "['%s',%d,%d,%d]", data[i].detailP.name.c_str(), data[i].detailP.id, data[i].amount, data[i].detailP.price);
        }
    }*/
    for(int i=0; i<data.size(); i++){
        if(i!=data.size()-1){
            fprintf(name_File, "['%s',%d],", data[i].detailP.name.c_str(), data[i].detailP.price);
        }else{
            fprintf(name_File, "['%s',%d]", data[i].detailP.name.c_str(), data[i].detailP.price);
        }
    }
    fprintf(name_File, "]);");
    fprintf(name_File, "var options = { chart: { title: 'Amount Product Sales',");
    fprintf(name_File, "subtitle: 'sumPrice: ',},");
    fprintf(name_File, "bars: 'horizontal'}; // Required for Material Bar Charts.\n");
    fprintf(name_File, "var chart = new google.charts.Bar(document.getElementById('barchart_material'));");
    fprintf(name_File, "chart.draw(data, google.charts.Bar.convertOptions(options));}");
    fprintf(name_File, "</script></head><body>");
    fprintf(name_File, "<div id=\"barchart_material\" style=\"width: 1024px; height: 576px;\">");
    fprintf(name_File, "</div></body></html>");

    fclose(name_File);
    delay(500);
    system("start chart.html");
    }else{
        printf("Not Found....\n");
    }
    //delay(1000);
}
