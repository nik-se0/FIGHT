#include "polynom.h"
#include <iostream>
using namespace std;

void menu()
{ cout << "\n\t1. Add two polynomials\n\t2. Subtract two polynomials\n\t3. Multiply a polynomial by a constant\n\t4. Multiply two polynomials\n\t5. Calculate the polynomial\n\t0. Exit\n\n\tInput: ";
}

int main()
{ int  entry = 1, entry2 = 0, f = 0, i;
  Polynom P [20];
  Polynom P1, P2, P3;
  double c;

  while (entry != 0)
    { system("cls");
      cout << "\t\tPOLYNOMIALS\n";
      menu();
      cin >> entry;
      if (entry != 0)
      {  system("cls");
        cout << "\n\t\tENTERING ARGUMENTS TO EXECUTE THE EXPRESSION";
        if (f >= 2) 
        { cout << "\n\t1. Introduce a new polynomial\n\t2. Use the written polynomial\n\n\tInput: ";
          cin >> entry2;
        }
        if((f<2)||(entry2==1))
        { cout<<"\n\t\tEntering the first argument.\n"; 
          cin>>P1;
          if ((entry != 5)&&(entry != 3)) { cout << "\n\n\t\tEntering the second argument.\n"; cin >> P2; }
        }
        else 
        { i=0; system("cls");
          cout << "\n\tSTORED POLYNOMIALS:\n";
          while(i<f)
          {cout << "\t F" << i << "\t" << P[i] << endl; i++;}
          cout << "\n\tEnter the sequence number of the polynomial\n\tInput: ";
          int q=0, w=0;
          if((entry == 5) || (entry == 3)) {cin >> q;}
          else { cin >> q >> w; }
          P1 = P[q];
          P2 = P[w];
        }
        system("cls");
        cout << "\n\t\t ENTERED:\n\tF1 - " << P1;
        switch (entry)
       { case 1: cout << "\n\tF2 - " << P2<< "\n\tAdd two polynomials: "; P3= P1 + P2; cout<<P3;
                break;
       case 2: cout << "\n\tF2 - " << P2 << "\n\tSubtract two polynomials: ";  P3 = P1 - P2; cout << P3;
                break;
        case 3: cout<<"\n\tEnter a constant\n\tInput: ";
                cin>> c;    
                cout << "\n\tMultiply a polynomial by a constant: ";  P3 = P1 * c; cout << P3;
                break;
        case 4: cout << "\n\tF2 - " << P2 << "\n\t4. Multiply two polynomials: "; P3 = P1 * P2; cout << P3;
                break;
        case 5: cout << "\n\tCalculate the polynomial:"<<P1.Сalculate() << "\n\tTo continue, enter any character: ";
                char e; cin >> e;
                break;
      }
        cout<<"\n\n\tDo you want to save polynomials?\n\t1. Yes\n\t2. No\n\tInput: ";
        cin >> entry2;
        if (entry2 == 1)         
        {  if (entry == 5) { P[f] = P1; f=f+1; }
          else
          { if (entry == 3) { P[f] = P1; P[f+1]=P3; f=f+2; }
          else { P[f] = P1; P[f + 1] = P2; P[f + 2] = P3;  f=f+3; }
        }
        }
      }
                
    }

	
}