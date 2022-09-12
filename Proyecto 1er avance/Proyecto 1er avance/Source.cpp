#include <iostream>
#include <string>
#include <string.h>
#include <fstream>


using namespace std;



void InicioSesionAdmin();
void InicioSesionCajero();
void RegistroAdmin();
void Mostrarlista();
void Mostrarlista2();
void Mostrarlista3();
void LeerArcAd();
void LeerArcCaj();
void RegistroCajero();
void Insertarcomercio();
void Insertarnombre();
void Insertarcontraseña();
void Insertarcomercio2();
void Insertarnombre2();
void Insertarcontrasena2();
void Insertarnombre3();
void Insertaralias();
void Insertartelef();
void Insertaremail();
void Insertarcomercio3();
void Insertarfecha();
void ArchivoAdminBi();
void ArchivoCajeBi();
void AltaClinte();
void AltaNAdmin();
void MenuAdmin();
void MenuCajero();
void BajaCajero();
void BajaCliente();
void Buscar();
void ActualizarUA();
void ActualizarUCA();


struct U_Admin {
	string comercio;
	string Anombre;
	string Acontrasena;
	U_Admin* sig;

};

U_Admin *primero;
U_Admin *ultimo;
U_Admin* lista = new U_Admin;

struct U_Cajero {
	string Ccomercio;
	string Cnombre;
	string Ccontrasena;

	U_Cajero* next;


};

U_Cajero* prim;
U_Cajero* ult;
U_Cajero* lista2 = new U_Cajero;

struct Cliente {

	string nombrec;
	string alias;
	char telefono[50];
	string email;
	string comercioc;
	char fecha;
	Cliente* siguiente;

};

Cliente* pun;
Cliente* aux;
Cliente* lista3;

int main()
{

	system("cls");
	int op = 0;
	int ele = 0;
	int tip = 0;

	cout << "* Bienvenido *" << endl << endl;
	cout << "1.INICIAR SESION" << endl;
	cout << "2.Registrar usuario" << endl;
	cout << "3.Salir" << endl << endl;
	cout << "Elija el numero segun que quiera hacer: ";
	cin >> op;


	switch (op) {


	   case 1:

		   system("cls");
		   cout << "¿Que tipo de usuario es?" << endl;
		   cout << "1.Administrador         2.Cajero        " << endl;
		   cin >> tip;

		   if (tip == 1) {

	
			   InicioSesionAdmin(); 


			   if (tip == 2) {



			   }
		   }

		   return main();
			break;


	   case 2:

		   system("cls");
		   cout << "Sea bienvinido" << endl;
		   cout << "Elija que tipo de usuario es; " << endl;
		   cout << "1. Administrador" << endl;
		   cout << "2. Cajero" << endl;
		   cin >> ele;

		   if (ele == 1) {
			  
			   RegistroAdmin();


		   }
		   else {

			   RegistroCajero();

		   }

		   return main();
		   break;



	   case 3:


			exit(0);
			break;


	}


}

void RegistroAdmin() {

	int o = 0;
	
	Insertarcomercio();
	Insertarnombre();
	Insertarcontraseña();


		cout << "1.Registrar usuario          2.Regresar" << endl;
		cin >> o;
		if (o == 1) {

			 ArchivoAdminBi();
			
			 if (o == 2) {

				 return ;
			 }
		}

		system("pause");
		return;


}
void ArchivoAdminBi() {

	ofstream archivoA;

	archivoA.open("ArchivoAdminBi.bin", ios::out | ios:: binary);
	
	if (archivoA.fail()) {

		cout << "No se abrio el archivo" << endl;
		exit(1);
	} 

	archivoA.write(reinterpret_cast<char*>(lista), sizeof(U_Admin));
	

    archivoA.close();

	cout << "Administrador registrado con exito" << endl;
}
void RegistroCajero() {

	int O = 0;

	Insertarcomercio2();
	Insertarnombre2();
	Insertarcontrasena2();


	cout << "1.Registrar usuario          2.Regresar" << endl;
	cin >> O;
	if (O == 1) {

		ArchivoCajeBi();

	}
	else {
		
		return;
		
	}

	system("pause");
	return;

}
void ArchivoCajeBi() {


	ofstream archivoCa;

	archivoCa.open("ArchivoCajeroBi.bin", ios::out | ios::binary);

	if (archivoCa.fail()) {

		cout << "No se abrio el archivo" << endl;
		exit(1);
	}

	archivoCa.write(reinterpret_cast<char*>(lista2), sizeof(U_Admin));


	archivoCa.close();

	cout << "Administrador registrado con exito" << endl;


}
void Insertarcomercio() {

	U_Admin* Nuevo_a = new U_Admin;
	cout << "Ingrese su tipo de comercio" << endl;
	cin.ignore();
	getline(cin, Nuevo_a->comercio);
	if(primero == NULL)
	{
		primero = Nuevo_a;
		primero-> sig = NULL;
		ultimo = Nuevo_a;
	}
	else
	{
		ultimo -> sig = Nuevo_a;
		Nuevo_a->sig = NULL;
		ultimo = Nuevo_a;

	}

	cout << "Comercio ingresado con exito" << endl;

}
void Insertarnombre() {

	U_Admin* Nuevo_a = new U_Admin;
	cout << "Ingrese su nombre (máximo 15 letras)" << endl;
	getline(cin, Nuevo_a->Anombre);
	if (primero == NULL)
	{
		primero = Nuevo_a;
		primero->sig = NULL;
		ultimo = Nuevo_a;
	}
	else
	{
		ultimo->sig = Nuevo_a;
		Nuevo_a->sig = NULL;
		ultimo = Nuevo_a;

	}

	cout << "Nombre ingresado con exito" << endl;

}
void Insertarcontraseña() {

	U_Admin* Nuevo_a = new U_Admin;
	cout << "Ingrese su contraseña" << endl;
	getline(cin, Nuevo_a->Acontrasena);
	if (primero == NULL)
	{
		primero = Nuevo_a;
		primero->sig = NULL;
		ultimo = Nuevo_a;
	}
	else
	{
		ultimo->sig = Nuevo_a;
		Nuevo_a->sig = NULL;
		ultimo = Nuevo_a;

	}

	cout << "Contraseña ingresada con exito" << endl;

}
void Insertarcomercio2() {


	U_Cajero* Nuevo_caj = new U_Cajero;
	cout << "Ingrese su tipo de comercio" << endl;
	cin.ignore();
	getline(cin, Nuevo_caj->Ccomercio);

	if (prim == NULL)
	{
		prim = Nuevo_caj;
		prim->next = NULL;
		ult = Nuevo_caj;
	}
	else
	{
		ult ->next = Nuevo_caj;
		Nuevo_caj->next = NULL;
		ult = Nuevo_caj;

	}

	cout << "Comercio ingresado con exito" << endl;


}
void Insertarnombre2() {

	U_Cajero* Nuevo_caj = new U_Cajero;
	cout << "Ingrese su tipo de nombre" << endl;
	getline(cin, Nuevo_caj->Cnombre);

	if (prim == NULL)
	{
		prim = Nuevo_caj;
		prim->next = NULL;
		ult = Nuevo_caj;
	}
	else
	{
		ult->next = Nuevo_caj;
		Nuevo_caj->next = NULL;
		ult = Nuevo_caj;

	}

	cout << "Nombre ingresado con exito" << endl;


}
void Insertarcontrasena2() {

	U_Cajero* Nuevo_caj = new U_Cajero;
	cout << "Ingrese su contraseña" << endl;
	getline(cin, Nuevo_caj->Ccontrasena);

	if (prim == NULL)
	{
		prim = Nuevo_caj;
		prim->next = NULL;
		ult = Nuevo_caj;
	}
	else
	{
		ult->next = Nuevo_caj;
		Nuevo_caj->next = NULL;
		ult = Nuevo_caj;

	}

	cout << "Contrasena ingresado con exito" << endl;

}
void MenuAdmin() {

	system("cls");
	int elc = 0;
	int opc = 0;
	int pic = 0;
	int ver = 0;
	int numero = 0;

	cout << "¿Que accion desea hacer?" << endl;
	cout << "------------------------" << endl << endl;
	cout << "1 - Alta de usuarios" << endl;
	cout << "2 - Actualizar usuarios" << endl << endl;
	cout << "3 - Restablecer contraseña" << endl;
	cout << "4 - Dar de baja" << endl;
	cout << "5 - Listado de usuarios" << endl;
	cout << "6 - Salir" << endl;

	cin >> elc;

	switch (elc) {
	case 1:

		cout << "Elija a que tipo de usuario dar de alta " << endl;
		cout << "1.- Cliente      2.-Nuevo Administrador" << endl;
		cin >> opc;

		if (opc == 1) {

			AltaClinte();
			return MenuAdmin();
		

		}
		else {

			AltaNAdmin();
			return MenuAdmin();

		}

		break;


	   case 2:

		   cout << "Elija a que tipo de usuario actualizara" << endl;
		   cout << "1.- Administrador     2.- Cajero" << endl;
		   cin >> numero;

		   if (numero == 1) {

			   ActualizarUA();
			   ArchivoAdminBi();

			   return MenuAdmin();


		   }
		   else {

			   ActualizarUCA();
			   ArchivoCajeBi();
			   return MenuAdmin();

		   }
		   break;


	   case 3:
		   break;

	   case 4:

		   cout << "¿Que tipo de usuario desea dar de baja?" << endl;
		   cout << " 1. Cajero           2. Cliente" << endl;
		   cin >> pic;
		   if (pic == 1) {

			   BajaCajero();
			   return MenuAdmin();

		   }
		   else {





		   }

		   system("pause");
		   break;

	   case 5:

		   cout << "Que lista tipo de usuario desea ver" << endl;
		   cout << "1. Usarios            2.Clientes" << endl;
		   cin >> ver;

		   if (ver == 1) {

			   cout << "Administradores" << endl;

			   Mostrarlista();

			   cout << "* Lectura en Binario *" << endl;

			   //LeerArcAd();

			   cout << "------------------" << endl;

			   cout << " $ Cajeros $" << endl;

			   Mostrarlista2();

			   cout << "Lectura en Binero" << endl;

			   //LeerArcCaj();

			   system("pause");

			   return MenuAdmin();
		   }

		   else{

			   cout << "Listado Cliente" << endl;

			   Mostrarlista3();


		   }

	   case 6:

		   return;
		   

	}



}
void AltaClinte() {

	Insertarnombre3();
	Insertaralias();
	Insertartelef();
	Insertaremail();
	Insertarcomercio3();
	
	system("pause");
}
void Insertarnombre3() {

	Cliente * Nuevo = new Cliente;
	cout << "Ingrese el nombre del cliente" << endl;
	cin.ignore();
	getline(cin, Nuevo->nombrec);
	if (pun == NULL)
	{
		pun = Nuevo;
		pun->siguiente = NULL;
		aux = Nuevo;
	}
	else
	{
		aux->siguiente = Nuevo;
		Nuevo->siguiente = NULL;
		aux = Nuevo;

	}

	cout << "Nombre de cliente ingresado con exito" << endl;


}
void Insertaralias() {

	Cliente* Nuevo = new Cliente;
	cout << "Ingrese su alias" << endl;
	getline(cin, Nuevo->alias);
	if (pun == NULL)
	{
		pun = Nuevo;
		pun->siguiente = NULL;
		aux = Nuevo;
	}
	else
	{
		aux->siguiente = Nuevo;
		Nuevo->siguiente = NULL;
		aux = Nuevo;

	}

	cout << "Alias de cliente ingresado con exito" << endl;

}
void Insertartelef() {

	Cliente* Nuevo = new Cliente;
	cout << "Ingrese su telefono" << endl;
	cin.getline(Nuevo->telefono, 50);
	if (pun == NULL)
	{
		pun = Nuevo;
		pun->siguiente = NULL;
		aux = Nuevo;
	}
	else
	{
		aux->siguiente = Nuevo;
		Nuevo->siguiente = NULL;
		aux = Nuevo;

	}

	cout << "Telefono de cliente ingresado con exito" << endl;

}
void Insertaremail() {

	Cliente* Nuevo = new Cliente;
	cout << "Ingrese su email" << endl;
	cin.ignore();
	getline(cin, Nuevo->email);
	if (pun == NULL)
	{
		pun = Nuevo;
		pun->siguiente = NULL;
		aux = Nuevo;
	}
	else
	{
		aux->siguiente = Nuevo;
		Nuevo->siguiente = NULL;
		aux = Nuevo;

	}

	cout << "Email de cliente ingresado con exito" << endl;

}
void Insertarcomercio3() {

	Cliente* Nuevo = new Cliente;
	Nuevo->comercioc = lista->comercio;
	if (pun == NULL)
	{
		pun = Nuevo;
		pun->siguiente = NULL;
		aux = Nuevo;
	}
	else
	{
		aux->siguiente = Nuevo;
		Nuevo->siguiente = NULL;
		aux = Nuevo;

	}

	cout << "Comercio de cliente aplicado con exito" << endl;

}
void Insertarfecha() {

	Cliente* Nuevo = new Cliente;
	Nuevo->fecha;
	if (pun == NULL)
	{
		pun = Nuevo;
		pun->siguiente = NULL;
		aux = Nuevo;
	}
	else
	{
		aux->siguiente = Nuevo;
		Nuevo->siguiente = NULL;
		aux = Nuevo;

	}

	cout << "Comercio de cliente aplicado con exito" << endl;



}
void AltaNAdmin() {

	Insertarcomercio();
	Insertarnombre();
	Insertarcontraseña();
	
}
void InicioSesionAdmin() {

	system("cls");
	string usuario = "";
	string contrasena = "";

	cout << "Bienvenido administrador" << endl;
	cout << "Ingrese su nombre de usuario" << endl;
	cin.ignore();
	getline(cin,usuario);

	cout << "Ingrese su contraseña" << endl;
	getline(cin,contrasena);

	if (usuario == "emi" && contrasena == "e12") {

		MenuAdmin();

	}
	else {

		cout << "Usuario o contraseña incorrectos" << endl;

	}
	return;
	
}
void Mostrarlista() {

	U_Admin* actual = new U_Admin;
	actual = primero;
	if (primero != nullptr) {
		while (actual != nullptr) {

			cout << " " << actual->comercio << endl;
			cout << " " << actual->Anombre << endl;
			cout << " " << actual->Acontrasena << endl << endl;
			actual = actual->sig;

		}
	}
	else {

		cout << "No hay usuarios registrados" << endl;
		return;
	}

}
void Mostrarlista2() {

	U_Cajero* recien = new U_Cajero;
	recien = prim;
	if (prim != nullptr) {
		while (recien != nullptr) {

			cout << " " << recien->Ccomercio << endl;
			cout << " " << recien->Cnombre << endl;
			cout << " " << recien->Ccontrasena << endl << endl;
			recien = recien->next;

		}
	}
	else {

		cout << "No hay usuarios registrados" << endl;
		return;
	}

}
void Mostrarlista3() {

	Cliente* otro = new Cliente;
	otro = pun;
	if (pun != nullptr) {
		while (otro != nullptr) {

			cout << " " << otro->comercioc << endl << endl;
			cout << " " << otro->nombrec << endl;
			cout << " " << otro->alias << endl;
			cout << " " << otro->telefono << endl;
			cout << " " << otro->email << endl;
			system("date/t");
			cout << "---------------------" << endl;

			otro = otro-> siguiente;

		}
	}
	else {

		cout << "No hay clientes registrados" << endl;
		return;
	}

}
void BajaCajero() {

	string borrarca;
	U_Cajero* nodo = new U_Cajero();
	cout << "ingresa el nombre: ";
	cin >> borrarca;

	if (prim == nullptr)
	{
		return;
	}
	ult = prim;
	if (ult->Cnombre == borrarca)
	{
		ult = ult->next;
		delete ult;
	}
	else
	{
		while (ult->next!= nullptr && ult->next->Cnombre != borrarca)
		{
			ult = ult->next;
		}

		if (ult->next != nullptr && ult->next->Cnombre == borrarca)
		{
			U_Cajero* temporal = ult-> next;
			ult->next = ult->next->next;
			delete temporal;
		}
	}

	cout << "Usuario dado de baja correctamente" << endl;

}
void Buscar() {

	U_Cajero* recien = new U_Cajero;
	recien = prim;
	bool encontrado = false;
	string clientebuscado;
	cout << "Ingrese el nombre del cajero a buscar" << endl;
	getline(cin, clientebuscado);
	if (prim != NULL) {

		while (recien != NULL && encontrado != true) {

			if (recien->Cnombre == clientebuscado) {

				cout << "Cajero: " << clientebuscado << endl;
				encontrado = true;

			}

			recien = recien->next;

		}if (!encontrado) {

			cout << "Cajero no encontrado" << endl;

		}


	}
	else {

		cout << "Lista vacia" << endl;

	}

}
void LeerArcAd() {

	ifstream archivoA;

	archivoA.open("ArchivoAdminBi.bin", ios::in | ios::binary);

	if (archivoA.fail()) {

		cout << "No se abrio el archivo" << endl;
		exit(1);
	}

	int size = archivoA.tellg();

	int i = 0;
	U_Admin* Tem = new U_Admin;
	archivoA.seekg(i* sizeof(U_Admin));
    archivoA.read(reinterpret_cast<char*>(Tem), sizeof(U_Admin));

	


	archivoA.close();

	cout << "Administrador registrado con exito" << endl;




}
void LeerArcCaj() {


}
void ActualizarUA(){

	U_Admin* actual= new U_Admin;
	actual = primero;
	bool encon = false;
	string adminbuscado;
	cout << "Ingrese el nombre del cajero a buscar" << endl;
	cin.ignore();
	getline(cin, adminbuscado);
	if (primero != NULL) {

		while (actual != NULL && encon != true) {

			if (actual->Anombre == adminbuscado) {

				cout << "Nombre de administrador encontrado " << adminbuscado << endl;
				cout << "Ingrese el cambio de nombre" << endl;
				getline(cin, actual->Anombre);
				cout << "Cambio hecho con exito" << endl;
				encon= true;

			}

			actual = actual->sig;

		}if (!encon) {

			cout << "Administrador no encontrado" << endl;

		}
	}
	else {

		cout << "Lista vacia" << endl;

	}

	system("pause");

}
void ActualizarUCA(){

	U_Cajero* recien = new U_Cajero;
	recien = prim;
	bool trado = false;
	string cajerobuscado;
	cout << "Ingrese el nombre del cajero a buscar" << endl;
	cin.ignore();
	getline(cin, cajerobuscado);
	if (prim != NULL) {

		while (recien != NULL && trado != true) {

			if (recien->Cnombre == cajerobuscado) {

				cout << "Nombre de cajero encontrado " << cajerobuscado << endl;
				cout << "Ingrese el cambio de nombre" << endl;
				getline(cin, recien->Cnombre);
				cout << "Cambio hecho con exito" << endl;
				trado = true;

			}

			recien = recien->next;

		}if (!trado) {

			cout << "Cajero no encontrado" << endl;

		}


	}
	else {

		cout << "Lista vacia" << endl;

	}




}