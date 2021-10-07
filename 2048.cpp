#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class play{
    
	int g[4][4];
	int g_copy[4][4];
	void initialize();
	void display();
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	int check_full();
	int random_index(int x);
	void sum_up();
	void sum_down();
	void sum_left();
	void sum_right();
	void generate_new_index();
	int calculate_max();
	void instructions();
	int game_ends();
	void end_display();
	void win_display();
	void lose_display();

	public:
	void play_game();
	play(){
	}
};

void play :: instructions(){
	cout<<"\nInstructions for playing 2048 are:: \n"<<endl;
	cout<<"For moving tiles enter \nw-move up/na-move left\nd-move right\ns-move down\n"<<endl;
	cout<<"When two tiles with same number touch, they merge into one. \nWhen 2048 is created, the player wins!\n"<<endl;
	display();
}

int play :: random_index(int x){
	int index;
	index=rand()%x + 0;
	return index;
}

void play :: lose_display(){
	system("clear");
	cout<<"\t\t\tGAME OVER\n\n";
	cout<<"Thanks for trying!!!\n\n";
	exit(0);
}

int play :: check_full(){
	int full_flag=1;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(g[i][j]==0){
				full_flag=0;
				break;
			}
		}
	}
	return full_flag;
}

void play :: win_display(){
	char ch;
	cout<<"\t\t\tYOU WON!!!\n\n";
	cout<<"Do you wish to continue???\n";
	cout<<"Enter y to continue and n to quit\n\n";
	cin>>ch;
	if(ch=='n'){
		end_display();
	}
}

int play :: calculate_max(){
	int i,j;
	int max=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(g[i][j]>max){
				max=g[i][j];
			}
		}
	}
	return max;
}

void play :: end_display(){
	system("clear");
	cout<<"Thanks for trying!!!\n\n";
	cout<<"Good Bye!!!\n"<<endl;
	exit(0);
}

int play :: game_ends(){
	int i,j,flag=1;
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			if(g[i][j]==g[i][j+1]){
				flag=0;
				break;
			}
		}
		if(flag==0){
				break;
		}
	}
	if(flag==1){
		for(i=0;i<3;i++){
			for(j=0;j<4;j++){
				if(g[i][j]==g[i+1][j]){
					flag=0;
					break;
				}
			}
			if(flag==0){
				break;
			}
		}
	}
	return flag;
}


void play :: generate_new_index(){
	int flag=1;
	if(!check_full()){
		while(flag){
			int i=random_index(4);
			int j=random_index(4);
			if(g[i][j]==0){
				int y=rand()%10+0;
				if(y<6){
					g[i][j]=2;
				}else{
					g[i][j]=4;
				}
				flag=0;
			}
		}
	}
}

void play :: initialize(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			g[i][j]=0;
			g_copy[i][j]=0;
		}
	}
	int i=random_index(4);
	int j=random_index(4);
	g[i][j]=2;
	i=random_index(4);
	j=random_index(4);
	g[i][j]=2;
	display();
}


void play :: move_up(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!g[j][i]){
				for(int k=j+1;k<4;k++){
					if(g[k][i]){
						g[j][i]=g[k][i];
						g[k][i]=0;
						break;
					}
				}
			}
		}
	}
}

void play :: move_down(){
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!g[j][i]){
				for(int k=j-1;k>=0;k--){
					if(g[k][i]){
						g[j][i]=g[k][i];
						g[k][i]=0;
						break;
					}
				}
            }
        }
    }
}

void play :: move_left(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(!g[i][j]){
				for(int k=j+1;k<4;k++){
					if(g[i][k]){
						g[i][j]=g[i][k];
						g[i][k]=0;
						break;
					}
				}
			}
		}
	}
}

void play :: move_right(){
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(!g[i][j]){
				for(int k=j-1;k>=0;k--){
					if(g[i][k]){
						g[i][j]=g[i][k];
						g[i][k]=0;
						break;
					}
				}
			}
		}
	}
}

void play :: sum_up(){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(g[j][i] && g[j][i]==g[j+1][i]){
				g[j][i]=g[j][i] + g[j+1][i];
				g[j+1][i]=0;
			}
		}
	}
}

void play :: sum_down(){
	for(int i=0;i<4;i++){
		for(int j=3;j>0;j--){
			if(g[j][i] && g[j][i]==g[j-1][i]){
				g[j][i]=g[j][i] + g[j-1][i];
				g[j-1][i]=0;
			}
		}
	}
}

void play :: sum_left(){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(g[i][j] && g[i][j]==g[i][j+1]){
				g[i][j]=g[i][j] + g[i][j+1];
				g[i][j+1]=0;
			}
		}
	}
}

void play :: sum_right(){
	for(int i=0;i<4;i++){
		for(int j=3;j>0;j--){
			if(g[i][j] && g[i][j]==g[i][j-1]){
				g[i][j]=g[i][j] + g[i][j-1];
				g[i][j-1]=0;
			}
		}
	}
}

/*
	* function to take choice from user
	* and call functions accordingly
*/
void play :: play_game(){
	int flag=0;
	char choice,ch;
	initialize();
	cin>>choice;

	while((choice=='w' || choice=='a' || choice=='s' || choice=='d' || choice=='q' || choice=='i')){
		//make copy of previous move before updating the current matrix to g_copy

	switch(choice){
		//move up
		case 'w':
			move_up();
			sum_up();
			move_up();
			generate_new_index();
			system("clear");
			display();
			break;
		//move down
		case 's':
			move_down();
			sum_down();
			move_down();
			generate_new_index();
			system("clear");
			display();
			break;
		//move left
		case 'a':
			move_left();
			sum_left();
			move_left();
			generate_new_index();
			system("clear");
			display();
			break;
		//move right
		case 'd':
			move_right();
			sum_right();
			move_right();
			generate_new_index();
			system("clear");
			display();
			break;
		//quit
		case 'q':
			cout<<"Are you sure you want to quit??\nEnter y to quit and n to continue!\n"<<endl;
			cin>>ch;
			if(ch=='y' || ch == 'Y'){
				end_display();
			}
			display();
			break;
		//display instructions
		case 'i':
			instructions();
			break;
		//undo move
		
	}
	//check if any block of matrix reached to value = 2048
	int find_max=calculate_max();
	if(find_max==2048){
		win_display();
	}

		if(check_full()){
			if(game_ends()){
				lose_display();
			}
		}
		cout<<"enter choice: "<<endl;
		cin>>choice;
		while(choice!='w'  && choice!='s'  && choice!='d'  && choice!='a' && choice!='q' && choice!='i'){
			cout<<"\nYou had entered the wrong choice!\nPlease enter correct choice to continue!"<<endl;
			cin>>choice;
		}
	}
}

/*
	* display function
	* called after every move
*/
void play :: display(){
	cout<<"\n\t\t\t\t\t\t\t 2048\n\n";
	for(int i=0;i<4;i++){
		cout<<"                       ";
		for(int j=0;j<4;j++){
			cout<<setw(8)<<g[i][j]<<setw(8)<<"|"<<setw(8);
		}
		cout<<endl<<endl<<endl;
	}
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\n\tw\t\t\t\t^\t\t\t\ti-instructions\na\ts\td\t\t<\t"<<"v"<<"\t>\t\t\tq-quit\n\n";
}

int main(){
	play p;
	srand(time(NULL));
	p.play_game();
	return 0;
}