#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include <algorithm>
#include<initializer_list>
#include<map>
#include<set>
using namespace std;

int main() {
	vector<int>a = {1, 2, 3, 4, 5};	
	for(auto it = a.begin();it!=a.end();it++){
		printf("%d ", *it);
	}
	puts("");
	for(auto it = a.begin();it!=a.end();it++){
		if(*it == 3) a.erase(it);
		printf("%d ", *it);
	}

	return 0;
}



