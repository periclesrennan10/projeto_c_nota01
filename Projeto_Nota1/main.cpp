#include <iostream>
#include <string> 

using namespace std; 

int const fileira = 10;
int const coluna = 10;
double preco = 12.50;

void armazenaAssento(bool assentos[fileira][coluna]){

    for(int i = 0; i < fileira; i++) {
        for(int j = 0; j < coluna; j++){
            assentos[i][j] = false;
        }
    }
}

void mostrarAssentosDisponiveis(bool assentos[fileira][coluna]){

    cout << "Assentos: " << endl;
    for(int i = 0; i < fileira; i++) {
        for(int j = 0; j < coluna; j++){
             if(assentos[i][j]){
                cout << "1 ";
             }  else{
                cout << "0 ";
             }

        }
        cout << endl;
    }
}

int main () {

    bool assentos[fileira][coluna];
    armazenaAssento(assentos);

    int assentosVendidos = 0;
    double lucro = 0;

    char resposta; 

    do {
        cout << "Deseja comprar um ingresso?" << endl; 
        cin >> resposta; 

        if(resposta == 's' || resposta == 'S'){
            int fileira; 
            int coluna; 
            cout << "Qual assento voce deseja?" << endl;
            cout << "Digite a posicao da fileira de (1-10): " << endl;
            cin >> fileira; 
            cout << "Digite a posicao da coluna de (1-10): " << endl; 
            cin >> coluna; 
            
            if(fileira >= 1 && fileira <= 10 && coluna >= 1 && fileira <= 10 && !assentos[fileira - 1][coluna - 1]){
                assentos[fileira - 1][coluna - 1] = true;
                assentosVendidos++;
                lucro += preco;
                cout << "Compra realizada com sucesso" << endl;
            } else {
                cout << "Este lugar já foi vendido ou eh um lugar invalido" << endl;
            }
        } 
        mostrarAssentosDisponiveis(assentos);
    } while(resposta == 's' || resposta == 'S');

    cout << "Lugares vendidos: " << assentosVendidos << endl;
    cout << "Lucro total: " << lucro << endl;
    
    return 0;
}
