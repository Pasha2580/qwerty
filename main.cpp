#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    double arg_r = 1;
    double arg_l = 1;
    int r_1 = 0;
    int r_2 = 0;
    int l_1 = 0;
    int l_2 = 0;

//  Считывание файла и преобразование каждой компоненты в чсило
    string str;
    ifstream in ("F:\\homework1\\in.txt");
    in.is_open();
    getline(in, str);
    int x_1 = stoi(str);
    string z = to_string(x_1);
    str.erase(str.find(z), z.length());
    int x_2 = stoi(str);

    if(in.is_open()){
        while (getline (in,str)){
//          координата х точки файла
            int a_1;
            a_1 = stoi(str);
            string b = to_string(a_1);
            str.erase(str.find(b), b.length());
//          координата y точки из файла
            int a_2;
            a_2 = stoi(str);
            double ugol = (x_1 * a_1 + x_2 * a_2) / (sqrt(x_1 * x_1 + x_2*x_2) * sqrt(a_1 * a_1 + a_2 * a_2));
            if ((x_2 != 0 && a_1 >= x_1 * a_2 / x_2) || (x_2 == 0 && x_1 >= 0 && a_2 <= 0) || (x_2 == 0 && x_1 < 0 && a_2 >= 0)) {
                if (ugol <= arg_r) {
                    arg_r = ugol;
                    r_1 = a_1;
                    r_2 = a_2;
                }
            }
            else {
                if (ugol <= arg_l) {
                    arg_l = ugol;
                    l_1 = a_1;
                    l_2 = a_2;
                }
            }
        }
    }
    in.close();
    cout << "Leftmost: " << l_1 << " " << l_2 << endl;
    cout << "Rightmost: " << r_1 << " " << r_2 << endl;

    return 0;
}
