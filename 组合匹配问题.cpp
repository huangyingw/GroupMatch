// 组合匹配问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

//打印出Achecked,Bchecked的值
void PrintAchecked(bool*Achecked,int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<Achecked[i]<<",";
	}
	cout<<endl;
}

//将两组数据比较，若满足组合匹配的条件则返回真值，否则返回假值
//眼前暂时还做不到动态计算数组的长度。
bool ArrayComp(int*a,int*b,int length)
{
	//两个数组Achecked,Bchecked分别记录a,b中相应位置的元素是否已经参与过比较
	bool* Achecked=new bool[length];
	bool* Bchecked=new bool[length];
	int i,j;

	for(i=0;i<length;i++)
	{
		Achecked[i]=Bchecked[i]=false;
	}
	for(i=0;i<length;i++)
	{
		if(Achecked[i])
			continue;
		else
		{
			for(j=0;j<length;j++)
			{
				if(Bchecked[j])
					continue;
				else
				{
					if(a[i]==b[j])
					{
						Achecked[i]=Bchecked[j]=true;
						break;
					}
				}
			}
		}
	}

	//再看看Achecked里是否全部为true,若是则返回true,若否则返回false
	for(j=0;j<length;j++)
	{
		if(Bchecked[j]&&Achecked[j])
			continue;
		else if(!Bchecked[j]||!Achecked[j])
		{
			return false;   
		}
	}
	return true;
}
	
int _tmain(int argc, _TCHAR* argv[])
{
	int res[4]={1,2,2,2};
	int tar[4]={2,2,2,1};
	//将两组数据比较，若满足组合匹配的条件则返回真值，否则返回假值
	cout<<ArrayComp(res,tar,4)<<endl;
	return 0;
}

