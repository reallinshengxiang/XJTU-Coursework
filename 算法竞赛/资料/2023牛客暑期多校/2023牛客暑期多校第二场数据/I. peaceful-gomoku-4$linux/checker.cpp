#include <vector>
#include "testlib.h"
 
using namespace std;
 
void readAndCheckAnswer(int n,int m,InStream& in) {
	vector<vector<char>> c(n,vector<char>(m));
	int cx = 0;
	int co = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c[i][j] = in.readChar();
			if(c[i][j]!='x'&&c[i][j]!='o'){
				in.quitf(_wa, "Unexpected charactor %c at line %d column %d.",c[i][j],i+1,j+1);
			}
			if(c[i][j]=='x') cx++;
			else co++;
		}
		in.readEoln();
	}
	if(cx!=(n*m+1)/2){
		in.quitf(_wa, "Incorrect total number of black pieces. Read %d, expect %d.",cx,(n*m+1)/2);
	}
	if(co!=n*m/2){
		in.quitf(_wa, "Incorrect total number of white pieces. Read %d, expect %d.",co,n*m/2);
	}
	for(int i=0;i<n-4;i++){
		for(int j=0;j<m;j++){
			bool flag = true;
			for(int d=1;d<5;d++){
				if(c[i+d][j]!=c[i][j]){
					flag = false;
					break;
				}
			}
			if(flag) in.quitf(_wa, "Five %c were found to be in a row starting from row %d, column %d.", c[i][j], i+1,j+1);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m-4;j++){
			bool flag = true;
			for(int d=1;d<5;d++){
				if(c[i][j+d]!=c[i][j]){
					flag = false;
					break;
				}
			}
			if(flag) in.quitf(_wa, "Five %c were found to be in a column starting from row %d, column %d.", c[i][j], i+1,j+1);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i+4>=n||j+4>=m) continue;
			bool flag = true;
			for(int d=1;d<5;d++){
				if(c[i+d][j+d]!=c[i][j]){
					flag = false;
					break;
				}
			}
			if(flag) in.quitf(_wa, "Five %c were found to be in a positive diagonal starting from row %d, column %d.", c[i][j], i+1,j+1);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i+4>=n||j-4<0) continue;
			bool flag = true;
			for(int d=1;d<5;d++){
				if(c[i+d][j-d]!=c[i][j]){
					flag = false;
					break;
				}
			}
			if(flag) in.quitf(_wa, "Five %c were found to be in a negative diagonal starting from row %d, column %d.", c[i][j], i+1,j+1);
		}
	}
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int T = inf.readInt();
    
    for(int t=1;t<=T;t++){
    	setTestCase(t);
    	int n = inf.readInt();
    	int m = inf.readInt();
    	readAndCheckAnswer(n,m,ans);
    	readAndCheckAnswer(n,m,ouf);
    }
    quitf(_ok, "%d test cases.", T);
}
