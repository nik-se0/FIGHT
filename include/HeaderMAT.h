// Copyright 2021 Semenova Veronika
#include <iostream>

//class VEC;

//КЛАСС МАТРИЦА
class MAT
{   
    int M[10][10];
    
public:
	//конструкторы 
	MAT();
/*	MAT(const MAT & M);
	
	//дeструктор  
	~MAT();
	
	//передача значений по ссылке для матрицы
	int M_n() const;
	VEC* M_arr() const;
	
	//Рандомное заполнение матрицы;
	void RAND(int a=1, int b=100);
	
	//перегрузка равно
	MAT& operator = ( const MAT& M);
	
	//перегрузка бинарных операций
	VEC operator * (const VEC& V) const ;  //перегрузка умножения
*/	
	//перегрузка ввода и вывода
//	friend std::istream& operator>> (std::istream &is, MAT &M);
	friend std::ostream& operator<< (std::ostream &os, const MAT &M);
//	friend class MG;
};

