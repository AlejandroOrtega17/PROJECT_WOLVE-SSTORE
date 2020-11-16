#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct venta{
 //Nombres
    string namesitos;
 //Cantidad que se va a llevar el cliente de X producto
    int  count_art;
    int cantidadarticulos;
 //Precio de venta
    float  Count_precio;
    float precioporcantidad;

 //Nombres de los articulos (Dato quemado)
    string Nrosa = "Rosas Unicornio   ";
    string Ngirasol = "Girasol de la vida";
    string Nclavel = "Clavel de la noche";
    string NAB1 = "Abono sencillo    ";
    string NAB2 = "Abono Grande      ";
    string NHR = "Rastrillo         ";
    string NHP = "Pala              ";

 //Precios con IVA +1$ para vender a los clientes
 //Precio de flores
    float precioff1 = 3.50; 
    float precioff2 = 3.25;
    float precioff3 = 5.00;
 //Precio de abono
    float precioaa1 = 5.50;
    float precioaa2 = 10.50;
 //Precio de herramientas
    float preciohh1 = 8.50;
    float preciohh2 = 5.99;
};

struct articulos{
    int cantidad;
    float TCP;

 //precio de compra para ingresar al stock
 //precio de flores
    float preciof1 = 2.50; 
    float preciof2 = 2.25;
    float preciof3 = 4.00;
 //precio de abono
    float precioa1 = 4.50;
    float precioa2 = 8.50;
 //precio de herramientas
    float precioh1 = 6.50;
    float precioh2 = 3.99;

};
typedef struct articulos AT;

struct unArticulo{
//Estas colas funcionaran como registros de todas las entradas al almacen 
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
//MENU DEL ADMIN 
void agregarInventario();
void menuadmin();
void inventario();
void showtime();
void agregar();
void showQueue();
void ganacia();

//MENU DEL CLIENTE
void cliente();
void tipplatas();
void tipaono();
void tipherramientas();
void agregarproducto(string namae, int canart, float precioart);
void Totalincliente();
void factura();

//Creamos la lista para las compras de los clientes 
list<venta> client;

//Acumuladores
//Estos acumuladoras funcionaran como registros de entrada y salida
float acumR1, acumG2, acumC3, acumA1, acumA2,acumHR,acumHP;
float acump1=0, acump2=0, acump3=0, acump4=0, acump5=0, acump6=0, acump7=0;
float ACPR1, ACPG2, ACPC3, ACPA1, ACPA2, ACPHR, ACPHP;

//Programa principal
int main(){
system("CLS");

int opcion;
bool continuar1 = true;

do{
    cout <<"\n\t\t****FLORERIA WOLVES****"<<endl;
    cout<<"\n\t 1) Administrador";
    cout<<"\n\t 2) Cliente";
    cout<<"\n\t 3) Salir";
    cout<<"\n Digite su opcion: ";
        cin>>opcion;

    switch (opcion){
        case 1: menuadmin(); break;

        case 2: cout<<"\n\t\tBIENVENIDO A LA FLORERIA WOLVES";    
                cliente(); break;

        case 3: cout<<"\n\n\t\tGracias por su visita, lo esperamos pronto."<<endl; 
        system("pause");
        system("cls");
        continuar1 = false; break;
        }
}while(continuar1);
 system("cls");
return 0; }

 //Menu que se le despliega al administrador de la tienda
void menuadmin(){
system("cls");
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
 system("cls");
   bool continuar3 = true;
   int lot = 0;

   do{
       cout<<"\n\t1) Actualizar inventario";
       cout<<"\n\t2) Ver el inventario";
       cout<<"\n\t3) Salir";
       cout<<"\nDigite su opcion: ";
       cin>>lot;

    switch (lot){
        case 1:  agregar(); break; //agregar compras
        
        case 2: showtime();  break; //Ver inventario

        case 3: continuar3 = false; break;
    }
   }while(continuar3);
}

 void agregar(){
 system("cls");
    AT PNU;
        cout << "\n\t\tSeleccione lo que desee agregar al inventario" << endl;
    int cheek =0;
    bool  select = true;
    do{
        cout << "\n1) Rosas unicornio\n";
        cout << "2) Girasol de la vida\n";
        cout << "3) Clavel de la noche\n";
        cout << "4) Abono sencillo\n";
        cout << "5) Abono grande\n";
        cout << "6) Rastrillos\n";
        cout << "7) Palas\n";
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
        select = false; break;

        case 2:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad; 
            PNU.TCP = PNU.cantidad * PNU.preciof2;  
         cout << "El precio de la compra: " << PNU.TCP << endl;
            AU.Girasol.push(PNU);
                acumG2+=PNU.cantidad;
                ACPG2+= PNU.TCP ;
        select = false; break;

        case 3: 
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.preciof3;  
         cout << "El precio de la compra: " << PNU.TCP << endl; 
            AU.clavel.push(PNU); 
                acumC3 += PNU.cantidad;
                ACPC3+= PNU.TCP;
        select = false; break;

        case 4:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.precioa1;  
         cout << "El precio de la compra: " << PNU.TCP << endl;
            AU.AbonoSencillo.push(PNU); 
            acumA1+= PNU.cantidad;
            ACPA1 += PNU.TCP;
        select = false; break;

        case 5:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.precioa2; 
         cout << "El precio de la compra: " << PNU.TCP << endl; 
            AU.AbonoGrande.push(PNU); 
                acumA2+= PNU.cantidad;
                ACPA2+= PNU.TCP;
        select = false; break;

        case 6:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.precioh1;
         cout << "El precio de la compra: " << PNU.TCP << endl;  
            AU.HR.push(PNU);
                acumHR+= PNU.cantidad;
                ACPHR+= PNU.TCP;
        select = false; break;

        case 7:
         cout << "Digite la cantidad: "; cin >> PNU.cantidad;
         PNU.TCP = PNU.cantidad * PNU.precioh2; 
         cout << "El precio de la compra: " << PNU.TCP << endl; 
            AU.HP.push(PNU);
                acumHP+= PNU.cantidad;
                ACPHP+= PNU.TCP;
        select = false; break;

        case 8: select = false ; break;     
        }
    }while (select);
    system("cls");
}


void showQueue(queue<AT> q) {
        queue<AT> clone = q;
    while (!clone.empty()) {
        cout << "Cantidad de compra de lote " << clone.front().cantidad << endl;
        cout << "$"<< clone.front().TCP << " Dolares"<< endl;
        clone.pop();
    }
}

void showtime(){ 
 system("cls");
//mostrando el inventario actual de la tienda
cout << "\n\t\t*******DATO DE FLORES*******" << endl;
cout << "\n///Rosa Unicornio/// " << endl; 
showQueue(AU.Rosa);
cout << endl;
cout << "\tDisponiles aun: ";
cout << acumR1 << " rosas." << endl;
cout << "\tGasto de la compra: "; 
cout << "$ " << ACPR1 << endl;
cout << endl;
 
cout << "\n///Girasol de la vida///" << endl;
showQueue(AU.Girasol);cout << endl;
cout << "\tDisponiles aun: ";
cout << acumG2 << " girasoles." << endl;
cout << "\tGasto de la compra: "; 
cout << "$ " << ACPG2 << endl;
cout << endl;

cout << "\n///Clavel de la noche///" << endl; 
showQueue(AU.clavel);
cout << endl;
cout << "\tDisponiles aun: ";
cout << acumC3 << " claveles."<< endl; 
cout << "\tGasto de la compra: "; 
cout << "$ " << ACPC3 << endl;
cout << endl;

cout << endl << endl;
cout << "\t\t*******DATO DEL ABONO*******" << endl;
cout << "\n///Abono sencillo//" << endl;
showQueue(AU.AbonoSencillo);
cout << endl;
cout << "\tDisponiles aun: ";
cout << acumA1 << " abonos sencillos." << endl; 
cout << "\tGasto de la compra: "; 
cout << "$ "<< ACPA1<< endl;
cout << endl;

cout << "\n///Abono Grande///" << endl;
showQueue(AU.AbonoGrande); 
cout << endl;
cout << "\tDisponiles aun: ";
cout << acumA2 << " abonos grandes." << endl; 
cout << "\tGasto de la compra: "; 
cout << "$ " << ACPA2 << endl;
cout << endl;

cout << endl << endl;
cout << "\t*******DATO DE LAS HERRAMIENTAS*******" << endl;
cout << "\n///Rastrillos///" << endl;
showQueue(AU.HR);
cout << endl;
cout << "\tDisponiles aun: ";
cout << acumHR << " rastrillos." << endl; 
cout << "\tGasto de la compra: "; 
cout << "$ "<< ACPHR << endl;
cout << endl;

cout << "\n///Palas//"<< endl;
showQueue(AU.HP);
cout << endl;
cout << "\tDisponiles aun: ";
cout << acumHP << " palas." <<endl;
cout << "\tGasto de la compra: ";
cout << "$ " << ACPHP << endl;
cout << endl;

cout << endl << endl;
system("pause");
system("cls");
}

void ganacia(){
 system("cls");
       float TOTAL;

TOTAL = ACPR1 + ACPG2 + ACPC3 + ACPA1 + ACPA2 + ACPHR +ACPHP;
cout << "Total actual: " <<"$"<< TOTAL << " Dolares" <<endl;
system ("pause");
system("cls");
}

//El menu que se despliega al cliente
void cliente(){
 system("cls");
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
        case 1:  cout<<"\n\t\tEliga la planta que desea comprar:";
                tipplatas(); break;
        
        case 2:  cout<<"\n\t\tElige como quieres tu abono:";
                tipaono(); break;

        case 3:  cout<<"\n\t\tCompra tus herramientas para tu jardin:";
                tipherramientas(); break;

        case 4:  factura();  continuar4 = false; break; 

        case 5:  continuar4 = false; break;
    }
   }while(continuar4);
    }
    
void tipplatas(){
 system("cls");
        venta unaventaplanta;
        int plantass = 0;
        bool lasplantas = true;
     do{
            cout<<"\n\t1) Rosas unicornio " ;
            cout<<"\n\t2) Girasol de la vida ";
            cout<<"\n\t3) Clavel de la noche";
            cout<<"\n\t4) Salir al menu anterior";
            cout<<"\n\tDigite su opcion: ";
            cin>>plantass;

    switch (plantass){
        case 1: 
        unaventaplanta.Nrosa;
            cout<<"\nCuantas desea llevar: ";  
            cin >> unaventaplanta.cantidadarticulos;
                unaventaplanta.precioporcantidad = unaventaplanta.cantidadarticulos * unaventaplanta.precioff1;
                agregarproducto(unaventaplanta.Nrosa, unaventaplanta.cantidadarticulos, unaventaplanta.precioporcantidad);
      acump1 += unaventaplanta.precioporcantidad;
      acumR1 += acumR1 - acump1;
        break;
        
        case 2:  
        unaventaplanta.Ngirasol;
             cout<<"\nCuantas desea llevar: ";
             cin >> unaventaplanta.cantidadarticulos;
                unaventaplanta.precioporcantidad = unaventaplanta.cantidadarticulos * unaventaplanta.precioff2;
                agregarproducto(unaventaplanta.Ngirasol,  unaventaplanta.cantidadarticulos, unaventaplanta.precioporcantidad);
              acump2 += unaventaplanta.precioporcantidad;
              acumG2 += acumG2 - acump2;
        break;

        case 3: cout<<"\nCuantas desea llevar: ";
                 cin >> unaventaplanta.cantidadarticulos;
                unaventaplanta.precioporcantidad = unaventaplanta.cantidadarticulos * unaventaplanta.precioff3;
                agregarproducto(unaventaplanta.Nclavel, unaventaplanta.cantidadarticulos, unaventaplanta.precioporcantidad);
             acump3 += unaventaplanta.precioporcantidad;
             acumC3 += acumC3 - acump3; 
        break;

        case 4: lasplantas = false; break;

    }
   }while(lasplantas);
   system("cls");
   cout << "Desea seguir comprando en este apartado?" << endl; 
 }

 void tipaono(){
     system("cls");
     venta unaventabono;
     int abbono = 0;
     bool elabono = true;
     do{
            cout<<"\n\t1) Sencillo";
            cout<<"\n\t2) Grande";
            cout<<"\n\t3) Salir al menu anterior";
            cout<<"\n\tDigite su opcion: ";
                cin>>abbono;
    switch (abbono){
        case 1: 
        unaventabono.NAB1;
        cout <<"\nCuantas desea llevar: "; 
                 cin >> unaventabono.cantidadarticulos;
                unaventabono.precioporcantidad = unaventabono.cantidadarticulos * unaventabono.precioaa1;
                agregarproducto(unaventabono.NAB1, unaventabono.cantidadarticulos, unaventabono.precioporcantidad);
                acump4 += unaventabono.precioporcantidad;
                acumA1 += acumA1 - acump4;
        break;
        
        case 2: 
        unaventabono.NAB2;
        cout<<"\nCuantas desea llevar: ";
                 cin >> unaventabono.cantidadarticulos;
                unaventabono.precioporcantidad = unaventabono.cantidadarticulos * unaventabono.precioaa2;
                agregarproducto(unaventabono.NAB2  , unaventabono.cantidadarticulos, unaventabono.precioporcantidad);
             acump5 += unaventabono.precioporcantidad;
             acumA2 += acumA2 - acump5;
        break;

        case 3: elabono = false; break;

    }
   }while(elabono);
   system ("cls");
   cout << "Desea seguir comprando en este apartado?" << endl; 
 }       

 void tipherramientas(){
     system("cls");
 venta unaventaH;
 int herramientas = 0;
     bool lasherramientas = true;
     do{
            cout<<"\n\t1) Rastrillo";
            cout<<"\n\t2) Pala ";
            cout<<"\n\t3) Salir al menu anterior";
            cout<<"\n\tDigite su opcion: ";
               cin>>herramientas;
               
    switch (herramientas){
        case 1: 
        unaventaH.NHR;
            cout<<"\nCuantas desea llevar: "; 
            cin >> unaventaH.cantidadarticulos;
                unaventaH.precioporcantidad = unaventaH.cantidadarticulos * unaventaH.preciohh1;
            agregarproducto(unaventaH.NHR, unaventaH.cantidadarticulos, unaventaH.precioporcantidad);
                acump6 += unaventaH.precioporcantidad; 
                acumHR += acumHR - acump6; 
        break;
        
        case 2: 
        unaventaH.NHP;
            cout<<"\nCuantas desea llevar: ";
            cin >> unaventaH.cantidadarticulos;   
                unaventaH.precioporcantidad = unaventaH.cantidadarticulos * unaventaH.preciohh2;
            agregarproducto(unaventaH.NHP , unaventaH.cantidadarticulos, unaventaH.precioporcantidad);
                 acump7 += unaventaH.precioporcantidad;  
                 acumHP += acumHP - acump7; 
        break;

        case 3: lasherramientas = false; break;
    }
   }while(lasherramientas); 
   system("cls");
   cout << "Desea seguir comprando en este apartado?" << endl; 
 }

void agregarproducto (string namae, int canart, float precioart){
    venta unaventa; 
    unaventa.namesitos = namae;
    unaventa.count_art = canart;
    unaventa.Count_precio = precioart;
    
    client.insert(client.end(), unaventa);
}

void Totalincliente(){
    float TOTALAPAGAR ;

    TOTALAPAGAR = acump1 + acump2+ acump3+ acump4+ acump5+ acump6+acump7;
    cout << "\n\t\t  El Total  pagar es: $ " <<TOTALAPAGAR <<  endl;
}

void factura(){      
    system("cls"); 
                                //interfaz de la factura 
cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"                         FLORERIA WOLVES"<<endl;
    cout<<"     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
 cout<<"------------------------------------------------------------------------"<<endl;
 cout<<"                             FACTURA"<<endl;
 cout<<"------------------------------------------------------------------------"<<endl; 
                    //aqui va detallado lo que lleva de la compra
  cout<<"Nombre del producto:     Cantidad:    Precio:"<<endl;
for(venta i: client){
    cout << i.namesitos; 
    cout << "           "<< i.count_art;
    cout <<"         $ " << i.Count_precio  << endl;
}
 cout<<"------------------------------------------------------------------------"<<endl;
                   Totalincliente(); //Aqui va el total que va a paga
 cout<<"------------------------------------------------------------------------"<<endl;
 cout<<"                          GRACIAS POR SU COMPRA                         "<<endl;
 cout<<"                 SIEMPRE LO MEJOR PARA NUESTROS CLIENTES                "<<endl;
 cout<<"------------------------------------------------------------------------"<<endl;
 system("pause");
 system("cls");
}