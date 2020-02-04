#include<iostream>
#include<string>

void box_disp(std::string* arr){
	// Display the tic_tac_toe box
	// Input array has three strings showing the location and if it is occupied or not
	for(int i=0; i<3; i++){
		std::string str = arr[i];
		std::cout<<str[0] << '|' << str[1] <<'|' <<str[2]<<'\n';	
		std::cout<<"______"<<'\n';
	}
	
}

bool checkP1Char(char val){
	if(val == 'X' || val == 'O' || val == 'x' || val == 'o'){
		return true;
	}

	return false;
}

char choose_p1_char(){
	// Choose Player 1 charecter
	char val;
	int tmp;
	std::cout<<"Player1 Choose your charecter: O or X\n";
	std::cin>>val;
	
	while(!checkP1Char(val)){
		std::cout<<"Invalid Input, Enter Again"<<'\n';
		std::cin>>val;
	}

	tmp = static_cast<int>(val);

	if(tmp == 111 || tmp == 120){
		tmp = tmp - 32;
		val = static_cast<char>(tmp);
	}

	return val;
}

bool checkBox(std::string* arr){
	// Check the box for victory
	for(int i = 0; i<3; i++){
		if(arr[i] == "XXX" || arr[i] == "OOO"){
			
			return true;

		} else if(arr[0][i] == 'X'){
			
			bool x_val = (arr[1][i]=='X') && (arr[2][i] == 'X');
			
			if(x_val){
				return true;
			}

		} else if(arr[0][i] == 'O'){
			
			bool o_val = (arr[1][i] == 'O') && (arr[2][i]=='O');

			if(o_val){
                                return true;
                        }

		}
	}

	if(arr[0][0] == 'X'){
		bool x_val = (arr[1][1] == 'X') && (arr[2][2] == 'X');
		
		if(x_val){
			return true;
		}
	} else if(arr[0][0] == 'O'){
                bool o_val = (arr[2][2] == 'O') && (arr[1][1] == 'O');

                if(o_val){
                        return true;
                }

	} 
	
	if(arr[0][2] == 'X'){
        	bool x_val = (arr[1][1] == 'X') && (arr[2][0] == 'X');

                if(x_val){
                        return true;
                }

        } else if(arr[0][2] == 'O'){
                bool o_val = (arr[2][0] == 'O') && (arr[1][1] == 'O');

                if(o_val){
                        return true;
                }

        }


}

bool checkPos(std::string str, int pos){
	// Chek if entered pos is valid
	if(str[pos] == 'X' || str[pos] == 'O'){
		return false;
	}

	return true;
}
	
void takeTurn(std::string* arr, char ch){
	//Take turn 
	std::string str = arr[0] + arr[1] + arr[2];
	std::cout<<"Available positions: ";
	std::cout<<str;
/*	for(int i=0 ; i<9; i++){
		if((static_cast<int>(str[i])>=30) && ((static_cast<int>(str[i]))) <= 39 ){
			std::cout<<arr[i] << " ";
		}
	}*/

	std::cout<<'\n';

	int pos {};
	std::cin>>pos;
	pos -= 1;
	
	while(!checkPos(str, pos)){
		std::cout<<"Invalid entry, Enter again"<<'\n';
		std::cin >>pos;
		pos -= 1;
	}

	if(pos<3){
		arr[0][pos] = ch;
	} else if(pos < 6){
		arr[1][pos%3] = ch;
	} else {
		arr[2][pos%3] = ch;
	}

}


int main(){
	// Driver code
	char p1Char = choose_p1_char();
	char p2Char = (p1Char == ('X') ? 'O':'X');
	
	std::cout<<p1Char<<"    "<<p2Char<<"\n";

	std::string arr[3] = { "123",
			       "456",
		               "789"
			};

	box_disp(arr);

	bool gameOver = false;

	int P1 = 1;
	int P2 = 0;
	while(!gameOver){
		if(P1^P2){
			std::cout<<"Player1 turn\n";
			takeTurn(arr, p1Char);
			box_disp(arr);
			P2 = 1;
			gameOver = checkBox(arr);
		}else {
			std::cout<<"Player2 turn\n";
			takeTurn(arr, p2Char);
			box_disp(arr);
			P2 = 0;
			gameOver = checkBox(arr);
		}
	

	}

	if(P2){
		std::cout<<"PLAYER ONE WINS"<<'\n';
	} else {
		std::cout<<"PLAYER TWO WINS"<<'\n';
	}

	return 0;
}
