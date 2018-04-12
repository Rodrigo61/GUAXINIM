package corraporsuavida;

import java.util.HashMap;

/**
 *
 * @author rodrigo
 */
public class DisjointSet<Type> {
    
    private static class Node<Type>{
        int rank;
        Type parent;   

        public Node(int rank, Type parent) {
            this.rank = rank;
            this.parent = parent;
        }
    }
    
    private HashMap<Type, Node<Type>> mapObjectToNode; 

    public DisjointSet() {
        mapObjectToNode = new HashMap<>();
    }
    
    
    public Type findSet(Type object){
        Node<Type> currenteNode = mapObjectToNode.get(object);
        
        if(currenteNode == null){
            return null;
        }
        
        if(currenteNode.parent != object){
            currenteNode.parent = findSet(currenteNode.parent); //path compression
            return currenteNode.parent;
        }
        
        return object;
    }
    
    
    public void makeSet(Type object){
        mapObjectToNode.put(object, new Node<>(0, object));
    }
    
    /*Junta dois conjuntos utilizando as raizes dos mesmos.
      Esse método utiliza do conceito UnionByRank para manter a menor profundidade
    para a árvore de saída.
      Caso algum objeto passado como parametro nao seja raiz nao é feita 
    a operacao*/
    public void union(Type objectRoot1, Type objectRoot2){
        Node<Type> nodeRoot1 = mapObjectToNode.get(objectRoot1);
        Node<Type> nodeRoot2 = mapObjectToNode.get(objectRoot2);
        
        if((nodeRoot1.parent != objectRoot1) || (nodeRoot2.parent != objectRoot2)){
            return;
        }
        
        
        if(nodeRoot1.rank > nodeRoot2.rank){
            nodeRoot2.parent = objectRoot1;
        }else{
            nodeRoot1.parent = objectRoot2;
            if(nodeRoot1.rank == nodeRoot2.rank){
                ++nodeRoot2.rank; 
            }
            
        }
    }
    
}
