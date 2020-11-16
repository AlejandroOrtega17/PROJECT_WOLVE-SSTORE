#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>


using namespace std;

struct venta{
    string lote;
    int numero;
    //precio de compra
    int Precio;
};

struct articulos{
    int cantidad;
    float TCP;
    //precio de compra

    //precio de flores
    float preciof1 = 3.50; 
    float preciof2 = 3.25;
    float preciof3 = 5.00;
    //precio de abono
    float precioa1 = 5.50;
    float precioa2 = 10.50;
    //precio de herramientas
    float precioh1 = 8.50;
    float precioh2 = 5.99;

};
typedef struct articulos AT;

struct unArticulo{
//colas de plantas
queue <AT> Rosa;
queue <AT> Girasol;
queue <AT> clavel;
//colas de abonos
queue <AT> AbonoSencillo;
queue <AT> AbonoGrande;
//colas de herramientas
queue <AT> HR;
queue <AT> HP;
};
typedef struct unArticulo UA;

UA AU;


//prototipos de funciones
//MENU ADMIN 
void agregarInventario();
void menuadmin();
void inventario();
void showtime();
void agregar();
void showQueue();
void ganacia();

//MENU CLIENTES
void cliente();
void tipplatas();
void tipaono();
void tipherramientas();
void factura();


//creamos la lista
list<venta> backspace;

//acumuladores
float acumR1, acumG2, acumC3, acumA1, acumA2,acumHR,acumHP;
float ACPR1, ACPG2, ACPC3, ACPA1, ACPA2, ACPHR, ACPHP;

//programa principal

int main(){

system("CLS");
cout <<"\n****Tiendita de las plantitas****"<<endl; 

int opcion;
bool continuar1 = true;

do{

    cout<<"\n\t 1) Administrador";
    cout<<"\n\t 2) Cliente";
    cout<<"\n\t 3) Salir";
    cout<<"\n Digite su opcion: ";
        cin>>opcion;

    switch (opcion){
        case 1: menuadmin(); break;

        case 2: cout<<"\n\t\tBIENVENIDO A LA TIENDITA DE LAS PLANTITAS";    
        cliente(); break;

        case 3: cout<<"Gracias por su visita."<<endl; 
        continuar1 = false; break;

        }
}while(continuar1);

return 0; }
 
void menuadmin(){

   bool continuar2 = true;

   int admin1 = 0;
       
   do{
      
      cout<<"\n\t1) Inventario";
      cout<<"\n\t2) Ganancias de ventas";
      cout<<"\n\t3) Ir al menu principal";
      cout<<"\nDigite su opcion: ";
      cin>>admin1;

    switch (admin1){
        case 1: inventario(); break;
        
        case 2:  ganacia(); break;

        case 3: continuar2 = false; break;

    }
   }while(continuar2);
}

void inventario(){

 bool continuar3 = true;
 
   int lot = 0;
   do{
       
   cout<<"\n\t1) Actualizar inventario";
   cout<<"\n\t2) Ver el inventario";
   cout<<"\n\t3) Salir";
   cout<<"\nDigite su opcion: ";
   cin>>lot;

    switch (lot){
        case 1: //agregar compras
        agregar();break;
        
        case 2: //Ver inventario
        showtime();
        break;

        case 3:
       continuar3 = false; break;

        break;

    }
   }while(continuar3);
}

 void agregar(){
    AT PNU;

    cout << "\n\t\tSeleccione lo que desee agregar al inventario" << endl;

    bool  select = true;
    do{
        
        int cheek =0;
        cout << "\n1)Rosas unicornio\n";
        cout << "2)Girasol de la vida\n";
        cout << "3)Clavel de la noche\n";
        cout << "4)Abono sencillo\n";
        cout << "5)Abono grande\n";
        cout << "6)Rastrillos\n";
        cout << "7)Palas\n";
        cout << "8) salir\n";
        cout << "Opcion elegida:  ";
        cin >> cheek; cin.ignore();  
    
        switch (cheek){
            
        case 1:
        cout << "Digite la cantidad: "; cin >> PNU.cantidad;
            PNU.TCP = PNU.cantidad * PNU.preciof1;  
        cout << "El precio de la compra: " << PNU.TCP << endl;
            AU.Rosa.push(PNU);
                acumR1+=PNU.cantidad;
                ACPR1+= PNU.TCP;
        select = false;
         break;

        case 2:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad; 
            PNU.TCP = PNU.cantidad * PNU.preciof2;  
         cout << "El precio de la compra: " << PNU.TCP << endl;
            AU.Girasol.push(PNU);
                acumG2+=PNU.cantidad;
                ACPG2+= PNU.TCP ;
        select = false;
         break;

        case 3: 
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.preciof3;  
         cout << "El precio de la compra: " << PNU.TCP << endl; 
            AU.clavel.push(PNU); 
                acumC3 += PNU.cantidad;
                ACPC3+= PNU.TCP;
        select = false;
        break;

        case 4:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.precioa1;  
         cout << "El precio de la compra: " << PNU.TCP << endl;
            AU.AbonoSencillo.push(PNU); 
            acumA1+= PNU.cantidad;
            ACPA1 += PNU.TCP;
         select = false;
         break;

        case 5:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.precioa2; 
         cout << "El precio de la compra: " << PNU.TCP << endl; 
            AU.AbonoGrande.push(PNU); 
                acumA2+= PNU.cantidad;
                ACPA2+= PNU.TCP;
         select = false;
         break;

        case 6:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.precioh1;
         cout << "El precio de la compra: " << PNU.TCP << endl;  
            AU.HR.push(PNU);
                acumHR+= PNU.cantidad;
                ACPHR+= PNU.TCP;
         select = false;
            break;

        case 7:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.precioh2; 
         cout << "El precio de la compra: " << PNU.TCP << endl; 
            AU.HP.push(PNU);
                acumHP+= PNU.cantidad;
                ACPHP+= PNU.TCP;
           select = false;
            break;

        case 8:
         select = false ; break;     

        }
         
    }while (select);

}



void showQueue(queue<AT> q) {
    queue<AT> clone = q;
    while (!clone.empty()) {
        cout << clone.front().cantidad <<" en existencia. "<< endl;
        cout << "$"<< clone.front().TCP << " Dolares"<< endl;
        clone.pop();
    }

}

void showtime(){ 
//mostrando el inventario actual de la tienda


cout << "\n*******FLORES*******" << endl;

cout << "---Rosa Unicornio--- " << endl; 
showQueue(AU.Rosa);
cout << endl;
cout << "**CANTIDAD TOTAL EN STOCK**" << endl;
cout << "\t " << acumR1 << endl;
cout << "**DINERO EN TOTAL**" << endl; 
cout << "\t$" << ACPR1 << endl;
cout << endl;

cout << "---Girasol de la vida----" << endl;
showQueue(AU.Girasol);
cout << endl;
cout << "**CANTIDAD TOTAL EN STOCK**" << endl;
cout << "\t " << acumG2 << endl;
cout << " **DINERO EN TOTAL**" << endl; 
cout << "\t$" << ACPG2 << endl;
cout << endl;

cout << "---Clavel de la noche---" << endl; 
showQueue(AU.clavel);
cout << endl;
cout << "**CANTIDAD TOTAL EN STOCK**" << endl;
cout << "\t " << acumC3 << endl; 
cout << "**DINERO EN TOTAL**" << endl;
cout << "\t$" << ACPC3 << endl;
cout << endl;

cout << endl << endl;
cout << "*******ABONO*******" << endl;
cout << "---Abono sencillo---" << endl;
showQueue(AU.AbonoSencillo);
cout << endl;
cout << "**CANTIDAD TOTAL EN STOCK**" << endl;
cout << "\t " << acumA1 << endl; 
cout << "**DINERO EN TOTAL**" << endl;
cout << "\t$"<< ACPA1 << endl;
cout << endl;

cout << "---Abono Grande---" << endl;
showQueue(AU.AbonoGrande); 
cout << endl;
cout << "**CANTIDAD TOTAL EN STOCK**" << endl;
cout << "\t " << acumA2 << endl; 
cout << "**DINERO EN TOTAL**" << endl;
cout << "\t$" << ACPA2 << endl;
cout << endl;

cout << endl << endl;
cout << "*******Herramientas*******" << endl;
cout << "---Rastrillos---" << endl;
showQueue(AU.HR);
cout << endl;
cout << "**CANTIDAD TOTAL EN STOCK**" << endl;
cout << "\t " << acumHR << endl; 
cout << "**DINERO EN TOTAL**" << endl;
cout << "\t$"<< ACPHR << endl;
cout << endl;

cout << "---Palas---"<< endl;
showQueue(AU.HP);
cout << endl;
cout << "**CANTIDAD TOTAL EN STOCK**" << endl;
cout << "\t " << acumHP << endl;
cout << "**DINERO EN TOTAL**" << endl; 
cout << "\t$" << ACPHP << endl;
cout << endl;

cout << endl << endl;
}

void ganacia(){
float TOTAL;

TOTAL = ACPR1 + ACPG2 + ACPC3 + ACPA1 + ACPA2 + ACPHR +ACPHP;
cout << "Total actual: " <<"$"<< TOTAL << " Dolares" <<endl;

}




//esto es lo del cliente

    void cliente(){
   
      bool continuar4 = true;

      int usuario = 0;

      do{

          cout<<"\n\t1) Comprar plantas";
          cout<<"\n\t2) Comprar abono";
          cout<<"\n\t3) Comprar herramientas";
          cout<<"\n\t4) Ir al pago";
          cout<<"\n\t5) Regresar al menu anterior";
          cout<<"\nDigite su opcion: ";
              cin>>usuario;
      
      switch (usuario){
        case 1:  cout<<"\n\t\tEliga la planta que desea comprar";
                tipplatas(); break;
        
        case 2:  cout<<"\n\t\tElige como quieres tu abono";
                tipaono(); break;

        case 3:  cout<<"\n\t\tCompras tus herramientas para tu jardin";
                tipherramientas(); break;

        case 4:  factura();  system("pause"); break; 

        case 5: continuar4 = false; break;

    }
   }while(continuar4);
    }

    void tipplatas(){

        int plantass = 0;
        bool lasplantas = true;

     do{
            cout<<"\n\t1) Rosas unicornio";
            cout<<"\n\t2) Girasol de la vida";
            cout<<"\n\t3) Clavel de la noche";
            cout<<"\n\t4) Salir al menu anterior";
            cout<<"\n\tDigite su opcion: ";
            cin>>plantass;

    switch (plantass){
        case 1: cout<<"\nCuantas desea llevar: ";  
        
        break;
        
        case 2: 
    
        break;

        case 3: cout<<"\nCuantas desea llevar: ";

        break;

        case 4: lasplantas = false; break;

    }
   }while(lasplantas);
        }

 void tipaono(){
     
     int abbono = 0;
     bool elabono = true;

     do{
            cout<<"\n\t1) Sencillo";
            cout<<"\n\t2) Grande";
            cout<<"\n\t3) Salir al menu anterior";
            cout<<"\n\tDigite su opcion: ";
                cin>>abbono;

    switch (abbono){
        case 1: cout<<"\nCuantas desea llevar: "; 
        
        break;
        
        case 2: cout<<"\nCuantas desea llevar: ";
    
        break;

        case 3: elabono = false; break;

    }
   }while(elabono);
 }       

 void tipherramientas(){
 
 int herramientas = 0;
     bool lasherramientas = true;
     do{
            cout<<"\n\t1) Rastrillo";
            cout<<"\n\t2) Pala";
            cout<<"\n\t3) Salir al menu anterior";
            cout<<"\n\tDigite su opcion: ";
               cin>>herramientas;
               
    switch (herramientas){
        case 1: cout<<"\nCuantas desea llevar: "; 
        
        break;
        
        case 2: cout<<"\nCuantas desea llevar: ";

        break;

        case 3: lasherramientas = false; break;

    }
   }while(lasherramientas); 
 }



void factura(){

cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"                      Tiendita de las plantitas"<<endl;//interfaz de la factura 
    cout<<"     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
 cout<<"------------------------------------------------------------------------"<<endl;
 cout<<"                             FACTURA"<<endl;
 cout<<"------------------------------------------------------------------------"<<endl; 

  //aqui va detallado lo que lleva 

 cout<<"------------------------------------------------------------------------"<<endl;

   //Aqui va el total que va a paga

 cout<<"------------------------------------------------------------------------"<<endl;

 cout<<"                          GRACIAS POR SU COMPRA                         "<<endl;
 cout<<"                 SIEMPRE LO MEJOR PARA NUESTROS CLIENTES                "<<endl;
 cout<<"------------------------------------------------------------------------"<<endl;

}