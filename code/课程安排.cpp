#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int terms_num;
int term_score;
int* class_scores;
int** adj;
int* visit;
int class_num;
float sigma2 = -1;
int** array;
int** perfect;

int fac(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fac(n-1);
	}
}

vector<int> nextparam(vector<int> param)
{
	if (param[0] == -1)
	{
		return vector<int> (param.size(), 0);
	}
	else
	{
		if (!next_permutation(param.begin(), param.end()))
        {
            sort(param.begin(), param.end());
        }
        return param;
	}
}

void resetVisit()
{
	for (int i = 0; i < class_num; i++)
	{
		visit[i] = 0;
	}
}

void sortVector(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int max_i = i;
		for (int j = i+1; j < vec.size(); j++)
		{
			if (class_scores[vec[max_i] < class_scores[j]])
			{
				max_i = j;
			}
		}
		int tmp = vec[max_i];
		vec[max_i] = vec[i];
		vec[i] = vec[max_i];
	}
}

int check()
{
	int count = 0;
	for (int i = 0; i < class_num; i++)
	{
		visit[i] = 0;
	}
	while (count < class_num)
	{
		int now = -1;
		for (int i = 0; i < class_num; i++)
		{
			if (visit[i] == 0)
			{
				int flag = 1;
				for (int j = 0; j < class_num; j++)
				{
					if (adj[j][i])
					{
						 if (visit[j] == 0)
						 {
						 	flag = 0;
							break;
						 }
					}
				}
				if (flag)
				{	
					now = i;	
				}
			}
		}
		if (now == -1)
		{
			return 1;	
		}
		visit[now] = 1;
		count ++;
	}
	resetVisit();
	return 0;	
} 

float count_sigma2()
{
	float scores_sum = 0;
	for (int i = 0; i < class_num; i++)
	{
		scores_sum += class_scores[i];
	}
	float ave = scores_sum / terms_num;
	float sum = 0;
	for (int t = 0; t < terms_num; t++)
	{
		float tmp = 0;
		for (int c = 0; c < class_num; c++)
		{
			if (array[t][c])
			{
				tmp += class_scores[c];
			}
		}
		sum += (tmp - ave) * (tmp - ave);
	}
	return sum / terms_num;
}

void dfs(int n, int i, vector<int> tmpvec, int now, int score_left)
{
	if (terms_num == i && now == n)
	{
		if (sigma2 == -1 || sigma2 > count_sigma2())
		{
			sigma2 = count_sigma2();
			for (int t = 0; t < terms_num; t++)
			{
				for (int c = 0; c < n; c++)
				{
					perfect[t][c] = array[t][c];
				}
			}
		}
	}
	else if(score_left <= (terms_num - i) * term_score)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[j] == 0)
			{
				int flag = 1;
				for (int k = 0; k < class_num; k++)
				{
					if (adj[k][j] && visit[k] == 0)
					{
						flag = 0;
						break;
					}
				}
				if (flag)
				{
					tmpvec.push_back(j);
				}
			}
		}
		int tsum = 0;
		int tmpsize = tmpvec.size();
		vector<int> param(tmpsize, -1);
		vector<int> copytmp = tmpvec;
		for (int j = 0; j < fac(tmpsize); j++)
		{
			param = nextparam(param);
			for (int k = 0; k < tmpsize; k++)
			{
				if (param[k])
				{
					visit[tmpvec[k]] = 1;
					tsum += class_scores[tmpvec[k]];
					array[i][tmpvec[k]] = 1;
					tmpvec.erase(tmpvec.begin() + k);
					now++;
				}
			}
			dfs(n, i+1, tmpvec, now, score_left-tsum);
			for (int k = 0; k < tmpsize; k++)
			{
				if (param[k])
				{
					tmpvec.insert(tmpvec.begin() + k, copytmp[k]);
					visit[tmpvec[k]] = 0;
					tsum -= class_scores[tmpvec[k]];
					array[i][tmpvec[k]] = 0;
					now--;
				}
			}
		}
	}
}

int sortForAve(int n)
{
	vector<int> tmpvec;
	dfs(n, 0, tmpvec, 0, 0);
	cout << "-----------------排课-----------------\n";
	for (int i = 0; i < terms_num; i++)
	{
		cout << "第" << i+1 << "学期学习课序号:";
		int tsum = 0;
		for (int j = 0; j < class_num; j++)
		{
			if (perfect[i][j])
			{
				tsum += class_scores[class_scores[j]];
				cout << j+1 << " ";
			}
		}
		cout << "\t本学期总学分:" << tsum;
		cout << endl;
	}
	resetVisit();
	return 1;
}

int sortForFast(int n)
{
	vector<int> tmpvec;
	int i = 0;
	int term_num = 1;
	cout << "-----------------排课-----------------\n";
	while (i < n && term_num <= terms_num)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[j] == 0)
			{
				int flag = 1;
				for (int k = 0; k < n; k++)
				{
					if (adj[k][j] && visit[j] == 0)
					{
						flag = 0;
						break;
					}
				}
				if (flag)
				{
					tmpvec.push_back(j);
					visit[j] = 1;
				}
			}
		}
		cout << "第" << term_num << "学期学习课序号:";
		int tsum = 0;
		int j = 0;
		while (j < tmpvec.size())
		{
			if (tsum+class_scores[tmpvec[j]] <= term_score)
			{
				tsum += class_scores[tmpvec[j]];
				cout << tmpvec[j]+1 << " ";
				i++;
				tmpvec.erase(tmpvec.begin()+j);
				j--;
			}
			j++;
		}
		cout << "\t本学期总学分:" << tsum;
		cout << endl;
		term_num++;
	}
	if (term_num <= terms_num)
	{
		cout << "学分修满,其余学期无安排\n";
	}
	cout << endl;
	cout << "-------------------------------------\n";
	resetVisit();
	return 1;
}

void delAll()
{
	delete [] visit;
	delete [] class_scores;
	for (int i = 0; i < class_num; i++)
	{
		delete [] adj[i];
	}
	delete [] adj;
	for (int i = 0; i < terms_num; i++)
	{
		delete [] array[i];
		delete [] perfect[i];
	}
	delete [] array;
	delete [] perfect;
}

int main()
{
	int sum = 0;
	int flag = 1;
	cout << "输入学期总数:\n";
	cin >> terms_num;
	cout << "输入课程总数:\n";
	cin >> class_num;
	cout << "每学期学分上限:\n";
	cin >> term_score;
	int sum_max = term_score * terms_num;
	class_scores = new int [class_num];
	adj = new int* [class_num];
	visit = new int [class_num];
	resetVisit();
	for (int i = 0; i < class_num; i++)
	{
		int* temp = new int [class_num];
		adj[i] = temp;
		for (int j = 0; j < class_num; j++)
		{
			adj[i][j] = 0;
		}
	}
	array = new int* [class_num];
	perfect = new int* [class_num];
	for (int i = 0; i < terms_num; i++)
	{
		int* temp1 = new int [terms_num];
		array[i] = temp1;
		int* temp2 = new int [terms_num];
		perfect[i] = temp2;
		for (int j = 0; j < terms_num; j++)
		{
			array[i][j] = 0;
			perfect[i][j] = 0;
		}
	}
	for (int i = 0; i < class_num; i++)
	{
		cout << "课程"  << i+1 << "信息:\n";
		cout << "学分:";
		cin >> class_scores[i];
		sum += class_scores[i];
		if (class_scores[i] > term_score)
		{
			flag = 0;	
		} 
		int front_class = class_num;
		while (front_class > class_num - 1 || front_class < 0)
		{
			cout <<  "先修课程数:";
			cin >> front_class;
			if (front_class > class_num - 1)
			{
				cout << "输入错误,课程数不合理\n";
				continue;
			}
			for (int j = 0; j < front_class; j++)
			{
				int tmp;
				cout << "输入第" << j+1 << "个先修课程:";
				cin >> tmp;
				if (tmp == i+1)
				{
					cout << "本课程不能作为自己的先修课程\n";
					cout << "重新"; 
					j--;
					continue; 
				}
				else if (tmp <= 0 && tmp > class_num)
				{
					cout << "先修课程序号不合理\n";
					cout << "重新"; 
					j--;
					continue; 
				}
				adj[tmp-1][i] = 1;
			}
		}
	}
	cout << "课程序号和学分:\n";
	for (int i = 0 ; i < class_num; i++)
	{
		cout << "课序号" << i+1 << "    "  << class_scores[i] << "学分" << endl;
	}
	cout << endl; 
	int help = 1;
	cout << "--------------排课方案--------------\n";
	while (1)
	{
		cout<<"选择1:使学生在各学期中的学习负担尽量均匀         输入1\n";
		cout<<"选择2:使课程尽可能地集中在前几个学期中           输入2\n";
		cout<<"选择3:关闭程序                                   输入q\n";
		char choice;
		cin >> choice;
		
		if(check())
		{
			cout << "错误先修关系，出错了,程序结束\n"; 
			delAll();
			return 0;	
		}
		
		if (help == 0)
		{
			cout << "出错了,程序结束\n"; 
			delAll();
			return 0;	
		}
		
		if (flag == 0)
		{
			cout << "找不到可行方案,因为有一门课学分大于单学期学分上限\n";
			delAll();
			return 0;	
		}
		if (sum > sum_max)
		{
			cout << "找不到可行方案,因为有总学分大于所有学期学分上限和\n";
			delAll();
			return 0;	
		}
		
		switch (choice){
			case '1':
				help = sortForAve(class_num);
				break;
			case '2':
				help = sortForFast(class_num);
				break;
			case 'q':
				cout << "感谢使用\n";
				delAll();
				return 0;
			}
	}
	return 0;
}
