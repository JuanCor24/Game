#include<iostream>

#include<ctime>  //este es para que el numero aleatorio salga con respecto a la hora del programa
int calcular_aleatorio (int& primero);
void verificar(int primero,bool& bandera);
void comparar(int numero,int primero,int& fijas);
void comparar2(int numero,int primero,int& picas);
using namespace std;

int main(){
    int primero = 0;
    bool bandera = false;
    bool bandera2 = false;
    char modo = 'a';
    char rendirse;
    int contador = 0;
    int numero = 0;
    int fijas = 0;
    int picas = 0;
    cout << "Elija cuantos intentos quiere (o = infinitos/i = ilimitados)";
    cin >> modo;
    if(modo == 'i'){
        cout << "Cuantos intentos quiere: ";
        cin >> contador;
    }


calcular_aleatorio(primero);

verificar(primero,bandera);
//si no son distintos se ejecuta la primera funcion hasta que ya se pueda
cout << "Si no te sale nada siginfica que no hay ninguna fija ni pica "<<endl;
while(bandera == false){
   calcular_aleatorio(primero);

   verificar(primero,bandera);

}
cout << "Ya tengo un numero intenta adivinarlo recuerda que no tiene digitos repetidos y son solamente 4 : "<<endl;
cin >> numero;

if(numero == primero){
    cout << "Felicidades ud es un crack gano a la primera se gano un 10.0 en adivinacion...."<<endl;
    bandera2 = true;
}
while((bandera2 == false)){
if(contador > 0){
    contador -= 1;
    if(contador == 0){
       cout << "Perdiste el juego vuelve a intentarlo,el numero era "<< primero <<endl;
       break;
       }
}
comparar( primero, numero, fijas);
comparar2(primero,numero, picas);

cout << "Vuelva a digitar un numero(si quiere rendirse despues escriba r/ si no n) "<<endl;
cin >> numero;
cin >> rendirse;
if(rendirse == 'r'){
    cout << "jaajja que noob perdio,el numero era "<<primero<< endl;
    break;
}
if(numero == primero){
    cout << "Felicidades gano: "<<"el numero efectivamente era "<<primero <<endl;
    bandera2 = true;
}
}

cout << "Gracias por jugar "<<endl;


return 0;
}
int calcular_aleatorio(int& primero){
    srand(time(NULL));
primero = rand()% (9999-1000+1)+ 1000;

}
//Esto es para verificar que todos los numero son distintos
 void verificar(int primero,bool& bandera){
     int a,b,c,d;
    if(primero <= 9999){
     a = primero/1000;
     b =  (primero % 1000)/100;
     c = (primero%1000)%100/10;
    d = (primero%1000)%100%10/1;
    }
   if((a == b || a == c || a == d)){
    bandera = false;
}
else if(b == c || b == d){
    bandera = false;
}
else if(c == d){
    bandera = false;
}
else{
    bandera = true;
}
   }
   void comparar(int primero,int numero,int& fijas){
   int a,b,c,d,a1,b1,c1,d1;
    if(primero <= 9999 ){
     a = primero/1000;
     b =  (primero % 1000)/100;
     c = (primero%1000)%100/10;
    d = (primero%1000)%100%10/1;
    }

     if(numero <= 9999 && numero >= 1000){
     a1 = numero/1000;
     b1 =  (numero % 1000)/100;
     c1 = (numero%1000)%100/10;
    d1 = (numero%1000)%100%10/1;
    }
    else{
        cout << "El numero digitado no es valido vuelvalo a intentar"<<endl;
    }
    if(a == a1){
        fijas += 1;
        cout << "La fija es: "<<a1<<endl;
    }
    if(b == b1){
        fijas +=1;
        cout << "La fija es: "<<b1<<endl;
    }
    if (c == c1){
        fijas +=1;
         cout << "La fija es: "<<c1<<endl;
    }
    if (d == d1){
        fijas +=1;
         cout << "La fija es: "<<d1<<endl;
    }


   }
   void comparar2(int numero,int primero,int& picas){
   int a,b,c,d,a1,b1,c1,d1;
    if(primero <= 9999){
     a = primero/1000;
     b =  (primero % 1000)/100;
     c = (primero%1000)%100/10;
    d = (primero%1000)%100%10/1;
    }
     if(numero <= 9999){
     a1 = numero/1000;
     b1 =  (numero % 1000)/100;
     c1 = (numero%1000)%100/10;
    d1 = (numero%1000)%100%10/1;
    }
    if(a == b1 || a == c1 || a == d1){
        cout << "La pica es: " << a << endl;
    }

    if(b == a1 || b == c1 || b == d1){
        cout << "La pica es "<< b <<endl;
    }
    if(c == a1 || c == b1 || c == d1){
        cout << "La pica es "<< c <<endl;
    }
    if(d == a1 || d == b1 || d == c1){
        cout << "La pica es "<< d <<endl;
    }

   }

