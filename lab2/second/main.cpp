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
    int next_hash;
};

struct REC tab_id[LEN];

int hash(int insert, bool randomize);
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
    int j = 0;
    bool flag = false;
    bool random_flag = false;
    int curr = 0;
    std::string buffer;
    int last_id = 0;

    while(!readFile.eof()){
        readFile >> buffer;
        //paranoid
        flag = false;
        j = 0;
        random_flag = false;
        last_id = 0;
        while(true != flag && j < buffer.length()){
            if(random_flag == true){
                if(tab_id[curr].next_hash == 0){
                    tab_id[curr].next_hash = hash(buffer[j], true);
                    curr = tab_id[curr].next_hash;
                } else {
                    last_id = curr;
                    //curr = hash(buffer[j], false);
                    //tab_id[curr].next_hash = hash(buffer[j], false);
                    curr = tab_id[curr].next_hash;
                }
                //curr = hash(buffer[j], true);
            } else {
                curr = hash(buffer[j], false);
            }
            if(tab_id[curr].name == "\0"){
                tab_id[curr].name = buffer;
                tab_id[curr].id = curr;
                flag = true;
            }
            random_flag = true;
            j++;
        }
        //readFile >> tab_id[i].name;
        //std::cout << tab_id[i].id<< " " << tab_id[i].name << " ";
        //i++;
    }

    readFile.close();
    return 0;
}

int insert_id(std::string identy){
    int i = 0;
    int j = 0;
    bool flag = false;
    bool random_flag = false;
    int curr = 0;
    int last_id = 0;

    while(true){
        //paranoid
        flag = false;
        j = 0;
        random_flag = false;
        last_id = 0;
        while(true != flag && j < identy.length()){
            if(random_flag == true){
                if(tab_id[curr].next_hash == 0){
                    tab_id[curr].next_hash = hash(identy[j], true);
                    curr = tab_id[curr].next_hash;
                } else {
                    last_id = curr;
                    //curr = hash(buffer[j], false);
                    //tab_id[curr].next_hash = hash(buffer[j], false);
                    curr = tab_id[curr].next_hash;
                }
                //curr = hash(buffer[j], true);
            } else {
                curr = hash(identy[j], false);
            }
            if(tab_id[curr].name == "\0"){
                tab_id[curr].name = identy;
                tab_id[curr].id = curr;
                flag = true;
                return 0;
            }
            random_flag = true;
            j++;
        }
        //readFile >> tab_id[i].name;
        //std::cout << tab_id[i].id<< " " << tab_id[i].name << " ";
        //i++;
    }
    // int i = 0;
    // int curr = 0;
    // bool flag = false;
    // int j = 0;
    // bool random_flag = false;
    // while(true != flag && j < identy.length()){
    // curr = hash(identy[j], false);
    // if(random_flag == true){
    //     if(tab_id[curr].next_hash == 0){
    //         tab_id[curr].next_hash = hash(identy[j], true);
    //         curr = tab_id[curr].next_hash;
    //     } else {
    //         //last_id = curr;
    //         //curr = hash(buffer[j], false);
    //         //tab_id[curr].next_hash = hash(buffer[j], false);
    //         curr = tab_id[curr].next_hash;
    //     }
    //     //curr = hash(buffer[j], true);
    // } else {
    //     curr = hash(identy[j], false);
    // }
    // if(tab_id[curr].name == "\0"){
    //     tab_id[curr].name = identy;
    //     tab_id[curr].id = curr;
    //     flag = true;
    // }
    // random_flag = true;
    // j++;
    // }

    return 0;
}

int find_id(std::string strf){
    int i = 0;
    int j = 0;
    int curr = 0;
    bool curr_flag = false;
    //empity
    if(i > LEN){
        std::cout << "Table is empity";
        exit(-1);
    }

    while(true){
        if(curr_flag == true){

        } else {
            curr = hash(strf[j], false);
        }
        if(tab_id[curr].name == strf) {
            std::cout << "Stirng is find! ID: " << tab_id[curr].id << " next-id: " << tab_id[curr].next_hash << std::endl;
            return 0;
        } else {
            if(tab_id[curr].next_hash == 0){
                std::cout << "Element not find!((" << std::endl;
                return 0;
            } else {
                curr = tab_id[curr].next_hash;
                curr_flag = true;
            }
        }
        j++;
    }
    return 0;
}

int print_id(){
    int i = 0;
    std::cout << "Id" << "\tName" << "\t\tNext_hash"<< std::endl;
    for(int t = 0; t < 200; t++){
        if(tab_id[t].name != "\0"){
        //tab_id[t].id = i;
        std::cout << tab_id[t].id << "\t" << tab_id[t].name <<"\t\t" << tab_id[t].next_hash << std::endl;
        }
    }
    return 0;
}

int hash(int insert, bool randomize = false){
    if(false == randomize){
        return insert % LEN;
    } else {
        return (insert + (rand() % 99 + 1))% LEN;
    }
}