echo off
cd Desktopproject_comproshop
mysql -u root -p123456 -e "select bill.id_bill, bill.id, product.name, product.price, bill.amount from shop_test.bill join shop_test.product on bill.id = product.id where bill.id_bill = 3" shop_test > output.txt
exit