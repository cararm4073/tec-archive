#include "personaje.h"

//builder por defecto
Personaje::Personaje() {
    vida = 100;
    salud = 100; 
    ataque = 10;
    nivel = 1;
};
//builder para personaje personalizado
Personaje::Personaje(int vida, int salud, int ataque, int nivel){
    this -> vida = vida;
    this -> salud = salud;
    this -> ataque = ataque;
    this -> nivel = nivel;
};

//destructor
Personaje::~Personaje(){
    
};

//setters y getters
void Personaje::setVida(int vida){
    this -> vida = vida;
};

void Personaje::setSalud(int salud){
    this -> salud = salud;
};

void Personaje::setAtaque(int ataque){
    this -> ataque = ataque;
};

void Personaje::setNivel(int nivel){
    this -> nivel = nivel;
};

int Personaje::getVida(){
    return vida;
}

int Personaje::getSalud(){
    return salud;
};

int Personaje::getAtaque(){
    return ataque;
};

int Personaje::getNivel(){
    return nivel;
};

//funciones juego
int Personaje::calcularPorcentajeSalud(){
    //unicamente se va a mostrar el porcentaje, mas no la barra!!!
    int porctSalud;

    porctSalud = salud * 100 / vida; //para sacar el porcentaje
    return porctSalud;
};

void Personaje::imprimirBarra(){
    int cantVida;
    int cantDaño;
    int porctSalud = calcularPorcentajeSalud(); //se llama a la función que ya realiza el cálculo

    cantVida = porctSalud/5; //para la cantidad de simbolos de vida dependiendo la vida del perosnaje
    cantDaño = 20-cantVida; //para la cantidad de simbolos que se deben de poner de daño, dependiendo de la vida del personaje
    
    //loop para imprimir los símbolos de acuerdo a los niveles calculados
    for(int i=0; i<cantVida; i++){
        std::cout << "%";    
    }
    for(int i=0; i<cantDaño; i++){
        std::cout << "=";    
    }
};

void Personaje::recibeAtaque(int ptosAtaque){
    salud = salud - ptosAtaque;
    //verificar que la salud no baje de 0 nunca al recibir daño
    if(salud < 0){
        salud = 0;
    }
};


int Personaje::calculaAtaque(Personaje& objetivo){
    //objetivo = a quién está atacaondo/a quien se está llamando en main dentro de una funcion
    int daño;
    if(objetivo.getNivel()> nivel){
        //si el objetivo tiene umayor nivel que el atacante... ataque entre 1 y la mitad. rival fuerte
        
        //entre 1 (min) y mitad (max)
        // 1 + numero al azar entre la mitad del ataque
        daño = 1 + rand() % (ataque / 2);

    } else{
        //si el objetivo tiene menor nivel... ataque entre mitad y maximo. rival debil

        //entre mitad (min) y ataque (max)
        //mitad del ataque y ataque
        daño = (ataque / 2) + rand() % (ataque - (ataque/2) +1);
    }
    return daño;
};

void Personaje::atacar(Personaje& objetivo){
    int daño = calculaAtaque(objetivo); //obtener el daño realizado al objetivo
    std::cout << "Ataque realizado con " << daño << " puntos de daño!" << std::endl;
    objetivo.recibeAtaque(daño); //reflejar y actualizar el daño realizado al objetivo
};

void Personaje::imprimir(){
    //stats del personaje
    std::cout << "   Vida máxima: " << vida << std::endl;
    std::cout << "   Salud actual: " << salud << std::endl;
    std::cout << "   Porcentaje de salud: " << calcularPorcentajeSalud() << "%" << std::endl;
    std::cout << "   Barra de vida: [";
    imprimirBarra();
    std::cout << "]" << std::endl;  
    std::cout << "   Ataque máximo: " << ataque << std::endl;
    std::cout << "   Nivel: " << nivel << std::endl;
};

