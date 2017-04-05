#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
#include <stdio.h>
#include <string.h>
#include <cstdlib>  // string to number

using namespace std;

static int lower = 0, upper = 99, guess = -2;
bool turn = false;
bool mode = false;
    
int chooseMode(){
	char inputmode[1];
	char str1[]="C";
	char str2[]="c";
	bool result;
	cin>>inputmode;
	(!strcmp(inputmode,str1)||!strcmp(inputmode,str2))? result=1:result=0;//strcmp比對成功回傳0 
	return result ;
}

int whoGuess(){
	// mode : 1 - player vs computer; mode: 0 - player 1 vs player 2
	// player : 0 - player 1; player : 1 - player 2
	int guess = 0;
	if (mode & turn) { // Computer
		guess= rand()%(upper-lower+1) + lower;  
		cout << "COM enter the number (" <<lower<< "~" <<upper<< "): "<<guess<<endl;	 
	}
	else{ //player
		if (turn==0)
			cout << "P1 enter the number (" <<lower<< "~" <<upper<< "): ";	
		else if (turn==1) 
			cout << "P2 enter the number (" <<lower<< "~" <<upper<< "): ";
		cin>>guess;	
	}	
	return guess;				
}
	

void winJudge(int answerFinial){
	/* 利用guess與answerFinial關係，判斷輸贏*/
	
	if(guess == -1) {
		if (mode) { // Computer
			cout << "COM Win"<<endl;
		}
		else if (!mode && turn==0) {
				cout << "P2 Win";
		}
		else if (!mode && turn==1) {
				cout << "P1 Win";
		}
	exit(1);
	} 
	// 猜中 
	else if (guess == answerFinial) {
		if (mode & turn) { // Computer
			cout << "COM Win"<<endl;
		}
		else{
			if (turn==0)
				cout << "P1 Win";	
			else if (turn==1) 
				cout << "P2 Win";	
		}
		exit(1);
	}
	//猜的值太大
	else if (guess > answerFinial){ 
		cout<< "Too large!"<<endl;
		upper=guess-1;
	}
	//猜的值太小 
	else if (guess < answerFinial){
		cout<< "Too small!"<<endl;
		lower=guess+1;
	}	
}


int main (int argc, char **argv){
	srand(time(NULL)); // 加這行才會每次執行亂數都隨機抓，不然都會只抓到第一次執行的亂數 
	// Computer答案 
	static int answerFinial=rand()%(99-1+1)+1; //final answer, Gobal not changes
	cout<<answerFinial<<endl;
	//
	cout<<"Choose a mode (C or c: P1 vs COM, other: P1 vs P2): ";
	mode=chooseMode(); // mode(ture):player vs computer; mode(false):player 1 vs player 2
	
	
	while (guess!=answerFinial){
		//(turn)? (player=0):(player=1);
		// player(0):player 1; player(1): player 2
		guess=whoGuess();
		winJudge(answerFinial);
		turn = !turn; // 1 -> 0, 0 -> 1
	}
	return 0;
}
	

