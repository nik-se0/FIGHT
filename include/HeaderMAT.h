// Copyright 2021 Semenova Veronika
#include <iostream>

//class VEC;

//����� �������
class MAT
{   
    int M[10][10];
    
public:
	//������������ 
	MAT();
/*	MAT(const MAT & M);
	
	//�e��������  
	~MAT();
	
	//�������� �������� �� ������ ��� �������
	int M_n() const;
	VEC* M_arr() const;
	
	//��������� ���������� �������;
	void RAND(int a=1, int b=100);
	
	//���������� �����
	MAT& operator = ( const MAT& M);
	
	//���������� �������� ��������
	VEC operator * (const VEC& V) const ;  //���������� ���������
*/	
	//���������� ����� � ������
//	friend std::istream& operator>> (std::istream &is, MAT &M);
	friend std::ostream& operator<< (std::ostream &os, const MAT &M);
//	friend class MG;
};

