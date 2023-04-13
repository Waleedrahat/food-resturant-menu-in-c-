#include<iostream>
#include<string>
using namespace std;
struct selected_item_info{
    int item[6];
    int quantity[6];
    int price[6];

    string name;
    double contact;
};

selected_item_info take_order(selected_item_info customer,int &i)
{
    cout<<"ENTER THE NAME OF THE CUSTOMER :"<<endl;
    cin>>customer.name;
    cout<<"ENTER THE MOBILER NUMBER OF THE CUSTOMER :"<<endl;
    cin>>customer.contact;
    char ch;
  for(i=1; i<=6; i++)
  {
    cout << "ENTER THE NUMBER OF THE ITEM YOU WANNA ORDER :" << endl;
		cin >> customer.item[i];
		
		cout << "ENTER THE QUANTITY OF THE ITEM: " << endl;
		cin >> customer.quantity[i];
		cout << "DO YOU WANT TO ORDER MORE " << endl; 
			cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			continue;
		}
		else
		{
			break;
		}

  }
  if(i>6)
  {
      cout<<"SORRY SIR YOU CAN'T ORDER MORE"<<endl;
  }
return customer;
};
void show_bill(string items[],int price[],int &i,int total_bill,  selected_item_info customer)
{
  int totalquantity=0;
 
  cout<<"_____________________________________________________________"<<endl;
   cout<<"ITEM NAME"<<"\t\t\t\t\t"<<"QUANTITY"<<"\t\t\t"<<"PRICE"<<endl;
  for(int j=1; j<=i; j++)
  {
    cout<<items[customer.item[j]]<<"\t\t\t\t"<<customer.quantity[j]<<"\t\t\t\t"<<price[customer.item[j]]*customer.quantity[j]<<endl;
    total_bill+=price[customer.item[j]]*customer.quantity[j];
    totalquantity+=customer.quantity[j];
   
  }
  double gst=(12.0/100.0)*total_bill;
  cout<<"\n\n\n\n"<<"|\t\t\t"<<"TOTAL QUANTITY :"<<totalquantity<<endl;
  cout<<"|\t\t\t"<<"TOTAL BILL\t: "<<total_bill<<endl;
  cout<<"|\t\t\t"<<"GST \t\t:"<<gst<<endl;
  cout<<"|\t\t\t"<<"TOTAL BILL :"<<total_bill+gst<<endl;
    cout<<"_____________________________________________________________"<<endl;
  
}

int main()
{

      string items[22]={"","PASTA\t\t", "CHINESE RICE ","RICE   \t\t","CHICKEN PRATHA "
     ,"CHICKEN QORMA ","PIZZA\t\t","KHEER\t\t","BIRYANI\t\t","MUTTON\t\t","ZINGER BURGER","SHAWARMA\t"
     ,"PLATER SHAWARMA","ANDA BURGER\t","SOUP\t\t","CHICKEN PLAO","CHICKEN KABAB",
     "SEIKH KABAB\t","MICRONI\t\t","CHICKEN ROLL","NOODLES\t\t"};
 int  pri[21]={250,150,100,240,1400,
         100,2200,250,200,250,90,130,500,
        450,300,560,220,122,320,200,300};
     for(int i = 1 ; i<=20; i++){
        cout<<i<<"\t\t"<<items[i]<<"\t\t\t\t"<<pri[i]<<endl;
     }
    int i;
string a;
int b[20];
int total_bill=0;
selected_item_info customer;

show_bill(items,pri,i,total_bill,  take_order(customer , i));
return 0;
}

