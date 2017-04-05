#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cmath>
#define LEN 4
using namespace std;
/* random generate a 4 distinct-digit number */
void generateAnswer(int answer[]){
	for (int i=0; i<LEN; i++){ 
		do{ 
			answer[i]=rand()%10; 
			for (int j=0; j<i; j++){ 
				if (answer[i]==answer[j]) { 
					answer[i]=0; 
					break; 
				} 
			} 
		}
		while(answer[i]==0); 
	} 
}

/* calculate how much a and b are
* think why passing by reference instead of by value */
void calNaNb(int answer[], int guess[], int &a, int &b){
	for (int i=0; i<LEN; i++){ 
		for (int j=0; j<LEN; j++){ 
			if ((i==j)&&(answer[i]==guess[j]))
				a++;
			else if ((i!=j) && (answer[i]==guess[j]))
				b++;
		}
	}
}

int main(int argc, char**argv){
	int answer[LEN], num, a = 0, b = 0;
	srand(time(NULL));
	generateAnswer(answer);
	cout<<answer[0]<<answer[1]<<answer[2]<<answer[3]<<endl;
	
	//cout<<"answer:"<<answer[0]<<answer[1]<<answer[2]<<answer[3]<<endl;
	do {
		a = b = 0; //每次都要重算幾a幾b 
		cout<< "Please enter a "<< LEN <<"-digit integer: ";
		cin>> num; //輸入 
		
		int guess[LEN], abc;
		int degree=0, tempv=0;
		for (int i=0;i<LEN;i++){
				degree=(LEN-i-1);	
				tempv=(num/pow(10,degree));
				guess[i] = tempv%10;
		}
		
			//{(num/1000)%10,(num/100)%10,(num/10)%10,num%10}; // 判斷輸入分別是哪四個數字		
		calNaNb(answer, guess, a, b); //得到幾a幾b 
		cout<< a << 'a' << b << 'b' << endl;
	} while(a != LEN); //當a 不等於4就繼續做do while 
	
	cout<< "You win! The answer is ";
	for(int i= 0; i< LEN; i++) cout<< answer[i];
	cout<< '.'<< endl;
	
	return 0;
}
