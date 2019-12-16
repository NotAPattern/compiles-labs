//#include <iostream>

#define LEN 200

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <numeric>
#include <functional>

struct REC
{
    int id;
    std::string name;
    std::string proch[16];
};

struct REC tab_id[LEN];

int read_table();
int find_id(std::string identy);
int insert_id(std::string identy);
int print_id();

int main(){
    char menu;
    std::string identy;
    read_table();
    while(menu !='0'){
        std::cout << "--Menu--\n"
                << "1) Insert id\n"
                << "2) Find id\n"
                << "3) Show\n"
                << "Select: ";

        //Да простит меня Тюменцев Е.А.
        std::cin >> menu;
        std::cout << std::endl;
        switch (menu)
        {
        case '1':
            std::cout << "Input identy: ";
            identy.clear();
            std::cin >> identy;
            std::cout << std::endl;
            insert_id(identy);
            break;
        case '2':
            std::cout << "Input identy: ";
            identy.clear();
            std::cin >> identy;
            std::cout << std::endl;
            find_id(identy);
            break;
        case '3':
            print_id();
            break;    
        default:
            break;
        }
    }
    return 0;
}

int read_table(){
    std::ifstream readFile("/home/nikita/git/compiles-labs/lab2/id");
    int i = 0;
    
    while(!readFile.eof()){
        tab_id[i].id = i;
        readFile >> tab_id[i].name;
        //std::cout << tab_id[i].id<< " " << tab_id[i].name << " ";
        i++;
    }

    readFile.close();
    return 0;
}

int insert_id(std::string identy){
    int i = 0;
    
    while(tab_id[i].name != "\0"){
        i++;
    }

    tab_id[i].id = i-1;
    tab_id[i].name = identy;

    return 0;
}

int find_id(std::string str){
    int i = 0;
    int j = 0;
    //find last element
    while(tab_id[i].name != "\0"){
        i++;
    }
    //empity
    if(i > LEN){
        std::cout << "Table is empity";
        exit(-1);
    }
    //find
    while(tab_id[j].name != str){
        if(j >= i){
            std::cout << "Not find element" << std::endl;
            return 0;
        }
        j++;
    }
    std::cout << "El: " << tab_id[j].id << std::endl;
    return 0;
}

int print_id(){
    int i = 0;
    std::cout << "Id" << "\tName" << std::endl;
    while(tab_id[i].name != "\0"){
        tab_id[i].id = i;
        std::cout << tab_id[i].id << "\t" << tab_id[i].name << std::endl;
        i++;
    }
    return 0;
}