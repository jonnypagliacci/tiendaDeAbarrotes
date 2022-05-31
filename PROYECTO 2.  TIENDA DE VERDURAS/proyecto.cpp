#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

void Administrador(); 
void Ventas();
void Altas();
void Bajas();
void Consultas();
void Modificaciones();
void Mostrar();
void Cuentas();
void Altas_Cuentas();
void Bajas_Cuentas();
void Modificar_Cuentas();
void Mostrar_Cuentas();
int buscar(string prod);
int buscarc(string user);
int vendedor;

int id[100]={2,4,1,3,5};
string producto[100]={"leche","pan","agua","huevos","refresco"};
int existencias[100]={23,20,12,20,10};
float precio_compra[100]={10,10,10,10,10};
float precio_venta[100]={10,20,10,15,11};
int reorden[100]={5,5,5,5,5};
bool status[100]={true,true,true,true,true};
int ventas[100];
int b;
int ven;
int y=0;
string user;
int z=0;
int totals[100];
string cuentav[100];

int total=5;

string cuenta[10]={"admin","admin1","ventas","ventas1"};
int passw[10]={1234,1111,3333,4321};
int statusc[10]={1,1,2,2};
int vendedores[10]={1,2};
float totales[100];

int totalc=3;

int main() {
    
    int op,pass;
    int cont=0;
    
    do{
        cout<<endl<<setw(50)<<"Menu"<<endl;
        cout<<"1. Administrador"<<endl;
        cout<<"2. Ventas"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>op;
        if (op==3){
            cout<<"Cerrando Sistema";
            break;}
        cout<<"User: ";
        cin>>user;
        cout<<"Password: ";
        cin>>pass;
        
        switch (op){
            case 1:
                if (buscarc(user)>=0 && pass == passw[buscarc(user)]){
                    b=buscarc(user);
                    if(statusc[b]==2)
                        cout<<"Esta cuenta no tiene acceso"<<endl;
                    if(statusc[b]==1)
                        Administrador();
                    break;
                    }
                else 
                    cout<<"Cuenta Inexistente"<<endl;
                break;
                
            case 2:
                if (buscarc(user)>=0 && pass == passw[buscarc(user)]){
                    b=buscarc(user);
                    if(statusc[b]==1)
                        cout<<"Esta cuenta no tiene acceso"<<endl;
                    if(statusc[b]==2)
                        ven=buscarc(user);
                        Ventas();
                    break;
                    }
                else 
                    cout<<"Cuenta Inexistente"<<endl;
                break;
                
            case 3:
                cout<<"Cerrando Sistema"<<endl;
                break;
                
            default:
                cout<<"Opcion Invalida";
        }
    } while (op!=3);

    return 0;
}

void Administrador(){
    int opadm;
    
    do{
        cout<<setw(50)<<"Menu Administrador"<<endl;
        cout<<"1. Altas"<<endl;
        cout<<"2. Bajas"<<endl;
        cout<<"3. Consultas"<<endl;
        cout<<"4. Modificar"<<endl;
        cout<<"5. Mostrar Inventario"<<endl;
        cout<<"6. Cuentas"<<endl;
        cout<<"7. Salir"<<endl;
        cin>>opadm;
        
        switch(opadm)
        {
        case 1:
            Altas();
            break;
        case 2:
            Bajas();
            break;
        case 3:
            Consultas();
            break;
        case 4:
            Modificaciones();
            break;
        case 5:
            Mostrar();
            break;
        case 6:
            Cuentas();
            break;
        case 7:
            cout<<"Saliendo de Administrador"<<endl;
            break;
        default:
            cout<<"Opcion Invalida"<<endl;
        } 
    } while (opadm!=7);
}

void Ventas(){
    cout<<endl<<setw(50)<<"Ventas"<<endl;
    string produc[20];
    float prodv[20];
    string prod;
    string vendor[100];
    int a;
    float v;
    float s;
    float t;
    int totalz;
    int cant;
    
    int opv;
    float totalt[100];
    int p;
    int w;
    int totaly;
           
    cuenta[ven];
    b=ven-1;
    do {
    cout<<endl<<"1. Venta"<<endl;
    cout<<"2. Cierre de Caja"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>opv;
    
        if(opv==1){
            z=0;
            while (true)
    {
        v=0;
        cout <<endl<< "Producto: "<<endl;
        cin >> prod;
        if(prod.compare("*")==0)
            break;
        cout<<endl<<"cantidad: "<<endl;
        cin>>cant;

        cout<<setw(10)<<" "<<left<<setw(20)<<"producto"<<setw(20)<< "venta"<<setw(20)<<"Subtotal"<<setw(20)<<"Vendedor"<<endl;
        
        if (buscar(prod) < 0)
            cout << "Producto no existe \n";
        if (buscar(prod) >= 0)
            a = buscar(prod);
        if (status[a] == false)
            cout << "Producto inactivo\n";
        if(cant>existencias[a])
            cout<<"No cuentas con esa cantidad, solo quedan "<<existencias[a]<<endl;
        else
        { 
            v=0;
            if(buscar(prod) >= 0){
            existencias[a]-=cant;
            produc[z]=producto[buscar(prod)];
            prodv[z]=precio_venta[buscar(prod)];
            totalt[z]=cant*prodv[z];
            v=totalt[z];
            z++;
            cuentav[y]=cuenta[b+1];
            
            cout<<z<<endl;
            cout<<setw(10)<<" "<<left<<setw(30)<<producto[buscar(prod)]<< setw(20)<< precio_venta[buscar(prod)]<<setw(20)<<v<<setw(20)<<cuentav[y]<<endl;
            if (existencias[a]<=reorden[a])
            cout<<"Solo te quedan "<<existencias[a]<<" debes ordenar mas "<<endl;
            cout<<endl<<existencias[a];
            produc[y]=producto[buscar(prod)];
            prodv[y]=precio_venta[buscar(prod)];
            vendor[y]=cuenta[b];
            totals[y]=(float)cant*prodv[y];
            y++;}
            }
        }
    totalz=z;
    cout<<endl<<setw(60)<<"Ticket"<<endl;
    cout<<setw(30)<<left<<"Producto"<<setw(20)<<"Venta"<<endl<<endl;
for (z=0;z<totalz;z++){
    cout<<setw(30)<<left<<produc[z]<< setw(20)<<totalt[z]<<endl;
    v+=totalt[z];
    s+=v;
}
    
    cout<<setw(30)<<left<<"Total"<<setw(20)<<v;
        }
    
        if(opv==2){   
            v=0;
            totalz=y;
    cout<<endl<<endl<<endl<<setw(60)<<"Ticket"<<endl;
    cout<<setw(30)<<left<<"Producto"<<setw(20)<<"Venta"<<setw(20)<<"Vendedor"<<endl<<endl;
for (y=0;y<totalz;y++){
    cout<<setw(30)<<left<<produc[y]<< setw(20)<<totals[y]<<setw(20)<<cuentav[y]<<endl;
    v+=totals[y];
    s+=v;
        
    }
    cout<<setw(30)<<left<<"Total"<<setw(20)<<v;
    if (opv==3){
            for (y=0;y<totalz;y++){
            cout<<setw(30)<<left<<produc[y]<< setw(20)<<totals[y]<<endl;
            v+=totals[y];
            }
            p=v;
            cout<<setw(30)<<left<<"Subtotal "<<vendor[y]<<" "<<p<<endl;
            for (y=0;y<totalz;y++){
            cout<<setw(30)<<left<<produc[y]<< setw(20)<<totals[y]<<endl;
            v+=totals[y];
            }
            w=v;
            p+=v;
        cout<<setw(30)<<left<<"Subtotal "<<vendor[y]<<" "<<w<<endl;
        cout<<setw(30)<<left<<"Total "<<p<<endl;
    }
        }
    } while (opv!=3);
    
    }

void Altas(){
    cout<<endl<<setw(50)<<"Altas";
    int i=total;
    string prod;
    int ex,nr,opalt,a,ids;
    float pc,pv;
    
    while (true){
        cout<<endl<<"Producto: ";
        cin>>prod;
        if (prod.compare("*")==0)
            break;
        if (buscar(prod)>=0){
            
            a=buscar(prod);
        if(status[a]== true)
            cout<<"Producto existente"<<endl;
        else{
            cout<<"Producto inactivo"<<endl;
            cout<<"Reactivar: "<<endl;
            cout<<"1,Si    2.No"<<endl;
            cin>>opalt;
            
            if(opalt==1){
                status[a]=true;
                
                do{
                    cout<<endl<<"Existencias"<<endl;
                    cin>>ex;
                    cout<<"Reorden";
                    cin>>nr;
                    
                    if (ex<=nr)
                        cout<<"Error, debe de haber mas existencias"<<endl;
                   
                } while (ex<=nr);
                
                do{
                    cout<<"Precio de compra: ";
                    cin>>pc;
                    cout<<"Precio de venta: ";
                    cin>>pv;
                    
                    if(pc>pv)
                        cout<<"Error, debe ser mayor el precio de venta"<<endl;
                } while (pc>pv);
                existencias[a]=ex;
                reorden[a]=nr;
                precio_compra[a]=pc;
                precio_venta[a]+pv;
            }
        }
    }  else {
           producto[i]=prod;
           do {
               cout<<"Existencias";
               cin>>ex;
               cout<<"Reorden: ";
               cin>>nr;
               
               if (ex<nr)
                   cout<<"Las existencias deben ser mayores al nivel de reorden";        
           } while (ex<=nr);
           do{
               cout<<"Precio de compra: ";
               cin>>pc;
               cout<<"Precio de venta: ";
               cin>>pv;
               cout<<"ID: ";
               cin>>ids;
               if(pc>pv);
               cout<<"El precio de compra debe ser menor al precio de venta";
           } while(pc>pv);
           existencias[i]=ex;
           reorden[i]=nr;
           precio_compra[i]=pc;
           precio_venta[i]=pv;
           status[i]=true;
           id[i]=ids;
           i++;
        }
        total=i;
    }
}

void Bajas(){
    cout << endl<< setw(60) << " "<< "Bajas\n";
    int i = total;
    int opb, st, a;
    string prod;

    while (true)
    {
        cout << "Producto: ";
        cin >> prod;
        if (prod.compare("*") == 0)
        {
            break;
        }
        if (buscar(prod) < 0)
            cout << "Producto inexistente"<<endl;
        if (buscar(prod) >= 0)
            a = buscar(prod);
        if (status[a] == false)
            cout << "El producto esta dado de baja"<<endl;
        else
        {
            cout << "Desea dar de baja el producto " << producto[buscar(prod)] << endl;
            cout << "1.Si    2.No\n";
            cout << "Opcion: ";
            cin >> opb;
            if (opb == 1)
            {
                status[a] = false;
                cout << "Producto dado de baja"<<endl;
            }

            else
                cout << "No se dio de baja el producto"<<endl;
        }
    }
}

void Consultas(){
    cout<<endl<<setw(50)<<"Consultas"<<endl;

    string prod;
    int c;

    while (true)
    {
        cout <<endl<< "Producto: "<<endl;
        cin >> prod;

        if (prod.compare("*") == 0)
        {
            break;
        }
        if (buscar(prod) < 0)
            cout << "Producto no existe \n";
        if (buscar(prod) >= 0)
            c = buscar(prod);
        if (status[c] == false)
            cout << "Producto inactivo\n";
        else
        {
            cout << endl;
            cout << setw(10) << " " << left << setw(30) << "producto" << setw(20) << "existencias" << setw(20) << "nivel_reorden" << setw(20) << "compra" << setw(20) << "venta" << endl
                 << endl;
            cout << setw(10) << " " << left << setw(30) << producto[buscar(prod)] << setw(20) << existencias[buscar(prod)] << setw(20) << reorden[buscar(prod)] << setw(20) << precio_compra[buscar(prod)] << setw(20) << precio_venta[buscar(prod)] << endl;
        }
    }
}

void Modificaciones(){
    cout<<endl<<"Modificaciones"<<endl;
    string prod, produ;
    int opm,ex,nr,st,a;
    float pc,pv;
    
    while(true){
        cout<<"Producto:";
        cin>>prod;
        if (prod.compare("*")==0)
            break;
        if(buscar(prod)<0)
            cout<<"Producto Inexistente"<<endl;
        if (buscar(prod)>=0)
            a=buscar(prod);
        if (status[a]==false)
            cout<<"Producto inactivo"<<endl;
        else{
            do{
                cout <<endl<<"Modificar"<<endl;
                cout << "1.Nombre"<<endl;
                cout << "2.Existencias"<<endl;
                cout << "3.Reorden"<<endl;
                cout << "4.Precio de compra"<<endl;
                cout << "5.Precio de venta"<<endl;
                cout << "6.Salir"<<endl;
                cout << "Opcion: ";
                cin >> opm;
                
                switch (opm){
                    
                    case 1:
                        cout <<endl<< "Nombre: ";
                        cin >> produ;
                        producto[a] = produ;
                        break;
                    case 2:
                        do{
                            cout<<"Existencia: ";
                            cin>>ex;
                            if (ex<reorden[a])
                                cout<< "Deben ser mayor a "<<reorden[a];    
                        } while (ex<reorden[a]);
                        existencias[a]=ex;
                        break;
                    case 3:
                            cout<<"Reorden: ";
                            cin>>nr;
                            reorden[a]=nr;
                        break;
                    case 4:
                        cout<<"Precio de Compra: ";
                        cin>>pc;
                        precio_compra[a]=pc;
                        break;
                    case 5:
                        do{
                            cout<<"Precio de Venta: ";
                            cin>>pv;
                            if(pv<precio_compra[a])
                                cout<<"El precio debe ser mayor a "<<precio_venta[a];
                        } while (pv<precio_compra[a]);
                        precio_venta[a]=pv;
                        break;
                    case 6:
                        cout << "Saliendo de modificacion del producto"<<endl;
                    break;

                default:
                    cout << "Opcion invalida"<<endl;
                }
            } while (opm!=6);
        }
    }  
}

void Mostrar(){
    int f;
    int u;
    
    int auxid;
    string auxp;
    int auxex;
    float auxpc;
    float auxpv;
    int auxre;
    bool auxst;
    
    for (f=0;f<total;f++){
        for(u=0;u<total-1;u++){
        if (id[u]>id[u+1]){
            auxid=id[u];
            auxp=producto[u];
            auxex=existencias[u];
            auxpc=precio_compra[u];
            auxpv=precio_venta[u];
            auxre=reorden[u];
            auxst=status[u];
            id[u]=id[u+1];
            producto[u]=producto[u+1];
            existencias[u]=existencias[u+1];
            precio_compra[u]=precio_compra[u+1];
            precio_venta[u]=precio_venta[u+1];
            reorden[u]=reorden[u+1];
            status[u]=status[u+1];
            id[u+1]=auxid;
            producto[u+1]=auxp;
            existencias[u+1]=auxex;
            precio_compra[u+1]=auxpc;
            precio_venta[u+1]=auxpv;
            reorden[u+1]=auxre;
            status[u+1]=auxst;
            }
        }
    }
    int m;
    cout<<endl<<setw(60)<<"Mostrar Inventario"<<endl;
    cout<<setw(30)<<left<<setw(10)<<"ID"<<setw(20)<<"Producto"<<setw(20)<<"Existencias"<<setw(20)<<"Nivel_reorden"<<setw(20)<<"Compra"<<setw(20)<<"Venta"<<endl<<endl;
for (m=0;m<total;m++){
    if (status[m]==true)
    cout<<setw(30)<<left<<setw(10)<<id[m]<<setw(20)<<producto[m]<<setw(20)<<existencias[m]<<setw(20)<<reorden[m]<<setw(20)<<precio_compra[m]<<setw(20)<<precio_venta[m]<< endl;
    }
}

void Cuentas(){
    int opc;
    do{
        cout<<endl<<endl<<setw(60)<<"Cuenta"<<endl;
        cout<<"1. Altas"<<endl;
        cout<<"2. Bajas"<<endl;
        cout<<"3. Modificaciones"<<endl;
        cout<<"4. Mostrar"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>opc;
        
        switch (opc){
            case 1:
                Altas_Cuentas();
                break;
            case 2:
                Bajas_Cuentas();
                break;
            case 3:
                Modificar_Cuentas();
                break;
            case 4:
                Mostrar_Cuentas();
                break;
            case 5:
                cout<<"Saliendo de Administrador"<<endl;
                break;
            default:
                cout<<"opcion invalida"<<endl;
        }
    } while (opc!=5);
}

void Altas_Cuentas(){
    cout<<endl<<setw(60)<<"Alta de cuentas";
    int j=totalc+1;
    string usuario;
    int opal,contra,opac,b;
    
    while(true){
        cout<<endl<<"Usuario: ";
        cin>>usuario;
        
        if(usuario.compare("*")==0)
            break;
        if (buscarc(usuario)>=0){
            b=buscarc(user);
            if(statusc[b]>=1)
                cout<<"Usuario existente"<<endl;
            else{
                cout<<"Usuario inactivo"<<endl;
                cout<<"1.Dar de alta    2.Dejar inactivo";
                cin>>opal;
                
                if(opal==1){
                    cout<<"Permiso: "<<endl;
                    cout<<"1.Administrador   2.Ventas"<<endl;
                    cin>>opac;
                    if(opac==1){
                        cout<<"Nueva Contraseña: ";
                        cin>>contra;
                        passw[b]=contra;
                        statusc[b]=1;
                    }
                    else{
                        cout<<"Nueva Contraseña: ";
                        cin>>contra;
                        passw[b]=contra;
                        statusc[b]=2;
                    }
                }
            }
        }
        else{
            cuenta[j]=usuario;
            cout << "Ingrese contraseña: ";
            cin >> contra;

            cout << "1.Administrador     2.Ventas\n";
            cout << "Opcion: ";
            cin >> opac;

            passw[j] = contra;
            statusc[j] = opac;
            j++;
        }
        totalc=j;
    }
}

void Bajas_Cuentas(){
    cout<<endl<<setw(60)<<"Bajas Cuentas"<<endl<<endl;
    int j=totalc;
    int opba,st,b;
    string user;
    
    while(true){
        cout << "\nUsuario: ";
        cin >> user;
        if (user.compare("*") == 0)
        {
            break;
        }
        if (buscarc(user) < 0)
            cout << "Cuenta inexistente\n";
        if (buscarc(user) >= 0)
        {
            b = buscarc(user);
            if (statusc[b] == 0)
                cout << "La cuenta esta dada de baja\n";
            else
            {
                cout << "Desea dar de baja la cuenta " << cuenta[b] << endl;
                cout << "1.Si    2.No\n";
                cin >> opba;

                if (opba == 1)
                {
                    statusc[b] = 0;
                    cout << "Cuenta dada de baja\n";
                }

                else
                    cout << "No se dio de baja la cuenta\n";
            }
        }
    }
    
}

void Modificar_Cuentas(){
    cout<<endl<<setw(50)<<"Modificaciones de cuentas"<<endl<<endl;
    string usuario,usu;
    int opcon,stcu,contra,b;
    
    while(true){
        cout<<"Usuario: ";
        cin>>usuario;
        if (user.compare("*")==0)
            break;
        if(buscarc(user)<0)
            cout<<"Producto Inexistente"<<endl;
        if(buscarc(user)>=0)
            b=buscarc(user);
        if(statusc[b]==0)
            cout<<"Cuenta inactiva"<<endl;
        else{
            do{
                cout<<"Que desea modificar: "<<endl;
                cout<<"1.Usuario"<<endl;
                cout<<"2.Contraseña"<<endl;
                cout<<"3.Cuenta"<<endl;
                cout<<"4.Salir"<<endl;
                cin>>opcon;
                
                switch(opcon){
                    case 1:
                        cout<<endl<<"Usuario: ";
                        cin>>usu;
                        cuenta[b]=usu;
                        break;
                        
                    case 2:
                        cout<<endl<<"Contraseña: ";
                        cin>>contra;
                        passw[b]=contra;
                        break;
                        
                    case 3:
                        cout<<endl<<"Cuenta: ";
                        cout<<endl<<"1.Administrador   2.Ventas"<<endl;
                        cin>>stcu;
                        statusc[b]=stcu;
                        break;
                        
                    case 4:
                        cout<<endl<<"Saliendo de modificacion de la cuenta"<<endl;
                        break;
                    default:
                        cout<<"Opcion invalida"<<endl;
                        
                }
            }while (opcon !=4);
        }
    }
    
}

void Mostrar_Cuentas(){
    int j;
    cout<<endl<<setw(50)<<"Mostrar cuentas"<<endl<<endl;
    cout<<setw(40)<<left<<setw(20)<<"Usuario"<<setw(20)<<"Contraseña"<<setw(20)<<"Cuenta"<<endl<<endl;
    for(j=0;j<=totalc;j++)
        if (statusc[j]>0){
            if(statusc[j]==1)
                cout<<setw(40)<<left<<setw(20)<<cuenta[j]<<setw(20)<<passw[j]<<setw(20)<<"Administrador"<<endl;
            else
                cout<<setw(40)<<left<<setw(20)<<cuenta[j]<<setw(20)<<passw[j]<<setw(20)<<"Administrador"<<endl;
        }
    
}

int buscar(string prod)
{
    int i;

    for (i = 0; i < total; i++)
        if (prod == producto[i])
            return i;
    return -1;
}

int buscarc(string user)
{
    int j;

    for (j = 0; j <= totalc; j++)
        if (user == cuenta[j])
            return j;
    vendedor=j;
    return -1;
}