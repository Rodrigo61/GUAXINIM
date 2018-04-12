#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class ABBADiv1 {

public:

    string canObtain(string initial, string target){
        int initialCountA = 0, initialCountB = 0, 
        targetCountA = 0, targetCountB = 0;
        
        for(int i = 0; i < initial.length(); ++i){  
            if(initial[i] == 'A'){
                ++initialCountA;
            }else{
                ++initialCountB;
            }
        }

        for(int i = 0; i < target.length(); ++i){
            if(target[i] == 'A'){
                ++targetCountA;
            }else{
                ++targetCountB;
            }
        }
        
        if(canObtainRec(initial, target, initialCountA, initialCountB, 
                targetCountA, targetCountB) == 1){
        	return "Possible";
        }
        
        return "Impossible";
    }
    
    
    int canObtainRec(string initial, string target, int initialCountA,
            int initialCountB, int targetCountA, int targetCountB){
    	
        if(initial.length() >= target.length()){
            if(initial == target){
                return 1;
            }
            
            return 0;
        }

        string aux = initial;
        reverse(aux.begin(), aux.end());

        if(target.find(initial) == string::npos && target.find(aux) == string::npos){
            return 0;
        }

        
        int returnRecValue = 0;
        
        if(initialCountA < targetCountA){
            returnRecValue += canObtainRec(addA(initial), target, initialCountA+1, 
                    initialCountB, targetCountA, targetCountB);
        }
        
        if(initialCountB < targetCountB){
            returnRecValue += canObtainRec(addB(initial), target, initialCountA,
                    initialCountB+1, targetCountA, targetCountB);
        }
        
        return returnRecValue;
        
    }
    
    
    string addA(string str){
        str.append("A");
        return str;
    }
    
    string addB(string str){
        str.append("B");
        reverse(str.begin(), str.end());
        return str;
    }
    
};

int main(){
    ABBADiv1* cls = new ABBADiv1();
    string initial = "A";
    string target = "BABA";


    cout << cls->canObtain(initial, target);

}
