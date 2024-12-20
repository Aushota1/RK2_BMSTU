
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
            cout << "пополнено на:  " << amount << endl; 
        } else { 
            cout << "не верная сумма пополнения" << endl; 
        }
    } 

    void withdraw(float amount) { 
        if (amount > 0 && amount <= balance) { 
            balance -= amount; 
            cout << "Снято со счета: " << amount << endl; 
        } else if (amount > balance) { 
            cout << "Недостаточно средств." << endl; 
        } else { 
            cout << "неверная сумма снятия." << endl; 
        } 
    }

    void showBalance() const { 
        cout << "Текущий баланс: " << balance << endl; 
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
		cout<<"ваш баланс после начисления процентов" << balance_s << endl;
	    
	}
	
	void new_stawka(){
		cout<<"введите новую процентную ставку"<<endl;
		cin>>procents;
		
	}
    
};
int main() { 
    setlocale(LC_ALL, "rus"); 

    int accountNum; 
    string ownerName; 
    float initialBalance; 
    int procents;
    
    
    cout << "Введите номер счета: "; 
    cin >> accountNum; 

    cout << "Введите имя: "; 
    cin >> ownerName; 

    cout << "Введите начальный баланс: "; 
    cin >> initialBalance; 

    cout << "Введите процентную ставку: ";
    cin >> procents;
    

    SavingAccount myAccount(procents, accountNum, ownerName, initialBalance);
    int vibor;
    float depositAmount;
    float withdrawAmount; 
    int years;
    do{
        cout<<"1: пополнить баланс"<<endl;
        cout<<"2: снять деньги со счета"<<endl;
        cout<<"3: посмотреть баланс"<<endl;
        cout<<"4: начислить проценты"<<endl;
        cout<<"5: обновить стаку"<<endl;
        	
		
		cin>>vibor;
		switch(vibor){
			case 1:
				cout << "Введите размер депа: "<<endl; 
                cin >> depositAmount; 
                myAccount.deposit(depositAmount); 
                break;
                
			case 2:
				cout << "Введите сумму для снятия: "<<endl; 
                cin >> withdrawAmount; 
                myAccount.withdraw(withdrawAmount); 
                break;
			
			case 3:
				myAccount.showBalance(); 
				break;
			case 4:
				cout<<"Введите количество лет для вклада"<<endl;
				cin>>years;
				myAccount.stavka(years);
				myAccount.bal_with_proc();
				
				break;
			
			case 5:
				myAccount.new_stawka();
				
		    default:
		    	cout<<"попробуй другой вариант"<<endl;
				
			
		}
	}while(vibor != 0);


     
    

    return 0; 
}

