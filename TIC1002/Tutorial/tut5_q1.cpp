#include <iostream>
#include <map> 
#include <vector>

using namespace std;

struct NUSModule {
    string code;
    int credits;
    string grade;
    bool su;
};

void make_module(NUSModule &module, string code, int credits, string grade) {
    module.code = code;
    module.credits = credits;
    module.grade = grade;
    module.su = false;
}

void set_su(NUSModule &module, bool su) {
    if (su) {
        if (module.grade == "D+" || module.grade == "D" || module.grade == "F") {
            module.grade = "U"; 
        } else {
            module.grade = "S"; 
        }
    } 
}

int credits_obtained(const vector<NUSModule> &modules) {
    int total_credit = 0;
    
    for (int i = 0; i < modules.size(); i++)
    {
        if ( modules[i].grade != "F" && modules[i].grade != "U" ) total_credit += modules[i].credits; 
    }
    return total_credit;
}

double calculate_cap(const vector<NUSModule> &modules, const map<string, double> &points) {
    double cap = 0, total = 0;
    
    for (int i = 0; i < modules.size(); i++)
    {     
        string grade = modules[i].grade;
        if (grade == "S" || grade == "U") continue; 

        int credits = modules[i].credits;
        cap += credits * points.at(grade);
        total = total + credits;
    }
    
    return cap/total; 
}

int main() {
    NUSModule tic1001, tic1101, tba2102, tic2301, tic1231 ; 

    make_module(tic1001, "TIC1001", 4, "A"); 
    make_module(tic1101, "TIC1101", 4, "B-"); 
    make_module(tba2102, "TBA2102", 3, "C"); 
    set_su(tba2102, true);	

    make_module(tic2301, "TIC2301", 4, "D"); 
    set_su(tic2301, true);

    make_module(tic1231, "TIC1231", 2, "F"); 

    vector<NUSModule> modules; 
    // {tic1001, tic1101, tba2102, tic2301, tic1231};

    modules.push_back(tic1001); 
    modules.push_back(tic1101); 
    modules.push_back(tba2102);
    modules.push_back(tic2301); 
    modules.push_back(tic1231); 

    // for (int i = 0; i < modules.size(); i++) 
    //     cout << modules[i].code << " "; 

    cout << credits_obtained(modules) << endl; 

    map<string, double> grade2points; 

    grade2points.insert(pair<string, double>("A+", 5.0)); 
    grade2points.insert(pair<string, double>("A", 5.0)); 
    grade2points.insert(pair<string, double>("A-", 4.5)); 
    grade2points.insert(pair<string, double>("B+", 4.0)); 
    grade2points.insert(pair<string, double>("B", 3.5)); 
    grade2points.insert(pair<string, double>("B-", 3.0)); 
    grade2points.insert(pair<string, double>("C+", 2.5)); 
    grade2points.insert(pair<string, double>("C", 2.0)); 

    grade2points.insert(pair<string, double>("D+", 1.5)); 
    grade2points.insert(pair<string, double>("D", 1.0)); 
    grade2points.insert(pair<string, double>("F", 0.0)); 

    // cout << grade2points.at("A+") << endl;

    cout << calculate_cap(modules, grade2points) << endl;

}