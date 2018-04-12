package abbadiv1;

public class ABBADiv1 {
    

    public String canObtain(String initial, String target){
        int initialCountA = 0, initialCountB = 0, 
        targetCountA = 0, targetCountB = 0;
        
        for(int i = 0; i < initial.length(); ++i){  
            if(initial.charAt(i) == 'A'){
                ++initialCountA;
            }else{
                ++initialCountB;
            }
        }
        
        for(int i = 0; i < target.length(); ++i){
            if(target.charAt(i) == 'A'){
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
    
    
    public int canObtainRec(String initial, String target, int initialCountA, 
            int initialCountB, int targetCountA, int targetCountB){
    	
        if(initial.length() >= target.length()){
            if(initial.equals(target)){
                return 1;
            }
            
            return 0;
        }
        
        if(!target.contains(initial) && !target.contains(new StringBuilder(initial).reverse())){
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
    
    
    public String addA(String str){
        return new StringBuilder(str).append('A').toString();
    }
    
    public String addB(String str){
        return new StringBuilder(str).append('B').reverse().toString();
    }
    
}
