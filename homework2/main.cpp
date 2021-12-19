#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    float g = 9.81;

    // Считываем начальную высоту и скорость мат. точки
    string str;
    ifstream in ("test2(1).txt");
    in.is_open();
    in >> str;
    float h_0 = stof(str);
    in >> str;
    float v_x = stof(str);
    in >> str;
    float v_y = stof(str);

    int n = 0;
    float arr[100][100];

    // Считываем координаты и высоты перегородок
    if (in.is_open()){
        while (in >> str){
            float x_n = stof(str);
            arr[n][0] = x_n;
            in >> str;
            float h_n = stof(str);
            arr[n][1] = h_n;
            n++;
        }
    }
    in.close();


    float x = arr[0][0];
    float p = arr[0][1];
    float h = x * v_y / v_x - x * x * g / (2 * v_x * v_x) + h_0;
    int i = 0;

    if (v_x > 0){
        while (h > 0){
            if ((x * v_y / v_x - x * x * g / (2 * v_x * v_x) + h_0) <= p){
                v_x = - v_x;

                if (v_x > 0){
                    x = arr[i+1][0];
                    p = arr[i+1][1];
                    i = i + 1;
                    h = x * v_y / v_x - x * g / (2 * v_x * v_x) + h_0;
                }else{
                    if (i - 1 >= 0){
                        x = arr[i-1][0];
                        p = arr[i-1][1];
                        i = i - 1;
                        h = x * v_y / v_x - x * g / (2 * v_x * v_x) + h_0;#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    float g = 9.81;

    // Считываем начальную высоту и скорость мат. точки
    string str;
    ifstream in ("test2(1).txt");
    in.is_open();
    in >> str;
    float h_0 = stof(str);
    in >> str;
    float v_x = stof(str);
    in >> str;
    float v_y = stof(str);

    int n = 0;
    float arr[100][100];

    // Считываем координаты и высоты перегородок
    if (in.is_open()){
        while (in >> str){
            float x_n = stof(str);
            arr[n][0] = x_n;
            in >> str;
            float h_n = stof(str);
            arr[n][1] = h_n;
            n++;
        }
    }
    in.close();


    float x = arr[0][0];
    float p = arr[0][1];
    float h = x * v_y / v_x - x * x * g / (2 * v_x * v_x) + h_0;
    int i = 0;

    if (v_x > 0){
        while (h > 0){
            if ((x * v_y / v_x - x * x * g / (2 * v_x * v_x) + h_0) <= p){
                v_x = - v_x;

                if (v_x > 0){
                    x = arr[i+1][0];
                    p = arr[i+1][1];
                    i = i + 1;
                    h = x * v_y / v_x - x * g / (2 * v_x * v_x) + h_0;
                }else{
                    if (i - 1 >= 0){
                        x = arr[i-1][0];
                        p = arr[i-1][1];
                        i = i - 1;
                        h = x * v_y / v_x - x * g / (2 * v_x * v_x) + h_0;
                    }else{
                        i = 0;
                        h = -1;
                    }
                }

            } else {
                if (i + 1 <= n) {
                    x = arr[i + 1][0];
                    p = arr[i + 1][1];
                    h = x * v_y / v_x - x * g / (2 * v_x * v_x) + h_0;
                    i = i + 1;
                } else{
                    i = n;
                    h = -1;
                }
            }
        }
        cout << i << endl;
    } else{
        cout << 0 << endl;
    }

    return 0;
}
