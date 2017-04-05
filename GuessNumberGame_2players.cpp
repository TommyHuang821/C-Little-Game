#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
using namespace std;

int main (int argc, char **argv){
	
	srand(time(NULL)); // 加這行才會每次執行亂數都隨機抓，不然都會只抓到第一次執行的亂數 
	// Computer答案 
	int ans_computer=rand()%100+1; //computer answer
	int i=1; // while loop counter
	int guess=0; // initial guess 
	int BoundLow=0, BoundUP=99;
	int player=1; // subject code
	
	
	while (guess!=ans_computer){
	
		//看現在是 player 1 or 2
		if (i%2) {player=1;}
		else {player=2;}
		
		//輸入值
		cout << "\nP" << player << " enter the number (" <<BoundLow<< "~" <<BoundUP<< "): ";	 
		cin >> guess;
		
		//認輸則結束
		if (guess==-1){  
			if (player==1){player=2;}
			else if (player==2){player=1;}
			cout<< "P" << player <<" Win!";
			break;		
		}
		//如果輸入值不在範圍內 
		else if (guess<BoundLow || (guess>BoundUP)){ 
			cout<< "Guess value doesn't between the range (" <<BoundLow<< "~" <<BoundUP<< "). "<<
			"\nP" << player << " please re-answer the guess"<<endl;
		}
		// 輸入值在範圍內 
		else{
			i++;
			// 答對了 
			if (guess==ans_computer){
				cout<< "P" << player <<" Win!";
				break;
			}
			//猜的值太大 
			else if (guess > ans_computer){
				cout<< "Too large!"<<endl;
				BoundUP=guess-1;
			}
			//猜的值太小 
			else if (guess < ans_computer){
				cout<< "Too small!"<<endl;
				BoundLow=guess+1;
			}	
		}									
 	}	
	//cout<<ans_computer;
	return 0;
}

