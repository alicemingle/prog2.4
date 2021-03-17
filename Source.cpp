#include "Creator.h"
#include "AutoTest.hpp"
#include <map>
using namespace std;

int main() {
	if (!AutoTest()) {
		cout << "Ouch..." << endl;
		return 0;
	}
	cout << "Yeeeeey!!!" << endl;
	ifstream in("input.txt");
	int n = 0;
	in >> n;
	vector<CComplexVector*> arr(n);
    map<std::string, Creator*> fabrica;
    fabrica["Hori"] = new CreatorVector1();
    fabrica["Vert"] = new CreatorVector0();
	std::string j;
	int s = 0;
	std::string filename;
	for (auto i = arr.begin(); i != arr.end(); i++) {
		in >> j;
		in >> filename;
		in >> s;
		CComplexVector* a;
        a = fabrica[j]->create(s);
		a->setFilename(filename.c_str());
			for (int k = 0; k < s; k++) {
				string cur;
				in >> cur;
				int l = cur.find('+');
				if (l != string::npos) {
                    (*a)[k].re = atoi(cur.substr(0, l).c_str());
                    (*a)[k].im = atoi(cur.substr(l + 1, cur.size() - l - 2).c_str());
				}
				else if ((l = cur.find('-')) != string::npos) {
					(*a)[k].re = atoi(cur.substr(0, l).c_str());
					(*a)[k].im = atoi(cur.substr(l, cur.size() - l - 1).c_str());
				}
				else if ((l = cur.find('i')) != string::npos) {
					(*a)[k].re = 0;
					(*a)[k].im = atoi(cur.substr(0, cur.size() - 1).c_str());
				}
				else {
					(*a)[k].re = atoi(cur.c_str());
					(*a)[k].im = 0;
				}
				*i = a;
			}
	}
	for (auto i = arr.begin(); i != arr.end(); i++) {
        (*i)->output((*i)->getFilename());
	}
	for(auto i = arr.begin(); i != arr.end(); i++){
	    delete (*i);
	}
	for(auto i : fabrica){
	    delete i.second;
	}
	arr.clear();
	fabrica.clear();
	return 0;
}
