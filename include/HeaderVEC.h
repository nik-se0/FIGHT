// Copyright 2021 Semenova Veronika
#include <iostream>

class VEC
{   
    int* V=new int[3];
    
public:
	//������������ 
	VEC();
/*	VEC(const VEC & V);
	
	//�e�������� ��� ������� 
	~VEC();
*/	
	//�������� �������� �� ������ ��� �������
	int* V_arr() const;
	
/*	//��������� ���������� �������;
	void RAND(int a=1, int b=100);
	
	//���������� �����
	VEC& operator = ( const VEC& V);
	
	//���������� �������� ��������
	VEC operator + (const VEC& V) const ;  //���������� �����
	VEC operator * (double n) const ; //���������� ��������� �� ���������
	
	//���������� ����� � ������
	friend std::istream& operator>> (std::istream &is, VEC &V);
	friend std::ostream& operator<< (std::ostream &os, const VEC &V);
	friend class MAT;*/
	friend class FIGHT;
};


    
    


