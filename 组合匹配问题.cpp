// ���ƥ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

using namespace std;

//��ӡ��Achecked,Bchecked��ֵ
void PrintAchecked(bool*Achecked,int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<Achecked[i]<<",";
	}
	cout<<endl;
}

//���������ݱȽϣ����������ƥ��������򷵻���ֵ�����򷵻ؼ�ֵ
//��ǰ��ʱ����������̬��������ĳ��ȡ�
bool ArrayComp(int*a,int*b,int length)
{
	//��������Achecked,Bchecked�ֱ��¼a,b����Ӧλ�õ�Ԫ���Ƿ��Ѿ�������Ƚ�
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

	//�ٿ���Achecked���Ƿ�ȫ��Ϊtrue,�����򷵻�true,�����򷵻�false
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
	//���������ݱȽϣ����������ƥ��������򷵻���ֵ�����򷵻ؼ�ֵ
	cout<<ArrayComp(res,tar,4)<<endl;
	return 0;
}

