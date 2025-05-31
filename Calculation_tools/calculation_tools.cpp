#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const double phi = 3.141592653589793;

double operation(double x, string op, double y) {
    if (op == "+") {
        return x + y;
    }
    else if (op == "-") {
        return x - y;
    }
    else if (op == "*") {
        return x * y;
    }
    else if (op == "/") {
        if (y != 0) {
            return x / y;
        } else {
            cerr << "Error: Pembagian dengan nol!" << endl;
            return 0;
        }
    } else if (op == "%") {
        return static_cast<int>(x) % static_cast<int>(y);
    }
    else if (op == "^") {
        return pow(x, y);
    }
    else if (op == "sqrt") {
        return sqrt(x);
    }
    else if (op == "log") {
        return log(x);
    }
    else if (op == "exp") {
        return exp(x);
    }
    else if (op == "sin") {
        return sin(x);
    }
    else if (op == "cos") {
        return cos(x);
    }
    else if (op == "tan") {
        return tan(x);
    }
    else if (op == "asin") {
        return asin(x);
    }
    else if (op == "acos") {
        return acos(x);
    }
    else if (op == "atan") {
        return atan(x);
    }
    else if (op == "abs") {
        return abs(x);
    }
    else if (op == "ceil") {
        return ceil(x);
    }
    else if (op == "floor") {
        return floor(x);
    }
    else if (op == "round") {
        return round(x);
    }
    else if (op == "max") {
        return max(x, y);
    }
    else if (op == "min") {
        return min(x, y);
    }
    else if (op == "pow") {
        return pow(x, y);
    }
    else if (op == "log10") {
        return log10(x);
    }
    else if (op == "log2") {
        return log2(x);
    }
    else if (op == "exp2") {
        return exp2(x);
    }
    else if (op == "hypot") {
        return hypot(x, y);
    }
    else if (op == "fmod") {
        return fmod(x, y);
    }
    else if (op == "remainder") {
        return remainder(x, y);
    }
    else if (op == "trunc") {
        return trunc(x);
    }
    else if (op == "nearbyint") {
        return nearbyint(x);
    }
    else if (op == "copysign") {
        return copysign(x, y);
    }
    else if (op == "nextafter") {
        return nextafter(x, y);
    }
    else if (op == "nexttoward") {
        return nexttoward(x, y);
    }
    else if (op == "fdim") {
        return fdim(x, y);
    }
    else if (op == "fmax") {
        return fmax(x, y);
    }
    else if (op == "fmin") {
        return fmin(x, y);
    }
    else if (op == "isnan") {
        return isnan(x);
    }
    else if (op == "isinf") {
        return isinf(x);
    }
    else if (op == "isfinite") {
        return isfinite(x);
    }
    else if (op == "isnormal") {
        return isnormal(x);
    }
    else if (op == "signbit") {
        return signbit(x);
    }
    else if (op == "isgreater") {
        return isgreater(x, y);
    }
    else if (op == "isgreaterequal") {
        return isgreaterequal(x, y);
    }
    else if (op == "isless") {
        return isless(x, y);
    }
    else if (op == "islessequal") {
        return islessequal(x, y);
    }
    else if (op == "islessgreater") {
        return islessgreater(x, y);
    }
    else {
        cout << "Error: Operator tidak dikenal!" << endl;
        return 0;
    }
}

struct Cube {
    double panjang, lebar, tinggi, volume, luasPermukaan, panjangDiagonal;
    double volumeF() {
       if (panjang != 0 && lebar != 0 && tinggi != 0) {
            return panjang * lebar * tinggi;
        } else if (luasPermukaan != 0) {
            return luasPermukaan / 6;
        } else if (panjangDiagonal != 0) {
            return pow(panjangDiagonal, 3) / 6;
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double luasPermukaanF() {
        if (panjang != 0 && lebar != 0 && tinggi != 0) {
            return 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
        } else if (volume != 0) {
            return 6 * pow(volume, 2.0 / 3.0);
        } else if (panjangDiagonal != 0) {
            return 6 * pow(panjangDiagonal, 2);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double panjangF() {
        if (volume != 0) {
            return volume / (lebar * tinggi);
        } else if (luasPermukaan != 0) {
            return (luasPermukaan / 2 - lebar * tinggi) / (lebar + tinggi);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double lebarF() {
        if (volume != 0) {
            lebar = volume / (panjang * tinggi);
        } else if (luasPermukaan != 0) {
            lebar = (luasPermukaan / 2 - panjang * tinggi) / (panjang + tinggi);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double tinggiF() {
        if (volume != 0) {
            tinggi = volume / (panjang * lebar);
        } else if (luasPermukaan != 0) {
            tinggi = (luasPermukaan / 2 - panjang * lebar) / (panjang + lebar);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double panjangDiagonalF() {
        if (volume != 0) {
            return pow(volume, 1.0 / 3.0);
        } else if (luasPermukaan != 0) {
            return sqrt(luasPermukaan / 6);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    };
    double handler(string calc, vector<double> params) {
        panjang = params[0];
        lebar = params[1];
        tinggi = params[2];
        volume = params[3];
        luasPermukaan = params[4];
        panjangDiagonal = params[5];
        if (calc == "volume") {
            return volumeF();
        } else if (calc == "luasPermukaan") {
            return luasPermukaanF();
        } else if (calc == "panjang") {
            return panjangF();
        } else if (calc == "lebar") {
            return lebarF();
        } else if (calc == "tinggi") {
            return tinggiF();
        } else if (calc == "panjangDiagonal") {
            return panjangDiagonalF();
        } else {
            printf("[Error]  0\n");
        }
        
    }
};
struct Sphere {
    double radius, diameter, volume, luasPermukaan;
    double volumeF() {
        if (radius != 0) {
            return (4.0 / 3.0) * phi * pow(radius, 3);
        } else if (diameter != 0) {
            return (1.0 / 6.0) * phi * pow(diameter, 3);
        } else if (luasPermukaan != 0) {
            return luasPermukaan / (4 * phi);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double luasPermukaanF() {
        if (radius != 0) {
            return 4 * phi * pow(radius, 2);
        } else if (diameter != 0) {
            return phi * pow(diameter, 2);
        } else if (volume != 0) {
            return (3 * volume) / (phi * pow(radius, 2));
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double radiusF() {
        if (volume != 0) {
            return pow((3 * volume) / (4 * phi), 1.0 / 3.0);
        } else if (luasPermukaan != 0) {
            return sqrt(luasPermukaan / (4 * phi));
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double diameterF() {
        if (volume != 0) {
            return pow((6 * volume) / phi, 1.0 / 3.0);
        } else if (luasPermukaan != 0) {
            return sqrt(luasPermukaan / phi);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double handler(string calc, vector<double> params) {
        radius = params[0];
        diameter = params[1];
        volume = params[2];
        luasPermukaan = params[3];
        if (calc == "volume") {
            return volumeF();
        } else if (calc == "luasPermukaan") {
            return luasPermukaanF();
        } else if (calc == "radius") {
            return radiusF();
        } else if (calc == "diameter") {
            return diameterF();
        } else {
            printf("[Error]  0\n");
        }
        
    }
};
struct Prism {
    double panjang, lebar, tinggi, volume, luasPermukaan;
    double volumeF() {
        if (panjang != 0 && lebar != 0 && tinggi != 0) {
            return panjang * lebar * tinggi;
        } else if (luasPermukaan != 0) {
            return luasPermukaan / 2;
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double luasPermukaanF() {
        if (panjang != 0 && lebar != 0 && tinggi != 0) {
            return 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
        } else if (volume != 0) {
            return volume * 2;
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double panjangF() {
        if (volume != 0) {
            return volume / (lebar * tinggi);
        } else if (luasPermukaan != 0) {
            return (luasPermukaan / 2 - lebar * tinggi) / (lebar + tinggi);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double lebarF() {
        if (volume != 0) {
            lebar = volume / (panjang * tinggi);
        } else if (luasPermukaan != 0) {
            lebar = (luasPermukaan / 2 - panjang * tinggi) / (panjang + tinggi);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double tinggiF() {
        if (volume != 0) {
            tinggi = volume / (panjang * lebar);
        } else if (luasPermukaan != 0) {
            tinggi = (luasPermukaan / 2 - panjang * lebar) / (panjang + lebar);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double handler(string calc, vector<double> params) {
        panjang = params[0];
        lebar = params[1];
        tinggi = params[2];
        volume = params[3];
        luasPermukaan = params[4];
        if (calc == "volume") {
            return volumeF();
        } else if (calc == "luasPermukaan") {
            return luasPermukaanF();
        } else if (calc == "panjang") {
            return panjangF();
        } else if (calc == "lebar") {
            return lebarF();
        } else if (calc == "tinggi") {
            return tinggiF();
        } else {
            printf("[Error]  0\n");
        }
        
    }
};
struct Cone {
    double radius, tinggi, volume, luasPermukaan;
    double volumeF() {
        if (radius != 0 && tinggi != 0) {
            return (1.0 / 3.0) * phi * pow(radius, 2) * tinggi;
        } else if (luasPermukaan != 0) {
            return (luasPermukaan - phi * pow(radius, 2)) * tinggi / (phi * pow(radius, 2));
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double luasPermukaanF() { 
        if (radius != 0 && tinggi != 0) {
            return phi * radius * (radius + sqrt(pow(radius, 2) + pow(tinggi, 2)));
        } else if (volume != 0) {
            return (3 * volume) / (phi * radius);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double radiusF() {
        if (volume != 0) {
            return sqrt((3 * volume) / (phi * tinggi));
        } else if (luasPermukaan != 0) {
            return sqrt((luasPermukaan - phi * pow(radius, 2)) / (phi * radius));
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double tinggiF() {
        if (volume != 0) {
            return (3 * volume) / (phi * pow(radius, 2));
        } else if (luasPermukaan != 0) {
            return (luasPermukaan - phi * pow(radius, 2)) / (phi * radius);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double handler(string calc, vector<double> params) {
        radius = params[0];
        tinggi = params[1];
        volume = params[2];
        luasPermukaan = params[3];
        if (calc == "volume") {
            return volumeF();
        } else if (calc == "luasPermukaan") {
            return luasPermukaanF();
        } else if (calc == "radius") {
            return radiusF();
        } else if (calc == "tinggi") {
            return tinggiF();
        } else {
            printf("[Error]  0\n");
        }
        
    }
};
struct Pyramid {
    double panjang, lebar, tinggi, volume, luasPermukaan;
    double volumePyramid() {
        if (panjang != 0 && lebar != 0 && tinggi != 0) {
            return (1.0 / 3.0) * panjang * lebar * tinggi;
        } else if (luasPermukaan != 0) {
            return (luasPermukaan - panjang * lebar) * tinggi / (panjang * lebar);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double luasPermukaanPyramid() {
        if (panjang != 0 && lebar != 0 && tinggi != 0) {
            return panjang * lebar + (panjang + lebar) * sqrt(pow(tinggi, 2) + pow(panjang / 2, 2));
        } else if (volume != 0) {
            return (3 * volume) / (panjang * lebar);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double panjangPyramid() {
        if (volume != 0) {
            return (3 * volume) / (lebar * tinggi);
        } else if (luasPermukaan != 0) {
            return (luasPermukaan - lebar * tinggi) / (lebar + tinggi);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double lebarPyramid() {
        if (volume != 0) {
            lebar = (3 * volume) / (panjang * tinggi);
        } else if (luasPermukaan != 0) {
            lebar = (luasPermukaan - panjang * tinggi) / (panjang + tinggi);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double tinggiPyramid() {
        if (volume != 0) {
            tinggi = (3 * volume) / (panjang * lebar);
        } else if (luasPermukaan != 0) {
            tinggi = (luasPermukaan - panjang * lebar) / (panjang + lebar);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double handler(string calc, vector<double> params) {
        panjang = params[0];
        lebar = params[1];
        tinggi = params[2];
        volume = params[3];
        luasPermukaan = params[4];
        if (calc == "volume") {
            return volumePyramid();
        } else if (calc == "luasPermukaan") {
            return luasPermukaanPyramid();
        } else if (calc == "panjang") {
            return panjangPyramid();
        } else if (calc == "lebar") {
            return lebarPyramid();
        } else if (calc == "tinggi") {
            return tinggiPyramid();
        } else {
            printf("[Error]  0\n");
        }
        
    }
};
struct Cylinder {
    double radius, tinggi, volume, luasPermukaan, luasSelimut;
    double luasSelimutF() {
        if (radius != 0 && tinggi != 0) {
            return 2 * phi * radius * tinggi;
        } else if (luasPermukaan != 0) {
            return luasPermukaan - 2 * phi * pow(radius, 2);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double volumeF() {
        if (radius != 0 && tinggi != 0) {
            return phi * pow(radius, 2) * tinggi;
        } else if (luasPermukaan != 0) {
            return (luasPermukaan - 2 * phi * pow(radius, 2)) * tinggi / (phi * pow(radius, 2));
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double luasPermukaanF() {
        if (radius != 0 && tinggi != 0) {
            return 2 * phi * radius * (radius + tinggi);
        } else if (volume != 0) {
            return (3 * volume) / (phi * radius);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double tinggiF() {
        if (volume != 0) {
            return volume / (phi * pow(radius, 2));
        } else if (luasPermukaan != 0) {
            return (luasPermukaan - 2 * phi * pow(radius, 2)) / (2 * phi * radius);
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double radiusF() {
        if (volume != 0) {
            return sqrt(volume / (phi * tinggi));
        } else if (luasPermukaan != 0) {
            return sqrt((luasPermukaan - 2 * phi * pow(radius, 2)) / (2 * phi * radius));
        } else {
            printf("[Error] terdapat parameter yang kosong 0\n");
        }
    }
    double handler(string calc, vector<double> params) {
        radius = params[0];
        tinggi = params[1];
        volume = params[2];
        luasPermukaan = params[3];
        luasSelimut = params[4];
        if (calc == "volume") {
            return volumeF();
        } else if (calc == "luasPermukaan") {
            return luasPermukaanF();
        } else if (calc == "luasSelimut") {
            return luasSelimutF();
        } else if (calc == "radius") {
            return radiusF();
        } else if (calc == "tinggi") {
            return tinggiF();
        } else {
            printf("[Error]  0\n");
        }
        
    }
};

Cube cube;
Sphere sphere;
Prism prism;
Cone cone;
Pyramid pyramid;
Cylinder cylinder;



string shift (bool type, string text, int s) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += char(int(base + (c - base + s) % 26));
        } else {
            result += c;
        }
    }
    return result;
}
string vigenere(bool type, const string& text, const vector<string>& params) {
    string result = "";
    int keyIndex = 0;
    int keyLength = params[0].length();
    if (type) {
        for (char ch : text) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                int shift = (tolower(params[0][keyIndex]) - 'a') * (type ? 1 : -1);
                ch = (ch - base + shift + 26) % 26 + base;
                keyIndex = (keyIndex + 1) % keyLength;
            }
            result += ch;
        }
    } else {
        for (char ch : text) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                int shift = (tolower(params[0][keyIndex]) - 'a') * (type ? -1 : 1);
                ch = (ch - base + shift + 26) % 26 + base;
                keyIndex = (keyIndex + 1) % keyLength;
            }
            result += ch;
        }
    }
    return result;
}
string xorEncrypt(bool type, const string& text, const vector<string>& params) {
    string result = "";
    for (char ch : text) {
        result += ch ^ params[0][0]; // XOR dengan karakter pertama dari kunci
    }
    return result;
}

// enkripsi dan dekripsi
string encryption(string algorithm, bool type, string text, vector<string> params) {
    if (algorithm == "caesar") {
        return shift(type, text, stoi(params[0]));
    } else if (algorithm == "vigenere") {
        return vigenere(type, text, params);
    } else if (algorithm == "xor") {
        return xorEncrypt(type, text, params);
    } /* else if (algorithm == "substitution") {
        return substitution(type, text, s);
    } else if (algorithm == "railfence") {
        return railfence(type, text, s);
    } else if (algorithm == "playfair") {
        return playfair(type, text, s);
    } else if (algorithm == "rsa") {
        return rsa(type, text, s);
    } else {
        cerr << "[Error] Algoritma tidak dikenal!" << endl;
        return "";
    } */
    
}

// Fungsi untuk memecah string berdasarkan delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}

// Fungsi utama untuk menjalankan command
void executeCommand(const string& target, const string& command, const string& params) {
    
    /* format command: <target|command|parameter{}>
    contoh:
        cube|volume|panjang;lebar;tinggi;volume;luasPermukaan;panjangDiagonal;
        operation|+|parameter1;parameter2;
        encryption|encrypt|caesar;5;Hello World;
        encryption|decrypt|caesar;5;Hello World;
    */

    vector<string> paramList = split(params, ';');
    vector<double> doubleParamList;
    
    for (const auto& x : paramList) {
        bool isDouble = true;
        for (char c : x) {
            if (!isdigit(c)) {
                isDouble = false;
                break;
            }
        }
        if (isDouble) {
            doubleParamList.push_back(stod(x));
        } else if (isDouble == false) {
            break;
        }
    }
    
    cout << "Command: " << command << "\n";
    cout << "Target : " << target << "\n";
    cout << "Params : " << params << "\n";

    if (target == "cube") {
       cout << cube.handler(command, doubleParamList);
    } else if (target == "sphere") {
        cout << sphere.handler(command, doubleParamList);
    } else if (target == "prism") {
        cout << prism.handler(command, doubleParamList);
    } else if (target == "cone") {
        cout << cone.handler(command, doubleParamList);
    } else if (target == "pyramid") {
        cout << pyramid.handler(command, doubleParamList);
    } else if (target == "cylinder") {
        cout << cylinder.handler(command, doubleParamList);
    } else if (target == "operation") {
        if (paramList.size() == 2) {
            double x = stod(paramList[0]);
            double y = stod(paramList[1]);
            cout << operation(x, command, y);
        } else {
            cerr << "Format salah! Gunakan <target|operasi|parameter1;parameter2>\n";
        }
    } else if (target == "encryption") {
        cout << encryption(paramList[0], command == "encrypt"? true : false, paramList[2], paramList);
        // encryption|encrypt|caesar;5;Hello World;
    } else {
        cerr << "Target tidak dikenal!\n";
    }
}

int main() {
    string input;
    cout << "Masukkan perintah (<target|command|parameter{}>): ";
    getline(cin, input);
    vector<string> parts = split(input, '|');
    if (parts.size() != 3) {
        cerr << "Format salah! Gunakan <target|command|parameter{}>\n";
        return 1;
    }
    string target = parts[0];
    string command = parts[1];
    string params = parts[2];

    executeCommand(target, command, params);

    return 0;
}
