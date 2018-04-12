/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package corraporsuavida;

import java.util.Scanner;

/**
 *
 * @author rodrigo
 */
public class CorraPorSuaVida {

    public static void main(String[] args) {
        int matrixWidth, matrixHeight;
        PathNode pathNodeMatrix[][];
        int pathNodeXpos, pathNodeYpos;
        PathNode startNode;
        PathNode endNodeArray[];
        Scanner scan = new Scanner(System.in);
        
        
        /*Montando as configuracoes iniciais*/
        matrixHeight = scan.nextInt();
        matrixWidth = scan.nextInt();
        pathNodeMatrix = new PathNode[matrixHeight][matrixWidth];
        
        /*Montando o set ordenado de nós e a matriz de valores dos caminhos*/
        for(int i = 0; i < matrixHeight; ++i){
            for(int j = 0; j < matrixWidth; ++j){
                pathNodeMatrix[i][j] = new PathNode(scan.nextInt(), i, j);
            }
        }
        
        /*no inicial*/
        pathNodeXpos = scan.nextInt();
        pathNodeYpos = scan.nextInt();
        startNode = pathNodeMatrix[pathNodeXpos][pathNodeYpos];
        
        /*Montando array de nos de saida*/
        endNodeArray = new PathNode[scan.nextInt()];        
        for(int i = 0; i < endNodeArray.length; ++i){
            pathNodeXpos = scan.nextInt();
            pathNodeYpos = scan.nextInt();
            
            endNodeArray[i] = pathNodeMatrix[pathNodeXpos][pathNodeYpos];
        }
        
        PathCalculator pathCalculator = new PathCalculator(pathNodeMatrix, startNode, endNodeArray);

        System.out.println(pathCalculator.getHighestMinimizedNodeOnPath());
        
    }
    
}
