/*PROGRAMOTECA DE METODOS NUMERICOS

Encarnacion Angeles Carlos……………… 15
Hernández Medrano Abigali ……………….26
Martínez Hernández Alonso Yosafat……...30
Quiñonez Ginez Erik ……………………….38
Reyes Martínez Abigail Valeria…………….39
Rodriguez Jimenez Gilde Valeria………….44

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define p printf
#define s scanf
#define IterMax 30
#define MAX 10
int dim;
float norma(float vector1[],float vector2[]);
float suma_jacobi(float Matriz[], float vector[], int componente);
void grafica();
double Funcion(double ab);
float funcion(float x);

float funcion(float x)
{
    return cos(x)-3*x;
}
void grafica(){
               double es,ab,ord;
               int i,o;
               do{
                  p("\n\tINGRESE EL LIMITE INFERIOR DEL INTERVALO EN QUE DESEA GRAFICAR LA FUNCION: ");
                  s("%lf",&ab);
                  p("\tSE GRAFICARAN 10 DATOS\n");
                  p("\n\tINGRESE EL ESPACIAMIENTO: ");
                  s("%lf",&es);
                  p("\n\t\t   X\t  ||\t  Y\n");
                  for(i=0;i<11;i++)
                  {
                    ord=pow(ab,4)-5*pow(ab,3)+2*pow(ab,2)+ab;
                    p("\n\t\t%f\t%.5f",ab,ord);
                    ab=ab+es;
                  }
                  p("\n\n\n\tDESEA GRAFICAR OTRO INTERVALO\n\n\t1)SI\n\t2)NO\n\n\t--> ");
                  s("%i",&o);
                  }while(o==1);
}
float norma(float vector1[],float vector2[])
{
    float aux=0;
    int i;
    for(i=1;i<=dim;i++){
        aux=aux+(vector1[i]-vector2[i])*(vector1[i]-vector2[i]);
    }
    return aux;
}
float suma_jacobi(float Matriz[], float vector[], int componente)
{
    float aux=0;
    int i;
    for(i=1;i<=dim;i++){
        if (componente!=i){
            aux=aux+Matriz[i]*vector[i];
        }
    }
    return aux;
}
double Funcion(double ab)
{
	return(pow(ab,4)-5*pow(ab,3)+2*pow(ab,2)+ab);
}

float buscaRaiz(float xo, float pendiente)
{
    float e = 0, xa = 0;
    int i = 0;
    p("\n\n\tx(i)         ||   RAIZ                    ||  ERROR                   \n ");
    do{
        xa = xo;
        xo = (funcion(xa)-(pendiente*xa))/-(pendiente);
        e=(xo-xa)/xo;
        if(e<0){
            e = -e;
        }
        p("\nx-%d             %f                   %f\n",i,xo,e);
        i++;
    }
    while(e > 0.0005);
return xo;
}
float pendiente(float x)
{
    return -sin(x)-3;
}
void tabular(int a , int b , float c){
    int d = 0, r = 0;
    float i = 0, s = 0;
    printf("%d   %d   %f",a,b,c);
    if(b < a){
        c=a;
        a=b;
        b=c;
    }
    if(b == a){
        p("\n\n\t\tERROR\n\n");
    }
    p("\n\tITERACION  ||       F(X)               \n");
    for(i=a ; i <= b ; i=i+c)
    {
    s = funcion(i);
    printf("\n%d         ||%f                ",r,s);
    r = r+1;
    }
    p("\n\n****");
}
float funcion(float h, float valor);
float funcion(float h, float valor)
{
    float f = ((sin(valor+h))-(sin(valor-h)))*(1/(2*h));
    return f;
}
float trapecio()
{
    int tama;
    float a, b, h,m=0, suma=0, resultado=0;
    int i=0, n;
    p ("\n\tINGRESE EL INTERVALO");
    p ("\n\ta= ");
    s("%f",&a);
    p("\n\tb= ");
    s("%f",&b);
    p("\nINGRESE EL VALOR DE n(n-1 puntos o numero de segmentos): ");
    s("%d",&n);
    h=(b-a)/n;
    tama=n;
    m=a;
    float Puntos[tama];
    p("\nINGRESE LOS VALORES DE LA FUNCION");
    while(i<=tama)
    {
        p("\n\tY(%.2f)= ",m);
        s("%f",&Puntos[i]);
        i++;
        m=m+h;
    }
    for (i=0; i<tama; i++)
    {
      if (i==tama || i==0)
        suma = suma;
      else
          suma=suma+(2*Puntos[i]);

    resultado = (h/2)*(suma+ Puntos[0]+Puntos[tama]);;
    }
return resultado;
}

 main ()
 {
     system ("color F0");
 	int M, Iter,tab;
        p ("\n\t--- BIENVENIDO A LA PROGRAMOTECA DE METODOS NUMERICOS ---\n\n\tPRESIONE UNA TECLA PARA CONTINUAR... ");
       getchar();
    do
    {
    inicio:
        system ("cls");
        p ("\n\tA CONTINUACION SE MUESTRAN LOS PROGRAMAS DISPONIBLES\n\tPOR FAVOR SELECCIONE EL QUE DESEA UTILIZAR:\n");
        p ("\n\t\t1) CALCULADORA DE SIN(X).\n\t\t2) SOLUCION DE ECUACIONES ALGEBRAICAS Y TRASCENDENTES.\n\t\t3) SISTEMAS DE ECUACIONES LINEALES.\n");
        p ("\t\t4) INTERPOLACION.\n\t\t5) DERIVACION NUMERICA.\n\t\t6) INTEGRACION NUMERICA.\n\t\t7) SALIR DEL PROGRAMA.\n\n\tSELECCION: ");
		s ("%i",&M);
        switch (M)
      {
        case 1:
           {    system ("cls");
               int signo=1,cifras,G,conti,contf,fact,i,salto=2,opt=1,z;
               float a,X,error,PI=3.141593;
               float r,sen,ant;
               p("\n\t\t--- CALCULADORA DE SIN(X) ---\n\n");
               do{
               p ("\n\tINGRESE EL VALOR DEL ANGULO X QUE DESEA CALCULAR:\n\tX = ");
               s ("%f",&X);
               p ("\n\n\tINDIQUE SI EL VALOR DE X ESTA EN RADIANES\n\t\t1.- SI\n\t\t2.- NO\n\n\tSELECCION: ");
               s("%i",&G);
               p("\n\tCUANTAS CIFRAS SIGNIFICATIVAS EXACTAS DESEA: ");
               s("%i",&cifras);
               error=0.5*pow(10,(2-cifras));
               system("cls");

              if (G==2)
                {
                 a=X*PI/180;
                 p("\n\tEL ANGULO ES IGUAL A %f RADIANES\n",a);}

              else
                 a=X;

              z=a/PI;
              a=a-z*PI;
              if (a>(PI/2))
                a=a-PI/2;

              if (z%2==0)
                 signo=1;
              else
                 signo=-1;

              if (a==0){
                    sen=0;
                    if (G==2)
                       p("\n\t\tEL VALOR DEL SENO DE %.5f GRADOS ES %i",X,sen);
                    else
                       p("\n\t\tEL VALOR DEL SENO DE %.5f RADIANES ES %i",X,sen);
                       }
              else
              if (a==(PI/2))
                 {
                     if (G==2)
                    p("\n\tEL VALOR DEL SENO DE %.5f GRADOS ES %i",X,signo);
                  else
                    p("\n\tEL VALOR DEL SENO DE %.5f RADIANES ES &i",X,signo);}
               else{

               sen=a;
               conti=1;
               contf=1;
               fact=1;
               p("\n\tITERACION\tSENO(%.5f)\t\tERROR\n",X);
               p("\t\t%i\t%.5f\t\t\t------",conti-1,sen);

               do
               {
                contf=contf+2;
                fact=fact*(contf-1)*contf;
                ant=sen;
                conti++;

                if(conti%2==0)
                    sen=sen-pow(a,contf)/fact;
                else
                    sen=sen+pow(a,contf)/fact;
                r=sen-ant;
                if (r<0)
                    r=-1*r;
                r=(r/sen)*100;
                p("\n\t\t%i\t%5f\t\t%5f",conti-1,sen,r);
                }while(r>=error);
                sen=signo*sen;
                if (G==2)
                    p("\n\n\tEL VALOR DEL SENO DE %.5f GRADOS ES %f",X,sen);
                  else
                    p("\n\n\tEL VALOR DEL SENO DE %.5f RADIANES ES %f",X,sen);}
                p("\n\n\tERROR < %.5f\n\tCIFRAS SIGNIFICATIVAS EXACTAS: %i\n\n",error,cifras);
                getchar();

                p("\n\n\tDESEA CALCULAR EL SENO DE OTRO ANGULO\n\t1)SI\n\t2)NO\n\tSELECCION: ");
                s("%i",&opt);
                system("cls");
               }while(opt==1);}
              break;
      case 2:
          {  system("color F0");
             double fa, fb, fc,a,b,c,prod,res, Error;
             int M, regreso;
             do
             {
            volver1:
            system ("cls");
            p ("\n\t--- SOLUCION DE ECUACIONES ALGEBRAICAS Y TRASCENDENTES ---\n\n\tSELECCIONE QUE METODO DESEA UTILIZAR");
            p ("\n\n\tMETODOS CERRADOS:\n");
            p ("\n\t1) METODO DE BISECCION\n\t2) METODO DE LA REGLA FALSA.\n");
            p ("\n\tMETODOS ABIERTOS:\n");
            p ("\n\t3) METODO DE LA SECANTE\n\t4) REGRESAR AL INICIO.\n\n\tSELECCION: ");
		    s ("%i",&M);
           switch (M)
              {
             case 1:
                {
                 system ("cls");
                  p("\n\t\t--- SOLUCION NUMERICA DE ECUACIONES ALGEBRAICAS Y TRASCENDENTALES ---\n\tMETODO CERRADO: BISECCION\n");
                  volver:
                  p("\n\tF(x)=X^4 - 5X^3 + 2X^2 + X");
                  p("\n\tDESEA TABULAR LA FUNCION\n\t1) SI\n\t2) NO\n\t-->");
                  s("%i",&tab);
                  if (tab==1)
                      grafica();
                  p("\n\n\tINGRESA LOS LIMITES PARA COMENZAR A ITERAR\n\n");
                  do{
                  p("\n\tLIMITE INFERIOR: ");
                  s("%lf",&a);
	              p("\n\tLIMITE SUPERIOR: ");
	              s("%lf",&b);
	              res=Funcion(a)*Funcion(b);
	              if(a>b)
                    p("\n\n\tERROR, EL LIMITE INFERIOR DEBE SER MENOR AL LIMITE SUPERIOR. INTENTA NUEVAMENTE");
                  if(res>0)
                    p("\n\n\tERROR, EL INTERVALO ESTA MAL DEFINIDO, DEBE HABER UN CAMBIO DE SIGNO ENTRE LOS PUNTOS. INTENTA NUEVAMENTE\n");
	              }while(a>b||res>0);

                  p("\n\tINGRESE EL VALOR DE LA TOLERANCIA: ");
                  s("%lf",&Error);
                  p("\n\tn\t a\t\t  c\t\t  b\t\t  f(a)\t\t  f(c)\t\t  f(b)\t\t  f(a)f(b)\n");
                  Iter=0;

                do
	                {
                     c=(a+b)/2;
                     fa=Funcion(a);
		             fb=Funcion(b);
		             fc=Funcion(c);
		             prod=fa*fc;
                     res=fa*fb;
                     p("\n\t%i\t%f\t%f\t%f\t%f\t%f\t%f\t%f",Iter,a,c,b, fa, fc, fb ,res);
                     if(prod<0)
				          b=c;
                     else
				         a=c;
                     Iter++;
                  }while(fabs(fc)>=Error);

                  p("\n\n\tLA RAIZ ES: %lf\n\n",c);
                  p("\n\n\tQUE DESEA HACER\n\n\t\t1)CALCULAR OTRA RAIZ\n\t\t2)USAR OTRO METODO\n\t\t3)VOLVER AL MENU PRINCIPAL\n\n\t\t-->");
                  s("%i",&tab);
                  if(tab==1)
                   goto volver;
                  else if(tab==2)
                          goto volver1;
                       else if (tab==3)
                             goto inicio;
                  }
                 break;
            case 2:
            {   system ("cls");
                int r,r1;
                double m,n,e,X,Y,i;
                p("\n\t\t--- SOLUCION NUMERICA DE ECUACIONES ALGEBRAICAS Y TRASCENDENTALES ---\n\tMETODO CERRADO: REGLA FALSA\n");
                v1:
                p("\n\tF(x)=X^4 - 5X^3 + 2X^2 + X");
                p("\n\tDESEA TABULAR LA FUNCION\n\t1) SI\n\t2) NO\n\t-->");
                s("%i",&tab);
                if (tab==1)
                    grafica();
                p("\n\n\tINGRESA LOS LIMITES PARA COMENZAR A ITERAR\n\n");
                do{
                  p("\n\tLIMITE INFERIOR: ");
                  s("%lf",&a);
	              p("\n\tLIMITE SUPERIOR: ");
	              s("%lf",&b);
	              res=Funcion(a)*Funcion(b);
	              if(a>b)
                    p("\n\n\tERROR, EL LIMITE INFERIOR DEBE SER MENOR AL LIMITE SUPERIOR. INTENTA NUEVAMENTE");
                  if(res>0)
                    p("\n\n\tERROR, EL INTERVALO ESTA MAL DEFINIDO, DEBE HABER UN CAMBIO DE SIGNO ENTRE LOS PUNTOS. INTENTA NUEVAMENTE\n");
	              }while(a>b||res>0);

                  p("\n\tINGRESE EL VALOR DE LA TOLERANCIA: ");
                  s("%lf",&Error);
                  p("\n\tn\t a\t\t  c\t\t  b\t\t  f(a)\t\t  f(c)\t\t  f(b)\t\t  f(a)f(b)\n");
                  Iter=0;
                  do {
                    fa=Funcion(a);
                    fb=Funcion(b);
                    c=a-fa*((b-a)/(fb-fa));
                    fc=Funcion(c);
                    prod=fa*fc;
                    res=fa*fb;
                    p("\n\t%i\t%f\t%f\t%f\t%f\t%f\t%f\t%f",Iter,a,c,b, fa, fc, fb ,res);
                    if(prod<0)
                        b=c;
                    else
                        a=c;
                    Iter++;
                }while(fabs(fc)>=Error);
                p("\n \n %lf ES UNA RAIZ ",c);
                p("\n\n\tQUE DESEA HACER\n\n\t\t1)CALCULAR OTRA RAIZ\n\t\t2)USAR OTRO METODO\n\t\t3)VOLVER AL MENU PRINCIPAL\n\n\t\t-->");
                s("%i",&tab);
                if(tab==1)
                   goto v1;
                else if(tab==2)
                   goto volver1;
                else if (tab==3)
                   goto inicio;
                }
                break;
           case 3:
                 p("\n\t\t--- SOLUCION NUMERICA DE ECUACIONES ALGEBRAICAS Y TRASCENDENTALES ---\n\tMETODO ABIERTO: METODO DE LA SECANTE\n");
                 system ("cls");
                 int op = 0 , a = 0 , b = 0 , d=0 ;
                  float c = 0 , xo=0, raiz = 0, pendiente = 0, r=0;
                 do{
                    p("\n\tF(x)=COS(X)-3X\n");
                    p("\n\n\tQUE DESEAS HACER?:\n\n\t(1)TABULAR\n\t(2)BUSCAR RAIZ EN INTERVALO \n\t(3)REGRESAR\n");
                    p("\n\n\tINGRESE LA OPCION DESEADA: ");
                    s("%d",&op);
                 switch(op)
	                {
                      case 1 :
                           {
			                p("\nINGRESE EL INTERVALO\nINGRESE a: ");
                             s("%d",&a);
                             p("\nINGRESE EL VALOR DE b: ");
                             s("%d",&b);
                             p("\nINGRESE EL TAMAÑO DEL ESPACIO ENTRE TABULACION: ");
                            s("%f",&c);
                             tabular(a,b,c);
                           }
                         break;
                      case 2 :
                      	{
                              p("\n\n\tINGRESA LOS LIMITES PARA COMENZAR A ITERAR\n");
                              v3:
                      		  p("\n\tLIMITE INFERIOR: ");
                              s("%lf",&a);
	                          p("\n\tLIMITE SUPERIOR: ");
	                          s("%lf",&b);
                             if(b <= a)
							 {
                                  c = a;
                                  a = b;
                                  b = c;
                             }
                              if ( a == b)
							  {
                                p("\nERROR\n");
                                goto v3;
                                break;
                              }
                               r = b-a;
                                r = r/2;
                             pendiente = (funcion(b)-funcion(a))/(b-a);
                            raiz = buscaRaiz(r, pendiente);
                            p("\n\n\t\tLA RAIZ ES: %f\n\t\tCON UN ERROR PREFIJADO DE 0.0005\n\n",raiz);
                      	 }
                             break;
                          default:
                         break;
                        }
	                }while(op !=3);
               system("pause");
                }
              break;
           }while (M!=4);
           goto inicio;
           break;
      case 3:
          {  system ("cls");
             system("color F0");
              int M, regreso;
             do
             {
            Inicio2:
                system ("cls");
            p ("\n\tSISTEMA DE ECUACIONES LINEALES\n");
            p ("\t(DESCOMPOSICION LU)");
            p ("\n\n'1': METODO LU DOLITTE\n\n'2': METODO LU CROUTT.\n");
             p ("\n\t(CRITERIO DE CONVERGENCIA)");
            p ("\n\n'3': JACOBY \n\n'4': REGRESAR AL INICIO.\n");
		    s ("%i",&M);
           switch (M)
              {
            case 1:
                 {   system ("cls");
                   system("color F0");
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
                system("color F0");
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
          }
              break;
      case 4:
          {
              system("cls");
              int grado=0, i=0;
             float yk=0 , k=0, h=0, xo=0, segDif=0, terDif=0, x=0;
            float princ[4][2]={{0}};
             p("%f",pow(k,2));
             p("DE QUE GRADO ES EL POLINOMIO ANALISE LOS PUNTOS, MAXIMOS GRADO 3\n\n");
            s("%d",&grado);
            p("\n\nSE NECESITAN GRADO+1 PUNTOS CONOCIDOS Y EL VALOR A INTERPOLAR DEBE ESTAR ENTRE ESTOS \n");
            p("INDIQUE EL ESPACIAMIENTO----");
            s("%f",&h);
             p("\nINGRESE EL VALOR INICAL DE x PARA COMENZAR A TABULAR HACIA ADELANTE:  ");
             s("%f",&xo);
             for (i = 0; i<=grado ; i++)
			 {
               princ[i][0] = i;
                princ[i][1] = xo+(h*i);
             }
             p("\nINGRESE LOS VALORES DE Y CORRESPONDIENTES\n\n");
            for (i=0 ; i<=grado ; i++)
			{
              p("y-%f-  ",xo+h*i);
              s("%f",&princ[i][2]);
              p("\n");
           }
             p("\nINGRESE EL VALOR DE x A INTERPOLAR");
             s("%f",&x);
             k = (x-princ[0][1])/h;
                if (grado == 1)
				{
                 yk = princ[0][2]+k*(princ[1][2]-princ[0][2]);
                 p("\nyk = %f",yk);
                }
            if (grado == 2)
			{
              segDif = (princ[2][2]-princ[1][2])-(princ[1][2]-princ[0][2]);
              yk = princ[0][2]+k*(princ[1][2]-princ[0][2])+((pow(k,2)-k)/2)*segDif;
              p("\nyk = %f",yk);
           }
               if (grado == 3)
			   {
                 segDif = (princ[2][2]-princ[1][2])-(princ[1][2]-princ[0][2]);
                   terDif = (princ[3][2]-princ[2][2])-princ[1][3];
                  terDif = terDif-segDif;
                  yk = princ[0][2]+k*(princ[1][2]-princ[0][2])+((pow(k,2)-k)/2)*segDif+((pow(k,3)-3*pow(k,2)+2*k)/6)*terDif;
                  p("\nyk = %f",yk);
               }
                p("\nLISTO");
              system("pause");
          }
          break;
      case 5:
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
	         system("pause");
          }
              break;
          case 6:
          { system ("cls");
              char des = 's';
               p("\tINTEGRACION TRAPECIAL");
              do
              {
               float integral = trapecio();
              p("\n\nEl RESULTADO ES: %.2f", integral);
              p("\n\nDESEA REALIZAR OTRA OPERACION?(s/n)\n");
              s("%s",&des);
              }while(des!='n');
              system("pause");
          }
          break;
   }
   }}while (M!=7);
    system ("cls");
    p("\n\t\t\t\t............FIN DEL PROGRAMA............\n\n\n");
    system("pause");
    return 0;
 }

