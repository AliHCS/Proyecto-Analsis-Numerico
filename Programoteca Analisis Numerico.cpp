/*PROGRAMOTECA DE METODOS NUMERICOS

Gómez Trejo Ali
Hernandez Alaniz Mario Alberto
Polo Pérez Ulises
Romero Sandoval Eliot Misael
Velázquez Rendón Luis Ángel


*/
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<conio.h>
#include <math.h>
#define DIM 10
#define p printf
#define s scanf
#define IterMax 30
#define MAX 10
//Sistema de ecuaciones lineales  
int dim;
float norma(float vector1[],float vector2[]);
float suma_jacobi(float Matriz[], float vector[], int componente);
//Derivada numerica
float funcion(float h, float valor);
//Biseccion
double biseccion (double a, double b, double tol);
double f (double x);
//Simpson 1/3
double g (double x);
double sumaImpares (double a,double h,int n);
double sumaPares (double a,double h,int n);
double Simpson13 (double a,double b,double h,int n);
// Runge Kutta
double A (double x, double y);
double RK4 (double x0,double y0,double h,double x);
double Euler2 (double x0,double y0,double h,double x);
double Euler (double x0,double y0,double h,double x);
//Gauss Jordan
void datos(int *tam, float mat1[][102]);
void esc_data(int tam1, float mat2[][102]);
void solucion(int Dim, float Sist[][102]);
//Newton Rapshon
double gN (double x);
double fN (double x);
double newtonRaphson (double xr, double tol);

int main (void){
	int opcion,n,M, regreso;
	char temporal[10]; //variable donde se guarda el numero que introduce el usuaria para lo que desea usar
	double a,b,tol,h,integral;
inicio:
	do{ //Repeticion
		printf("\t\t\t\tPROGRAMOTECA\n");
		printf("\t\t\t\tMENU DE OPCIONES\n"); //Opciones 
		printf("1) Biseccion \n");
		printf("2) Simpson 1/3\n");
		printf("3) Runge Kutta\n");
		printf("4) Gauss Jordan\n");
		printf("5) Newton Rapshon\n");
		printf("6) Sistemas De Ecuaciones Lineales\n");
		printf("7) Derivada numerica\n");
		printf("8) Euler Mejorado\n");
		printf("9) salir\n");
		//fgets(temporal,10,stdin);//lee la opcion e char por si ingresa caracteres
		//opcion=atoi(temporal); //La trasnforma y  asigna a la variable 
		s("%d",&opcion);
		switch (opcion){
			case 1: 
				system ("cls");//se llaman a las funciones segun la opcion que 
				//double a,b,tol;
     
   				 // Solicitar intervalo y asegurar la convergencia
    			do {
        			printf ("Limite inferior: ");
       				scanf ("%lf", &a);
        			printf ("Limite superior: ");
        			scanf ("%lf", &b);
        			if (f(a)*f(b) < 0) break;
        			printf ("El intervalo no contiene una raiz\n");
   				} while (1);
    				printf ("Tolerancia: ");
    				scanf ("%lf", &tol);
    				printf ("La raiz aproximada= %lf\n", biseccion (a,b,tol));

			
				break;
			case 2:
				system ("cls");
				//int n;
    			//double h,integral;
    			printf ("Limite inferior: ");
    			scanf ("%lf",&a);
    			printf ("Limite superior: ");
    			scanf ("%lf",&b);
    			do {
        			printf ("No de particiones (minimo 2): ");
        			scanf ("%d",&n);
        			if (n > 1 && (n % 2) == 0) break;
        			printf ("Valor invalido, n debe ser #par\n");
    			} while (1);
    			h= (b-a)/n;
    			integral= Simpson13 (a,b,h,n);
    			printf ("La integral aproximada= %lf\n",integral);

				
				break;
			case 3:
				system ("cls");
				double x0,y0,x,y,h;
     
   				printf ("Condicon inicial (x0,y0): ");
    			scanf ("%lf,%lf",&x0,&y0);
    			printf ("Valor de h: ");
    			scanf ("%lf",&h);
    			printf ("Valor de x: ");
    			scanf ("%lf",&x);
    			y= RK4 (x0,y0,h,x);
    			printf ("y'(%lf)= %lf\n", x,y);

				
				break;
			case 4:
				system ("cls");
				 int i,tam;
    			float mat[101][102];
 
    			datos(&tam,mat);
 
    			printf("\n\n\nEcuacion: \n\n");
    			esc_data(tam,mat);
 
 
    			solucion(tam,mat);
 
 
    			printf("\n\n\nSolucion:\n");
   				 for(i=1;i<=tam;i++)
       				printf("\n X%d=%f\n",i,mat[i][tam+1]);
 
    				scanf("");
    				return(0);

			
				break;
			case 5:
				system ("cls");
				 double a,b,w,tol;
                			printf ("Valor inicial: ");
                			scanf ("%lf", &w);
                			printf ("Tolerancia: ");
                			scanf ("%lf", &tol);
                			x=  newtonRaphson (w,tol);
                			printf ("La raiz aproximada= %lf\n", x);
			
				break;
			case 6: 
				 do
             {
            Inicio2:
                system ("cls");
            p ("\n\tSISTEMA DE ECUACIONES LINEALES\n");
            p ("\t(DESCOMPOSICION LU)");
            p ("\n\n1): METODO LU DOLITTE\n\n2): METODO LU CROUTT.\n");
             p ("\n\t(CRITERIO DE CONVERGENCIA)");
            p ("\n\n3): JACOBY \n\n4): REGRESAR AL INICIO.\n");
		    s ("%i",&M);
           switch (M)
              {
            case 1:
                 {   system ("cls");
                   int i,j,k,n;
	              float a[MAX][MAX],b[MAX],x[MAX],l[MAX][MAX],y[MAX],u[MAX][MAX],imp[MAX][MAX],sum,r;
	            p("\n\n     DESCOMPOSICION LU 'DOLITTE'.  \n\n ");
	            p("\n   INGRESA EL NUMERO DE VARIABLES DE TU SISTEMA:  ");
                s("%d",&n);
                p("\nINGRESE LOS DATOS:\n\n");
	           for(i=1;i<=n;i++)
                 {
                 p("\n");
		       for(j=1;j<=n;j++)
		        {
				p("a[%d][%d] = ",i,j);
				s("%f",&a[i][j]);
		       }
               }
               getchar();
              system("cls");
               p("\nLA MATRIZ A ES:\n\n");
              for(i=1;i<=n;i++)
                 {
                 p("\n");
                for(j=1;j<=n;j++)
                {
                 p (" \t%10.5f ", a[i][j]);
                }
                }
             for(i=1;i<=n;i++)
               {
               for(j=1;j<=n;j++)
			   if(i>j)
			   {
			    u[i][j]=0;
			   }
			  else
                  if(i==j)
			    {
			    l[i][j]=1;
			    }
			   }
            for(i=1;i<=n;i++)
               {
               for(j=1;j<=n;j++)
			   if(i<j)
			  {
               l[i][j]=0;
			  }
             }
         	for(i=1;i<=n;i++)
	         {
		    for(j=1;j<=n;j++)
		     {
			 sum=0;
			 if(i<=j)
			{
				for(k=1;k<=n;k++)
                {
                  if(k!=i)
						sum=sum+l[i][k]*u[k][j];
				        u[i][j]=a[i][j]-sum;
                }
             }
             else
              {
				for(k=1;k<=n;k++)
					if(k!=j)
						sum=sum+l[i][k]*u[k][j];
					l[i][j]=(a[i][j]-sum)/u[j][j];
			   }
		      }
          }

          p("\n\n LA MATRIZ L ES:\n\n");
             getchar();
               for(i=1;i<=n;i++)
	            {
                 p("\n    ");
             for(j=1;j<=n;j++)
                        p("\t%10.5f",l[i][j]);
                }
            p("\n\n LA MATRIZ U ES :\n\n");
            getchar();
	       for(i=1;i<=n;i++)
	        {
	     	 p("\n    ");
		    for(j=1;j<=n;j++)
                         p("\t%10.5f",u[i][j]);
	        }
            p("\n");
           getchar();
            etiqueta1:
            p("\n\nINGRESA EL VALOR DEL VECTOR B:\n\n");
           for(i=1;i<=n;i++)
                {
			     {
				    p("b[%d] = ",i);
			    	s("%f",&b[i]);
				   p("\n");
			    }
               }
             y[1]=b[1]/l[1][1];
	        for(i=2;i<=n;i++)
	         {
		      sum=0;
	     	for(j=1;j<=(i-1);j++)
		       {
			   sum=sum+y[j]*l[i][j];
		       }
		       y[i]=(b[i]-sum)/l[i][i];
	         }
	         p("\nEL VECTOR Y ES; \n");
	         for(i=1;i<=n;i++)
             {
              p("\n    ");
                p ("Y[%i]=%10.5f",i,y[i]);
	        }
	         x[n]=y[n]/u[n][n];
	          for(i=(n-1);i>=1;i--)
	        {
		     sum=0;
		     for(j=n;j>i;j--)
               {
               sum=sum+x[j]*u[i][j];
               }
		       x[i]=(y[i]-sum)/u[i][i];
	         }
             p("\n\nLA SOLUCION ES: \n");
	        for(i=1;i<=n;i++)
            {
            p("\n     ");
            p("X[%i]=%10.5f",i,x[i]);
            }
           p("\n\nDESEAS COMPROBAR CON OTRO VECTOR B:(1)SI/(2)NO:\n ");
           s("%f",&r);
          if(r==1)
           {
           goto etiqueta1;
           }else
              goto Inicio2;
                  system("pause");
                }
                break;
           case 2:
                {
                 system ("cls");
                int i,j,k,n;
	            float a[MAX][MAX],b[MAX],x[MAX],l[MAX][MAX],y[MAX],u[MAX][MAX],imp[MAX][MAX],sum,r;
	            p("\n\n     DESCOMPOSICION LU 'CROUTT'.  \n\n ");
	            p("\n   INGRESA EL NUMERO DE VARIABLES DE TU SISTEMA:  ");
                 s("%d",&n);
                 p("\nINGRESE LOS DATOS:\n\n");
	           for(i=1;i<=n;i++)
               {
                p("\n");
		      for(j=1;j<=n;j++)
		        {
				p("a[%d][%d] = ",i,j);
				s("%f",&a[i][j]);
		       }
              }
              getchar();
            p("\nLA MATRIZ A ES:\n\n");
                for(i=1;i<=n;i++)
                {
                 p("\n");
                for(j=1;j<=n;j++)
               {
               p (" \t%10.5f ", a[i][j]);
               }
              }
            for(i=1;i<=n;i++)
              {
              for(j=1;j<=n;j++)
			  if(i>j)
			   {
			  u[i][j]=0;
			  }
			else
                if(i==j)
		    	{
			    u[i][j]=1;
			   }
			  }
            for(i=1;i<=n;i++)
             {
              for(j=1;j<=n;j++)
			   if(i<j)
			   {
			  l[i][j]=0;
			   }
             }
	       for(i=1;i<=n;i++)
	         {
	   	       for(j=1;j<=n;j++)
		     {
			 sum=0;
			 if(i>= j)
			    {
				for(k=1;k<=n;k++)
                {
                  if(k!=j)
						sum=sum+l[i][k]*u[k][j];
				        l[i][j]=a[i][j]-sum;
                }
              }
             else
              {
				for(k=1;k<=n;k++)
					if(k!=i)
						sum=sum+l[i][k]*u[k][j];
					u[i][j]=(a[i][j]-sum)/l[i][i];
			   }
		      }
            }
         p("\n\n LA MATRIZ L ES:\n\n");
            getchar();
               for(i=1;i<=n;i++)
	              {
                 p("\n    ");
                 for(j=1;j<=n;j++)
                        p("\t%10.5f",l[i][j]);
                 }
           p("\n\n LA MATRIZ U ES :\n\n");
            getchar();
	        for(i=1;i<=n;i++)
	           {
		        p("\n    ");
		        for(j=1;j<=n;j++)
                         p("\t%10.5f",u[i][j]);
	            }
           p("\n");
          getchar();
           etiqueta:
        p("\n\nINGRESA EL VALOR DEL VECTOR B:\n\n");
         for(i=1;i<=n;i++)
          {
			{
				p("b[%d] = ",i);
				s("%f",&b[i]);
				p("\n");
			}
		  }
            y[1]=b[1]/l[1][1];
	    for(i=2;i<=n;i++)
	     {
	     	sum=0;
	    	for(j=1;j<=(i-1);j++)
		  {
			sum=sum+y[j]*l[i][j];
		   }
		   y[i]=(b[i]-sum)/l[i][i];
	     }
	     p("\nEL VECTOR Y ES; \n");
	     for(i=1;i<=n;i++)
	         {
              p("\n    ");
                p ("Y[%i]=%10.5f",i,y[i]);
	        }
	         x[n]=y[n]/u[n][n];
	     for(i=(n-1);i>=1;i--)
	       {
		    sum=0;
		     for(j=n;j>i;j--)
              {
             sum=sum+x[j]*u[i][j];
             }
		   x[i]=(y[i]-sum)/u[i][i];
	      }
          p("\n\nLA SOLUCION ES: \n");
	      for(i=1;i<=n;i++)
           {
           p("\n     ");
          p("X[%i]=%10.5f",i,x[i]);
           }
           p("\nDESEAS COMROBAR CON OTRO VECTOR B:(1)SI/(2)NO:\n ");
            s("%f",&r);
          if(r==1)
           {
           goto etiqueta;
          }else
            goto Inicio2;
               system("pause");
                }
              break;
          case 3:
               {
                system ("cls");
                 int i,j,iteraciones=0;
                   float error,epsilon;
                  p("\n\n\t\tMETODO DE JACOBI ( Ax=b) \n\n");
                 p("DAME EL NUMERO DE VARIABLES DE TU SISTEMA: ");
                 s("%d",&dim);
                float A[dim][dim],b[dim],x[dim],x_prev[dim],aux[dim];
                 p("\n\n LOS ELEMENTOS DE TU MATRIZ A: \n\n");
                 for(i=1;i<=dim;i++)
                  {
                       p("\n");
                    for(j=1;j<=dim;j++)
                   {
                    p("A[%d][%d]=",i,j);
                    s("%f",&A[i][j]);
                   }
                  }
                   p("\n ESCRIBE LOS ELEMENTOS DE TU COMPONENTE b: \n");
                 for(i=1;i<=dim;i++)
                   {
                    p("b[%d]=",i);
                    s("%f",&b[i]);
                   }
                    p("\n TOLERANCIA: \n");
                    p("Tol=",i);
                   s("%f",&epsilon);
                   error=epsilon+1;
                  p("\n VALOR INICAL DE LA ITERACION: \n");
                 for(i=1;i<=dim;i++)
                   {
                     p("X0[%d]=",i);
                    s("%f",&x_prev[i]);
                   }
                    while (error>epsilon)
                   {
                    for(i=1;i<=dim;i++)
                    {
                     for(j=1;j<=dim;j++)
                     {
                      aux[j]=A[i][j];
                      x[i]=(1/A[i][i])*(b[i]-suma_jacobi(aux,x_prev,i));
                     }

                     }
                     error=norma(x,x_prev);
                     p("\n\n ITERACION %d: \n",iteraciones);
                    for(i=1;i<=dim;i++)
                     {
                      x_prev[i]=x[i];
                      p("X[%d]=%f \n",i,x[i]);
                    }
                      iteraciones++;
                    if (iteraciones==10) error=epsilon-1;
                  }
                   p("\n\nSOLUCION DEL SISTEMA\n\n");
                   p("NUMERO DE ITERACIONES: %d \n", iteraciones);
                    for(i=1;i<=dim;i++)
					{
                      p("x[%d]=%f\n",i,x[i]);
                    }
                system("pause");
                 }
                break;
               case 4:
               {
                system ("cls");
                goto inicio;
			    regreso=12;
                }
                break;
              }
              system ("cls");
             }
           while (regreso!=12);
            system("pause");
				break;
			case 7:
				{ system ("cls");
            char des='s';
             p("\tPROGRAMA QUE CALCULA LA DERIVADA NUMERICA DEL SENO");
             float valor, h, derivada;
               do
              {
                  p("\nINGRESE EL VALOR DE h\n");
                  s("%f", &h);
                 p("QUE VALOR DESEAS CALCULAR?(En radianes)\n");
                  s("%f", &valor);
                 derivada = funcion(h, valor);
                    p("\nEL VALOR APROXIMADO DE LA DERIVADA DEL SENO  DE %.2f ES: %f\n\n", valor, derivada);
                    p("\nDESEA REALIZAR OTRA OPERACION?\t(s/n)\n");
                   s("%s",&des);
             }while(des=='s');
             goto inicio;
	         system("pause");
          }
				break;
			case 8:
				system ("cls");
				//double x0,y0,x,y,h;
    			printf ("Condicon inicial (x0,y0): ");
    			scanf ("%lf,%lf",&x0,&y0);
    			printf ("Valor de h: ");
    			scanf ("%lf",&h);
    			printf ("Valor de x: ");
    			scanf ("%lf",&x);
    			y= Euler2 (x0,y0,h,x);
    			printf ("y'(%lf)= %lf\n", x,y);
				break;
			case 9:
				printf("Hasta la Proxima UwU\n");
				break;
			default: printf("\nLa opcion que ingreso no es correcta\n");
		
		}
		//system("pause");
	
	}while(opcion !=9); 
	
}
//Biseccion
double f (double x){
    return pow (x,3)-x-1;
}

double biseccion (double a, double b, double tol){
    int i=1;
    double c,er;
     
    do {
        c= (a+b) / 2.0;
        if (f(a)*f(c) < 0)   b= c;
        else            	a = c;
        er = fabs (a-b);
        printf ("%d\t%lf\t%lf\t%lf\t%lf\t\n",i,a,b,c,er);
        i++;
    } while (er > tol && f (c) != 0);
    return c;
}

//Simpson 1/3
double g (double x){
    return 4/(1+pow(x,2));
}
double sumaImpares (double a,double h,int n){
    int i;
    double suma= 0.0;
     
    for (i = 1; i <= n-1; i += 2)
        suma= suma + g(a+h*i);
    return suma;
}
double sumaPares (double a,double h,int n){
    int i;
    double suma= 0.0;
     
    for (i = 2; i <= n-2; i += 2)
        suma= suma + g(a+h*i);
    return suma;
}
double Simpson13 (double a,double b,double h,int n){
    double I;
     
    I= (h/3)*(g(a)+4*sumaImpares(a,h,n)+2*sumaPares (a,h,n)+g(b));
     
     
    return I;
}
// Runge Kutta
double A (double x, double y){
    return 2*x*y;
}
double RK4 (double x0,double y0,double h,double x){
    double xi,yi;
    double k1,k2,k3,k4;
    int i,n;
     
    n= (int) ((x-x0)/h);
    printf ("x-x0= %lf,N= %d\n",x-x0,n);
    for (i= 0; i <= n; i++) {
//  	printf ("%lf %lf\n",x0,x);
        xi= x0+h;
         
        k1= A (x0,y0);
        k2= A (x0+h/2,y0+h/2*k1);
        k3= A (x0+h/2,y0+h/2*k2);
        k4= A (x0+h,y0+k3*h);
        yi= y0+(h/6*(k1+2*k2+2*k3+k4));
         
        printf ("%d\t%lf\t%lf\t%lf\n",i+1,xi,h,yi);
        x0= xi;
        y0= yi;
    }
    return yi;
}
// Metodo de Euler Mejorado
double Euler2 (double x0,double y0,double h,double x){
    double xi,yi,yii;
    int i= 1;
         
    do {
//  	printf ("%lf\n", x);
        xi= x0+h;
        yii= y0+h*A(x0,y0);
        yi= y0+h*((A(x0,y0)+A(xi,yii))/2);
         
        printf ("%d\t%lf\t%lf\t%lf\n",i,xi,h,yi);
        x0= xi;
        y0= yi;
        i++;
    } while (x0 < x);
    return yi;
}
// Metodo de Euler
double Euler (double x0,double y0,double h,double x){
    double xi,yi;
    int i= 1;
         
    while (x0 < x) {
        xi= x0+h;
        yi= y0+h*A(x0,y0);
        printf ("%d\t%lf\t%lf\t%lf\t%lf\t\n",i,x0,y0,h,yi);
        x0= xi;
        y0= yi;
        i++;
    }
    return yi;
}
//Gauss Jordan
void datos(int *tam,float mat1[][102]){
    int j,k;
    printf("\n\n SISTEMA DE ECUACIONES POR GAUSS");
    printf("\n\n\n INCOGNITAS: ");
    scanf("%d",&*tam);
    printf("\n\n MATRIZ DE INCOGNITAS:\n");
    for(j=1;j<=*tam;j++)
        for(k=1;k<=*tam;k++)
        {
        printf("\n VALORES MATRIZ(%d,%d):",j,k);
    scanf("%f",&mat1[j][k]);
    }
 
    for(j=1;j<=*tam;j++){
        printf("\n VECTOR DE RESULTADOS(%d):",j);
        scanf("%f",&mat1[j][*tam+1]);
    }
    }
 
void esc_data(int tamano, float mat2[][102]){
    int x,y;
 
    for(x=1;x<=tamano;x++)
    {
 
        for(y=1;y<=(tamano+1);y++)
        {
            printf("%7.2f",mat2[x][y]);
            if(y==tamano)
             printf("   |");
        }
 
        printf("\n");
    }
}
 
void solucion(int tam, float mat[][102]){
    int res,i,j,k,m;
    float col_pivote,x;
 
    for(i=1;i<=tam;i++)
    {
 
        res=0;m=i;
 
            ///COMPRUEBA LA POSICION DEL PIVOTE EN EL PRIMER RENGLON
            ///MEJORAS:
            ///AGREGAR EXCEPCION PARA CASOS: 0=1
            ///AGREGAR EXCEPCION PARA ECUACIONES NULAS 0=0
            while(res==0)
            {
                    if((mat[m][i]>0.0000001)||((mat[m][i]<-0.0000001)))
                    {
                            res=1;
                    }
                    else
                    m++;
            }
 
        col_pivote=mat[m][i];
 
            ///DIVIDE PRIMER RENGLON ENTRE PIVOTE
            for(j=1;j<=(tam+1);j++)
            {
                x=mat[m][j];
                mat[m][j]=mat[i][j];
                mat[i][j]=x/col_pivote;
            }
 
 
            for(k=i+1;k<=tam;k++)
            {
                x=mat[k][i];
 
                    for(j=i;j<=(tam+1);j++)
                    {
                        /*
                    printf("%7.2f",mat[k][j]);
                    printf("%7.2f",mat[i][j]);
                    printf("I:%d J:%d",i,j);*/
                    mat[k][j]=mat[k][j]-x*mat[i][j];
                    /*
                    printf("%7.2f",mat[k][j]);
                    printf("%7.2f",x);
                    */
                    }
            }
 
 
 
                            int a,b;
    printf("\nInteracion %d: \n\n",i);
                            for(a=1;a<=tam;a++)
                            {
 
                                for(b=1;b<=(tam+1);b++)
                            {
                                printf("%7.2f",mat[a][b]);
                                        if(b==tam)
                                            printf("   |");
                            }
 
 
                                printf("\n");
                            }
 
                            system("pause");
 
    }
 
    int a,b;
    printf("\n\nMatriz despues de iteraciones:\n");
    a=0;
    b=0;
    for(a=1;a<=tam;a++)
    {
        for(b=1;b<=(tam+1);b++)
        {
            printf("%7.2f",mat[a][b]);
            if(b==tam)
             printf("   |");
        }
 
        printf("\n");
    }
 
 
 
    for(i=tam;i>=1;i--)
        for(j=(i-1);j>=1;j--)
        {
        mat[j][tam+1]=mat[j][tam+1]-mat[j][i]*mat[i][tam+1];
        mat[j][i]=0;
        }
 
 
printf("\n\nMatriz final diagonal:\n");
    a=0;
    b=0;
    for(a=1;a<=tam;a++)
    {
 
        for(b=1;b<=(tam+1);b++)
        {
            printf("%7.2f",mat[a][b]);
            if(b==tam)
             printf("   |");
        }
 
        printf("\n");
    }
}
//Newton Rapshon
double gN (double x) {
    return 2*x+9;
}
double fN (double x){
    return pow(x,2)+9*x+4;
}
double newtonRaphson (double xr, double tol){
    double x0,er;
    int i=1;
     
    printf ("It.\tXi+1\tXi\tf(x)\tf'(x)\tEr\t\n");
    do {
        x0= xr;
        xr= x0 - fN(x0) / gN(x0);
         
        er = fabs (xr-x0);
        printf ("%d\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%lf\n",i,xr,x0,fN(x0),gN(x0),er);
        i++;
    } while (er > tol && fN(xr) != 0);
    return xr;
}
double biseccion2 (double a, double b, double tol){
    int i=1;
    double c,er;
     
    printf ("It.\ta\tb\tc\tf(a)\tf(c)\tEr\t\n");
    do {
        c= (a+b) / 2.0;
        er = fabs (a-b);
        printf ("%d\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t\n",i,a,b,c,fN(a),fN(c),er);
        if (fN(a)*fN(c) < 0)   b= c;
        else            	a = c;
        i++;
    } while (er > tol && fN (c) != 0);
    return c;
}

//Sistema de ecuaciones
float norma(float vector1[],float vector2[]){
    float aux=0;
    int i;
    for(i=1;i<=dim;i++){
        aux=aux+(vector1[i]-vector2[i])*(vector1[i]-vector2[i]);
    }
    return aux;
}
float suma_jacobi(float Matriz[], float vector[], int componente){
    float aux=0;
    int i;
    for(i=1;i<=dim;i++){
        if (componente!=i){
            aux=aux+Matriz[i]*vector[i];
        }
    }
    return aux;
}
//Derivada Numerica 
float funcion(float h, float valor){
    float f = ((sin(valor+h))-(sin(valor-h)))*(1/(2*h));
    return f;
}

