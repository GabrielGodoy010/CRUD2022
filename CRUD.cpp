#include <iostream>
#include <string.h>

using namespace std;
const char *nombre_archivo = "archivo.dat";
const char *nombre_archivo_temp = "archivo_temp.dat";
int opc = 0;

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	char direccion[50];
	int telefono;
};

void menu();
void crear();
void leer();
void actualizar();
void delete_line();

main(){
menu();
}

void menu(){
	system("cls");
	cout<<"\n\t\tMenu CRUD"<<endl;
cout<<"\t1. Insertar estudiante"<<endl;
cout<<"\t2. Ver estudiantes"<<endl;
cout<<"\t3. Actualizar estudiante"<<endl;
cout<<"\t4. Eliminar estudiante"<<endl;
cout<<"\t5. Salir"<<endl<<endl;
cout<<"\tDigite su opcion: ";
cin>>opc; 
			
	system("cls");
	
	switch(opc)
	{
		case 1: crear();		 		;break;
 		case 2: leer();					;break;
 		case 3: actualizar();	 		;break;
 		case 4: delete_line();	 		;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}	
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"\n\t_______________________________________________"<<endl;
		cout<<"\n\t\t\tDatos Ingresados"<<endl;
		do{
		cout<<"\n\t_______________________________________________"<<endl;
		cout<<"\n\t|Id:"<<id<<"|\n\n\t|Codigo: "<<estudiante.codigo<<"|\n\n\t|Nombre: "<<estudiante.nombres<<"|\n\n\t|Apellido: "<<estudiante.apellidos<<"|\n\n\t|Direccion: "<<estudiante.direccion<<"|\n\n\t|Telefono: "<<estudiante.telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		
		system("pause");
		
		menu();
}
void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido,direccion;
	cout<<"\n\tIngrese el ID que desea Modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"\n\tIngrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"\n\tIngrese los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"\n\tIngrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"\n\tIngrese la Direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"\n\tIngrese el Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido,direccion;
	do{
		fflush(stdin);
		cout<<"\n\tIngrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"\n\tIngrese los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"\n\tIngrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"\n\tIngrese la Direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"\n\tIngrese el Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"\n\tDesea agregar otro Estudiante (s/n): ";
		cin>>continuar;
		cout<<"\n\t___________________________________________________________"<<endl;
		cout<<endl;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}
void delete_line(){
 	
	FILE *archivo, *archivo_temp; 
	int codigo; 
	Estudiante estudiante; 
	
	archivo_temp=fopen(nombre_archivo_temp,"w+b"); 
	archivo=fopen(nombre_archivo,"rb"); 
	                      				                
	cout<<"\n\tCodigo del estudiante a eliminar: "; 
	cin>>codigo; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	
			if (estudiante.codigo != codigo) 
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); 
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	                
		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombre_archivo,"wb"); 
	 
		while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
		}
	                
	fclose(archivo_temp); 
	fclose(archivo); 
	
	leer(); 

}
