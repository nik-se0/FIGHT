// Copyright 2021 Semenova Veronika
#include <iostream>
#include <locale>
#include <cstdlib>
#include "HeaderFIGHT.h"
using namespace std;
int main()

{  // a 1 2 c 3 2 e 5 2 g 7 2 i 9 2 b 9 2 d 9 f 2 h 2 j 4 
   // a 6 b 1 b 3 b 6 c 1 c 3 c 6 e 1 e 3 e 8 f 6 f 5 f 8 f 10 g 8 h 3 h 6 h 8 j 3 i3
   setlocale(LC_ALL, "Rus");
   srand(time(NULL));
   FIGHT www;
   
   char entry=0;
   do {cout<<"\t������� ���\n\n \tC������?\n\t1.��\n\t2.� ��������� ���\n\t����: ";
       cin>>entry;
       if(entry!='1'){system("cls"); cout<<"�� ��� �, �� ��� ��������\n";}
       else { system("cls"); cout<<"\t���� ������. ����� ���������� �������\n"; cout<<www; }
   }  while(entry!='1');
	
	www.DEC();	         
	cout<<"\n\t� ����� ���� �������. ���� �������\n";
	www.CIN();
	cout<<"��� ������� �������, ����� ������";
	www.FIRE();
    cin>>entry;   
}

