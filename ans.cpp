//░░░░░░░░░░▄
//░░░░░░░░▄▐░▄▄█████▄▄
//░░░░░░▄█████████████▄▀▄▄░▄▄▄
//░░░░░█████████████████▄██████
//░░░░████▐█████▌████████▌█████▌
//░░░████▌█████▌█░████████▐▀██▀
//░▄█████░█████▌░█░▀██████▌█▄▄▀▄
//░▌███▌█░▐███▌▌░░▄▄░▌█▌███▐███░▀
//▐░▐██░░▄▄▐▀█░░░▐▄█▀▌█▐███▐█
//░░███░▌▄█▌░░▀░░▀██░░▀██████▌
//░░░▀█▌▀██▀░▄░░░░░░░░░███▐███
//░░░░██▌░░░░░░░░░░░░░▐███████▌
//░░░░███░░░░░▀█▀░░░░░▐██▐███▀▌
//░░░░▌█▌█▄░░░░░░░░░▄▄████▀░▀
//░░░░░░█▀██▄▄▄░▄▄▀▀▒█▀█░▀
//░░░░░░░░░▀░▀█▀▌▒▒▒░▐▄▄
//░░░░░░░░▄▄▀▀▄░░░░░░▄▀░▀▀▄▄
//░░░░░░▄▀░▄▀▄░▌░░░▄▀░░░░░░▄▀▀▄
//░░░░░▐▒▄▀▄▀░▌▀▄▄▀░░░░░░▄▀▒▒▒▐
//░░░░▐▒▒▌▀▄░░░░░▌░░░░▄▄▀▒▐▒▒▒▒▌
//░░░▐▒▒▐░▌░▀▄░░▄▀▀▄▀▀▒▌▒▐▒▒▒▒▐▐
//░░░▌▄▀░░░▄▀░█▀▒▒▒▒▀▄▒▌▐▒▒▒▒▒▌▌
//░░▄▀▒▐░▄▀░░░▌▒▐▒▐▒▒▒▌▀▒▒▒▒▒▐▒▌
#include<bits/stdc++.h>
using namespace std; 
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define mp make_pair 

int board[3][3];

bool game() {
	int lines[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
	for(auto x : lines)
		if (board[x[0]/3][x[0]%3]!=0 and board[x[0]/3][x[0]%3] == board[x[1]/3][x[1]%3] and board[x[0]/3][x[0]%3] == board[x[2]/3][x[2]%3])
			return false;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(board[i][j] == 0)
				return true;
	return false;
}

bool won() {
	int lines[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
	for(auto x : lines)
		if (board[x[0]/3][x[0]%3] == 1 and board[x[1]/3][x[1]%3] == 1 and board[x[2]/3][x[2]%3] == 1)
			return true;
	return false;
}

bool canwin2();

bool canwin1() {
	if(won())
		return true;
	bool flag = true;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(board[i][j] == 0) {
				board[i][j] = 1;
				flag = canwin2();
				board[i][j] = 0;
			}
	return flag;
}

bool canwin2() {
	if(won())
		return true;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(board[i][j] == 0) {
				board[i][j] = 2;
				if(canwin1())
					return true;
				board[i][j] = 0;
			}
	return false;
}

void update() {
	if(won())
		return;
	cout<<"update"<<endl;
	int temp[3][3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			temp[i][j] = board[i][j];

	bool flag = false;

	for(int i=0;i<3 and !flag;i++)
		for(int j=0;j<3;j++)
			if(board[i][j] == 0) {
				board[i][j] = 2;
				flag = canwin1();
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						board[i][j] = temp[i][j];
				if(flag) {
					temp[i][j] = 2;
					break;
				}
			}

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			board[i][j] = temp[i][j];
	return;
}

int main() {
	memset(board,0,sizeof(board));
	for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
	int x,y;
	cin>>x>>y;
	board[x][y] = 1;
	if(y == 0 and x!=1)
		board[1][2] = 2;
	else if(y == 2 and x!=1)
		board[1][0] = 2;
	else if(y == 1 and x == 0)
		board[2][2] = 2;
	else if(y == 0 and x == 1)
		board[0][2] = 2;
	else
		board[0][0] = 2;
	for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
	while(game()) {
		cin>>x>>y;
		board[x][y] = 1;
		update();
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
	}
}