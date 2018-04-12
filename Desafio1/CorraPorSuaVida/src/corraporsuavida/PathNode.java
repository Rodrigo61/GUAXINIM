package corraporsuavida;

public class PathNode implements Comparable<PathNode>{
    int value;
    int xPos, yPos;

    public PathNode(int value, int xPos, int yPos) {
        this.value = value;
        this.xPos = xPos;
        this.yPos = yPos;
    }
    
    @Override
    public int compareTo(PathNode node) {
        if(node.value > value){
            return -1;
        }else if(node.value < value){
            return 1;
        }
        return 1;
    }
    
}
