#include "iostream"
#include "stdlib.h"
#include "ctime"
#include "windows.h"
using namespace std;

void menu_principal();
void menu_opc();
void animations(int );
bool result(int,int);
int CalcularEdad(int,int,int);

#pragma region Variables Globales
char title[] = "\t     -----<<Calculador de Edad 3000>>-----\n";

int year,mes,dia;

time_t now = time(0);

    tm *ltm = localtime(&now);
    int ano = 1900+ltm->tm_year;
    int month = 1+ltm->tm_mon;
    int day = ltm->tm_mday;
#pragma endregion

int main(){
    SetConsoleTitle("Calculador de Edad 3000");
    animations(1);
    return 0;
}

int CalcularEdad(int year,int mes,int dia){
    int edad;
    if((mes < month)){
        edad = ano - year;
    }else if((mes == month)and(dia <= day)){
        edad = ano - year;
    }else if(mes>month){
        edad = (ano - year)-1;
    }else{
        edad = (ano - year)-1;
    }
    return edad;
}

bool result(int month,int day){
    bool band_fin,band_mes,band_day;
    int dia = day;
    int mes = month;
    //Mes
    if((mes>0)&&(mes<13)){
        band_mes = true;
    }else if((mes<0)or(mes>12)){
        band_mes = false;
    }

    //Dia
    if((dia>0)&&(dia<32)){
        band_day = true;
    }else if((dia<0)or(dia>31)){
        band_day =false;
    }

    if(band_mes == band_day){
        band_fin = true;
    }else{
        band_fin = false;
    }

    return band_fin;
}

void menu_principal(){
    int opc;
    cout<<"\t"<<title<<endl;
    cout<<"1.Calcular edad"<<endl;
    cout<<"2.Salir"<<endl;
    cout<<"Opcion::\t";
    cin>>opc;
    switch(opc){
        case 1:
            menu_opc();
            break;
        case 2:
            break;
    }
}

void animations(int id){
    int n = 0;
    int n1 = 0;
    string title1[] = {"|INICIANDO|","/INICIANDO/","-INICIANDO-","\134INICIANDO\134"};
    string title2[] = {"|CALCULANDO|","/CALCULANDO/","-CALCULANDO-","\134CALCULANDO\134"};
    switch (id){
        case 1:
            for(int i=0;i<4;i++){
                cout<<"\t"<<title<<endl;
                cout<<"\t\t\t        "<<title1[i];
                Sleep(1000);
                system("cls");
                if(i==3){
                    i=-1;
                }
                n++;
                if(n == 6){
                    break;
                }
            }
            menu_principal();
            break;
        case 2:
            for(int i=0;i<4;i++){
                cout<<"\t"<<title<<endl;
                cout<<"\t\t\t        "<<title2[i];
                Sleep(1000);
                system("cls");
                if(i==3){
                    i=-1;
                }
                n1++;
                if(n1 == 10){
                    break;
                }
            }
    }
}
void menu_opc(){
    system("cls");
    cout<<"\t"<<title<<endl;
    do{
    cout<<"Digite lo sgte(en numeros porfavor):: "<<endl;
    cout<<"\tMes::\t";cin>>mes;
    cout<<"\tDia::\t";cin>>dia;
    cout<<"\tA\244o::\t";cin>>year;
    }while(result(mes,dia)==0);


    system("cls");
    animations(2);
    cout<<"Su edad es::\t"<<CalcularEdad(year,mes,dia);
    cout<<"\n\nGracias por usar mi programa :)\n";
    cout<<"\t\t\t\t\tby The_EKJ\n";
    system("pause");
}
