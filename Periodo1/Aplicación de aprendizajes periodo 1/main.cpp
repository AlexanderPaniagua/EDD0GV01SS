#include <iostream>
#include <cmath> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
int  total;

    int seleccion;
    cout<<"Bienvenid@, este programa realizara lo solictado segun tarea, escoja su opcion " << endl;
    cout<< " "<< endl << endl;
    cout<<endl<<"Indica el numero de tarea que desees realizar: " <<endl;
    cout<<"(1) Determinar que tipo de triangulo es y su respectiva area" << endl;
    cout<<"(2) Indicar 5 numeros y cual es el mayor de todos" << endl;
    cout<<"(3) Calculo de el promedio de n numeros" << endl;
    cin>>seleccion;
    //Para realizar la operación solicitada utilizamos una estructura switch
    //Intencionalmente se ha omitido el uso de break;
    switch (seleccion) {
        case 1: 
    float a, b, c;
    float sp, area;
    
    cout << "\nPrimer lado: "; cin >> a;
    cout << "\nSegundo lado: "; cin >> b;
    cout << "\nTercer lado: "; cin >> c;
    sp = ( (a+b+c)/2);
    area = sqrt((sp-a)+(sp-b)+(sp-c));
    
    if (a == b && b == c)
        {
		cout << "\nEs un triangulo Equilatero" << endl;
        cout << "\n Su area es :" << area << endl;
        }
    else if (a == b || a == c || b == c)
     {
        cout << "\nEs un triangulo Isosceles" << endl;
        cout << "\n Su area es :" << area << endl;
         } 
    else
       {
	    cout << "\nEs un triangulo Escaleno" << endl;
        cout << "\n Su area es :" << area << endl;
		} 

 
    return 0;

	case 2: 
		int a1, b1, c1, d1, e1;
		{
			cout << "\n Digite los cinco valores a comparar" << endl;
			cout << "\nDato 1: "; cin >> a1;
    		cout << "\nDato 2: "; cin >> b1;
    		cout << "\nDato 3: "; cin >> c1;
    		cout << "\nDato 4: "; cin >> d1;
    		cout << "\nDato 5: "; cin >> e1;
    		 if (a1 >= b1 && a1 >= c1&& a1 >= d1 && a1 >= e1)
        		{
        		cout << "\n El valor mayor es :" << a1 << endl;
        		}
    		else if (b1 >= c1 && b1 >= d1 && b1 >= e1 )
    		 	{
        		cout << "\n El valor mayor es :" << b1 << endl;
        		 } 
    				else if (c1 >= d1 && c1 >= e1 )
     		  			{
	   						 cout << "\n El valor mayor es :" << c1 << endl;
						} 
						else if (d1 >= e1 )
								{
	   							 cout << "\n El valor mayor es :" << d1 << endl;
								} 
							else 
								 cout << "\n El valor mayor es :" << e1 << endl;
    		
		}
		 return 0;
        case 3: 
        int n, i, valor;
        float promedio;
			{
			cout << "Calcularemos el promedio de los datos digitados" << endl;
			cout << "Cuantos valores digitara : "; cin >> n;
			promedio = 0;
			for (i=1; i<=n; i++)
				{
					cout << "Digite el valor " <<i<< ":"; cin >> valor;
					promedio = promedio + valor;
				}
			cout << "El promedio de los " <<n<< " valores es : " << promedio/n << endl;	
			
			}
    return 0; 
        default: cout << "Opcion no valida" << endl;
     
    } //Fin de switch
    cout<<"Gracias por utilizar este programa" << endl;	
	return 0;
}
