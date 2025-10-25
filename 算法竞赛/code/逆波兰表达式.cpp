#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
const char* yunsf[6] = {"+","-","*","/","^","%"};
 
struct Expression{	//表达式结构体
	char expre[6];
	int length;
	int logo; //0表示整数，1表示浮点数，2表示字符 
};
 
struct Polish{
	int int_num;
	float float_num;
	char calcu[4];
	int calcu_length;
	int logo; //0表示整数，1表示浮点数，2表示字符 
};
 
char user_string [20]; //存储用户输入的中缀表达式
Polish struct_hou[20]; //存储逆波兰表达式
Expression lexical_expre[20]; //存储词法分析之后的结果
 
char omega_stack[20]; //分析栈
int omega_pointer; //分析栈的指针
 
int zhong_leng; //中缀表达式的长度 
int length_lexical; //经词法分析之后的数组的长度 
int hou_leng; //逆波兰表达式的长度 
 
int float_flag = 0; //0表示没有输入小数，1表示输入小数 
 
struct Polish result; //最终计算结果
 
bool input_string();
void translate();
void calculate();
void init();
void lexical_analysis();
int digitProcess(char buffer,int pointer);
int calcuProcess(char buffer,int pointer);
bool isDigit(char buffer);
bool isCalcu(char buffer);
void translate();
int string_to_int(char *str,int length);
float string_to_float(char *str,int length);
 
int main(){
	bool input_correctly = false;
	while(!input_correctly){
		input_correctly = input_string();
	}
 
	init();
	lexical_analysis();
 
	translate();
	printf("后缀表达式：");
	for(int i = 0; i<hou_leng;i++){
		if(struct_hou[i].logo==0 && struct_hou[i].int_num<0){
			printf("%d - ",struct_hou[i].int_num*(-1));
		}
		else if(struct_hou[i].logo==0){
			printf("%d ",struct_hou[i].int_num);
		}
		else if(struct_hou[i].logo==1){
			printf("%.2f ",struct_hou[i].float_num);
		}
		else{
			printf("%s ",struct_hou[i].calcu);
		}
	}
	printf("\n");
	calculate();
	
	if(float_flag){
		printf("计算结果：%.2f\n",result.float_num);
	}
	else{
		printf("计算结果：%d\n",result.int_num);
	}
}
 
void translate(){ //将中缀表达式转换为后缀 
	int struct_point = 0;
	while(struct_point<length_lexical){ //当词法分析结果栈还有内容时
		struct Expression expre_trans = lexical_expre[struct_point];
		//omega_stack栈中只存储运算符
		if(strcmp(expre_trans.expre,"(")==0){
			//如果是左括号，直接入栈
			omega_stack[++omega_pointer] = '(';
		}
		else if(strcmp(expre_trans.expre,")")==0){
			//如果是右括号，则一直出栈，直到栈顶是左括号
			while(omega_stack[omega_pointer]!='('){
				struct_hou[hou_leng].calcu[struct_hou[hou_leng].calcu_length++] = omega_stack[omega_pointer];
				hou_leng++;
				omega_pointer--;
			}
			omega_pointer--;
		}
		
		else if(strcmp(expre_trans.expre,"^")==0){
			omega_stack[++omega_pointer] = expre_trans.expre[0]; //如果是乘除取余符号，则expre_trans中的字符长度为1 
		}
		
		else if(strcmp(expre_trans.expre,"*")==0 || strcmp(expre_trans.expre,"/")==0||strcmp(expre_trans.expre,"%")==0){
			//如果是乘除符号和取余符号 
			//则把全部*/%符号都出栈（相当于：在左边的*/号的优先级比后面的*/的优先级高） 
			while(omega_stack[omega_pointer]=='*'||omega_stack[omega_pointer]=='/'||omega_stack[omega_pointer]=='%'||omega_stack[omega_pointer]=='^'){
				struct_hou[hou_leng].calcu[struct_hou[hou_leng].calcu_length++] = omega_stack[omega_pointer];
				hou_leng++;
				omega_pointer--;
			}
			//将刚才的*/%号入栈
			omega_stack[++omega_pointer] = expre_trans.expre[0]; //进栈 
		}
		
		else if(strcmp(expre_trans.expre,"+")==0 || strcmp(expre_trans.expre,"-")==0){
			//如果是加减符号
			if(struct_point==0||(strcmp(lexical_expre[struct_point-1].expre,"(")==0)){
				//如果正负号在第一位，则说明是单目运算符 
				//如果加减符号的前一个符号为(，则说明是单目运算符。
				if(lexical_expre[struct_point+1].logo==0){ //如果下一个是整数 
					//如果是整数
					struct_hou[hou_leng].int_num =0-string_to_int(lexical_expre[struct_point+1].expre,lexical_expre[struct_point+1].length);
					struct_hou[hou_leng].logo = 0;
					hou_leng++;
				}
				else if(lexical_expre[struct_point+1].logo==1){ //如果下一个是浮点数 
					//如果是浮点数
					struct_hou[hou_leng].float_num =0-string_to_float(lexical_expre[struct_point+1].expre,lexical_expre[struct_point+1].length);
					struct_hou[hou_leng].logo = 1;
					hou_leng++;
				}
				else{
					printf("格式输入错误！\n");
					exit(0);
				}
				struct_point++;
			}
			else{
				//由于该+-号的优先级最低，只比(高，因此使所有栈中的字符都出栈，直至符号为(
				while(omega_pointer!=-1&&omega_stack[omega_pointer]!='('){
					struct_hou[hou_leng].calcu[struct_hou[hou_leng].calcu_length++] = omega_stack[omega_pointer];
					hou_leng++;
					omega_pointer--;
				}
				//将新的加减符号入栈
				omega_stack[++omega_pointer] = expre_trans.expre[0]; //如果是加减符号，则expre_trans中的字符长度为1
			}
		}
		
		else{//非运算符 
			//说明是数字
			if(expre_trans.logo==0){
				//如果是整数
				struct_hou[hou_leng].int_num = string_to_int(expre_trans.expre,expre_trans.length);
				struct_hou[hou_leng].logo = 0;
				hou_leng++;
			}
			else{
				//如果是浮点数
				struct_hou[hou_leng].float_num = string_to_float(expre_trans.expre,expre_trans.length);
				struct_hou[hou_leng].logo = 1;
				hou_leng++;
			}
		}
		struct_point++;
	}
	
	while(omega_pointer!=-1){
		//当表达式扫描完毕后， 假如omage分析栈还存在元素，就依次全部加入到Polish栈中。 
		if(omega_stack[omega_pointer]!='('){
			struct_hou[hou_leng].calcu[struct_hou[hou_leng].calcu_length++] = omega_stack[omega_pointer];
			hou_leng++;
		}
		else{
			printf("输入的表达式错误！\n");
			exit(0);
		}
		omega_pointer--;
	}
}
 
void calculate(){ //计算后缀表达式 
	int struct_point = 0;
	while(struct_point<hou_leng){ //当逆波兰结果数组中还有内容时 
		struct Polish polish = struct_hou[struct_point];
		if (strcmp(polish.calcu,"+")==0){
			//如果是加号
			if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==1){
				//如果都是浮点数
				struct_hou[struct_point].float_num = struct_hou[struct_point-2].float_num+struct_hou[struct_point-1].float_num;
				struct_hou[struct_point].logo=1;
			}
			
			//如果有一方是浮点数
			else if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==0){
	
				float temp = struct_hou[struct_point-2].int_num;
				struct_hou[struct_point].float_num = struct_hou[struct_point-1].float_num+temp;
				struct_hou[struct_point].logo=1;
			}
			else if(struct_hou[struct_point-1].logo==0&&struct_hou[struct_point-2].logo==1){
				float temp = struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].float_num = temp + struct_hou[struct_point-2].float_num;
				struct_hou[struct_point].logo=1;
			}
			
			else{
				//如果都是整型 
				struct_hou[struct_point].int_num = struct_hou[struct_point-2].int_num+struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].logo=0;
			}
		}
		
		else if (strcmp(polish.calcu,"-")==0){
			if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==1){
				//如果都是浮点数
				struct_hou[struct_point].float_num = struct_hou[struct_point-2].float_num-struct_hou[struct_point-1].float_num;
				struct_hou[struct_point].logo=1;
			}
			
			else if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==0){
				//如果有一方是浮点数
				float temp = struct_hou[struct_point-2].int_num;
				struct_hou[struct_point].float_num = temp-struct_hou[struct_point-1].float_num;
				struct_hou[struct_point].logo=1;
			}
			else if(struct_hou[struct_point-1].logo==0&&struct_hou[struct_point-2].logo==1){
				float temp = struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].float_num = struct_hou[struct_point-2].float_num-temp;
				struct_hou[struct_point].logo=1;
			}
			else{
				//如果都是整型 
				struct_hou[struct_point].int_num = struct_hou[struct_point-2].int_num-struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].logo=0;
			}
		}
		
		else if (strcmp(polish.calcu,"*")==0){
//			printf("进入乘号页面！\n");
			//如果是乘号 
			if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==1){
				//如果都是浮点数
				struct_hou[struct_point].float_num = struct_hou[struct_point-2].float_num*struct_hou[struct_point-1].float_num;
				struct_hou[struct_point].logo=1;
			}
			
			else if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==0){
				//如果有一方是浮点数
				float temp = struct_hou[struct_point-2].int_num;
				struct_hou[struct_point].float_num = struct_hou[struct_point-1].float_num*temp;
				struct_hou[struct_point].logo=1;
			}
			else if(struct_hou[struct_point-1].logo==0&&struct_hou[struct_point-2].logo==1){
				float temp = struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].float_num = temp*struct_hou[struct_point-2].float_num;
				struct_hou[struct_point].logo=1;
			}
			else{
				//如果都是整型 
				struct_hou[struct_point].int_num = struct_hou[struct_point-2].int_num*struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].logo=0;
			}
		}
		
			else if (strcmp(polish.calcu,"^")==0){ 
			if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==1){
				//如果都是浮点数
				struct_hou[struct_point].float_num = pow(struct_hou[struct_point-2].float_num,struct_hou[struct_point-1].float_num);
				struct_hou[struct_point].logo=1;
			}
			
			else if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==0){
				//如果有一方是浮点数
				float temp = struct_hou[struct_point-2].int_num;
				struct_hou[struct_point].float_num = pow(struct_hou[struct_point-1].float_num,temp);
				struct_hou[struct_point].logo=1;
			}
			else if(struct_hou[struct_point-1].logo==0&&struct_hou[struct_point-2].logo==1){
				float temp = struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].float_num = pow(temp,struct_hou[struct_point-2].float_num);
				struct_hou[struct_point].logo=1;
			}
			else{
				//如果都是整型 
				struct_hou[struct_point].int_num = pow(struct_hou[struct_point-2].int_num,struct_hou[struct_point-1].int_num);
				struct_hou[struct_point].logo=0;
			}
		}
		
		else if (strcmp(polish.calcu,"/")==0){
			if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==1){
				//如果都是浮点数
				struct_hou[struct_point].float_num = struct_hou[struct_point-2].float_num/struct_hou[struct_point-1].float_num;
				struct_hou[struct_point].logo=1;
			}
			
			else if(struct_hou[struct_point-1].logo==1&&struct_hou[struct_point-2].logo==0){
				//如果有一方是浮点数
				float temp = struct_hou[struct_point-2].int_num;
				struct_hou[struct_point].float_num =temp/struct_hou[struct_point-1].float_num;
				struct_hou[struct_point].logo=1;
			}
			else if(struct_hou[struct_point-1].logo==0&&struct_hou[struct_point-2].logo==1){
				float temp = struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].float_num = struct_hou[struct_point-2].float_num/temp;
				struct_hou[struct_point].logo=1;
			}
			else{
				//如果都是整型 
				struct_hou[struct_point].int_num = struct_hou[struct_point-2].int_num/struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].logo=0;
			}
		}
		
		else if (strcmp(polish.calcu,"%")==0){
			if(struct_hou[struct_point-1].logo==1||struct_hou[struct_point-2].logo==1){
				printf("浮点数不可以进行取整运算！\n");
				exit(0);
			}
			else{
				//如果都是整型 
				struct_hou[struct_point].int_num = struct_hou[struct_point-2].int_num % struct_hou[struct_point-1].int_num;
				struct_hou[struct_point].logo=0;
			}
		}
		
		if(polish.logo==2){
			for(int i = struct_point-2;  i<hou_leng-2; i++){
				struct_hou[i] = struct_hou[i+2];
			}
			struct_point = struct_point-2;
			hou_leng = hou_leng-2;
		}
		struct_point++;
	}
	result.float_num = struct_hou[0].float_num;
	result.int_num = struct_hou[0].int_num;
}
 
void lexical_analysis(){
	//对用户输入的串进行词法分析
	int pointer = 0;  //暂时的、只用于词法分析的指针 
    while (pointer<zhong_leng){ //当还有剩下的字符时
    	char cbuffer = user_string[pointer];
        if(cbuffer==' '||cbuffer=='\n'||cbuffer=='	'){
		 	/*掠过空格和回车符*/
		} 
	    
	    else if(cbuffer=='('||cbuffer==')'){ //括号单独拿出来处理 
	    	lexical_expre[length_lexical].expre[lexical_expre[length_lexical].length++]=cbuffer;
			length_lexical++;
			pointer++;
 
		}
	    
	    else if(isDigit(cbuffer)){ //处理常数 
	        pointer = digitProcess(cbuffer,pointer);
	    }
		
		else if(isCalcu(cbuffer)){ //处理算术运算符 
	    	pointer = calcuProcess(cbuffer,pointer);
		}
		else{
			printf("输入了不正确的字符！\n");
			exit(0);
		}
    }
	return ;
}
 
int digitProcess(char buffer,int pointer){
	//处理数字
	int flag = 0;//0表示没有小数点，1表示有小数点 
	while (isDigit(buffer)||buffer=='.'){
		if(buffer=='.'){
			flag=1;
		}
		lexical_expre[length_lexical].expre[lexical_expre[length_lexical].length++] = buffer;
	    buffer = user_string[++pointer];
	}
	if(flag){
		//如果有小数点
		lexical_expre[length_lexical].logo = 1;  //将类型置为浮点数 
		float_flag = 1; //说明有小数，要按照浮点数的运算规则进行计算 
	}
	else{
		lexical_expre[length_lexical].logo = 0; //将类型置为整形 
	}
	length_lexical++;
	return pointer;
}
 
int string_to_int(char *str,int length){
	int result = 0;
	for(int i = 0; i<length; i++){
		result = result*10+(int)(str[i]-'0');
	}
	return result;
}
 
float string_to_float(char *str,int length){
	int result_int = 0;
	float result_float = 0;
	int i=0;
	for(i; i<length; i++){
		if(str[i]=='.'){
			break;
		}
		result_int = result_int*10+(int)(str[i]-'0');
	}
	
	float decimal = 0.1; 
	for(i=i+1; i<length; i++){
		float temp = (int)(str[i]-'0');
		
		result_float = result_float+temp*decimal;
		
		decimal*=0.1;
	}
	float temp_int = result_int;
	return temp_int+result_float;
}
 
int calcuProcess(char buffer,int pointer){
	while ((isCalcu(buffer))){
		lexical_expre[length_lexical].expre[lexical_expre[length_lexical].length++]=buffer;
	    buffer=user_string[++pointer];
	}
	
	//检查该操作符是否在预设的符号之中
	int flag = 0; //0表示不在，1表示在 
	for (int i = 0;i<6;i++){
		if(strcmp(lexical_expre[length_lexical].expre,yunsf[i])==0){
			flag = 1;
		}
	}
	if(!flag){
		printf(" %s 输入错误！\n",lexical_expre[length_lexical].expre);
		exit(0);
	}
	length_lexical++;
	return pointer;
}
 
 
void init(){
	//进行一些初始化工作
	length_lexical = 0;
	omega_pointer = -1;
	hou_leng = 0;
	for(int i = 0; i<20;i++){
		lexical_expre[i].length = 0;
		struct_hou[i].calcu_length = 0;
		lexical_expre[i].logo  = 2; //默认为字符类型 
		struct_hou[i].logo = 2; //默认为字符类型 
	}
}
 
bool isDigit(char buffer){
	return buffer >= '0' && buffer <= '9';
}
 
bool isCalcu(char buffer){
	return buffer=='+' || buffer=='-'|| buffer=='*'|| buffer=='/'|| buffer=='^'|| buffer=='%';
}
 
bool input_string(){
	//输入中缀表达式
	int j=0;
	char ch;
	printf("Input such as 21+((42-2)*15+6)-18 or 21+(42-1)%%2 or 2^3 or -3+5*6:\n");
	while(true){
		ch = getchar();
		if(ch=='\n'){
	    	break;
		}
	    user_string[j] = ch;
	    j++;
    }
	printf("\n\n");
	printf("原来表达式：%s\n",user_string);
	for(int i=0; i<j; i++){
		ch = user_string[i];
		if(!(((ch<'9')&&(ch>'0'))||(ch=='+')||(ch=='*')||(ch=='\\')||(ch!=')')||(ch!='(')||(ch!='%')||(ch!='^')||(ch!='.'))){
			printf("输入了非法的字符！请重新输入！\n");
			return false;
		}
	}
 
	zhong_leng = j;
	return true; 
}
