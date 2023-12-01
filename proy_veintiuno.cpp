/* Proyecto - 21

Valeria Arce
Juliana Contreras
Santiago Jorigua
Simón Vélez

Algoritmos y Estructuras de Datos
Universidad del Rosario, 2023 */

#include<iostream>
#include <chrono>
#include <thread>

using namespace std;

template<typename T>
class Nodo{
private:
  T dato;
  Nodo* next;

public:

 Nodo(T d){
     dato = d;
     next =  NULL;
 }
 
 ~Nodo(){
 }
 
 T get_dato(){
     return dato;
 }
 
 void set_dato(T d){
     dato = d;
 }
 
 Nodo* get_next(){
     return next;
 }
 
 void set_next(Nodo* n){
     next = n;
 }
};

template<typename T>
class Lista{
private:
  Nodo<T>* ptr;
  int size;

public:

    Lista(){
        ptr = NULL;
        size = 0;
    }
  
    ~Lista(){
        Nodo<T>* temp = ptr;
        if(ptr != NULL){
            Nodo<T>* temp_next = ptr->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el último nodo
        }
    }
    
    void add(T d){
        Nodo<T>* nodo = new Nodo<T>(d);
        
        if(ptr == NULL){//La lista está vacía
            ptr  = nodo;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    void multiadd(int size, T d[]){
        for (int i = 0; i<size; i++){
            add(d[i]);
        }
    }
    
    void insert(T d, int i){
        if(i<=size && i>=0 && ptr != NULL){
            Nodo<T>* nodo = new Nodo<T>(d);
            if(i == 0){
                nodo->set_next(ptr);
                ptr = nodo;
            }else{
                int j = 0;
                Nodo<T>* temp =  ptr;
                while(j<i-1){
                    temp = temp->get_next();
                    j++;
                }
                nodo->set_next(temp->get_next());
                temp->set_next(nodo);
            }
            size++;
        }else{//Si el índice es incorrecto o la lista está vacía, se añade al final
            add(d);
        }
        
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                //cout<<temp->get_dato()<<","<<temp->get_next()<<"\t";
                cout<<temp->get_dato()<<"\t";
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    Nodo<T>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          Nodo<T>* temp = ptr;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
    
};

template<typename T>
class Pila{
private:
  Nodo<T>* ptr;
  int size;

public:

    Pila(){
        ptr = NULL;
        size = 0;
    }
  
    ~Pila(){
        Nodo<T>* temp = ptr;
        if(ptr != NULL){
            Nodo<T>* temp_next = ptr->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el último nodo
        }
    }
    
    void add(T d){
        Nodo<T>* nodo = new Nodo<T>(d);
        
        if(ptr == NULL){//La lista está vacía
            ptr  = nodo;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    void insert(T d, int i){
        if(i<=size && i>=0 && ptr != NULL){
            Nodo<T>* nodo = new Nodo<T>(d);
            if(i == 0){
                nodo->set_next(ptr);
                ptr = nodo;
            }else{
                int j = 0;
                Nodo<T>* temp =  ptr;
                while(j<i-1){
                    temp = temp->get_next();
                    j++;
                }
                nodo->set_next(temp->get_next());
                temp->set_next(nodo);
            }
            size++;
        }else{//Si el índice es incorrecto o la lista está vacía, se añade al final
            add(d);
        }
        
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La pila está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                //cout<<temp->get_dato()<<","<<temp->get_next()<<"\t";
                cout<<temp->get_dato()<<"\t";
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    Nodo<T>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          Nodo<T>* temp = ptr;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
    
    int get_size(){
        return size;
    }
    bool isEmpty(){
        if(size == 0){
            return true;
        }else{
            return false;
        }
    }
    void push(T val){
        insert(val, size);
    }
    T pop(){
        if (size == 0){
            cout<<"Error! (pop en lista vacía)"<<endl;
            return NULL;
        }
        if (size ==1){
            Nodo<T>* popped = get(size-1);
            ptr = NULL;
            size--;
            return popped->get_dato();
        }
        else{
            Nodo<T>* popped = get(size-1);
            get(size-2)->set_next(NULL);
            delete get(size-1);
            size--;
            return popped->get_dato();
        }
    }
    
    T peek(){
        Nodo<T>* nod_temp = get(size-1);
        return nod_temp->get_dato();
    }
    void clear(){
        if (size > 0){
            pop();
            clear();
        }
    }
    
};
class Mazo {
private:
    string suit[52] = {"AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AT", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T", "10T", "JT", "QT", "KT", "AP", "2P", "3P", "4P", "5P", "6P", "7P", "8P", "9P", "10P", "JP", "QP", "KP"};

    Pila<string> mazo;
    int size;

public:
    Mazo() {
        size = 52;
        for (int i = 0; i < size; i++) {
            mazo.push(suit[i]);
        }
    }

    Mazo(int tam, bool shuffled) {
        size = tam;
        if (shuffled) {
            std::srand(static_cast<unsigned int>(time(0)));  // Cambia time(nullptr) por std::time(0)

            string aux[52];
            for (int i = 0; i < size; i++) {
                aux[i] = suit[i];
            }

            for (int i = size - 1; i > 0; i--) {
                int j = std::rand() % (i + 1);
                std::swap(aux[i], aux[j]);
            }

            for (int i = 0; i < size; i++) {
                mazo.push(aux[i]);
            }
        } else {
            for (int i = 0; i < size; i++) {
                mazo.push(suit[i]);
            }
        }
    }

    void print() {
        mazo.print();
    }
    
    void add(string carta){
        size++;
        mazo.push(carta);
    }
    
    string remover(){
        size--;
        return mazo.pop();
    }
    
    void vaciar(){
        mazo.clear();
        size = 0;
    }
    
    int puntaje(){ //Suma el valor de las cartas
        int total = 0;
        int numA = 0; //Se guarda aparte la cantidad de A en el mazo, para después ajustar si vale 1 u 11
        for (int i = 0; i<size; i++){
            string carta = mazo.get(i)->get_dato();
            switch(carta[0]){ //Suma puntos dependiendo del tipo de carta
                case 'J':
                total += 10;
                break;
                case 'Q':
                total += 10;
                break;
                case 'K':
                total += 10;
                break;
                case '1':
                total += 10;
                break;
                case 'A':
                numA += 1;
                total += 11;
                break;
                default:
                total += carta[0]-'0';
            }
        }
        while (numA > 0 && total > 21) { //Si los A hacen que se pase de 21, se ajusta el valor de 11 a 1.
            total -= 10;
            numA--;
        }
        return total;
    }
    int get_size(){
        return size;
    }
};

class Jugador{
   private:
   Mazo mazo; //El jugador inicia con un mazo vacío
   int fichas;
   int puntaje;
   
   public:
    Jugador() {
       fichas = 100;
       puntaje = 0;
       mazo.vaciar();
    }
    void print(){
        cout<<"- - - - - - - - - - - - -"<<endl;
        cout<<"Tus cartas: ";
        mazo.print();
        cout<<"Tu puntaje actual es: "<<puntaje<<endl;
    }
    Mazo get_mazo(){
       return mazo;
    }
    int get_fichas(){
       return fichas;
    }
    int get_puntaje(){
       return puntaje;
    }
    void setFichas(int nuevasFichas) {
        fichas = nuevasFichas;
    }
    
    void setPuntaje(int nuevoPuntaje) {
        puntaje = nuevoPuntaje;
    }
    
    void addCartaAMazo(string carta) {
        mazo.add(carta);
    }
    
    void vaciarMazo() {
        mazo.vaciar();
    }
    
    int calcularPuntaje() {
        puntaje = mazo.puntaje();
        return puntaje;
    }
};

class Casa{
   private:
   Mazo mazo; //La casa inicia con un mazo vacío
   int puntaje;
   
   public:
   Casa(){
       mazo.vaciar();
       puntaje = 0;
   }
    void print(){
        cout<<"- - - - - - - - - - - - -"<<endl;
        cout<<"Cartas de la casa: ";
        mazo.print();
        cout<<"El puntaje de la casa es: "<<puntaje<<endl;
    }
   Mazo get_mazo(){
       return mazo;
   }
   int get_puntaje(){
       return puntaje;
   }
    void setPuntaje(int nuevoPuntaje) {
        puntaje = nuevoPuntaje;
    }

    void addCartaAMazo(string carta) {
        mazo.add(carta);
    }

    void vaciarMazo() {
        mazo.vaciar();
    }

    int calcularPuntaje() {
        puntaje = mazo.puntaje();
        return puntaje;
    }
};

void jugar(Mazo &mazo, Jugador &juga, Casa &casa){ //Función que inicia el juego
    int apuesta = 0;
    if (juga.get_fichas() == 0){ // Se acaba el juego si te quedaste sin fichas
        cout<<"No te quedan más fichas, gracias por jugar."<<endl;
        return;
    }
    // El jugador recibe la primera carta del mazo
    juga.addCartaAMazo(mazo.remover());
    juga.print();

    // Establecer la apuesta 
    cout<<"- - - - - - - - - - - - -"<<endl;
    cout<<"Actualmente tienes "<<juga.get_fichas()<<" fichas. ¿Cuántas deseas apostar?"<<endl;
    cin>>apuesta;
    while (apuesta > juga.get_fichas() || apuesta == 0){
        // Reinicia el cin 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        cout<<"Apuesta inválida, debes apostar al menos una ficha y no más de las que tienes. Inserta una nueva apuesta: "<<endl;
        cin>>apuesta;
    }
    
    //El jugador recibe más cartas
    juga.addCartaAMazo(mazo.remover());
    juga.calcularPuntaje();
    juga.print();
    string com = ""; //Se guarda la decisión del jugador de seguir o plantarse
    cout<<"¿Desea seguir o plantarse? (seguir/plantarse)"<<endl;
    cin>> com; 
    while (com != "seguir" && com != "plantarse"){ //Si el comando es inválido pide otro
        cout<<"Comando incorrecto. ¿Desea seguir o plantarse? (seguir/plantarse)"<<endl;
        cin>>com;
    }
    while (com == "seguir" && juga.get_puntaje()<22){ // Sacar cartas hasta que el jugador deje de seguir o se pase de 21
            juga.addCartaAMazo(mazo.remover());
            juga.calcularPuntaje();
            juga.print();
            cout<<"¿Desea seguir o plantarse? (seguir/plantarse)"<<endl;
            cin>> com;
            while (com != "seguir" && com != "plantarse"){
                cout<<"Comando incorrecto. ¿Desea seguir o plantarse? (seguir/plantarse)"<<endl;
                cin>>com;
            }
    }
    
    // Condiciones de pérdida
    if (juga.get_puntaje() > 21){
        juga.setFichas(juga.get_fichas()-apuesta);
        cout<<"¡Te pasaste de 21!"<<endl;
        cout<<"Ahora tienes "<<juga.get_fichas()<<" fichas"<<endl;
        apuesta = 0;
        juga.vaciarMazo();
        juga.setPuntaje(0);
        casa.vaciarMazo();
        casa.setPuntaje(0);
        return;
    }
    
    //El turno de la casa
    juga.print();
    casa.addCartaAMazo(mazo.remover());
    casa.calcularPuntaje();
    casa.print();
    while(casa.get_puntaje() < juga.get_puntaje()){ 
        if (casa.get_puntaje()>16 && casa.get_puntaje()<19 && rand()%2 == 1){ // Si el puntaje está entre 16 y 19 la casa tiene 50% de plantarse
             break;
        }
        cout<<"La casa decide sacar otra carta..."<<endl;
        this_thread::sleep_for(1s);
        casa.addCartaAMazo(mazo.remover());
        casa.calcularPuntaje();
        casa.print();
    }
    juga.print();
    
    //¿Quién ganó?
    if (juga.get_puntaje() > casa.get_puntaje() || casa.get_puntaje() > 21){
        juga.setFichas(juga.get_fichas()+apuesta);
        cout<<"¡Ganaste!"<<endl;
        cout<<"Ahora tienes "<<juga.get_fichas()<<" fichas"<<endl;
        apuesta = 0;
        juga.vaciarMazo();
        juga.setPuntaje(0);
        casa.vaciarMazo();
        casa.setPuntaje(0);
        return;
    }else{
        juga.setFichas(juga.get_fichas()-apuesta);
        cout<<"¡Perdiste!"<<endl;
        cout<<"Ahora tienes "<<juga.get_fichas()<<" fichas"<<endl;
        apuesta = 0;
        juga.vaciarMazo();
        juga.setPuntaje(0);
        casa.vaciarMazo();
        casa.setPuntaje(0);
        return;
    }
}

void sesion(Jugador &juga, Casa &casa){
    string com = ""; // Variable para comandos
    cout<<"¿Desea jugar una partida de 21? (y/n)";
    cin>>com;
    while (com != "y" && com != "n" && com != "Y" && com != "N"){ //Verificar si sí es un comando válido
        cout<<"Comando incorrecto. ¿Desea jugar una partida de 21? ('y' si sí o 'n' si no)";
        cin>>com;
    }
    cout<<"Jugar sin control causa adicción, el juego es entretenimiento, juega con moderación. Prohibida la venta a menores de edad."<<endl;
    while (com == "y" || com == "Y"){ //Jugar hasta que el jugador diga que no
        com = "";
        cout<< "Mezclando un nuevo mazo..."<<endl;
        Mazo mazo(52, true);
        jugar(mazo, juga, casa);
        cout<<"¿Desea jugar otra partida de 21? (y/n)"<<endl;
        cin>>com;
        while (com != "y" && com != "n" && com != "Y" && com != "N"){ //Verificar si sí es un comando válido
            cout<<"Comando incorrecto. ¿Desea jugar otra partida de 21? ('y' si sí o 'n' si no)";
            cin>>com;
        }
    }
    cout<<"Tu número final de fichas es: "<<juga.get_fichas()<<endl;
    cout<<"¡Gracias por jugar!"<<endl;
}
int main() {
    srand (time(NULL)); // Se establece una semilla aleatoria
    Jugador j;
    Casa c;
    sesion(j, c);
    return 0;
}
