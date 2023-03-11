#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <filesystem>
using namespace std;

namespace fs = std::filesystem;

const size_t TAB_SIZE = 2;
int tab_num = 0;

bool is_hidden(const fs::directory_entry& entry) {
    return entry.path().filename().string()[0] == '.';
}

void print_tabs() {
    int i = 0;
    while(i++ < tab_num) {
        for(size_t k=0; k<TAB_SIZE; ++k) { 
            cout << " ";
        }
    }
}

void explore(fs::path p) {
    for(const auto& entry : fs::directory_iterator(p)) {
        if(is_hidden(entry)) continue;

        print_tabs();

        cout << "L-- ";
        if(entry.is_directory()) {
            cout << entry.path().filename() << ":\n";
            tab_num += 1;
            explore(entry.path());
            tab_num -= 1;
        } else {
            cout << entry.path().filename() << "\n";
        }
    }
}

int main(void) {

    string path;
    cout << "Uneti apsolutni ili relativni put do foldera: ";
    getline(cin, path);
    fs::path p(path);

    cout << fs::absolute(p) << ":\n";
    explore(p);

    return 0;
}