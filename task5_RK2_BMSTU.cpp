
#include <iostream>
#include <string>
using namespace std;

class BankAccount { 
private: 
    int accountNumber; 
    string ownerName; 
    float balance; 
    
protected:
	    float getter(){
    	return balance;
	}

public: 
    BankAccount(int num, string name, float initialBalance) { 
        accountNumber = num; 
        ownerName = name; 
        balance = initialBalance; 
    } 
    


    void deposit(float amount) { 
        if (amount > 0) { 
            balance += amount; 
            cout << "��������� ��: " << amount << endl; 
        } else { 
            cout << "�� ������ ����� ���������� ." << endl; 
        }
    } 

    void withdraw(float amount) { 
        if (amount > 0 && amount <= balance) { 
            balance -= amount; 
            cout << "����� �� �����: " << amount << endl; 
        } else if (amount > balance) { 
            cout << "������������ �������." << endl; 
        } else { 
            cout << "�� ������ ����� ������." << endl; 
        } 
    }

    void showBalance() const { 
        cout << "������� ������: " << balance << endl; 
    } 
}; 
class SavingAccount : public BankAccount{
	private:
		float balance_s;
		int procents;
		int years;
		
    public:
    	
    SavingAccount(int procents_1, int num, string name, float initialBalance)
        : BankAccount(num, name, initialBalance), procents(procents_1) {
        balance_s = getter(); 
    } 
    
    void stavka(int year){
    	balance_s = getter();
    	int years = year;
    	for(int i = 0; i < years; i++){
    		balance_s += ((balance_s/100)*procents);
		}
	}
	
	void bal_with_proc(){
		cout<<"��� ������ ����� ���������� ���������" << balance_s << endl;
	    
	}
	
	void new_stawka(){
		cout<<"������� ����� ��������� ������"<<endl;
		cin>>procents;
		
	}
    
};
int main() { 
    setlocale(LC_ALL, "rus"); 

    int accountNum; 
    string ownerName; 
    float initialBalance; 
    int procents;
    
    
    cout << "������ ����� �����: "; 
    cin >> accountNum; 

    cout << "��� ���: "; 
    cin >> ownerName; 

    cout << "������� ��������� ������: "; 
    cin >> initialBalance; 

    cout << "������� ���������� ������: ";
    cin >> procents;
    

    SavingAccount myAccount(procents, accountNum, ownerName, initialBalance);
    int vibor;
    float depositAmount;
    float withdrawAmount; 
    int years;
    do{
        cout<<"1: ��������� ������"<<endl;
        cout<<"2: ����� ������ �� �����"<<endl;
        cout<<"3: ���������� ������"<<endl;
        cout<<"4: ��������� ��������"<<endl;
        cout<<"5: �������� ������"<<endl;
        	
		
		cin>>vibor;
		switch(vibor){
			case 1:
				cout << "������� ������ ����: "<<endl; 
                cin >> depositAmount; 
                myAccount.deposit(depositAmount); 
                break;
                
			case 2:
				cout << "������� ����� ��� ������ : "<<endl; 
                cin >> withdrawAmount; 
                myAccount.withdraw(withdrawAmount); 
                break;
			
			case 3:
				myAccount.showBalance(); 
				break;
			case 4:
				cout<<"������� ���������� ��� ��� ������"<<endl;
				cin>>years;
				myAccount.stavka(years);
				myAccount.bal_with_proc();
				
				break;
			
			case 5:
				myAccount.new_stawka();
				
		    default:
		    	cout<<"�������� ������ ��������"<<endl;
				
			
		}
	}while(vibor != 0);


     
    

    return 0; 
}



