#include <iostream>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include "HeaderFIGHT.h"

//КЛАСС МОРСКОЙ БОЙ
//конструкторы для морского боя
FIGHT::FIGHT()
     { int i,j; 
	   for(i=0;i<10;i++)
	   { for(j=0;j<10;j++)
         { M1[i][j]=0;
           M2[i][j]=0;
		   M3[i][j]=0;}
       }
       
       for(i=0;i<10;i++)
	   { for(j=0;j<5;j++)
         { V1[i][j]=-1;
           V2[i][j]=-1;
		 }
       }
       
       for(i=0;i<10;i++)//задание длины коробля через итерации
	   { if(i==0){V1[i][0]=4;V1[i][1]=4;}
         else{ if(i%2==0){V1[i][0]=1;V1[i][1]=1;}
  	           else{if(i%3==0){V1[i][0]=3;V1[i][1]=3;}
  	                 else{V1[i][0]=2;V1[i][1]=2; }}}
       }
       
       memset(b, 0, 9*sizeof(int));
     } 

//Задание рандомной точки на поле
void RANG_P(int& i, int& j)
{ int e;
    e=rand()%4+1;
  	i=rand()%10;
  	j=rand()%10;
	switch (e)
    {case 1: while((i>j)||(i+j>9))
	         {if(i>j){std::swap(i,j);}
              if(i+j>9){i=9-i;j=9-j;}}
             break;
     case 2: while((i>j)||(i+j<9))
	         {if(i>j){std::swap(i,j);}
              if(i+j<9){i=(i+4)%10;j=(j+5)%10;}}
             break;
     case 3: while((i<j)||(i+j<9))
	         {if(i<j){std::swap(i,j);}
              if(i+j<9){i=(i+4)%10;j=(j+5)%10;}}
             break;
     case 4: while((i<j)||(i+j>9))
	         {if(i<j){std::swap(i,j);}
              if(i+j>9){i=9-i;j=9-j;}}
             break;
    } 	
}

//Задание короблей для морского боя компьютером 
void FIGHT::DEC()
{ int i=0,j=0,i1=0,j1=0,e,d=0,flag=0,x,z,f=0;
  for(i=0;i<10;i++)
  {
   flag=1;
   while(flag==1)
    { RANG_P(i1,j1); //рандомное задание точки
      e=rand()%2+1;
	  switch (e) //рандомный выбор направления корабля
     {case 1 /*вертикальный корабль*/: 
             flag=0;
			 if(i1+V1[i][0]-1>9){flag=1;} else {//проверка на выход за границы
	         if(V1[0][2]!=-1){ //проверка кораблей на соприкосновение
	         j=0;
			 while((V1[j][2]!=-1)&&(j<10)&&(flag==0))
	         { if(V1[j][2]==1) //проверка вертикальных кораблей
			   { if(((V1[j][4]-j1)*(V1[j][4]-j1))<2) //если в соседних столбцах есть корабли
			     { if((V1[j][3]<=i1+V1[i][0])&&(V1[j][3]+V1[j][0]>=i1)){flag=1;} //то проверям принадлежит ли кордината соседним векторам
			   }} 
			   else //проверка горизонтальных кораблей
			   { if((V1[j][3]>=i1-1)&&(V1[j][3]<=i1+V1[i][0])) 
				 { if((V1[j][4]<j1+V1[i][0])&&(V1[j][4]+V1[j][0]>j1)){flag=1;} 
			   }}
			   j++;
			 }}}
			 if(flag==0){ V1[i][2]=1; V1[i][3]=i1; V1[i][4]=j1; 
			            for(f=i1;f<i1+V1[i][0];f++){M1[f][j1]=1;} //std::cout<<"ПОЛОЖЕННО";
			 }
			 break;
      case 2 /*горизонтальный корабль/*/: 
			 flag=0;
			 if(j1+V1[i][0]-1>9){flag=1;} else {//проверка на выход за границы
	         if(V1[0][2]!=-1){ //проверка кораблей на соприкосновение
	         j=0;
			 while((V1[j][2]!=-1)&&(j<10)&&(flag==0))
	         { if(V1[j][2]==2) 
			   { if(((V1[j][3]-i1)*(V1[j][3]-i1))<2) 
			     { if((V1[j][4]<=j1+V1[i][0])&&(V1[j][4]+V1[j][0]>=j1)){flag=1;} 
			   }} 
			   else 
			   { if((V1[j][4]>=j1-1)&&(V1[j][4]<=j1+V1[i][0])) 
				 { if((V1[j][3]<i1+V1[i][0])&&(V1[j][3]+V1[j][0]>i1)){flag=1;} 
			   }}
			   j++;
			 }}}
			 if(flag==0){ V1[i][2]=2; V1[i][3]=i1; V1[i][4]=j1; 
			             for(f=j1;f<j1+V1[i][0];f++){M1[i1][f]=1;}//std::cout<<"ПОЛОЖЕННО";
			 }
			 break;
     }
    }
  }
}

//по короблям стреляет игрок
void FIGHT::FIRE1(int &flag)
{ int i,j,k,h,y,l,e,fl;
  char l1;
  flag=0;
  fl=1;
  while(fl==1)
	  { fl=0;
	    std::cin>>l1>>h; 
	    if((l1<'a')||(l1>'j')){fl=1;}
	    if((h<1)||(h>10)){fl=1;}
		if(fl==1){ std::cin.clear(); std::cout<<"НЕКОРЕКТНО ВВЕДЕНЫ ЗНАЧЕНИЯ, ПОПРОБЙТЕ ЕЩЕ РАЗ\n";}}
  l=l1-'a';
  h=h-1;
  fl=0;
  e=0;
  while((e<10)&&(fl==0))
  { 
   if((M1[l][h]==-2)||(M3[l][h]==-1)){flag=3;} //был ли выстрел раньше
   else{ if(V1[e][2]==1) //проверка вертикальных кораблей
         {if(V1[e][4]==h) //если в этом столбце есть корабль
	      {if((V1[e][3]<=l)&&(V1[e][3]+V1[e][0]>=l))
	       {if(M1[l][h]==1){ 
		    M3[l][h]=1; fl=1; 
			M1[l][h]=-2; V1[e][1]=V1[e][1]-1;
	        if(V1[e][1]==0){system("cls"); std::cout<<(*this);std::cout<<"КОРАБЛЬ УБИТ\n";flag=1;}
	        if(V1[e][1]>0){system("cls"); std::cout<<(*this);std::cout<<"КОРАБЛЬ РАНЕН\n";flag=1;}
			}}}} 
	      else //проверка горизонтальных кораблей
	     {if(V1[e][3]==l) //если в этом столбце есть корабль
	      {if((V1[e][4]<=h)&&(V1[e][4]+V1[e][0]>=h))
	       {if(M1[l][h]==1)
		    { M3[l][h]=1; fl=1; 
			  M1[l][h]=-2; V1[e][1]=V1[e][1]-1;
	          if(V1[e][1]==0){system("cls"); std::cout<<(*this);std::cout<<"КОРАБЛЬ УБИТ\n"; flag=1;}
	          if(V1[e][1]>0){system("cls"); std::cout<<(*this);std::cout<<"КОРАБЛЬ РАНЕН\n";flag=1;} 
			}}}}}
	e++;}
  if(flag==0){ M3[l][h]=-1;}
  
}

void FIGHT::FIRE2(int &flag)
{ int i,j,l,h,e,fl,z=0,x=0;
  char c; 
  if(b[0]==0){RANG_P(l,h); } //если нет попадания 
  else{ if(b[3]!=0) // если задано направление то
        { switch (b[3])
          {case 1: if(b[1]==0){b[3]=0; b[0]=2; b[8]=0; l=b[1]; h=b[2];} else{
		           l=b[1]-b[8]; h=b[2]; b[8]++; 
                   if((M2[l][h]==0)||(M2[l][h]==-1)||(M2[l][h]==-3)){b[3]=0; b[0]=2; b[8]=0; l=b[1]; h=b[2];}}
		           break;
		   case 2: if(b[1]==9){b[3]=0; b[0]=3; b[8]=0;l=b[1]; h=b[2];} else{
		           l=b[1]+b[8]; h=b[2]; b[8]++; 
                   if((M2[l][h]==0)||(M2[l][h]==-1)||(M2[l][h]==-3)){b[3]=0; b[0]=3; b[8]=0;l=b[1]; h=b[2];}} 
		           break;
		   case 3: if(b[2]==0){b[3]=0; b[0]=4; b[8]=0; l=b[1]; h=b[2];} else{
		           l=b[1]-b[8]; h=b[2]; b[8]++; 
		           l=b[1]; h=b[2]-b[8]; b[8]++; 
                   if((M2[l][h]==0)||(M2[l][h]==-1)||(M2[l][h]==-3)){b[3]=0; b[0]=4; b[8]=0;l=b[1]; h=b[2];}} 
		           break;
		   case 4: if(b[2]==9){b[3]=0; b[0]=5; b[8]=0;l=b[1]; h=b[2];} else{
		           l=b[1]; h=b[2]+b[8]; b[8]++; 
                   if((M2[l][h]==0)||(M2[l][h]==-1)||(M2[l][h]==-3)){b[3]=0; b[0]=5; b[8]=0;l=b[1]; h=b[2];}}   
		           break; 
          }
       }
    else{switch (b[0])
          {case 1: if(b[1]==0){b[4]=0; b[0]++; l=b[1]; h=b[2];} else{ 
		          l=b[1]-1; h=b[2]; 
	              if((M2[l][h]==1)||(M2[l][h]==-2)){b[4]=1; b[3]=1; b[8]=1;}
	              if((M2[l][h]==0)||(M2[l][h]==-1)||(M2[l][h]==-3)){b[4]=0; b[0]++;}}
                  break;
           case 2: if(b[1]==9){b[5]=0; b[0]++; l=b[1]; h=b[2];} else{
		           l=b[1]+1; h=b[2]; 
	               if((M2[l][h]==1)||(M2[l][h]==-2)){b[5]=1; b[3]=2; b[8]=1;}
	               if((M2[l][h]==0)||(M2[l][h]==-1)||(M2[l][h]==-3)){b[5]=0; b[0]++;}}
	   	           break;
           case 3: if(b[4]+b[5]>0){b[0]=0; memset(b, 0, 9*sizeof(int));} 
                   else 
			       { if(b[2]==0){b[6]=0; b[0]++; l=b[1]; h=b[2];} else{
				     l=b[1]; h=b[2]-1; 
	                if((M2[l][h]==1)||(M2[l][h]==-2)){b[6]=1; b[3]=3; b[8]=1;}
	                if((M2[l][h]==0)||(M2[l][h]==-1)||(M2[l][h]==-3)){b[6]=0; b[0]++;}} 
			       }
		           break;
           case 4: if(b[2]==9){b[7]=0; b[0]++; l=b[1]; h=b[2];} else{
		           l=b[1]; h=b[2]+1; 
	               if((M2[l][h]==1)||(M2[l][h]==-2)){b[7]=1; b[3]=4; b[8]=1;}
	               if((M2[l][h]==0)||(M2[l][h]==-1)||(M2[l][h]==-3)){b[7]=0; b[0]++; b[0]=5;}}
                   break;
           case 5: l=b[1]; h=b[2]; memset(b, 0, 9*sizeof(int)); b[0]=-1; 
                   break;
         }   
  }}
  flag=0;          
  fl=0;
  e=0;
  while((e<10)&&(fl==0))
  { if((M2[l][h]==-2)||(M2[l][h]==-1)||(M2[l][h]==-3)){flag=3;} //был ли выстрел раньше
   else{ if(V2[e][2]==1) //проверка вертикальных кораблей
	     {if(V2[e][4]==h) //если в этом столбце есть корабль
	      {if((V2[e][3]<=l)&&(V2[e][3]+V2[e][0]>=l))
	       {if(M2[l][h]==1)
		    {M2[l][h]=-2; fl=1; 
		     V2[e][1]=V2[e][1]-1;
	         if(V2[e][1]==0){ a[a1][0]=l; a[a1][1]=h; a[a1][2]=1; a1++; flag=1;  memset(b, 0, 9*sizeof(int)); 
			  if(V2[e][3]==0){z=0;} else{z=1; M2[V2[e][3]-1][V2[e][4]]=-3;}
	          if(V2[e][3]+V2[e][0]>8){x=1;} else{x=0;M2[V2[e][3]+V2[e][0]][V2[e][4]]=-3;}
			 for(int s=V2[e][3]-z;s<V2[e][3]+V2[e][0]-x+1;s++)
			    { M2[s][V2[e][4]-1]=-3;
			      M2[s][V2[e][4]+1]=-3;
				}
				}
	         if(V2[e][1]>0){ a[a1][0]=l; a[a1][1]=h; a[a1][2]=2; a1++; flag=1;if(b[0]==0){b[0]=1; b[1]=l; b[2]=h;}}
		    }}}} 
	     else //проверка горизонтальных кораблей
	     {if(V2[e][3]==l) //если в этом столбце есть корабль
	      {if((V2[e][4]<=h)&&(V2[e][4]+V2[e][0]>=h))
	       {if(M2[l][h]==1)
		    {M2[l][h]=-2; fl=1;
			 V2[e][1]=V2[e][1]-1;
	         if(V2[e][1]==0){ a[a1][0]=l; a[a1][1]=h; a[a1][2]=1; a1++;flag=1;  memset(b, 0, 9*sizeof(int));
	          if(V2[e][4]==0){z=0;} else{z=1; M2[V2[e][3]][V2[e][4]-1]=-3;}
	          if(V2[e][3]+V2[e][0]>8){x=1;} else{x=0;M2[V2[e][3]][V2[e][4]+V2[e][0]]=-3;}//проверка на выход за границы массива
			  for(int s=V2[e][4]-z;s<V2[e][4]+V2[e][0]-x+1;s++)
			    { M2[V2[e][3]-1][s]=-3;
			      M2[V2[e][3]+1][s]=-3;
				}
			 }
	         if(V2[e][1]>0){ a[a1][0]=l; a[a1][1]=h; a[a1][2]=2; a1++;flag=1;if(b[0]==0){b[0]=1;b[1]=l; b[2]=h;}}
		 }}}}} 
	 e++;
	}
  if(flag==0){ M2[l][h]=-1; a[a1][0]=l; a[a1][1]=h; a[a1][2]=3; a1++; }
  if(b[0]==-1){b[0]=0;}
}

void FIGHT::FIRE()
{ int flag=1,i,d1=10,d2=10,x,k=0;
  char c;
  
  while((d1!=0)&&(d2!=0))
  { flag=1;
    while((flag==1)&&(d1!=0)&&(d2!=0))
	{std::cout<<"\n\nВАШ ХОД:\nВведите координаты выстрела: "; FIRE1(flag);
	 d1=0;
	 for(i=0;i<10;i++)
    {d1=d1+V1[i][1];} if(flag==3){k=3;}
	}

	flag=1;
	while((flag==1)&&(d2!=0)&&(d1!=0))
	{FIRE2(flag); 
	
	if((flag==0)&&(a1!=0)){ system("cls");
	std::cout<<(*this); if(k==3){ std::cout<<"ВЫСТРЕЛ ПО ЭТИМ КООРДИНАТАМ БЫЛ ПРОИЗВЕДЕН РАНЕЕ\n"; k=0;} else{
	std::cout<<"\nВАШ ВЫСТРЕЛ МИМО\n";}
	for(x=0;x<a1;x++)
	{ c='a'+a[x][0];  std::cout<<"\nМОЙ ВЫСТРЕЛ НА "<<c<<" "<<a[x][1]+1;
	switch (a[x][2])
      {case 1: std::cout<< "\nКОРАБЛЬ УБИТ\n";
          break;
       case 2: std::cout<<"\nКОРАБЛЬ РАНЕН\n";
          break;
       case 3: std::cout<<"\nМИМО\n";
          break;
      }} a1=0;
	}
	if(flag==3){flag=1;}
	d2=0;
	for(i=0;i<10;i++)
    { d2=d2+V2[i][1];}
	}
   } 
	if(d1==0){std::cout<<"ИГРА ОКОНЧЕНА ВЫИГРАЛ ИГРОК\n";}
    if(d2==0){ system("cls");
	std::cout<<(*this); 
	for(x=0;x<a1;x++)
	{ c='a'+a[x][0]; std::cout<<"\nМОЙ ВЫСТРЕЛ НА "<<c<<" "<<a[x][1]+1;
	  switch (a[x][2])
      {case 1: std::cout<< "\nКОРАБЛЬ УБИТ\n";
          break;
       case 2: std::cout<<"\nКОРАБЛЬ РАНЕН\n";
          break;
       case 3: std::cout<<"\nМИМО\n";
          break;
      }
    }
	std::cout<<"ИГРА ОКОНЧЕНА ВЫИГРАЛ КОМПЬЮТЕР\n";    
	}
}

//Ввод полей для морского боя
void FIGHT::CIN()
{int i,j,k,h,y,l,n,fl,flag=-1,e,z,x;
 char l1;
 i=0;while(i<9)
 { if(i==0){n=1;}
   if(i==1){n=2;}
   if(i==3){n=3;}
   if(i==6){n=4;}

	 for(y=0;y<n;y++)
    { std::cout<<"Примечание:чтобы ввести корабль, укажите его начальную координату, затем 1 - если корабль вертикальный,  2 - если горизонтальный. \nДля однопалубных направление не вводится\n"; 
   	  if(i<1){std::cout<<"\n\tЧетырехпалубный ";} else{
      if(i<3){std::cout<<"\n\tТрехпалубный ";} else {
      if(i<6){std::cout<<"\n\tДвухпалубный ";} else 
      {std::cout<<"\n\tОднопалубный ";}}}
      std::cout<<"корабль №"<<y+1<<"\n";
      fl=1;
	  while(fl==1)
	  { fl=0;
	    if(n<4){std::cin>>l1>>h>>k; if((k<1)||(k>2)){fl=1;}} else {std::cin>>l1>>h; k=1;}
	    if((l1<'a')||(l1>'j')){fl=1;}
	    if((h<1)||(h>10)){fl=1;}
		if(fl==1){ std::cin.clear(); std::cout<<"НЕКОРЕКТНО ВВЕДЕНЫ ЗНАЧЕНИЯ, ПОПРОБЙТЕ ЕЩЕ РАЗ\n";}
		l=l1-'a';
        h=h-1;
		if(k==1){// проверка на соприкосновения кораблей    
		     flag=0;
	         if(l+4-n>9){flag=1;} else {//проверка на выход за границы
	         if(i!=0){ //проверка кораблей на соприкосновение 
	         e=0; 
			 while((V2[e][0]!=-1)&&(e<10)&&(flag==0))
	         { if(V2[e][2]==1) //проверка вертикальных кораблей
			   {if(((V2[e][4]-h)*(V2[e][4]-h))<2) //если в соседних столбцах есть корабли
			     {if((V2[e][3]<=l+(4-n+1))&&(V2[e][3]+V2[e][0]>=l)){flag=1;} //то проверям принадлежит ли кордината соседним векторам
			   }} 
			   else //проверка горизонтальных кораблей
			   { if((V2[e][3]>=l-1)&&(V2[e][3]<=l+(4-n+1))) 
				 { if((V2[e][4]-1<h)&&(V2[e][4]+V2[e][0]+1>h)){flag=1;} 
			   }}
			   e++;
			 }}}} 
		else { if(h+4-n>9){flag=1;} else {//проверка на выход за границы
	         if(i!=0){ //проверка кораблей на соприкосновение
	         e=0;
			 while((V2[e][0]!=-1)&&(e<10)&&(flag==0))
	         { if(V2[e][2]==2) 
			   { if(((V2[e][3]-l)*(V2[e][3]-l))<2) 
			     { if((V2[e][4]<=h+(4-n+1))&&(V2[e][4]+V2[e][0]>=h)){flag=1;} 
			   }} 
			   else 
			   { if((V2[e][4]>=h-1)&&(V2[e][4]<=h+(4-n+1))) 
				 { if((V2[e][3]<l+(4-n+1))&&(V2[e][3]+V1[e][0]>l)){flag=1;} 
			   }}
			   e++;
			 }}}}  
			 if(flag==1){std::cout<<"КОРАБЛИ РАСПОЛОЖЕНЫ НЕКОРЕКТНО, ПОПРОБЙТЕ ЕЩЕ РАЗ\n"; fl=1;} 
	  } 
      switch (k)
      {case 1: for(j=l;j<l+(4-n+1);j++)
          {M2[j][h]=1;} V2[i][0]=4-n+1; V2[i][1]=4-n+1;
          V2[i][2]=1; V2[i][3]=l; V2[i][4]=h; 
          break;
       case 2: for(j=h;j<h+(4-n+1);j++)
          {M2[l][j]=1;} V2[i][0]=4-n+1; V2[i][1]=4-n+1;
          V2[i][2]=2; V2[i][3]=l; V2[i][4]=h; 
          break;
      }
    system("cls");
    std::cout<<(*this);
    i++;  //std::cout<<i<<" ZXCVBN";
	}
 	
  }
}

//перезрузка вывода для морского боя
std::ostream& operator<< (std::ostream &os, const FIGHT &www)
 { HANDLE Con = GetStdHandle(STD_OUTPUT_HANDLE);
   int i,j,f, n;
   char c;
   os<<"---------------------------------------------\t\t---------------------------------------------\n";
   SetConsoleTextAttribute(Con, ((0 << 4) | 11));
   os<<"|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\t\t|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n"; SetConsoleTextAttribute(Con, ((0 << 4) | 15));
   for(i=0;i<10;i++)
   { os<<"---------------------------------------------\t\t---------------------------------------------\n";
     c='a'+i;
	  SetConsoleTextAttribute(Con, ((0 << 4) | 11));
	 os<<"| "<<c<<" |"; SetConsoleTextAttribute(Con, ((0 << 4) | 15));
	 for(j=0;j<10;j++)
	  { 
	    if(www.M3[i][j]==0){os<<"   ";}
	    if(www.M3[i][j]==1){SetConsoleTextAttribute(Con, ((9 << 4) | 15));os<<" o ";SetConsoleTextAttribute(Con, ((0 << 4) | 15));}
	    if(www.M3[i][j]==-1){os<<" · ";} os<<"|";
	  }
	 os<<"\t\t"; SetConsoleTextAttribute(Con, ((0 << 4) | 11));
	 os<<"| "<<c<<" |"; SetConsoleTextAttribute(Con, ((0 << 4) | 15));
	  for(j=0;j<10;j++)
	  { if(www.M2[i][j]==0){os<<"   ";}
	    if(www.M2[i][j]==1){SetConsoleTextAttribute(Con, ((5 << 4) | 15));os<<" * "; SetConsoleTextAttribute(Con, ((0 << 4) | 15));}
	    if(www.M2[i][j]==-1){os<<" · ";}
	    if(www.M2[i][j]==-2){SetConsoleTextAttribute(Con, ((9 << 4) | 15));os<<" o ";SetConsoleTextAttribute(Con, ((0 << 4) | 15));}
	    if(www.M2[i][j]==-3){os<<"   ";}
	    os<<"|"; 
	  }
	  os<<"\n";  
	}
	os<<"---------------------------------------------\t\t---------------------------------------------\n";
    
	return os;
    }

