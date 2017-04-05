#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
using namespace std;

int main (int argc, char **argv){
	
	srand(time(NULL)); // �[�o��~�|�C������üƳ��H����A���M���|�u���Ĥ@�����檺�ü� 
	// Computer���� 
	int ans_computer=rand()%100+1; //computer answer
	int i=1; // while loop counter
	int guess=0; // initial guess 
	int BoundLow=0, BoundUP=99;
	int player=1; // subject code
	
	
	while (guess!=ans_computer){
	
		//�ݲ{�b�O player 1 or 2
		if (i%2) {player=1;}
		else {player=2;}
		
		//��J��
		cout << "\nP" << player << " enter the number (" <<BoundLow<< "~" <<BoundUP<< "): ";	 
		cin >> guess;
		
		//�{��h����
		if (guess==-1){  
			if (player==1){player=2;}
			else if (player==2){player=1;}
			cout<< "P" << player <<" Win!";
			break;		
		}
		//�p�G��J�Ȥ��b�d�� 
		else if (guess<BoundLow || (guess>BoundUP)){ 
			cout<< "Guess value doesn't between the range (" <<BoundLow<< "~" <<BoundUP<< "). "<<
			"\nP" << player << " please re-answer the guess"<<endl;
		}
		// ��J�Ȧb�d�� 
		else{
			i++;
			// ����F 
			if (guess==ans_computer){
				cout<< "P" << player <<" Win!";
				break;
			}
			//�q���ȤӤj 
			else if (guess > ans_computer){
				cout<< "Too large!"<<endl;
				BoundUP=guess-1;
			}
			//�q���ȤӤp 
			else if (guess < ans_computer){
				cout<< "Too small!"<<endl;
				BoundLow=guess+1;
			}	
		}									
 	}	
	//cout<<ans_computer;
	return 0;
}

