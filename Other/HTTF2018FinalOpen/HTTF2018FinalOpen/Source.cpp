#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
char IDLE = '.';
char ROCK = '#';
char WARP = 'W';
class board {
public:
	static const int N = 50;
	static const int endturn = 1000;
	int score;
	vector<vector<char>> brd;
	board() {
		score = 0;
		brd = vector<vector<char>>(N, vector<char>(N));
		rep(i, N)rep(j, N)cin >> brd[i][j];
	}
};
enum commandType {
	ROAD, PLANT, HARVEST, DESTROY, GROWUP, WARPGATE, WORK
};

class command {
public:
	int x1, y1, x2, y2;
	command(int x1 = -1, int y1 = -1, int x2 = -1, int y2 = -1) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	virtual void print() = 0;
	virtual board update(board brd) = 0;


};
class road :public command {
public:
	road(int x1, int y1, int x2, int y2) :command(x1, y1, x2, y2) {}
	void print() {
		printf("road %d %d %d %d\n", x1, y1, x2, y2);
	}

	board update(board brd) {
		return board();

	}
};

class plant :public command {
public:
	plant(int x1, int y1, int x2, int y2) :command(x1, y1, x2, y2) {}

	void print() {
		printf("plant %d %d\n", x1, y1);
	}


	board update(board brd) {

		return board();

	}
};

class harvest :public command {
public:
	harvest(int x1, int y1, int x2, int y2) :command(x1, y1, x2, y2) {}

	void print() {
		printf("harvest %d %d %d %d\n", x1, y1, x2, y2);
	}


	board update(board brd) {

		return board();

	}
};

class destroy :public command {
public:
	destroy(int x1, int y1, int x2, int y2) :command(x1, y1, x2, y2) {}

	void print() {
		printf("destroy %d %d %d %d\n", x1, y1, x2, y2);
	}


	board update(board brd) {


		return board();
	}
};
class growup :public command {
public:
	growup(int x1, int y1, int x2, int y2) :command(x1, y1, x2, y2) {}

	void print() {
		printf("growup %d\n", x1);
	}


	board update(board brd) {


		return board();
	}
};
class warpgate :public command {
public:
	warpgate(int x1, int y1, int x2, int y2) :command(x1, y1, x2, y2) {}

	void print() {
		printf("warpgate %d %d\n", x1, y1);
	}


	board update(board brd) {


		return board();
	}
};

class work :public command {
public:
	work(int x1, int y1, int x2, int y2) :command(x1, y1, x2, y2) {}

	void print() {
		printf("work\n");
	}


	board update(board brd) {

		return board();
	}
};

command *commandGen(commandType cmd, int x1 = -1, int y1 = -1, int x2 = -1, int y2 = -1) {
	switch (cmd) {
	case commandType::ROAD:
		return new road(x1, y1, x2, y2);
		break;
	case commandType::PLANT:
		return new plant(x1, y1, x2, y2);
		break;
	case commandType::HARVEST:
		return new harvest(x1, y1, x2, y2);
		break;
	case commandType::DESTROY:
		return new destroy(x1, y1, x2, y2);
		break;
	case commandType::GROWUP:
		return new growup(x1, y1, x2, y2);
		break;
	case commandType::WARPGATE:
		return new warpgate(x1, y1, x2, y2);
		break;
	case commandType::WORK:
		return new work(x1, y1, x2, y2);
		break;
	}
}

int main() {
	board brd;
	vector<command*>cmd(board::endturn, commandGen(WORK));
	rep(i, board::endturn) cmd[i]->print();

	return 0;
}



