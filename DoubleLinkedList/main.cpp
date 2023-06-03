#include <iostream>
#include "List.hpp"
#include <fstream>
#include <string>

using namespace std;

int main() {
    List lst;
    List list;
    Circle krug;
    Circle krug2(10, 3,5);
    Circle krug3(100, 3,5);
    
    lst.push_back(&krug);
    lst.push_back(&krug3);
    
    lst.push_back(&krug2);
    lst.push_back(&krug);
    
    lst.sort();
    
    char file_out[256];
    cout << "Введите название файла с .txt на конце, перед этим указав путь к нему" << endl;
    cin >> file_out;

    ofstream fout(file_out);
    fout << lst;
    fout.close();
    
    char file_in[256];
    cout << "Введите название файла с .txt на конце, перед этим указав путь к нему" << endl;
    cin >> file_in;
     
    ifstream fin(file_in);
    fin >> lst;
    fin.close();

    return 0;
}
