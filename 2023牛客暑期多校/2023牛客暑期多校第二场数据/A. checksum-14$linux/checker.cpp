#include <vector>
#include "testlib.h"
 
using namespace std;

using uint8 = unsigned char;
using uint32 = unsigned int;
 
void readAndCheckAnswer(vector<uint8> v1,vector<uint8> v2,InStream& in) {
	uint32 crc = 0;
	uint32 ans = in.readLong(0ll,0xffffffffll,"answer");
	auto addv = [&](uint32 v){
		for(int i=7;i>=0;i--){
			crc ^= ((v>>i)&1)<<31;
			if(crc&0x80000000){
				crc = (crc<<1)^0x04C11DB7;
			}else{
				crc = crc<<1;
			}
		}
	};
	for(uint8 v:v1){
		addv(v);
	}
	for(int i=3;i>=0;i--){
		addv((ans>>(8*i))&0xff);
	}
	for(uint8 v:v2){
		addv(v);
	}
	if(crc!=ans){
		in.quitf(_wa, "Calculated CRC value = %u; CRC field value = %d;",crc,ans);
	}
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int n1 = inf.readInt();
    int n2 = inf.readInt();
    vector<uint8> v1(n1);
    vector<uint8> v2(n2);
    for(int i=1;i<=n1;i++){
    	v1[i-1] = inf.readInt(0,255,format("a[%d]",i));
    }
    for(int i=1;i<=n2;i++){
    	v2[i-1] = inf.readInt(0,255,format("b[%d]",i));
    }
    readAndCheckAnswer(v1,v2,ans);
    readAndCheckAnswer(v1,v2,ouf);
    
    quitf(_ok, "The answer is correct.");
}
