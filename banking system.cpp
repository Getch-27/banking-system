#include <iostream>
using namespace std;

// Class to store contact
// details
class node {
	long int account_number,mob_number;
	double balance=0;
    string name,address,email;


public:
	node()
	{

		account_number = 0;
	}
	friend class hashing;
};

class hashing {
	node account[20];
	string name ;
	string address;
	long int mobile;
	string email;
	int key, table_index;

public:
    //hashing constructor.
	hashing()
	{
		key = 0;

	}
	void open_new_account(int size)
	{
		// Enter fltkey


		// Enter Name


		// Enter destephone number
        cout<<"WELCOME TO OUR BANCK"<<endl;
		cout<<"ENTER THE DESIRED ACCOUNT NUMBER :";
        cin>>key;
        cout<<"YOUR NAME PLEASE :";
        cin.ignore();
		getline(cin,name);
		cout<<"YOUR ADDRESS :";
	    getline(cin,address);
		cout<<"YOUR MOBILE NUMBER :";
		cin>>mobile;
		cout<<"ENTER YOUR VALID EMAIL ID :"<<endl;
		cin>>email;
		cout<<"AS A NEW SUBSCRIBER YOUR MUST PAY 50 BIRR OR YOU CAN ADD MORE"<<endl;


		 table_index = key % size;

		// Inserting record using linear
		// probing in case of collision
		for (int j = 0; j < size; j++) {
			if (account[table_index].account_number == 0) {
				account[table_index].account_number = key;
				account[table_index].name = name;
				account[table_index].address = address;
				account[table_index].balance +=50.0;
				account[table_index].mob_number = mobile;
				account[table_index].email = email;
				cout<<"Dear coustomer your current balace is "<<account[table_index].balance<<"Birr"<<endl;
                cout<<"Tank you for choosing us...."<<endl;
				break;
			}
			else
				table_index = (table_index + 1) % size;
		}
		continue_page();
	}

	// This method takes the key of
	// the record to be searched.
	// Then, it traverses the hash
	// table, if record fltkey matches
	// with the key it displays the
	// record detail.
	void account_info(int size)
	{
		int table_index, key, flag = 0;

		cout << " please Enter your Account number : ";
        cin>>key;
		 table_index = key % size;

		// Traversing the directory
		// linearly inorder to search
		// record detail
		for (int i = 0; i < size; i++) {
			if (account[table_index].account_number == key) {
				flag = 1;
				cout<<"This is your information"<<endl;
                cout<<"ACCOUNT NUMBER : "<< account[table_index].account_number<<endl;
                cout<<"NAME : "<< account[table_index].name<<endl;
                cout<<"CURRENT BALANCE : "<<account[table_index].balance<<endl;
                cout<<"ADDRESS : "<< account[table_index].address<<endl;
				cout<<"PHONE NUMBER : "<<account[table_index].mob_number<<endl;
				cout<<"EMAIL : "<<account[table_index].email<<endl;
				break;
			}
			else{

				table_index= (table_index + 1) % size;
		}}
		if (flag == 0)
			cout << "YOUR INFORMATION IS NOT FOUND"<<endl;
continue_page();
	}

	// This method takes the key
	// of the record to be deleted.
	// Then, it searches in hash
	// table if record fltkey matches
	// with the key. Then, that
	// record is deleted.
	void unsubscribe(int size)
	{
		int table_index, key, flag = 0;

            cout << " please Enter your Account number : ";
            cin>> key;
		    table_index = key % size;
		// Traversing the directory
		// linearly inorder to delete
		// the record detail
		for (int i = 0; i < size; i++) {
			if (account[table_index].account_number== key) {
				flag = 1;
				account[table_index].account_number = 0;
				account[table_index].name = " ";
				account[table_index].account_number = 0;
				account[table_index].name =" ";
				account[table_index].address =" ";
				account[table_index].mob_number = 0;
				account[table_index].email = " ";


				cout << "you are unsubscribed successfully";
				break;
			}
			else
				table_index = (table_index + 1) % size;
		}
		if (flag == 0)
        cout << "\nRecord";
		cout << " not found";
		continue_page();
	}
void withdraw(int size){
       int table_index, key, flag = 0;
       double money;

		cout << " please Enter your Account number : ";
        cin>>key;
		 table_index = key % size;

		// Traversing the directory
		// linearly inorder to search
		// record detail
		for (int i = 0; i < size; i++) {
			if (account[table_index].account_number == key) {
				flag = 1;
				cout<<"This is your information"<<endl;
                cout<< account[table_index].account_number;
                cout<< account[table_index].name;
                cout<<"How much many do you want to witdrow ?";
                cin>>money;
                if(account[table_index].balance >money){
                    account[table_index].balance -= money;
                    cout<<"Dear coustomer your current balace is "<<account[table_index].balance<<"Birr"<<endl;
                    cout<<"Tank you for using our service"<<endl;
                }
                else{
                    cout<<"Your account balance is insufficient "<<endl;
                }
				break;
			}
			else{
				table_index= (table_index + 1) % size;
		}}
		if (flag == 0)
			cout << "\nRecord not found"<<endl;
continue_page();
	}


void Deposit(int size){
int table_index, key, flag = 0;
       double money;

		cout << " please Enter your Account number : ";
        cin>>key;
		 table_index = key % size;

		// Traversing the directory
		// linearly inorder to search
		// record detail
		for (int i = 0; i < size; i++) {
			if (account[table_index].account_number == key) {
				flag = 1;
				cout<<"This is your information"<<endl;
                cout<< "ACCOUNT NUMBER :"<<account[table_index].account_number;
                cout<<"NAME : "<< account[table_index].name<<endl;
                cout<<"BALANCE : "<<account[table_index].balance<<endl;
                cout<<"How much many do you want to Deposit  ?";
                cin>>money;

                    account[table_index].balance += money;
                    cout<<"Dear coustomer your current balace is "<<account[table_index].balance<<"Birr"<<endl;
                    cout<<"Tank you for using our service"<<endl;

				break;
			}
			else{
				table_index= (table_index + 1) % size;
		       }
		}
		if (flag == 0)
			cout << "\nRecord not found"<<endl;
continue_page();
	}

//works only if the destination account is on the table
void transfer(int size){
    //index users
    //userendex destination
    //key user account num
    //account_no_des destination account
    int index,userIndex, key, flag1 = 0 ,flag2=0 ,account_no_des;
    double money;
    cout << " please Enter your Account number : ";
    cin>>key;
    index = key % size;
     for (int i = 0; i < size; i++) {
			if (account[index].account_number == key) {
				flag1 = 1;
				cout<<"This is your information"<<endl;
                cout<< "ACCOUNT NUMBER :"<<account[index].account_number<<endl;
                cout<<"NAME : "<< account[index].name<<endl;
                cout<<"BALANCE : "<<account[index].balance<<endl;
                cout<<"Enter account number of destination ";
                cin>>account_no_des;
                       for (int i = 0; i < size; i++) {
			                      if (account[userIndex].account_number == account_no_des) {
                                         flag2 = 1;
                                         cout<<"users  information"<<endl;
                                         cout<< "ACCOUNT NUMBER :"<<account[userIndex].account_number<<endl;
                                         cout<<"NAME : "<< account[userIndex].name<<endl;
                                         cout<<"How much money do you want to transfer  ?";
                                         cin>>money;
                                         if(account[index].balance > money){
                                              account[index].balance -= money;//DECREASE CURRENT USER AMOUNT
                                              account[userIndex].balance+=money;//INCRASE DEST AMOUNT

                                              cout<<"Dear coustomer transfered" <<money <<"Birr to "<<account[userIndex].name<<endl;
                                              cout<<" your current balance is "<<account[index].balance<<"Birr"<<endl;
                                               cout<<"Tank you for using our service"<<endl;
                                               break;
                                             }
                                              else{
                                                   cout<<"Your account balance is insufficient "<<endl;
                                                   }
				                                    break;

                                        }
                                         else{
                                            userIndex= (userIndex + 1) % size;
                                         }

                       }
                        if (flag2 == 0)
			            cout << "DESTINATION IS NOT FOUND"<<endl;
			            break;

			    }
			 else{
                   index= (index + 1) % size;
                  }
     }
     if (flag1 == 0)
     cout << "\nRecord not found"<<endl;
     continue_page();
}




void continue_page(){
    string x;
    cout<<"Enter any key to continue :";
    cin >>x;
}
};

// Driver code
int main()
{
   //size or capacity of table.
   int size=20;
   // creating object of hashing for
	hashing ht;
	int c;
 while (1) {
      cout<<"PRESS 1 TO OPEN NEW ACCOUNT"<<endl;
      cout<<"PRESS 2 TO CHECK YOUR ACCOUNT INFO"<<endl;
      cout<<"PRESS 3 TO WITHDRAW AMOUNT"<<endl;
      cout<<"PRESS 4 TO DEPOSIT AMOUNT"<<endl;
      cout<<"PRESS 5 TO MONEY TRANSFER"<<endl;
      cout<<"PRESS 6 TO UNSBSCRIBE "<<endl;
      cout<<"PRESS 0 logout "<<endl;
      cout<<"Enter your choice: "<<endl;
      cin>>c;
      switch(c) {
          case 1:
               ht.open_new_account(size);
               system("cls");
               break;
          case 2:
                ht.account_info(size);
                 system("cls");
                break;
          case 3:
               ht.withdraw(size);
                system("cls");
               break;
          case 4:
               ht.Deposit(size);
                system("cls");
               break;
          case 5:
               ht.transfer(size);
                system("cls");
               break;
          case 6:
              ht.unsubscribe(size);
              system("cls");
              break;
           case 0:
           exit;
           break;

         default:
            cout<<"Please Enter correct option"<<endl;
      }
   }



	return 0;
}
