package corraporsuavida;

import java.util.TreeSet;

public class PathCalculator {
    
    private PathNode pathNodeMatrix[][];
    private TreeSet<PathNode> orderedPathNodeSet;
    private PathNode startNode;
    private PathNode endNodeArray[];

    public PathCalculator(PathNode[][] pathNodeMatrix, PathNode startNode, 
            PathNode[] endNodeArray) {
        
        this.pathNodeMatrix = pathNodeMatrix;
        this.startNode = startNode;
        this.endNodeArray = endNodeArray;
        
        initOrderedPathNodeSet();
    }
    
    
    public int getHighestMinimizedNodeOnPath(){
        DisjointSet<PathNode> sets = new DisjointSet<>();
        int matrixWidth = pathNodeMatrix.length;
        int matrixHeight = pathNodeMatrix[0].length;
        PathNode nodeMatrix[][] = new PathNode[matrixWidth][matrixHeight];
        PathNode currentNode = null;
        
        do{
            currentNode = orderedPathNodeSet.pollFirst();

            sets.makeSet(currentNode);
            nodeMatrix[currentNode.xPos][currentNode.yPos] = currentNode;
            connectToNeighbors(currentNode, 
                                nodeMatrix, sets);
            
        }while(!startEndConnected(sets));

        
        return currentNode.value;
       
    }

    
    private void connectToNeighbors(PathNode currentNode, PathNode[][] nodeMatrix, 
            DisjointSet<PathNode> sets) {
        
        int matrixHeight = nodeMatrix.length;
        int matrixWidth = nodeMatrix[0].length;
        
        int i = currentNode.xPos-1 >=0 ? currentNode.xPos-1:0;
        for(i=i; i < matrixHeight && i <= currentNode.xPos+1; ++i){
            
            int j = currentNode.yPos-1 >=0 ? currentNode.yPos-1:0;
            for(j=j; j < matrixWidth && j <= currentNode.yPos+1; ++j){
                
                if(nodeMatrix[i][j] != null){
                    sets.union(sets.findSet(currentNode), sets.findSet(nodeMatrix[i][j]));
                }
            }
        }
    }
    
    
    private void initOrderedPathNodeSet() {
        this.orderedPathNodeSet = new TreeSet<>();
        for (int i = 0; i < pathNodeMatrix.length; ++i) {
            for (int j = 0; j < pathNodeMatrix[i].length; ++j) {
                orderedPathNodeSet.add(pathNodeMatrix[i][j]);
            }
        }
    }

    
    private boolean startEndConnected(DisjointSet<PathNode> sets) {
        
        if(sets.findSet(startNode) == null){
            return false;
        }
        
        for(int i = 0; i < endNodeArray.length; ++i){
            if(sets.findSet(startNode).equals(sets.findSet(endNodeArray[i]))){
                return true;
            }
        }
        
        return false;
    }
    
}
